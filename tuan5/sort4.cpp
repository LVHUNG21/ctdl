#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        int min_value=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<min_value){
                min_index=j;
                min_value=arr[j];
            }
        }
            swap(arr[i],arr[min_index]);
    }
}
void insertionSort(int arr[],int n){
    for( int i=0;i<n;i++){
        int key =arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
    arr[j+1]=key;
    }
}
void bubbleSort(int arr[],int n ){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[j]>arr[i])
            swap(arr[j],arr[i]);
        }
    }
}
void quickSort(int arr[],int left,int right){
    int i=left;
    int j=right;
    int pivot=arr[(left+right)/2];
    while(i<=j){
        while(arr[i]>pivot)
        i++;
        while(arr[j]<pivot)
        j--;
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(i<right ) quickSort(arr,i,right);
    if(left<j) quickSort(arr,left,j);
}
void merge(int arr[],int left,int middle,int right){
    int len_left=middle-left+1;
    int len_right=right-middle;

    int arr_left[len_left];
    int arr_right[len_right];
    for(int i=0;i<len_left;i++){
        arr_left[i]=arr[left+i];
    }
    for(int i=0;i<len_right;i++){
        arr_right[i]=arr[middle+i+1];
    }
    int i1=0;
    int i2=0;
    int k=left;
    while(i1<len_left && i2<len_right){
        if(arr_left[i1]>arr_right[i2]){
            arr[k]=arr_left[i1];
            i1++;
        }
        else {
            arr[k]=arr_right[i2];
            i2++;
        }
        k++;
    }
    while(i1<len_left ){
        arr[k]=arr_left[i1];
        i1++;
        k++;
    }
    while(i2<len_right){
        arr[k]=arr_right[i2];
        i2++;
        k++;
    }
}
void mergeSort(int arr[], int left ,int right){
    if(left<right){
        int middle=(left+right)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);

        merge(arr,left,middle,right);
    }
}
int main(){
int arr[] = {9, 4, 1, 7, 3, 6, 8, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // insertionSort(arr,n);
    quickSort(arr,0,n-1);
    // bubbleSort(arr,n);
    // selectionSort(arr,n);
    // mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}   