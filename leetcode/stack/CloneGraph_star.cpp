/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> visitedMap;
    void dfs(Node* node){
        for(int i=0 ; i< node->neighbors.size(); i++){
            if(visitedMap.find(node->neighbors[i]) == visitedMap.end()){
                Node* copyNodeNew = new Node(node->neighbors[i]->val);
                visitedMap[node->neighbors[i]] = copyNodeNew;
                dfs(node->neighbors[i]);
                Node* parent = visitedMap[node];
                parent->neighbors.push_back(copyNodeNew);
            }else{
                Node* parent = visitedMap[node];
                Node* child = visitedMap[node->neighbors[i]];
                parent->neighbors.push_back(child);
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        Node* copyNodeNew = new Node(node->val);
        Node* copyNode = new Node();
        visitedMap[node] = copyNodeNew;
        copyNode = copyNodeNew;
        dfs(node);
        return copyNode;
    }
};
