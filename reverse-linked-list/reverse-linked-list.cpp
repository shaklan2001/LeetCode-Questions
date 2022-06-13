class Solution {
void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
    
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }
    
    ListNode* forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;

}
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head, curr, prev);
        return head;
        
        
        /* if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while( curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            
        }
        
        return prev;*/
    }
};