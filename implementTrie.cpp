struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch - 'a']!=NULL;
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string words) {
        Node* node = root;
        for(int i = 0; i < words.size(); i++){
            if(!node->containsKey(words[i])){
                node->put(words[i], new Node());
            }
            node = node->get(words[i]);
        }
        node->setEnd();
    }
    
    bool search(string words) {
        Node* node = root;
        for(int i = 0; i < words.size(); i++){
            if(!node->containsKey(words[i])){
                return false;
            }
            node  = node->get(words[i]);;
        }
        return node->isEnd();
    }
    
    bool startsWith(string words) {
        Node* node = root;
        for(int i = 0; i < words.size(); i++){
            if(!node->containsKey(words[i])){
                return false;
            }
            node  = node->get(words[i]);;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */