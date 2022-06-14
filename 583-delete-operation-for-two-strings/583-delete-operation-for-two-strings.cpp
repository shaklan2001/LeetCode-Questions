class Solution {
public:
    int minDistance(string a, string b ){
        vector<vector<int>> t( a.size() + 1, vector<int>( b.size() + 1 , 0 ) ) ;
        for( int i = 1 ; i <= a.size() ; i++ ){
            for( int j = 1 ; j <= b.size() ; j++ ){
                if( a[i-1] == b[j-1] )
                    t[i][j] = 1 + t[i-1][j-1] ;
                else
                    t[i][j] = max( t[i][j-1] , t[i-1][j] );
            }
        }

        return a.size() + b.size() - 2*t[a.size()][b.size()] ;
    }
};