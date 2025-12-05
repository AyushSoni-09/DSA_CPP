// Length of Longest substring with at most K Distinct Character 

#include<bits/stdc++.h>
using namespace std;

int LongestDistinct(string s , int k ){
    vector<int> freq(256 , 0);
    int left =0  , distinct = 0 , len =0;
    for( int right=0 ; right<s.size() ; right++){
        if(freq[s[right]]==0) distinct++;

        freq[s[right]]++;

        while(distinct > k ){
            freq[s[left]]--;
            if(freq[s[left]] == 0)distinct--;
            left++;
        }

        len = max(len , right-left +1);
    }
    return len ;
}

int main(){
    string s ="aabacbebebe";
    int k = 3;

    cout<<"Length of SubString with K Distinct Element : "<<LongestDistinct(s , k)<<endl;
}