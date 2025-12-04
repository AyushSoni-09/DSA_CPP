#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&adj , int start , int n  ){

    vector<bool>visited(n, false );
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout<<"Traversing Graph in BSF: "<<endl;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        
        for( int nbr : adj[node]){
            if(!visited[nbr]){
                visited[nbr] = true ;
                q.push(nbr);
            }
        }
    }
    cout<<endl;
}

int main(){

    int n = 5 ; // no. of nodes in graph 

    vector<vector<int>>adj(n);

    adj[0]={1,2};
    adj[1]={0,3};
    adj[2]={0,4};
    adj[3]={1};
    adj[4]={2};

    BFS(adj , 0 , n );

    return 0;
}