#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    stack<int> stack;

    for (int i=0; i<K; i++){
        int num;
        cin >> num;
        if(num != 0){
            stack.push(num);
        }
        else{
            stack.pop();
        }
    }

    int result = 0;
    while(!stack.empty()){
        result += stack.top();
        stack.pop();
    }

    cout << result << "\n";
}