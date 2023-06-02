#include <iostream>
using namespace std;
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
} 
// void bubbleSort(int a[], int size)
// {
//     bool swapped;
//     do
//     {
//         swapped = false;
//         for (int i = 0; i < size; i++)
//         {
//             if (a[i - 1] > a[i])
//             {
//                 swap(a[i - 1], a[i]);
//                 swapped = true;
//             }
//         }
//     } while (swapped == true);
// };
// void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; i < n - 1; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min_idx], arr[i]);
    }
}

void selectSort(int a[],int size){
    for( int i=0;i<size-1;i++){
        int min_index = i;
        for(int j=i+1 ;j<size;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
            Swap(a[min_index],a[i]);
        }
    }
}
int main()
{
    int a[5] = {3,2,23,4,55};
    // bubbleSort(a,5);
    // selectionSort(a, 5);
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<endl;
    // };
    // return 1;
}