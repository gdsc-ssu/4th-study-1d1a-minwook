#include <iostream>
#include <vector>
using namespace std;

int N;
int blue, white = 0;

void dnq(vector<vector<int> > arr, int y, int x, int size){
    int count = 0;

    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(arr[i][j] == 0){
                continue;
            }
            else{
                count += 1;
            }
        }
    }

    if(count == 0){
        white ++;
    }
    else if (count == size*size){
        blue ++;
    }
    else{
        dnq(arr, y, x, size/2);
        dnq(arr, y, x+size/2, size/2);
        dnq(arr, y+size/2, x, size/2);
        dnq(arr, y+size/2, x+size/2, size/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
   vector<vector<int> > dp(N, vector<int>(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int num;
            cin >> num;
            dp[i][j] = num;
        }
    }

    dnq(dp, 0, 0, N);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}