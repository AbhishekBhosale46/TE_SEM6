#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    int size;
    vector<int> *adjList;

    Graph(int size){
        this->size = size;
        adjList = new vector<int>[size];
    }

    void addEdge(int v1, int v2){
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    
    void printGraph(){
        for(int i=0; i<size; i++){
            cout<<i<<":";
            for(auto j: adjList[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(){
        queue<int> q;
        q.push(0);
        vector<int> visited(this->size, 0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node]==0){
                cout<<node<<" ";
                visited[node]=1;
                for(auto i: adjList[node]){
                    q.push(i);
                }
            }
        }
    }

    void DFS(int node, vector<int> &visited, vector<int> &result){
        result.push_back(node);
        visited[node] = 1;
        for(auto i: adjList[node]){
            if(visited[i]==0){
                DFS(i, visited, result);
            }
        }
    }

    void DFSHelper(){
        vector<int> result;
        vector<int> visited(this->size, 0);
        DFS(0, visited, result);
        for(auto i: result){
            cout<<i<<" ";
        }
    }

};

int main(){
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);
    graph.printGraph();
    cout<<endl;
    graph.DFSHelper();
    return 0;
}