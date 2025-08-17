#include<iostream>
using namespace std;

void selection_sort(int array[10]){
    for(int i=0;i<7;i++){
        int smallest_index=i;
        for(int j=i+1;j<7;j++){
            if(array[j]<array[smallest_index]){
                smallest_index=j;
            }}
            int temp=array[smallest_index];
            array[smallest_index]=array[i];
            array[i]=temp;
        }
}
void insertion_sort(int array[10]){
    for(int i=1;i<7;i++){
        int current_value = array[i];  
        int prev = i-1;
        
        while(prev >= 0 && array[prev] > current_value){
            array[prev+1] = array[prev];
            prev--;
        }
        array[prev+1] = current_value;  
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p);      
        quickSort(arr, p + 1, high);  
    }
}

int main()
{
int array[10]={2,8,5,3,9,4,1};
selection_sort(array);
cout<<"The selection sort is as follows:\n";
cout<<"Sorted array is\n";
for(int i=0;i<7;i++){
    cout<<array[i]<<"\t";
}

cout<<"\n======================================================";
cout<<"\nFor the insertion sort:\n";
int tempArray1[10] = {2,8,5,3,9,4,1};
for(int i=0;i<10;i++) array[i] = tempArray1[i];
insertion_sort(array);
cout<<"Soreted array\n";
for(int i=0;i<7;i++)
{
    cout<<array[i]<<"\t";
}
cout<<"\n======================================================";
cout<<"\nFor the quick sort:\n";
cout<<"Soreted array\n";
int tempArray2[10] = {2,8,5,3,9,4,1};
for(int i=0;i<10;i++) array[i] = tempArray2[i];
quickSort(array,0,6);
for(int i=0;i<7;i++)
{
    cout<<array[i]<<"\t";
}
cout<<"\n======================================================";
}