/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
        Node *temp = l1;
        int sum = 0;
        int carry = 0;
        while (temp != NULL && l2 != NULL){
            sum = (temp -> data + l2 -> data + carry) % 10;
            carry = (temp -> data + l2 -> data + carry) / 10;
            temp -> data = sum;
            temp = temp -> next;
            l2 = l2 -> next;
        }
        while (temp != NULL){
            sum = (temp -> data + carry) % 10;
            carry = (temp -> data + carry) / 10;
            temp -> data = sum;
            temp = temp -> next;
        }
        temp = l1;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        while (l2 != NULL){
            sum = (l2 -> data + carry) % 10;
            carry = (l2 -> data + carry) / 10;
            Node *t = new Node(sum);
            temp -> next = t;
            // temp -> data = sum;
            temp = temp -> next;
            l2 = l2 -> next;
        }
        if (carry != 0){
            Node *t = new Node(carry);
            temp -> next = t;
        }
        return l1;
}
