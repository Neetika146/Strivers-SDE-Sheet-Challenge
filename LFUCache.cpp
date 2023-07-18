#include <bits/stdc++.h> 
struct Node{
    int key, val, cnt;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        val = val_;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->next = head;
        size = 0;
    }

    void addnode(Node *newnode){
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        size++;
    }

    void deletenode(Node *node){
        Node* delnext = node->next;
        Node* delprev = node->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSize, minFreq, currSize;

    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updatefreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deletenode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) minFreq++;

        List* nextHigherFreq = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreq = freqListMap[node->cnt + 1];
        }
        node->cnt+=1;
        nextHigherFreq->addnode(node);
        freqListMap[node->cnt] = nextHigherFreq;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!= keyNode.end()){
            Node *node = keyNode[key];
            int value = node->val;
            updatefreqListMap(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* newnode = keyNode[key];
            newnode->val = value;
            updatefreqListMap(newnode);
        }
        else{
            if(currSize == maxSize){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deletenode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* newnode = new Node(key, value);
            listFreq->addnode(newnode);
            keyNode[key] = newnode;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */