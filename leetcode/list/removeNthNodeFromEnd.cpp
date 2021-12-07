class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode* nthNodePrev = NULL;
    ListNode* curr = head;
    int count = 0;

    while(curr != NULL){
        if(count == n){
            nthNodePrev = head;
        }
    	else if(count > n){
    		nthNodePrev = nthNodePrev->next;
    	}
    	curr = curr->next;
    	count++;
    }

    if(nthNodePrev == NULL){
      ListNode* nthNodePrev = head;
      head = head->next;
      delete nthNodePrev;
    }else{
      ListNode* nodeToBeRemoved = nthNodePrev->next;
      nthNodePrev->next = nodeToBeRemoved->next;
      delete nodeToBeRemoved;
    }
    return head;
    }
};
