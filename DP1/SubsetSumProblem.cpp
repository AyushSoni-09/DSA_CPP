#include<bits/stdc++.h>
using namespace std;
//Recursive Approach
bool subset(vector<int>&arr , int n , int sum){
    if( sum == 0) return true ; // we made the sum 
    if( n == 0 ) return false ; // no element left 

    if( arr[n-1]> sum ){
        return subset( arr , n-1 , sum); // exclude (not inlcude the element for sum)
    }
    return subset(arr , n-1 , sum )|| subset(arr , n-1 , sum-arr[n-1]);
}

//Memoization Approach

bool subsetMemo(vector<int>& arr , int n ,int sum , vector<vector<int>>& dp){ 

    if(sum == 0)return true;
    if(n == 0) return false;

    if( dp[n][sum] != -1 ) return dp[n][sum];

    
    if(arr[n-1] > sum )
    return subsetMemo(arr , n-1  , sum , dp);

    return subsetMemo(arr , n-1 , sum , dp) || subsetMemo(arr , n-1 , sum - arr[n-1] , dp);

}

//Tebulation Method 

bool subsetTabu(vector<int>&arr , int n , int sum){

    vector<vector<int>> dp (n+1 , vector<int>(sum+1 , 0));

    for( int i=0 ; i<=n ; i++){
        dp[i][0] = 1;
    }
    for( int i=1 ; i<=n ; i++){
        for( int j =1 ; j<=sum ; j++){
            if( arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}


int main(){
    vector<int> arr ={ 3 , 4 , 5 , 2};
    int n = arr.size();
    int target = 6;
    vector<vector<int>> dp(n+1 , vector<int>( target+1, -1));
    cout<<"Subset sum equal to target present : "<< (subset(arr , n , target ) ? "True": "False" )<<endl;
    cout<<"Subset sum equal to target present Memoixation Method : "<< (subsetMemo(arr , n , target , dp ) ? "True": "False" )<<endl;
    cout<<"Subset sum equal to target present  Tebulation Method : "<< (subsetTabu(arr , n , target ) ? "True": "False" )<<endl;
}