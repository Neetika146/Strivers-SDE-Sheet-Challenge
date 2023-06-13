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

Node* findIntersection(Node *headA, Node *headB)
{
        int l1 = 0;
        int l2 = 0;
        Node *temp1 = headA;
        Node *temp2 = headB;
        while(temp1){
            l1++;
            temp1=temp1->next;
        }
        while(temp2){
            l2++;
            temp2=temp2->next;
        }
        if (l1 > l2){
            int k = l1-l2;
            while(k){
                k--;
                headA=headA->next;
            }
        }
        else{
            int k = l2-l1;
            while(k){
                k--;
                headB=headB->next;
            }
        }
        // if (headA == headB) return headA;
        while(headA != NULL && headB != NULL){
            if(headA == headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    //Write your code here
}