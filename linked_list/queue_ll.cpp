#include<iostream>
#include<iomanip>
using namespace std;

struct node {
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

node *create_node(int value) {
    node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}
//enque operation
void Enque(node *new_node) {
    if (front == NULL) {
        front = rear = new_node;
        front->next=rear->next=NULL;
    } else {
        rear->next=new_node;
        rear=new_node;
    }
}
void Deque(){
    node *ptr=front;
    if(front==NULL){
        cout<<"Underflow\n";
        return;
    }
    else{
        ptr=front;
        front=front->next;
    }
    cout<<"Dequed.....";
    cout<<"Value freed:"<<ptr->data;
}

void Display() {
    node *ptr = front;
    while (ptr != NULL) {
        cout << "The data: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    int choice, value;
    while (true) {
        cout << "\nQueue using Linked List\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                Enque(create_node(value));
                break;
            case 2:
                Deque();
                break;
            case 3:
                {
                    Display();                
                }
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}