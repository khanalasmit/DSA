#include<iostream>
#include<iomanip>
using namespace std;

struct node {
    int data;
    node *next;
};

node *start = NULL;

node *create_node(int value) {
    node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void InsertBegin(node *new_node) {
    if (start == NULL) {
        start = new_node;
    } else {
        new_node->next = start;
        start = new_node;
    }
}

void InsertEnd(node *new_node) {
    if (start == NULL) {
        start = new_node;
    } else {
        node *ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void InsertAfter(node *new_node,int elem){
    if(start==NULL){
        start=new_node;
    }
    else{
        node *ptr=start;
        while(ptr->data!=elem){
            ptr=ptr->next;
        }
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
}

void Display() {
    node *ptr = start;
    while (ptr != NULL) {
        cout << "The data: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main() {
    while (true) {
        cout << "\n1.Insert item at the begining.\n2.Insert node at the end of the list\n3.Insert node after the specific node\n4.Insert node before specific node.\n5.Insert node after the kth node" << endl;
        cout << "6.Delete item from the begining\n7.Delete item from the end.\n8.Delete node after the specific node\n9.Delete the kth specific node\n10.Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to enter in node: ";
                cin >> value;
                node *new_node = create_node(value);
                InsertBegin(new_node);
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to enter in node: ";
                cin >> value;
                node *new_node = create_node(value);
                InsertEnd(new_node);
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value to enter in node: ";
                cin >> value;
                node *new_node = create_node(value);
                int specific;
                cout<<"Enter the specfic element";
                cin>>specific;
                InsertAfter(new_node,specific);
                break;
            }
            case 10:
                Display(); // Display before exiting
                return 0;  // ❗️Fix: Exit the program
        }
    }
}
