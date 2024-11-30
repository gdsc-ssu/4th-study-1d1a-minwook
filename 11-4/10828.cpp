#include <iostream>
#include <vector>
using namespace std;

int s = 0;
int arr[10001];
void push(int x){
    arr[s] = x;
    s++;
}   
int pop(){
    if (s== 0) return -1;
    int t = arr[s-1];
    s--;
    return t;
}

int top(){
    if (s==0) return -1;
    return arr[s-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str=="push"){
            int num;
            cin >> num;
            push(num);
        }
        else if(str == "pop"){
            cout << pop() << '\n';
        }
        else if(str == "top"){
            cout << top() << '\n';
        }
        else if(str == "size"){
            cout << s << '\n';
        }
        else{
            if(s==0){
                cout << "1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }
    }
}