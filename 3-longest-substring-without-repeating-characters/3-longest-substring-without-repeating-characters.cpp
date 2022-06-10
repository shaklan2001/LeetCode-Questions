class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n=s.size();
        int st=0,ml=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) != mp.end()){
                st = max(st,mp[s[i]]+1);
            }
            mp[s[i]] = i;
            ml = max(ml,i-st+1);
        }
        return ml;
    }
};