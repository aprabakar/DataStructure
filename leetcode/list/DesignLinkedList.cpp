class Node{
  public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        int val = -1;
        if( index >= size || index < 0){
            return val;
        }
        
        Node* temp = head;
        for(int i = 0 ; i < index ; i++){
            temp = temp->next;
        }
        
        return temp->val;
        
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
        
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }
        
        Node* temp = head;
        Node* newNode = new Node(val);
        
        //Insert front
        if(index == 0){
            newNode->next = temp;
            head = newNode;
            size +=1;
            return;
        }
        
        for(int i=0 ; i < index-1 ; i++){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        size +=1;
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        }
        
        Node* temp = head;
        
        //delete front
        if(index == 0){
            Node* newHead = temp->next;
            delete temp;
            head = newHead;
            size -= 1;
            return;
        }
        
        for(int i=0 ; i < index-1 ; i++){
            temp = temp->next;
        }
        
        Node* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
        size -= 1;
        return;
    }
    
    ~MyLinkedList() {
        Node* curr = head;
        
        while(curr != NULL){
            head = head->next;
            delete curr;
            curr = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
