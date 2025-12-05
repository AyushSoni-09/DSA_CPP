#include<bits/stdc++.h>

using namespace std;


int LargestSubArraySum(vector<int>arr , int k){
    int prefix=0;
    int maxi=INT_MIN;

    unordered_map<int,int>mp;

    mp[0]=-1;

    for( int i=0 ; i<arr.size() ; i++){
        prefix+=arr[i];
        int remain = prefix-k; //remain sum
        if(mp.find(remain) != mp.end()){ //checking if remianing sub is already exists in Map 
            int idx = mp[remain];
            maxi = max(i-idx , maxi);
        }
        if(mp.find(remain) == mp.end()){ // if not exist then put the remaining in map
            mp[remain]=i;
        }
    }
     return maxi;   
}

int main(){
    vector<int>arr={1,-1,5,-2,3};
    int k = 3;
    cout<<"Largest SubArray Sum Equale to K : "<<LargestSubArraySum(arr , k)<<endl;

}