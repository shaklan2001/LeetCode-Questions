 
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
        
        //step2 -> cloneNode add in between riginal Node
        Node* originalNode = head;
        Node * cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        // step3 -> copy random pointer
        temp = head;
        
        while( temp != NULL){
            if( temp -> next != NULL){
                
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
                
                // if(temp -> random != NULL){
                //     temp -> next -> random = temp -> random -> next;
                // }
                // else{
                //     temp -> next = temp -> random;
                // } 
            }
            
            temp = temp -> next -> next;
        }
        
        //step4 -> revert changes done in step2
        originalNode = head;
        cloneNode = cloneHead;
        
         while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
             if(originalNode != NULL){
                 cloneNode -> next = originalNode -> next;
             }
             cloneNode = cloneNode -> next;
        }
        
        //step5 -> return ans
        return cloneHead;
        
    }
};