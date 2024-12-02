#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int dp[n+1];
    
    dp[1] = 1;
    dp[2] = 2;

    for (int i=3; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[n] << '\n';
 
    return 0;
}