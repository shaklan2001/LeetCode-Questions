class Solution {
private:    
  vector<int> prevNearestSmaller(vector<int>&arr, int &n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]>=arr[i])s.pop();
            
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
        
    }
     vector<int> nextNearestSmaller(vector<int>&arr, int &n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i])s.pop();
            
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
        
    }

    int MAH(vector<int>& arr) {
        int n = arr.size();
        vector<int>prev(n);
        prev = prevNearestSmaller(arr,n);
        
        vector<int>next(n);
        next=nextNearestSmaller(arr,n);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l =arr[i];
            
            if(next[i]==-1)next[i]=n;
            int b = next[i]-prev[i]-1;
            area = max(area,l*b);
        }
        return area; 
    }
    
public:   
   int maximalRectangle(vector<vector<char>>& v) {
        
        vector<int> l(v[0].size(), 0);
        int mx = 0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]=='0')
                   l[j]=0;
                else
                {
                    l[j]=l[j]+1;
                }
            }
            mx=max(mx,MAH(l));
        }
         return mx;  
    }
};