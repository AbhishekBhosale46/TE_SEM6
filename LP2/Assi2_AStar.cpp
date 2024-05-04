#include<bits/stdc++.h>
using namespace std;

// Represent the current board state
class Node{

    public:
    vector<vector<int>> board;
    int g;
    int h;
    int f;

    Node(vector<vector<int>> board, int g, int h){
        this->board = board;
        this->g = g;
        this->h = h;
        this->f = g+h;
    }

};

// Get string representation of node
string getString(Node *node){
    string s = "";
    for(auto i: node->board){
        for(auto j:i){
            s += to_string(j);
        }
    }
    return s;
}

// Print the given node
void print(Node *node){
    cout<<endl;
    for(auto i: node->board){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"F="<<node->f<<" G="<<node->g<<" H="<<node->h<<endl;
}

// Get the hueristic of the given node
int getH(vector<vector<int>> node, vector<vector<int>> goal){
    int h = 0;
    for(int i=0; i<node.size(); i++){
        for(int j=0; j<node.size(); j++){
            if(node[i][j] != goal[i][j]){
                h++;
            }
        }
    }
    return h-1;
}

// Get all negihbours of the given node
vector<Node*> getNeighbours(Node *node, vector<vector<int>> goal_board){
    vector<Node*> neighbours;
    int dx[] = {0, 0, -1, 1}; 
    int dy[] = {-1, 1, 0, 0};
    int blankX, blankY;
    for(int i=0; i<node->board.size(); i++){
        for(int j=0; j<node->board.size(); j++){
            if(node->board[i][j]==0){
                blankX = i;
                blankY = j;
                break;
            }
        }
    }
    for(int i=0; i<4; i++){
        int newX = blankX + dx[i];
        int newY = blankY + dy[i];
        if((newX>=0 && newX<3 && newY>=0 && newY<3)){
            vector<vector<int>> new_board = node->board;
            swap(new_board[blankX][blankY], new_board[newX][newY]);
            neighbours.push_back(new Node(new_board, node->g+1, getH(new_board, goal_board)));
        }
    } 
    return neighbours;
}

// Check if given node is goal node
bool isGoal(vector<vector<int>> node, vector<vector<int>> goal){
    return node==goal;
}

// Helper to solve the 8 puzzle problem
void solve(vector<vector<int>> start, vector<vector<int>> goal){

    Node *startNode = new Node(start, 0, getH(start, goal));

    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    map<Node*, bool> visited;

    pq.push({startNode->f, startNode});

    while(!pq.empty()){

        Node *currentNode = pq.top().second;
        pq.pop();

        print(currentNode);

        if(isGoal(currentNode->board, goal)){
            cout<<"Goal state reached, total steps needed : "<<currentNode->g<<endl<<endl;
            return;
        }

        visited[currentNode] = true;

        vector<Node*> neighbours = getNeighbours(currentNode, goal);
        for(auto neighbour: neighbours){
            cout<<getString(neighbour)<<" ";
            cout<<"F="<<neighbour->f<<" G="<<neighbour->g<<" H="<<neighbour->h<<endl;
            if(!visited[neighbour]){
                pq.push({neighbour->f, neighbour});
            }
        }
        cout<<endl<<endl;

    }

    cout<<"No solution exists"<<endl;

}

int main(){

    Node *start = new Node({{1,2,3},{0,4,6},{7,5,8}}, 0, 0);
    Node *goal = new Node({{1,2,3},{4,5,6},{7,8,0}}, 0, 0);

    solve({{1,2,3},{0,4,6},{7,5,8}}, {{1,2,3},{0,4,6},{7,5,8}});

    return 0;
}