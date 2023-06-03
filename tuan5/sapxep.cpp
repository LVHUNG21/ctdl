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
// {
//     int i, j, min_idx;
//     // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
//     for (i = 0; i < n - 1; i++)
//     {
//         // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
//         min_idx = i;
//         for (j = i + 1; j < n; j++)
//             if (arr[j] < arr[min_idx])
//                 min_idx = j;

//         // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
//         swap(arr[min_idx], arr[i]);
//     }
// }

void selectSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
            swap(a[min_index], a[i]);
        }
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int index_of_left_array = mid - left + 1;
    int index_of_right_array = right - mid;

    int left_array[index_of_left_array];
    int right_array[index_of_right_array];

    for (int i = 0; i < index_of_left_array; i++)
    {
        left_array[i] = arr[left + i];
    }
    for (int i = 0; i < index_of_right_array; i++)
    {
        right_array[i] = arr[mid + 1 + i];
    }
    int index_of_first_subarray = 0;
    int index_of_second_subarray = 0;
    int index_of_merged_subarray = left;
    while (index_of_first_subarray < index_of_left_array && index_of_second_subarray < index_of_right_array)
    {
        if (left_array[index_of_first_subarray] <= right_array[index_of_second_subarray])
        {
            arr[index_of_merged_subarray] = left_array[index_of_first_subarray];
            index_of_first_subarray++;
        }
        else
        {
            arr[index_of_merged_subarray] = right_array[index_of_second_subarray];
            index_of_second_subarray++;
        }
        index_of_merged_subarray++;
    }
    while( index_of_first_subarray<index_of_left_array){
        arr[index_of_merged_subarray]=left_array[index_of_first_subarray];
        index_of_first_subarray++;
        index_of_merged_subarray++;
    }
    while(index_of_second_subarray<index_of_right_array){
        arr[index_of_merged_subarray]=right_array[index_of_second_subarray];
        index_of_second_subarray++;
        index_of_merged_subarray++;
    }
}
void mergSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergSort(arr, l, m);
        mergSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    
}
int main()
{
    int a[5] = {3, 2, 23, 4, 55};
    // bubbleSort(a,5);
    mergSort(a, 0, 4);
    // selectionSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    };
    cout << endl;
    // return 1;
}