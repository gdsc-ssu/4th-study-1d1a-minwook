#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int row, col; cin >> col >> row;
	vector<int> rowcut = { 0,row };
	vector<int> colcut = { 0,col };

	int N; cin >> N;
	while (N--) {
		bool x; int y; cin >> x >> y;
		if (x) colcut.push_back(y);
		else rowcut.push_back(y);
	}

	sort(rowcut.begin(), rowcut.end());
	sort(colcut.begin(), colcut.end());

	row = (int) rowcut.size();
	col = (int) colcut.size();
	
	int maxrow = 0;
	int maxcol = 0;
	for (int i = 1; i < row; i++) {
		int temp = rowcut[i] - rowcut[i - 1];
		if (temp > maxrow) maxrow = temp;
	}
	for (int i = 1; i < col; i++) {
		int temp = colcut[i] - colcut[i - 1];
		if (temp > maxcol) maxcol = temp;
	}

	cout << maxrow * maxcol;
}