/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int n)
{
    int l = 0;
        Node *temp = head;
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        if (l == n){
            head = head->next;
            return head;
        }
        int j = l - n - 1;
        temp = head;
        while (j>0){
            temp = temp->next;
            j--;
        }
        if (temp->next->next == NULL){
            temp->next = NULL;
        }
        else{
            temp->next = temp->next->next;
        }
        return head;
}
