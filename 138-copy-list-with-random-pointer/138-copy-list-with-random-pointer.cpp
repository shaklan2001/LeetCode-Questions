 
class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        
        //step1 -> create a clone list 
        Node* cloneHead = NULL;
        Node* colneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, colneTail, temp -> val);
            temp = temp -> next;
        }
        
        //step2 -> create a map
        unordered_map<Node* , Node*> oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode -> random = oldToNew[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
    }
};