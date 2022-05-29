/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
ListNode* getMiddle(ListNode* head){
        
    ListNode* fast = head -> next;
    ListNode* slow = head;
    
    while( fast != NULL && fast -> next != NULL){
        
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow; 
}
    
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

public:
    bool isPalindrome(ListNode* head) {
        
        if( head -> next == NULL){
        return true;
        }
        
        //step1-> find middle
        ListNode* mid = getMiddle(head);
        
        //step2 -> reverse list after middle
        ListNode* temp = mid -> next;
        mid -> next = reverse(temp);
        
        //compares both halfs
        ListNode* head1 = head;
        ListNode* head2 = mid -> next;
            
        while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        //step4 -> repeat step2
        temp = mid -> next;
        mid -> next = reverse(temp);
        
        return true;
    }
};