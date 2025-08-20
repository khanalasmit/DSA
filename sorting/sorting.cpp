#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void merge(int array[],int beg,int end,int mid);
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


void shell_sort(int array[], int length) {
    int gap_size = length / 2;
    
    while(gap_size >= 1) {  // Changed from > 1 to >= 1
        bool swapped;
        do {  // Add inner loop to repeat until no swaps
            swapped = false;
            for(int i = 0; i < (length - gap_size); i++) {
                if(array[i + gap_size] < array[i]) {
                    int temp = array[i + gap_size];
                    array[i + gap_size] = array[i];
                    array[i] = temp;
                    swapped = true;
                }
            }
        } while(swapped);
        
        gap_size = gap_size / 2;
    }
}

#include <iostream>
using namespace std;

void merge(int array[], int beg, int mid, int end) {
    int i = beg;
    int j = mid + 1;
    int index = 0;
    int temp[end - beg + 1];  // temporary array size = number of elements

    // Merge the two halves
    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            temp[index++] = array[i++];
        } else {
            temp[index++] = array[j++];
        }
    }

    // Copy remaining elements of left half, if any
    while (i <= mid) {
        temp[index++] = array[i++];
    }

    // Copy remaining elements of right half, if any
    while (j <= end) {
        temp[index++] = array[j++];
    }

    // Copy back to original array
    for (int k = 0; k < index; k++) {
        array[beg + k] = temp[k];
    }
}

void merge_sort(int array[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort(array, beg, mid);
        merge_sort(array, mid + 1, end);
        merge(array, beg, mid, end);
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
cout<<"\nFor the Shell sort:\n";
cout<<"Soreted array\n";
int tempArray3[10] = {2,8,5,3,9,4,1};
for(int i=0;i<10;i++) array[i] = tempArray2[i];
shell_sort(array,7);
for(int i=0;i<7;i++)
{
    cout<<array[i]<<"\t";
}
cout<<"\n======================================================";
cout<<"\nFor the Merge sort:\n";
cout<<"Soreted array\n";
int tempArray4[10] = {2,8,5,3,9,4,1};
for(int i=0;i<10;i++) array[i] = tempArray2[i];
merge_sort(array,0,6);
for(int i=0;i<7;i++)
{
    cout<<array[i]<<"\t";
}
cout<<"\n======================================================";
}