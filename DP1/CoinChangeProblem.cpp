#include<bits/stdc++.h>
using namespace std;
// Normal Recursive Call
int ways( vector<int>& coin ,int n , int amt){
     
    if(amt == 0) return 1;
    if(amt <0) return 0; //Amount negative ho gaya -> invalid.
    if( n == 0) return 0;

    //return ( include , exclude);
    return (ways(coin , n , amt-coin[n-1]) + ways( coin , n-1 , amt));

}


int waysMemo( vector<int> coin , int n , int amt , vector<vector<int>>&dp){

    if(amt == 0) return 1;
    if(amt<0) return 0;
    if(n == 0) return 0;

    if( dp[n][amt] != -1)return dp[n][amt];

    int include = waysMemo(coin , n , amt-coin[n-1] , dp);

    int exclude = waysMemo( coin , n-1 , amt , dp);

    return include+exclude;

}


//Dp Tebo

int waysTebo( vector<int>& coin , int n , int amt){

    vector<vector<int>> dp ( n+1 , vector<int>(amt+1));

    for( int i =0 ; i<=n ; i++){
        dp[i][0] = 1;
    }

    for( int i=0 ; i<=amt ; i++){
        dp[0][i]=0;
    }

    for( int i=1 ; i<=n ; i++){
        for( int j=1 ; j<=amt ; j++){
            int include = 0;
            if( j >= coin[i-1]){
            include = dp[i][j-coin[i-1]];
            }

            int exclude = dp[i-1][j];

            dp[i][j] = include + exclude;
        }
    }
    return dp[n][amt];
}

int main(){
    vector<int>coin={1,2,3};
    int amt = 4;
    int n = coin.size();
    int Ways = ways(coin ,n, amt);
    int WaysTebo = waysTebo( coin , n , amt);
   
       vector<vector<int>> dp ( n+1, (vector<int>(amt+1 ,-1)));
   int WaysMemo = waysMemo(coin , n , amt , dp);
    cout<<"Number of Ways to Coin change to made amount : "<<Ways<<endl;
    cout<<"Number of Ways to coin change to made amout Tebo Method : "<<WaysTebo<<endl;
    cout<<"Number of ways to coin change to made amount Memo Methos : "<<WaysMemo<<endl;
    return 0;
}