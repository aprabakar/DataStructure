struct Node{
  int key;
  int val;
  Node() : key(-1), val(-1){};  
  Node(int x, int y) : key(x),val(y){};
};
class MyHashMap {
public:
    vector<Node*> hashTable;
    MyHashMap() :  hashTable(1000001){};
    
    int getHashKey(int key){
        return (key % 1000001);
    }
    
    void put(int key, int value) {
        int hashKey = getHashKey(key);
        hashTable[hashKey] = new Node(key,value);
    }
    
    int get(int key) {
        int hashKey = getHashKey(key);
        return (hashTable[hashKey] != NULL && hashTable[hashKey]->key != -1) ? 
                hashTable[hashKey]->val : -1;
    }
    
    void remove(int key) {
        int hashKey = getHashKey(key);
        if(hashTable[hashKey] != NULL){
            hashTable[hashKey]->key = -1;
            hashTable[hashKey]->val = -1;
        } 
    }
};
