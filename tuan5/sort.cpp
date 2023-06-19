#include <iostream>
using namespace std;
// void insertionSort(int arr[],int n) {
//     for(int i=1;i<n;i++){
//         int key=arr[i];
//         int j=i-1;
//         while(j>=0 && arr[j] > key){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }

// }
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i + 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
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

void merge(int arr[], int left, int middle, int right) {
    int len_left = middle - left + 1;
    int len_right = right - middle;

    int arr_left[len_left];
    int arr_right[len_right];

    for (int i = 0; i < len_left; i++) {
        arr_left[i] = arr[left + i];
    }
    for (int i = 0; i < len_right; i++) {
        arr_right[i] = arr[middle + 1 + i];
    }

    int i1 = 0;
    int i2 = 0;
    int k = left;

    while (i1 < len_left && i2 < len_right) {
        if ((arr_left[i1] % 2 == 1 && arr_right[i2] % 2 == 0) ||
            (arr_left[i1] % 2 == arr_right[i2] % 2 && arr_left[i1] < arr_right[i2])) {
            arr[k] = arr_left[i1];
            i1++;
        } else {
            arr[k] = arr_right[i2];
            i2++;
        }
        k++;
    }

    while (i1 < len_left) {
        arr[k] = arr_left[i1];
        i1++;
        k++;
    }

    while (i2 < len_right) {
        arr[k] = arr_right[i2];
        i2++;
        k++;
    }
}
// void mergeSort(int arr[],int left,int right){
//     int middle=(left+right)/2;

//     mergeSort(arr,left,middle);
//     mergeSort(arr,middle+1,right);

//     merge(arr,left,middle,right);
// }

void mergeSort(int arr[], int left, int right)
{

    if (left < right)
    {
        int middle = (left + right) / 2;
        // goi de quy sort tung phan ben trai va ben phai
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // gop hai phan ben trai va ben phai lai voi nhau
        merge(arr, left, middle, right);
    }
}
int main()
{
    int arr[] = {64, 25, 12, 22};
    int arr1[] = {9, 4, 1, 7, 3, 6, 8, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // insertionSort(arr,n);
    mergeSort(arr1, 0, 8);
    cout << "Sorted array: ";
    for (int i = 0; i < 9; i++)
    {
        cout << arr1[i] << " ";
    }
}