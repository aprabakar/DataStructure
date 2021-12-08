/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* mergedList = new ListNode(-1);
        ListNode* pointerA = list1;
        ListNode* pointerB = list2;
        ListNode* head = mergedList;
        
        while(pointerA && pointerB){
            ListNode* curr;
            if(pointerA->val < pointerB->val){
                curr = new ListNode(pointerA->val);
                pointerA = pointerA->next;
            }else{
                curr = new ListNode(pointerB->val);
                pointerB = pointerB->next;
            }
            mergedList->next = curr;
            mergedList = mergedList->next;
        }
        
        mergedList->next = (pointerA) ? pointerA : pointerB;
        
        return head->next;
    }
};
