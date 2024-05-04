/*
Spanning tree is a tree in which we have N nodes and N-1 edges and all the nodes
are reachable from each other. A graph may have multiple spanning trees.

Minimum spanning tree is a spanning tree which has minimum sum of weights. There
may be multiple mst.
*/

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){   
    
    /* 
    Here adj[i] contains vectors of size 2, where the first integer in that vector denotes 
    the end of the edge and the second integer denotes the edge weight.

    Each element in pq is (weight, node, parent)
    */

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> visited(V, false);
    vector<vector<int>> mst;
    int sum = 0;

    pq.push({0, {0, -1}});
    while (!pq.empty()){
        int currWeight = pq.top().first;
        int currNode = pq.top().second.first;
        int currParent = pq.top().second.second;
        pq.pop();
        if (!visited[currNode]){
            visited[currNode] = true;
            sum += currWeight;
            mst.push_back({currParent, currNode});
            for (auto node : adj[currNode]){
                int adjNode = node[0];
                int adjWt = node[1];
                int adjParent = currNode;
                if (!visited[adjNode]){
                    pq.push({adjWt, {adjNode, adjParent}});
                }
            }
        }
    }

    for (auto edge : mst){
        cout<<edge[0]<<"-"<<edge[1]<<endl;
    }

    return sum;
}