/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *now, *tail, *head;

        now = root;
        head = tail = NULL;
        while(now){
            if (now->left){
                if (tail){
                   tail->next = now->left; 
                   tail = tail->next;
                }else{
                   head = tail = now->left; 
                } 
            }
              
            if (now->right){
                if (tail){
                   tail->next = now->right;
                   tail = tail->next; 
                }else{
                   head = tail = now->right; 
                } 
            }
            
            now = now->next;
                
            if(!now)
            {
                now = head;
                head = tail = NULL;
            }
        }
      return root;  
    }    
};
