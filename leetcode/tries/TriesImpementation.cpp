struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> children = {};
};
class Trie {
public:
    TrieNode* trieRoot;
    Trie() {
        trieRoot = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* trieNode = trieRoot;
        for (char ch : word) {
            if (!trieNode->children.count(ch)) {
                trieNode->children[ch] = new TrieNode(); 
            }
            trieNode = trieNode->children[ch];
        }
        trieNode->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* trieNode = trieRoot;
        for (char ch : word) {
            if (!trieNode->children.count(ch)) {
                return false; 
            }
            trieNode = trieNode->children[ch];
        }
        return trieNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* trieNode = trieRoot;
        for (char ch : prefix) {
            if (!trieNode->children.count(ch)) { 
                return false; 
            }
            trieNode = trieNode->children[ch];
        }
        return true;
    }
};
