/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return head;
        
        Node* curr = head;

        //Copy node side by side
        // Ex : for 1->2->3 = 1->1'->2->2'->3->3'
        while(curr != NULL){
            Node* copyNode = new Node(curr->val);
            Node* temp = curr->next;
            curr->next = copyNode;
            copyNode->next = temp;
            curr = temp;
        } 
        
        curr = head;
        
        //Copy Random Pointer
        while(curr != NULL){
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        curr = head;
        Node* copyNodeHead = new Node(-1);
        Node* copyCurr = copyNodeHead;
        
        //Split copy and original node list
        while(curr != NULL){
            Node* copyNode = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            copyCurr->next = copyNode;
            copyCurr = copyCurr->next;
        }
        
        return copyNodeHead->next;
        
    }
};
