#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (arr[j] % 3 > key % 3 || (arr[j] % 3 == key % 3 && arr[j] < key))) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;
    }
}

// void insertion_sort(vector<int> & arr){
//     for(int i=1;i<arr.size();i++){
//         int key=arr[i];
//         int j=i-1;
//         while(j>=0 && (arr[j] %3 > key %3 || (arr[j]%3 ==key%3 && arr[j]<key))){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }
// }
int main() {
    vector<int> arr = {9, 4, 1, 7, 3, 6, 8, 2, 5};
    insertion_sort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}