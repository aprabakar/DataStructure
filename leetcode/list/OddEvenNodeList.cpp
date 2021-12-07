class Solution {
public:
 ListNode* oddEvenList(ListNode* head) {
        
   if(!head || !head->next || !head->next->next) return head;

    ListNode* oddNode = head;
    ListNode* evenNode = head->next;
    ListNode* startEvenNode = head->next;
        

    while(oddNode->next && evenNode->next){
        
        oddNode->next = evenNode->next;
        evenNode->next = oddNode->next->next;
     	
     	oddNode = oddNode->next;
        evenNode = evenNode->next;
    }

        
    oddNode->next = startEvenNode;

    return head;
    }
};
