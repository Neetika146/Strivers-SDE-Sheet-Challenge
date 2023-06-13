#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedLinkedListNode<int> class:

    template <typename T>
    class LinkedLinkedListNode<int>
    {
    public:
        T data;
        LinkedLinkedListNode<int><T> *next;
        LinkedLinkedListNode<int>(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* middleLL(LinkedListNode<int>* head){
        if(head==0){
            return NULL;
        }
        LinkedListNode<int>* f= head;
        LinkedListNode<int>* s =head;
        while(f->next!=NULL && f->next->next!=NULL){
            f=f->next->next;
            s=s->next;
        }
        return s;
    }

    LinkedListNode<int>* reverseLL(LinkedListNode<int>* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        LinkedListNode<int>* p= NULL;
        LinkedListNode<int>* c =head;
        while(c!=NULL){
            LinkedListNode<int>* n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }

    bool isPalindrome(LinkedListNode<int>* head) {
        if(head == NULL || head -> next == NULL) return true;

        LinkedListNode<int> *middle = middleLL(head);
        middle = middle -> next;
        LinkedListNode<int> *temp = reverseLL(middle);
        while(temp != NULL){
            if(temp->data != head->data) return false;
            temp = temp -> next; 
            head = head -> next;
        }
        return true;
        // if(head==NULL || head->next==NULL){
        //     return true;
        // }
        // LinkedListNode<int>* mid=middleLL(head);
        // mid->next= reverseLL(mid->next);
        // LinkedListNode<int>* temp =mid->next;
        // while(temp!=NULL){
        //     if(!compareLL(head,temp)){
        //         return false;
        //     }
        //     head=head->next;
        //     temp=temp->next;
        // }
        // return true;
    }