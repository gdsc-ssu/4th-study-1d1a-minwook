#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

void dfs(vector<vector<int> >& graph, vector<vector<int> >& visited, int y, int x, int& count){
    count ++;
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int ddy = y + dy[i];
        int ddx = x + dx[i];
        if(ddy<0 || ddx<0 || ddy>=N || ddx>=N || graph[ddy][ddx] == 0){
            continue;
        }
        else{
            if(visited[ddy][ddx] == 0){
                visited[ddy][ddx] = 1;
                dfs(graph, visited, ddy, ddx, count);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin.ignore();

    vector<vector<int> > graph(N, vector<int>(N));
    vector<vector<int> > visited(N, vector<int>(N));

    for(int i=0;i<N;i++){
        string str;
        getline(cin, str);
        for(int j=0; j<N; j++){
            int num = str[j] - '0';
            graph[i][j] = num;
            if(num == 0){
                visited[i][j] = 1;
            }
        }
    }

    vector<int> result;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                int count = 0;
                dfs(graph, visited, i, j, count);
                result.push_back(count);
            }
        }
    }
    
    sort(result.begin(),result.end());

    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }

    return 0;
}