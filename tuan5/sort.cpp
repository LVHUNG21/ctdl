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
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
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