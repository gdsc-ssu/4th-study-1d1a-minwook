#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    long long B;

    cin >> N >> M >> B;

    vector<vector<int>> table(N, vector<int>(M));
    int mintime = 99999999;
    int result = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int h;
            cin >> h;
            table[i][j] = h; 
        }
    }
    
    for(int h=0; h<=256; h++){
        int remove = 0;
        int stack = 0;
        for(int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (table[i][j] == h){
                    continue;
                }
                else if (table[i][j] > h){
                    remove += (table[i][j]-h);
                }
                else{
                    stack += (h-table[i][j]);
                }
            }
        }
        if (remove + B >= stack){
            int time = remove*2 + stack;
            if (mintime >= time){
                mintime = time;
                result = h;
            }
        }
    }

    cout << mintime << ' ' << result << "\n";

    return 0;
}