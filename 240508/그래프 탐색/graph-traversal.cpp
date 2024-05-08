#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
int N, M, count;
bool isVisited[1001];

void DFS(int vertex){
    for(int i=0; i<graph[vertex].size(); i++){
        int current_v = graph[vertex][i];
        if(!isVisited[current_v]){
            count++;
            isVisited[current_v] = true;
            DFS(current_v);
        }
    }
}

int main() {
    int x, y;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    isVisited[1] = true;
    DFS(1);

    cout<<count<<'\n';
    return 0;
}