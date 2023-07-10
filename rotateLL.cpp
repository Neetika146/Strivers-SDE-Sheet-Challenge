/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        int len = 0;
        Node* temp = head;
        while(temp->next){
            len++;
            temp = temp->next;
        }
        len++;
        if(k>=len) k = k%len;
        if(k==0) return head;
        Node *curr = head;
        Node* prev = head;
        int t = len - k;
        while(t--){
            prev = curr;
            curr = curr->next;
        }
        temp->next = head;
        prev->next = NULL;
        return curr;
     // Write your code here.
}