
struct CustomTreeNode {
     int val;
     int count;
     CustomTreeNode *left;
     CustomTreeNode *right;
     CustomTreeNode() : val(0), count(0), left(nullptr), right(nullptr) {}
     CustomTreeNode(int x) : val(x), count(0), left(nullptr), right(nullptr) {}
     CustomTreeNode(int x, int y) : val(x), count(y), left(nullptr), right(nullptr) {}
     CustomTreeNode(int x, CustomTreeNode *left, CustomTreeNode *right) : val(x), left(left), right(right) {}
};

class KthLargest {
public:
    int kVal;
    CustomTreeNode* tree = NULL;
    KthLargest(int k, vector<int>& nums) {
        kVal = k;
        for(int i=0; i< nums.size() ; i++){
            if(i == 0){
                CustomTreeNode* newNode = new CustomTreeNode(nums[i],0);
                tree = newNode;
                continue;
            }
            insert(tree,NULL,nums[i]);
        }
    }
    
    void insert(CustomTreeNode* node,CustomTreeNode* prev,int val){
        if(!node){
            CustomTreeNode* newNode = new CustomTreeNode(val,0);
            if(prev->val >= val){
                prev->left = newNode;
            }else{
                prev->right = newNode;
            }
            return;
        }
        
        if(node->val < val){
            insert(node->right, node, val);
            node->count +=1;
            return;
        }
        
        insert(node->left, node, val);
    }
    
    int findKthLargestVal(CustomTreeNode* node, int val) {
        if(node->count == val-1){
            return node->val;
        }
        
        if(node->count >= val){
            return findKthLargestVal(node->right,val);
        }
        return findKthLargestVal(node->left,val-(node->count+1));
    }
    
    int add(int val) {
        if(!tree){
            CustomTreeNode* newNode = new CustomTreeNode(val,0);
            tree = newNode;
        }else{
            insert(tree,NULL,val);  
        }
        return findKthLargestVal(tree,kVal);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
