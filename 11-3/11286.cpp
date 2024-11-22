#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;

void heapify(vector<long long int>& vec, int n, int i ){
    long long int small = i;
    long long int left = 2*i + 1;
    long long int right = 2*i + 2;


    if(left < n && abs(vec[small]) >= abs(vec[left])){
        if(abs(vec[small]) == abs(vec[left])){
            if(vec[small] > vec[left]) small = left;
        }
        else{
            small = left;
        }
    } 
    if(right < n && abs(vec[small]) >= abs(vec[right])){
        if(abs(vec[small]) == abs(vec[right])){
            if(vec[small] > vec[right]) small = right;
        }
        else{
            small = right;
        }
    }
    if(small != i){
        swap(vec[small],vec[i]);
        heapify(vec, n ,small);
    }
}

void shiftup(vector<long long int>& vec, int i){
    while(i > 0 && abs(vec[(i-1)/2]) >= abs(vec[i])){
        if(abs(vec[(i-1)/2]) == abs(vec[i])){
            if(vec[(i-1)/2] > vec[i]){
                swap(vec[i],vec[(i-1)/2]);
            }
        }
        else{
            swap(vec[i],vec[(i-1)/2]);
        }
        i = (i-1)/2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<long long int> vec;

    for(int i=0; i<N; i++){
        long long int num;
        cin >> num;
        if(num == 0){
            if(vec.empty()) {
                cout << "0" << '\n';
                continue;
            }
            cout << vec.front() << '\n';
            swap(vec[0],vec.back());
            vec.pop_back();
            heapify(vec, vec.size(), 0);
        }
        else{
            vec.push_back(num);
            shiftup(vec, vec.size()-1);
        }
    }

    return 0;
}