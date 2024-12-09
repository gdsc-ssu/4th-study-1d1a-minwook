#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int weight, height;
    int N;
    cin >> N;

    vector<pair<int,int>> vec;
    
    for(int i=0; i<N; i++){
        cin >> weight >> height ;
        vec.push_back({weight, height});
    }

    vector<int> grade(50,1);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(vec[i].first < vec[j].first && vec[i].second < vec[j].second){
                grade[i]++;
            }
        }
    }



    for(int i=0; i<N; i++){
        cout << grade[i] << " ";
    }
}