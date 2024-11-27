#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> dq;
    int T;
    cin >> T;

    while(T--){
        dq.clear();
        string p;
        cin >> p;
        int n;
        cin >> n;
        string x;
        cin >> x;
        bool flag = true;
        bool err = true;
        string temp = "";

        for(int i=1; i<p.length(); i++){
            if (p[i] == ',' || p[i] == ']'){
                if(temp != ""){
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
            else{
                temp += p[i];
            }
        }

        for(int i=0 ; i<dq.size(); i++){
            cout << dq[i] << ' ';
        }
        cout << '\n';

        for(int i=0; i<p.size(); i++){
            char ch = p[i];
            if(ch == 'R'){
                flag = !flag;
            }
            else if(ch == 'D'){
                if(dq.empty()){
                    err = false;
                    break;
                }
                else{
                    if(flag) dq.pop_front();
                    else dq.pop_back(); //미리 뒤집어서 뺌
                }
            }
        }

        if(!err){
            cout << "error" << '\n';
        }
        else{
            if (!flag) reverse(dq.begin(),dq.end());
            cout << '[';
            for(int i=0; i<dq.size(); i++){
                if(i == dq.size() -1 ){
                    cout << dq[i];
                }
                else{
                    cout << dq[i] << ',';
                }
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}