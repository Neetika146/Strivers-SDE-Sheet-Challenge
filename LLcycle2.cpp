/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
        if(head == NULL || head->next == NULL) return NULL;
        
        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        if(slow != fast) return NULL;

        Node *dummy = head;
        while(slow != dummy){
            slow = slow->next;
            dummy = dummy->next;
        }
        return slow;
}