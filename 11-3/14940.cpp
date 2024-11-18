#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(vector<vector<int> >& mapp, vector<vector<int> >& result, vector<vector<int> >& visited, int y, int x){
    queue<pair<int,int> > q;
    visited[y][x] = 1;
    q.push(make_pair(y,x));
    
    while(!q.empty()){
        int uy = q.front().first;
        int ux = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ddy = dy[i] + uy;
            int ddx = dx[i] + ux;
            if (ddy<0 || ddx<0 || ddy>=n || ddx>=m || mapp[ddy][ddx] == 0)
                continue;
            else{
                if(visited[ddy][ddx] == 0){
                    result[ddy][ddx] = result[uy][ux] + 1 ;
                    q.push(make_pair(ddy,ddx));
                    visited[ddy][ddx] = 1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<int> > mapp(n,vector<int>(m));
    vector<vector<int> > result(n,vector<int>(m));
    vector<vector<int> > visited(n,vector<int>(m));


    int desty=0, destx=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num;
            cin >> num;
            mapp[i][j] = num;
            result[i][j] = 0;
            visited[i][j] = 0;
            if (num == 2){
                desty=i;
                destx=j;
            }   
        }
    }

    bfs(mapp, result, visited, desty, destx);


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mapp[i][j]!=0 && visited[i][j] == 0){
                result[i][j] = -1;
            }
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}