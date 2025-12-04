#include<bits/stdc++.h>
using namespace std;

//undirected DFS (Parent-Check)

bool DFS_Check( int node , int parent , vector<vector<int>>&adj , vector<int>&visited){
    visited[node] = true;

    for( int nbr : adj[node]){
        if(!visited[nbr]){
            //Go Deeper 
            if( DFS_Check( nbr , node , adj , visited)){
                return true; //if Deeper found cycle , return true
            }
        }  else if(nbr != parent){
            return true; // visited and not parent -> Cycle found (Back - Edge)
        }
    }

    return false;
}


bool hasCycle(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int> visited(n , 0);

    for( int i=0 ; i<n ; i++){
        if(!visited[i]){
            if(DFS_Check(i , -1 , adj , visited)){
                return true;
            }
    }
}

    return false;
}

int main(){

    int n = 5;
    int e = 5;

    vector<vector<int>>adj(n);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[2].push_back(0);

   cout<<"The Graph Has Cycle : "<<( hasCycle(adj) ? "Yes" : "No")<<endl;

    return 0;

}
