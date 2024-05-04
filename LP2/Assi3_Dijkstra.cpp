#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){

    /* 
    Here adj[i] contains vectors of size 2, where the first integer in that vector denotes 
    the end of the edge and the second integer denotes the edge weight.

    Each element in pq is (weight, node)
    */

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> ans(V, INT_MAX);
    
    ans[S] = 0;
    pq.push({0, S});
    
    while(!pq.empty()){
        int currNode = pq.top().second;
        int currNodeMinDist = pq.top().first;
        pq.pop();
        for(auto edge: adj[currNode]){
            int node = edge[0];
            int newDist = currNodeMinDist + edge[1];
            if(newDist<ans[node]){
                ans[node] = newDist;
                pq.push({newDist, node});
            }
        }
    }
    
    return ans;
}