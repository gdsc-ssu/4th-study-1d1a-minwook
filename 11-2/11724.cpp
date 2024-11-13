#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(vector<bool>& visited, vector<int> graph[], int v){
    visited[v] = true;

    for (int w=0; w<graph[v].size(); w++){
        int y = graph[v][w];
        if (!visited[y]){
            dfs(visited, graph, y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> graph[N+1];
    vector<bool> visited(N+1, false);
    visited[0] = true;

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count = 0;

    for(int i=1; i<=N; i++){
        if (visited[i] == false){
            count++;
            dfs(visited, graph, i);
        }
    }
    cout << count << '\n';

    return 0;
}