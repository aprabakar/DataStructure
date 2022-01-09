class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        deque<Node*> dq;
        
        if(!root){
            return result;
        }
        
        dq.push_back(root);
        
        while(!dq.empty()){
            int size = dq.size();            
            vector<int> curr_result;
            
            while(size--){
                Node* curr = dq.front();
                dq.pop_front();
                curr_result.push_back(curr->val);
                for(int i=0 ; i<curr->children.size();i++){
                    dq.push_back(curr->children[i]);
                }
            }
            result.push_back(curr_result);
        }
        
        return result; 
    }
};
