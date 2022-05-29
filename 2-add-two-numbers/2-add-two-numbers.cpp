
class Solution {
private:
ListNode* reverse(ListNode* head){
    
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;
    
    while( curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            
        }
        
        return prev;
}
    
void insertAtTail(ListNode* &head, ListNode* &tail, int d) {
     
    ListNode* temp = new ListNode(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
        
    }else{
        tail -> next = temp;
        tail  = temp;
    }
    
}
    
ListNode* add(ListNode* first, ListNode* second){
    int carry = 0;
    
    ListNode* ansHead = NULL;
    ListNode* ansTail = NULL;
    
    while(first != NULL && second != NULL){
        
        int sum = carry + first -> val + second -> val;
        int digit = sum%10;
        
        //create Node and add in answer LL
        insertAtTail(ansHead, ansTail, digit);
        
        carry = sum/10;
        
        first = first -> next;
        second = second -> next;
        
    }
    
    while(first != NULL){
        int sum = carry + first -> val;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first -> next;
    }
        
    while(second != NULL){
        int sum = carry  + second -> val;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        second = second -> next;
    }
    
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }
    
    return ansHead;
}
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = add(l1, l2);
        return ans;
        
    }
};