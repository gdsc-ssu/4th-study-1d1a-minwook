#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

void bfs(vector<int>* graph, vector<int >& visited, int v){
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++){
            int w = graph[u][i];
            if(visited[w] == 0){
                visited[w] = 1;
                q.push(w);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> graph[N];
    vector<vector<int> > result(N, vector<int>(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int num;
            cin >> num;
            if(num == 1){
                graph[i].push_back(j);
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     cout << "graph[i]: " << ' ';
    //     for(int j=0; j<graph[i].size(); j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i=0; i<N; i++){
        vector<int> visited(N,0);
        bfs(graph, visited, i);
        for(int j=0; j<N; j++){
            if(visited[j] == 1){
                result[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}