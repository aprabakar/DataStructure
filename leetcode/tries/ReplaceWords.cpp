struct TrieNode{
   bool isEnd = false;
   unordered_map<char,TrieNode*> children = {};
};
class Solution {
public:
    void formTrieStructure(TrieNode* trieRoot, vector<string>& dictionary){
        for (int i= 0 ; i< dictionary.size() ; i++){
            TrieNode* trieNode = trieRoot;
            for (char ch : dictionary[i]){
                if(!trieNode->children.count(ch)){
                    trieNode->children[ch] = new TrieNode();
                }
                
                trieNode = trieNode->children[ch];
            }
            trieNode->isEnd = true;
        }
        
        return;
    }
    
    string replaceWord(TrieNode* trieNode, string word){
        string result = "";
        for(char ch : word){
            if(!trieNode->children.count(ch)){
                return "";
            }
            
            if(trieNode->children.count(ch) && trieNode->children[ch]->isEnd){
                result += ch;
                return result;
            }else{
                result += ch;
            }
            trieNode = trieNode->children[ch];
        }
        return (trieNode->isEnd) ? result : "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* trieRoot = new TrieNode();
        formTrieStructure(trieRoot,dictionary);
        stringstream sentenceList(sentence);
        string word;
        string final_result = "";
        
        while (sentenceList >> word) {
            string replace_word = replaceWord(trieRoot,word);
            replace_word = (replace_word != "") ? replace_word : word;
            final_result += replace_word +" ";
        }        
        return final_result.substr(0,final_result.length()-1);
    }
};
