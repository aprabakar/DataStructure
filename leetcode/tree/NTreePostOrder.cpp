//Recursive
class Solution {
public:
    vector<int> result;
    void postorderUtil(Node* node){
        if(!node){
            return;
        }
        for(int i= 0 ; i< node->children.size();i++){
            postorderUtil(node->children[i]);
        }
        result.push_back(node->val);
        return;
        
    }
    vector<int> postorder(Node* root) {
        postorderUtil(root);
        return result;
    }
};

//Iterative
class Solution {
public:
    
    vector<int> postorder(Node* root) {
        vector<int> result;
        stack<Node*> st;
        
        if(!root){
            return result;
        }
        
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            for(int i= 0; i < curr->children.size(); i++){
                st.push(curr->children[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
