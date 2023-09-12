#include <bits/stdc++.h> 
struct Node{
    Node *links[26];
    int countEnd = 0;
    int countPrefix = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void increaseEnd(){
        countEnd++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void reduceEnd(){
        countEnd--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getEnd() { return countEnd; }
    int getPrefix() { return countPrefix; }
};
class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root = new Node();
        // Write your code here.
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getPrefix();
        // Write your code here.
    }

    void erase(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }
        node->reduceEnd();
        // Write your code here.
    }
};
