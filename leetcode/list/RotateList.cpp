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
    ListNode* rotateRight(ListNode* head, int k) {
        
         if(head == NULL){
            return head; 
         } 
        
        int size = 0, count = 0;
        ListNode* curr = head;
        ListNode* lastNode = NULL;

        while (curr != NULL){
            if(curr->next == NULL){
                lastNode = curr;
            }
            size +=1;
            curr = curr->next;
        }
        
        k = k % size;
        
        //No rotation
        if(k == 0){
           return head;
        }
            
        k = size - k;
        curr = head;
    
        while (count < k-1){
            count += 1;
            curr = curr->next;
        }
        
        ListNode* newStartNode = curr->next;
        curr->next = NULL;
        lastNode->next = head;
        head = newStartNode;
        return head;
        
    }
};
