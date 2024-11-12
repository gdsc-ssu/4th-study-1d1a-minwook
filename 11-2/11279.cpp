#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
int N;

void heapify(vector<long long>& arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[i] < arr[left]){
        largest = left;
    }
    if (right<n && arr[largest] < arr[right]){
        largest = right;
    }
    if (largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,arr.size(),largest);
    }
}

void shiftup(vector<long long>& arr, int i){
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(num == 0){
            if (arr.empty()){
                cout << "0" << '\n';
                continue;
            }
            cout << arr[0] << '\n';
            long long temp;
            temp = arr[0];
            arr[0] = arr.back();
            arr.back() = temp;
            arr.pop_back();
            heapify(arr, arr.size(), 0);
        }
        else{
            arr.push_back(num);
            shiftup(arr, arr.size()-1);            
        }
    }

    return 0;
}