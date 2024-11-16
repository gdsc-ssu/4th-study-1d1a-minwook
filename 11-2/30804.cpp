#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> fruit(10,0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; 
    cin >> N;
    vector<int> table;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        table.push_back(num);
    }

    int start=0 ,end=0, result=0;
    int count = 1;
    fruit[table[start]]++;

    while(start <= end && end < N){ //윈도우 크기를 늘려가면서
        if (count <= 2){
            result = max(result, end-start+1);
            end++; //윈도우 사이즈 증가
            if(fruit[table[end]]==0){ //한칸 증가했는데 새로운 과일이라면
                count ++;
            }
            fruit[table[end]]++;
        }
        else{
            fruit[table[start]]--; //윈도우 사이즈 감소시키고 해당 과일 제거
            if(fruit[table[start]]==0){ //이 과일을 뺐을 때 아예 이 과일이 0개가 되면
                count --;
            }
            start++;
        }
    }

    cout << result << '\n'; //최대 윈도우 사이즈 출력

    return 0;
}