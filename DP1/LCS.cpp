#include<bits/stdc++.h>
using namespace std;


//without DP ( Normal Recursive Solution)
int LCS( string s1 , string s2 , int m , int n ){
    if( n == 0 || m == 0)return 0 ;
    if( s1[m-1] == s2[n-1]){
        return 1+LCS(s1 , s2 , m-1 , n-1);
    }
    else{
        return max( LCS(s1 , s2 , m-1 ,n), LCS(s1 , s2 , m , n-1));
    }
}

//DP(?Memoization)

int LCSMemo(string s1 , string s2 , int n , int m , vector<vector<int>>& memo){
   

    if( memo[n][m] != -1) return memo[n][m];
    


    if(m == 0 || n == 0){
      return   memo[n][m] = 0 ;
    }
    else{
        if(s1[n-1] == s2[m-1]){
            memo[n][m] = 1 + LCSMemo(s1 , s2 ,n-1 , m-1 , memo);
        }
        else{
        memo[n][m] = max( LCSMemo(s1 , s2 ,n-1 ,  m, memo) , LCSMemo(s1 , s2 , n , m-1 , memo));
    }
}
    return memo[n][m];
}

//DP2 (Tabulation)
int LCSTebu(string s1 , string s2 ){
    int n = s1.size();
    int m = s2.size();
 
    vector<vector<int>> dp(n+1 , vector<int>(m+1));

    for(int i = 0 ; i<=n ; i++){
        dp[i][0] = 0;
    }

    for( int i = 0 ; i<=m ; i++){
        dp[0][i] = 0;
    }
    for( int i = 1 ; i<=n ; i++){
        for( int j = 1 ; j<=m ; j++){
            if( s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "abcds";
    string s2 = "acocbdsdd";

    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> memo(n+1, vector<int>(m+1 , -1));

    int subsequence = LCS(s1 , s2 , n , m);
    int subsequenceMemo = LCSMemo( s1 , s2 , n, m , memo); 
    int subsequenceTebu = LCSTebu(s1 , s2 );
    cout<<" Longest Common Subsequence : "<<subsequence<<endl;
    cout<<"Longest Common  Subsequence DP Memo: "<<subsequenceMemo<<endl;
    cout<<"Longest Common Subsequence DP Tebu : "<<subsequenceTebu<<endl;
    return 0;
}