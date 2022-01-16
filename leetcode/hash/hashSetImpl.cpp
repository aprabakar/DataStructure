struct Node{
  int val;
  Node() : val(-1){};  
  Node(int x) : val(x){};
};
class MyHashSet {
public:
    vector<Node*> hashTable;
    MyHashSet() :  hashTable(1000001){};
    
    int getHashKey(int key){
        return (key % 1000001);
    }
    void add(int key) {
        int hashKey = getHashKey(key);
        hashTable[hashKey] = new Node(key);
    }
    
    void remove(int key) {
        int hashKey = getHashKey(key);
        if(hashTable[hashKey] != NULL){
            hashTable[hashKey]->val = -1;
        }
    }
    
    bool contains(int key) {
        int hashKey = getHashKey(key);
        return (hashTable[hashKey] != NULL && hashTable[hashKey]->val != -1) ? true : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
