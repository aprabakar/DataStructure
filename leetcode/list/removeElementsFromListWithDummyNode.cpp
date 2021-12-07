class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        
        
        while(curr->next != NULL){
            if(curr->next->val == val){
                 ListNode* temp = curr->next;
                 curr->next = temp->next;
                 delete temp;
            }else{
               curr = curr->next; 
            }
        }
    
        return dummy->next;
    }
};
