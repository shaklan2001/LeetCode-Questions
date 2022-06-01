class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string, int>pq;
        if(s.size()==1 || s.size()<=k)
            return false;
        for(int i=0; i<=s.size()-k; i++)
            pq[s.substr(i, k)]++;
        return pq.size() == pow(2, k);
    
    }
};