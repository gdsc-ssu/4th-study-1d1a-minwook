#include <iostream>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int A[N];

	for (int i=0; i<N; i++){
		int val;
		cin >> val;
		A[i] = val;
	}

	int count = 0;

	for(int i=N-1; i>=0; i--){
		if ( K < A[i]){
			continue;
		}
		int num = K / A[i];
		count += num;
		K = K % A[i];
	}

	cout << count;
}
