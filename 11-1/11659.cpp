#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int arr[N];
    long long result[N+1];
    int sum = 0;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        arr[i] = num;
        sum += num;
        result[i+1] = sum;    
    }

    for(int i=0; i<M; i++){
        int start, last;

        cin >> start >> last;
        cout << result[last]-result[start-1] << '\n';
    }

    return 0;
}