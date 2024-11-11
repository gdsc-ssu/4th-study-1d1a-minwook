#include <iostream>

using namespace std;

void treecut(long long arr[], int len, long long max, long long M){
    long long left = 1;
    long long right = max;
    long long height = 0;

    while(left<=right){
        long long result=0;
        long long mid = (left+right)/2;

        for(int i=0; i<len; i++){
            if(arr[i] < mid)
                continue;
            else{
                result += (arr[i] - mid);
            }
        }
        if (result >= M){
            left = mid + 1;
            height = mid;
        }
        else{
            right = mid - 1;
        }
    }
    cout << height << '\n';
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;
    long long tree[N];
    long long max = 0;

    for(int i=0; i<N; i++){
        long long h;
        cin >> h;
        tree[i] = h;
        if(h > max)
            max = h;
    }

    treecut(tree, N, max, M);

    return 0;
}