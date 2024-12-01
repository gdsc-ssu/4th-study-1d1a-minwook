#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N , M;
    string str;
    string str2;
    map<string, int> person;
    vector<string> result;
    int cnt = 0;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> str;
        person.insert({str,1});
    }

    for(int i=0; i<M; i++){
        cin >> str2;
        if(person.find(str2) != person.end()){
            //cout << "find ! " << "\n";
            result.push_back(str2);
            cnt ++;
        }
    }

    sort(result.begin(), result.end());

    cout << cnt << "\n";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}