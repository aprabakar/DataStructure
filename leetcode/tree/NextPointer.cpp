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

// My Approach
class Solution {
public:
    void connectUtil(Node* leftNode , Node* rightNode)
    {
        if(!leftNode && !rightNode){
            return;
        }
        
        if(!leftNode){
            return;
        }
        
        //cout<<"leftNode val = "<<leftNode->val<<endl;
        leftNode->next = rightNode;
        
        connectUtil(leftNode->left, leftNode->right);
        
        if(rightNode){
            //cout<<"rightNode val = "<<rightNode->val<<endl;
            connectUtil(leftNode->right, rightNode->left);
            connectUtil(rightNode->left, rightNode->right);
            connectUtil(rightNode->right, NULL);
        }
        
        return;
            
    }
    Node* connect(Node* root) {
        connectUtil(root,NULL);
        return root;
    }
};

//Much Simpler
class Solution {
public:
    Node* connectUtil(Node* root) {
        //Initialize pointers
        if(root == NULL) return NULL;
        //connects the left subtree of same level with right subtree of that same level 
        if(root->left != NULL) root->left->next = root->right;
        //connect the rightmost node of a level to the leftmost node of the next level.
        if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;
        //recursive calls for left and right subtrees.
        connectUtil(root->left);
        connectUtil(root->right);
        return root;
    }
    Node* connect(Node* root) {
        return connectUtil(root);
    }
};
