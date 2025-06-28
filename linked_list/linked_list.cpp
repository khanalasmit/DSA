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
void InsertBefore(node *new_node,int elem)
{
    if(start==NULL)
    {
        start=new_node;
    }
    else{
        node *ptr=start;
        node *preptr;
        while(ptr->data!=elem)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;
    }
}
void InsertNth(node *new_node,int pos)
{
    if(start==NULL){
        start=new_node;
    }
    else{
        node *ptr=start;
        int ch=1;
        while(ch!=pos-1){
            ptr=ptr->next;
            ch++;
        }
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
}
void DeleteBeg(){
    node *ptr=start;
    if(start==NULL){
        cout<<"Underflow\n";
    }
    else{
        start=start->next;
    }
    cout<<"Free ptr"<<endl;
    cout<<"Value freed:"<<ptr->data;
}
void DeleteEnd(){
    node *preptr,*ptr=start;
    if(start==NULL){
        cout<<"Underflow\n";
    }
    else{
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
    }
    cout<<"Free ptr"<<endl;
    cout<<"Value freed:"<<ptr->data;
}
void DeleteAfter(int elem){
    node *preptr,*temp,*ptr=start;
    if(start==NULL){
        cout<<"Underflow\n";
    }
    else{
        while(ptr->data!=elem){
            preptr=ptr;
            ptr=ptr->next;
        }
        temp=ptr;
        preptr->next=ptr->next;
    }
    cout<<"Free temp"<<endl;
    cout<<"Value freed:"<<temp->data;
}
void DeleteNth(int pos) {
    if (start == NULL) {
        cout << "Underflow\n";
        return;
    }

    if (pos == 1) {
        DeleteBeg();  
        return;
    }

    node *ptr = start;
    node *preptr = NULL;
    int count = 1;

    while (ptr != NULL && count < pos) {
        preptr = ptr;
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        cout << "Position out of range.\n";
    } else {
        preptr->next = ptr->next;
        cout << "Free ptr" << endl;
        cout << "Value freed: " << ptr->data << endl;
        delete ptr;
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
                cout << "Enter the specific element: ";
                cin >> specific;
                InsertAfter(new_node, specific);
                break;
            }
            case 4: {
                int value, specific;
                cout << "Enter the value to enter in node: ";
                cin >> value;
                cout << "Enter the specific element: ";
                cin >> specific;
                node *new_node = create_node(value);
                InsertBefore(new_node, specific);
                break;
            }
            case 5: {
                int value, pos;
                cout << "Enter the value to enter in node: ";
                cin >> value;
                cout << "Enter the position (kth): ";
                cin >> pos;
                node *new_node = create_node(value);
                InsertNth(new_node, pos);
                break;
            }
            case 6: {
                DeleteBeg();
                break;
            }
            case 7: {
                DeleteEnd();
                break;
            }
            case 8: {
                int specific;
                cout << "Enter the specific element: ";
                cin >> specific;
                DeleteAfter(specific);
                break;
            }
            case 9: {
                // yet to be implemented
                break;
            }
            case 10:
                Display(); // Display before exiting
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    }
}
