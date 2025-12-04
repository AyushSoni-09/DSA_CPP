#include<bits/stdc++.h>
using namespace std;

int minDeletion(vector<int>&arr){
    int deletion = 0 ; 
    vector<int> res;

    for( int x : arr){
        if( res.size()%2 ==0){
            res.push_back(x);
        }
        else{
            if(res.back() == x){
                deletion++;
            }else{
                res.push_back(x);
            }
        }
    }

    if( res.size()%2 == 1)deletion++;
    return deletion ;
}

//Recursive Approach

int Recursive(vector<int>& arr  , int i , int pos){
    if( i == arr.size()){
        return (pos %2 == 1)? 1:0;
    }
    int take = 1e9;

    if((pos%2 == 0) || arr[i]!=arr[i-1]){
        take = Recursive(arr , i+1 ,pos+1);
    }
    int del = 1 + Recursive(arr , i+1 , pos);

    return min(take , del);
}

int main(){
    vector<int> arr = {1,1,2,1,1,2};
    
    cout<<"Mini Deletion to make Array Beautiful : "<<minDeletion(arr)<<endl;
    cout<<"Mini Deletion to make Array Beautiful (Recursion): "<<Recursive(arr , 0 , 0)<<endl;
    
    return 0;
}