/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenHelper(Node* head){
        //cout<<"head->val " << head->val <<endl;
        if(head->next == NULL){
            if(head->child != NULL){
                //cout<<"with child"<<endl;
                head->next = head->child;
                head->next->prev = head;
                Node* newNext = flattenHelper(head->next);
                head->child = NULL;
                return newNext;
            }
            //cout<<"without child"<<endl;
            return head;
        }
        
        if(head->child !=NULL){
            //cout<<"with child node"<<endl;
            Node* currNext = head->next;
            head->next = head->child;
            head->next->prev = head;
            Node* newNext = flattenHelper(head->next);
            head->child = NULL;
            if(newNext != currNext){
                newNext->next = currNext;
                currNext->prev = newNext;
            }
            return flattenHelper(currNext);
        }    
        //cout<<"without child node"<<endl;
        return flattenHelper(head->next);
        
    }
    Node* flatten(Node* head) {
        Node* curr = head;
        if(head == NULL){
            return head;
        }
        flattenHelper(curr);   
        return head;
    }
};
