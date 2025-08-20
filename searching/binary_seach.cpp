#include <iostream>
using namespace std;

int array[20] = {1, 3, 4, 5, 6, 77, 43, 22, 11, 77, 2221, 114, 56, 7775, 33};

void insertion_sort(int array[], int size){
    for(int i = 1; i < size; i++){
        int current_value = array[i];  
        int prev = i - 1;
        
        while(prev >= 0 && array[prev] > current_value){
            array[prev + 1] = array[prev];
            prev--;
        }
        array[prev + 1] = current_value;  
    }
}

void binary_iterative(int array[], int size) {
    int first = 0, last = size - 1, item, flag = 0;
    cout << "Enter item to search: ";
    cin >> item;
    
    while (first <= last) {
        int middle = (first + last) / 2;
        
        if (array[middle] == item) {
            cout << "Search successful at index " << middle << endl;
            flag = 1;
            break;
        }
        else if (item < array[middle]) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    
    if (flag == 0) {
        cout << "Search unsuccessful" << endl;  
    }
}

int binary_recursive(int array[], int first, int last, int item) {
    if (first > last) return -1;
    
    int middle = (first + last) / 2;
    
    if (array[middle] == item) return middle;
    else if (item < array[middle]) return binary_recursive(array, first, middle - 1, item);
    else return binary_recursive(array, middle + 1, last, item);
}

int main() {
    int size = 15;
    int choice, item;
    
    insertion_sort(array, size);
    
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    while(true) {
    cout << "\nBinary Search Menu:\n";
    cout << "1. Iterative Binary Search\n";
    cout << "2. Recursive Binary Search\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int result;  // Declare result here

    switch(choice) {
        case 1:
            binary_iterative(array, size);
            break;
        case 2:
            cout << "Enter item to search: ";
            cin >> item;
            result = binary_recursive(array, 0, size - 1, item);
            if(result != -1) cout << "Search successful at index " << result << endl;
            else cout << "Search unsuccessful" << endl;
            break;
        case 3:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
}

}

