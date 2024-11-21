#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;;
    for(int t=0; t<T; t++){
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int result = -1;

        int limit = lcm(M,N);
        for(int i=x; i<=limit; i+=M){
            if(i%N == y){
                result = i;
                break;
            }
            else if (i % N == 0){
                if (N == y){
                    result = i;
                    break;
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}