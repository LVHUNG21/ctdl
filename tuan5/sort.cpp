#include<iostream>
using namespace std;
void insertionSort(int arr[],int n) {
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key =arr[i];
        j=i+1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        a[j+1]=key
    }
}
int main(){
    int arr[]={64,25,12,22};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}