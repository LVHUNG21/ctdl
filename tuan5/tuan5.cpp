#include <stdio.h>
#include<iostream>
using namespace std;
// Hàm đổi chỗ 2 số nguyên
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
// Hàm selection sort
void selectSort(int a[],int size){
    for( int i=0;i<size-1;i++){
        int min_index = i;
        for(int j=i+1 ;j<size;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
            swap(a[min_index],a[i]);
        }
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    // printf("n");
}
 
void insertSort(int a[],int size){
    int j;
    for(int i=1;i<size;i++){
        j=i;
        while(j>0 && a[j-1] > a[j]){
            swap(a[j-1],a[j]);
            j--;
        }
    }
}



int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]);
    selectSort(a, n);
    printArray(a,n);
    cout<<endl;
    insertSort(a,n);
    printArray(a,n);
    return 0;
}