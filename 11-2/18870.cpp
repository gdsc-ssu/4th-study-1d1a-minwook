#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<long long int> arr;

    for(int i=0; i<N; i++){
        int X;
        cin >> X;
        arr.push_back(X);
    }

    vector<long long int> copyarr(arr);
    sort(copyarr.begin(),copyarr.end());
    copyarr.erase(unique(copyarr.begin(),copyarr.end()),copyarr.end());

    for(int i=0; i<N; i++){
        cout << lower_bound(copyarr.begin(),copyarr.end(),arr[i]) - copyarr.begin() << ' ';
    }
    cout << '\n';

    return 0;
}