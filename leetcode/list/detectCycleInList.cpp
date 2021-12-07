/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        ListNode* entryPointer = head;
        
        while(true){
            if(fastPointer->next == NULL){
                return NULL;
            }
            if(slowPointer->next == NULL || slowPointer->next->next == NULL){
                return NULL;
            }
            
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next->next;
            
            if(slowPointer == fastPointer){
                while(slowPointer != entryPointer){
                    slowPointer = slowPointer->next;
                    entryPointer = entryPointer->next;
                }
                return entryPointer;
            }
        }
        
       return NULL;
    }
};
