//Find Minimun no. of steps to make two strings Anagram

#include<bits/stdc++.h>
using namespace std;

int minSteps(string s , string t){
    vector<int> a(26 , 0) , b(26 , 0);

    for(char c : s){ a[c-'a']++;}
    for( char c : t ){b[c-'a']++;}
    
    for(int i=0 ; i<26 ; i++){
        if(a[i]>0){
            cout<<a[i]<< " ";
        }
    }
    cout<<endl;

    for(int i=0 ; i<26 ; i++){
        if(b[i]>0){
            cout<<b[i]<< " ";
        }
    }
    cout<<endl;

    int steps = 0 ;

    for( int i = 0 ; i<26 ; i++){
        if(a[i]>b[i]){
            steps += a[i]-b[i];
        }
    }
    return steps;
}

int main(){
    string s="aabbcc";
    string t="abccdd";

    cout<<"Mini Steps to make Anagram : "<<minSteps(s , t)<<endl;
}