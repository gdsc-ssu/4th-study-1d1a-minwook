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
    bool flag = true;
    bool err = true;
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
        string str = "";

        for(int i=1; i<x.length(); i++){
            if (x[i] == ',' || x[i] == ']'){
                if(str != ""){
                    dq.push_back(stoi(str));
                    str="";
                }
            }
            else{
                str += x[i];
            }
        }

        for(int i=0; i<p.length(); i++){
            char ch = p[i];
            if(ch == 'R'){
                if(flag) flag = false;
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
        if(flag){
            if (!flag) reverse(dq.begin(),dq.begin());
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

            dq.clear();
        }
        else{
            cout << "error" << '\n';
        }
    }

    return 0;
}