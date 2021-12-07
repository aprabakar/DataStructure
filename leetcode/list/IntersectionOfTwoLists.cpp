class Solution {
public:


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode* pointerA = headA;
    ListNode* pointerB = headB;

    ListNode* res = NULL;
    while(pointerA != NULL || pointerB !=NULL){
        
       if(pointerA == pointerB){
           res = pointerA;
           break;
       }
       
       if(pointerA == NULL){
         pointerA = headB;
       }else{
         pointerA = pointerA->next;
       }

       if(pointerB == NULL){
          pointerB = headA;
       }else{
		  pointerB = pointerB->next;
       }
    }

    return res;
    }
};
