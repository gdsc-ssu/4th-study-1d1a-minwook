#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    int arr[12]={0};

    arr[1]=1;
    arr[2]=2;
    arr[3]=4;

    for(int i=4; i<12; i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    
    for (int i=0; i<T; i++){
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }

    return 0;
}