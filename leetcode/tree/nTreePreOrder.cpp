//Recursive
class Solution {
public:
    vector<int> result;
    void preorderUtil(Node* node){
        if(!node){
            return;
        }
        result.push_back(node->val);
        for(int i= 0 ; i< node->children.size();i++){
            preorderUtil(node->children[i]);
        }
        return;
        
    }
    vector<int> preorder(Node* root) {
        preorderUtil(root);
        return result;
    }
};

//Iterative
class Solution {
public:
    
    vector<int> preorder(Node* root) {
        vector<int> result;
        deque<Node*> qu;
        
        if(!root){
            return result;
        }
        
        qu.push_front(root);
        while(!qu.empty()){
            Node* curr = qu.front();
            qu.pop_front();
            result.push_back(curr->val);
            for(int i= curr->children.size()-1; i >= 0 ; i--){
                qu.push_front(curr->children[i]);
            }
        }
        return result;
    }
};
