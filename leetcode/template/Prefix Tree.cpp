https://leetcode.com/problems/extra-characters-in-a-string/description/


struct TrieNode{
    bool isEnd;
    TrieNode* links[26];
    TrieNode(){
        isEnd=0;
        fill(links, links+26, (TrieNode*)NULL);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    ~Trie(){//destructor
        delete root; //avoid memory leaks
    }
    
    void insert(string& word) {
        TrieNode* Node=root;
        for(char c: word){
            int i=c-'a';
            if(Node->links[i]==NULL)
                Node->links[i]=new TrieNode();
            Node=Node->links[i];
        }
        Node->isEnd=1;
    }
    void insert(vector<string>& dictionary){
        for(auto& word: dictionary)
            insert(word);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        trie.insert(dictionary);//Insert all words in trie

        int n = s.size();
        vector<int> dp(n+1, 0);//dp[i]=the minimum extra characters needed for s[i:end]
        for (int i=n-1; i>=0; i--) {
            dp[i]=dp[i+1]+1;
            TrieNode* node=trie.root;
            for (int j=i; j<n; j++) {
                if (node->links[s[j]-'a']==NULL) break;//next i--
                node=node->links[s[j]-'a'];
                if(node->isEnd) //A word in dictionary is found
                    dp[i]=min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }
};
