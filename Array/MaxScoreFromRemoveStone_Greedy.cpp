#include<bits/stdc++.h>
using namespace std;

int maxScore(int a , int b , int c){
    int mx = max({a , b , c});
    int sum = a + b + c;

    if( mx > sum-mx)return sum-mx;

    return sum/2;
}

int main(){
    int A = 10 , B = 4 , C= 6;
    cout<<"Maximum Score to remove Stone : "<<maxScore(A , B , C)<<endl;
    return 0;
}