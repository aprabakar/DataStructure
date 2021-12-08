
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        int sum = 0;
        ListNode* res= new ListNode(-1);
        ListNode* head = res;
        // 1 4 3 4 -> 4341
        // 5 6 4   -> 465
        // 6 0 8 4 -> 4806
        while (l1 || l2){
            if(l1){
                sum += l1->val;
                l1 =l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 =l2->next;
            }
            
            sum += carry;
            ListNode* curr = new ListNode(sum%10);
            res->next = curr;
            res = res->next;
            carry = sum/10;
            sum = 0;
        }
        
        if(carry){
            ListNode* last = new ListNode(carry);
            res->next = last;
        }
        
        return head->next;
        
    }
};
