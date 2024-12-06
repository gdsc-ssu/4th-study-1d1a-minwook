#include <iostream> 
using namespace std; 

int cnt[1010][1010]; 
int student[1010][10]; 

int main() { 
	int n; 
	cin >> n;
	
	for(int i=1;i<=n;i++) 
	{ 
		for (int j = 1; j <= 5; j++)
			cin >> student[i][j];
	} 
	
	for(int k=1;k<=5;k++) 
	{ 
		for(int i=1;i<=n;i++) 
		{ 
			for(int j=1;j<=n;j++)
			{ 
				if(i==j) 
					continue; 

				if(student[i][k]==student[j][k]) 
				{ cnt[i][j]=1; 
				} 
			} 
		} 
	} 
	
	int maxcnt = 0; 
	int res = 1;
	
	for(int i=1;i<=n;i++) 
	{ 
		int c=0; 
		for(int j=1;j<=n;j++) 
			c+=cnt[i][j]; 
		
		if(maxcnt<c) 
		{ 
			maxcnt=c; 
			res=i; 
		} 
	} 
	cout << res;

	return 0; 
}