#include <iostream>
#include <queue>
using namespace std;

int arr[101] = {0};
bool visited[101] = {false};
 
void bfs(int n){
    
    queue<pair<int,int> > q;
    q.push(make_pair(n,0));
    visited[n] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == 100){
            cout << cnt << '\n';
            return;
        }
        for(int i=1; i<=6; i++){
            int next = cur + i;
            if(next > 100 ) {
                continue;
            }
            if(next > 100 || visited[next]) continue;
            if(arr[next] != 0) next = arr[next];
            q.push(make_pair(next,cnt+1));
            visited[next] = true;
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N , M;
    cin >> N >> M;
    for(int i=0; i<N+M; i++){
         int x, y;
         cin >> x >> y;
         arr[x] = y;
    } 

    bfs(1);

    return 0;
}