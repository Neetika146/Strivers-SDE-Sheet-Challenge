#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{ 
        if(head == NULL) return NULL;
        LinkedListNode<int> *iter = head, *front = head;
        while(iter !=NULL){
            front = iter->next;
            LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        

        iter = head;
        LinkedListNode<int> *psuedohead = new LinkedListNode<int>(0);
        LinkedListNode<int> *copy = psuedohead;
        while(iter != NULL){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return psuedohead->next;
    // Write your code here.
}
