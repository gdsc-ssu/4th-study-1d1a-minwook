#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;

void heapify(vector<long long>& arr, int n, long long i){
    long long min = i;
    long long l = 2*i+1;
    long long r = 2*i+2;

    if (l<n && arr[i] > arr[l]){
        min = l;
    }
    if (r<n && arr[min] > arr[r]){
        min = r;
    }
    if (min != i){
        long long temp;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        heapify(arr,n,min);
    }
    
}

void siftUp(vector<long long>& arr, int i) {
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for (int i=0; i<N; i++){
        long long num;
        cin >> num;
        if (num == 0){
            if(arr.empty()){
                cout << "0" << '\n';
                continue;
            }
            cout << arr[0] << '\n';
            long long temp;
            temp = arr[0];
            arr[0] = arr.back();
            arr.back() = temp;
            arr.pop_back();
            heapify(arr, arr.size(),0);
        }
        else{
            arr.push_back(num);
            siftUp(arr, arr.size() - 1);
        }
    }   

    return 0;
}