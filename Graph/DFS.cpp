#include<bits/stdc++.h>
using namespace std;

void DFS(int node , vector<vector<int>>&adj , vector<bool>&visited){

    cout<<node<<" ";
    visited[node] = true;

    for( int nbr : adj[node]){
        if(!visited[nbr]){
            DFS(nbr , adj , visited);
        }
    }
}

int main(){

    int n = 5;
    vector<vector<int>>adj(n);

    adj[0]={1,2};
    adj[1]={0,3};
    adj[2]={0,4};
    adj[3]={1};
    adj[4]={2};

    vector<bool> visited(n,false);
    cout<<"Trversing Graph DFS : "<<endl;
    DFS(0 , adj , visited);
    cout<<endl;
    return 0;

}