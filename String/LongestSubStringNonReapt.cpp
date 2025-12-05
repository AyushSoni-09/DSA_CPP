// Laongest Substring without repeating character

#include<bits/stdc++.h>
using namespace std;

int LS( string s){
    unordered_map<char , int > mp;
    int left = 0 , len = 0;
    for( int right =0  ; right<s.size() ; right++){
        char c = s[right];
        if( mp.count(c) && mp[c] >= left){
            left = mp[c]+1;
        }
        mp[c]=right;
        len = max( len , right-left+1);
    }
    return len;
    
}

int main(){
    string s="abcabcbb";

    cout<<"Length of longest Substring : "<<LS(s)<<endl;

}