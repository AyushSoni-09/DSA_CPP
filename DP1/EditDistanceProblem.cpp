#include<bits/stdc++.h>
using namespace std;
//Recusive method
int EditDistance(string s1 , string s2 , int m , int n ){

    if( m==0 ) return m;
    if( n==0 )return n;

    if( s1[m-1] == s2[n-1]){
       return  EditDistance(s1 , s2 , m-1 , n-1); //if the last is same the skip it and continue 
    }

    return 1 + min(
       { EditDistance(s1 , s2 , m , n-1), //Insert
        EditDistance(s1 , s2 , m-1 , n), //Replace
        EditDistance(s1 , s2 , m-1 , n-1),//Delete
       }
    );

}

//Memoization Method

int EditMemo(string s1 , string s2 , int m ,int n , vector<vector<int>> &dp){

    if(m==0)return m;
    if(n==0)return n;

    if(dp[m][n] != -1) return dp[m][n];

    if(s1[m-1] == s2[n-1]){
        return EditMemo(s1 , s2 , m-1 , n-1 , dp);
    }
    else{
        return 1+ min({
            EditMemo(s1 ,s2 , m , n-1 , dp),//insert
            EditMemo(s1 , s2 , m-1 , n , dp),//delete
            EditMemo(s1 ,s2 , m-1 , n-1 , dp)//replace
        });
    }
}


//Tabulation method
int EditTabu(string s1 , string s2 ){
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>>dp(m+1 , vector<int>(n+1));

    for( int i=0 ; i<=m ; i++){
        dp[i][0] = i ; //delete all
    }
    for( int i=0 ; i<=n ; i++){
        dp[0][i] = i; //insert all
    }

    for( int  i=1 ; i<=m ; i++){
        for( int j=1 ; j<=n ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(
                    {
                        dp[i][j-1], //insert 
                        dp[i-1][j], //delete
                        dp[i-1][j-1] //replace
                    }
                );
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1 ="cat";
    string s2 ="cut";
    int m=s1.size();
    int n=s1.size();
    vector<vector<int>>dp(m+1 , vector(n+1 , -1));
    cout<<"Total Changes to make s1 equal to s2 : "<<EditDistance(s1 , s2 , m , n )<<endl;
    cout<<"Total Changes to make s1 equal to s2  using Tabulation(DP): "<<EditTabu(s1 , s2)<<endl;
     cout<<"Total Changes to make s1 equal to s2 using Memoization(DP) : "<<EditMemo(s1 , s2 , m , n , dp )<<endl;
    return 0; 
}