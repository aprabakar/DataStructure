// leet -> https://leetcode.com/explore/learn/card/trie/148/practical-application-i/1058/

struct TrieNode {
    int val = 0;
    unordered_map<char, TrieNode*> children = {};
    TrieNode() : val(0) {};
    TrieNode(int x) : val(x) {};
};
class MapSum {
public:
    TrieNode* trieRoot;
    unordered_map<string,int> keyMap = {};
    MapSum() {
        trieRoot = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* trieNode = trieRoot;
        //Replace scenario
        if(keyMap.count(key)){
            int old_val = keyMap[key];
            keyMap[key] = val;
            for (char ch : key) {
                trieNode->children[ch]->val -= old_val;
                trieNode->children[ch]->val += val;
                trieNode = trieNode->children[ch];
            }
        }
        else{
            // add/append scenario
            keyMap[key] = val;
            for (char ch : key) {
                if (!trieNode->children.count(ch)) {
                    trieNode->children[ch] = new TrieNode(val); 
                }else{
                    trieNode->children[ch]->val += val;
                }
                trieNode = trieNode->children[ch];
            }
        }
        return;
    }
    
    int sum(string prefix) {
       TrieNode* trieNode = trieRoot;
       int total = 0;
       for (char ch : prefix) {
            if (!trieNode->children.count(ch)) {
                total = 0;
                break;
            }
            total = trieNode->children[ch]->val;
            trieNode = trieNode->children[ch];            
       }
       return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
