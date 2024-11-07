#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[50001];
    int n;
    cin >> n;
    fill_n(dp, 50001, 100);
    dp[0]=0;
    dp[1]=1;

    for(int i=2; i<n+1 ; i++){
        int a = sqrt(i);
        float b = sqrt(i);
        if(a == b){
            dp[i] = 1;
            cout << i << "=" << dp[i] << endl;
            continue;
        }
        for(int j=1; j*j<i+1; j++){
            int m = dp[j*j] + dp[i-j*j];
            if (m < dp[i]){
                dp[i] = m;
            }
        }
    }

    cout << dp[n] << '\n';


    return 0;
}