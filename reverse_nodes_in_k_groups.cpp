#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
		if(head == NULL || head->next == NULL || n == 1) return head;
        Node *dummy = new Node(0);
        dummy -> next = head;
        Node *nex = dummy, *pre = dummy, *curr = dummy;

        int l = 0;
        while(curr->next){
            l++;
            curr = curr -> next;
        } 

        int i = 0;
        while(l > 0 && i < n){
            if(b[i]==0){
            	i++;
            	continue;
            };
            curr = pre->next;
            nex = curr->next;
            int s = b[i];
            if(l>=b[i]){
              while (--s) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
              }
              l -= b[i];
              i++;
              pre = curr;
            }
            else if(l<b[i]){
				for(int j=1;j<l;j++){
				curr->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = curr->next;
			    }
				pre = curr;
				l-=b[i];
				i++;
			}	
        }
        return dummy->next;
	// Write your code here.
}