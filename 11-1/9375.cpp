#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int i=0; i < T; i++){
        int n;
        cin >> n;
        unordered_map<string,int> m;
        for(int i=0; i<n; i++){
            string name, ft;
            cin >> name >> ft;
            if (!m.count(ft))
                m.insert({ft,1});
            else 
                m[ft]++;
        }

        int num=1;
        for(auto iter = m.begin(); iter != m.end() ; ++iter){
            num *= m[iter->first] + 1;
        }
        if (m.size() ==1)
            cout << n << '\n';
        else{
            cout << num - 1 << '\n';
        }    
        
    }

    return 0;
}