#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int> > vec;
    
    for(int i=0; i<N; i++){
        int t1, t2;
        cin >> t1 >> t2;
        vec.push_back(make_pair(t2,t1));
    }

    sort(vec.begin(),vec.end());

    int start = vec[0].second;
    int end = vec[0].first;
    int count = 1;


    for(int i=1; i<N; i++){
        if (end > vec[i].second){
            continue;
        }
        else{
            count ++;
            start = vec[i].second;
            end = vec[i].first;
        }
    }

    cout << count << '\n';

    return 0;
}