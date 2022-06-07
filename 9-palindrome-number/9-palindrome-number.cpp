class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
    
        long long int temp=x;
        long long int rev =0;
        while( x != 0){
            long long int num = x%10;
            rev = rev*10 + num;
            x = x/10;
        }
        
        if(rev == temp){
            return true;
        }
        else{
            return false;
        }
    }
};