class Solution {
public:
    int minAddToMakeValid(string s) {
    
    // //Write your code here
    // if(s.length()%2 == 1){
    //     return -1;
    // }
    
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        
        if(ch == '(')
            st.push(ch);
        else{
            //ch is closed brace
            if( !st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
        
    //stack contains invlaid expression 
        int cnt = 0;
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        
        return cnt;

    }
};