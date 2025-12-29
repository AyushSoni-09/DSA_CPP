#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>&money){
    int n = money.size();
    if(n==0)return 0;
    if(n==1)return money[0];

    vector<int>dp(n);

    dp[0]=money[0];
    dp[1]=max(money[0] , money[1]);

    for( int i=2 ; i<money.size() ; i++){
        dp[i]=max(dp[i-1],money[i]+dp[i-2]);
    }
    return dp[n-1];

}

int main(){
    vector<int>money={2,7,9,3,1}; // o/p =12
    cout<<"Maximum money robbed from houses : "<<rob(money)<<endl;
}