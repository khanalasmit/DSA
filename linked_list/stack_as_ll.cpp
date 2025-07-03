
#include<iostream>
#include<iomanip>
using namespace std;

struct node {
    int data;
    node *next;
};

node *top = NULL;


node *create_node(int value) {
    node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}
void Push(node *new_node) {
    if (top == NULL) {
        top = new_node;
    } else {
        new_node->next = top;
        top = new_node;
    }
}
void Pop(){
    node *ptr=top;
    if(top==NULL){
        cout<<"Underflow\n";
        return;
    }
    else{
        top=top->next;
    }
    cout<<"Free ptr"<<endl;
    cout<<"Value freed:"<<ptr->data<<endl;
}
void Display() {
    node *ptr = top;
    while (ptr != NULL) {
        cout << "The data: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{

    int choice;
    while(true){
        cout<<"1.Push\n2.Pop\n3.Display\4.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
    case 1:
        {
            cout<<"Enter item to push:\n";
            int data;
            cin>>data;
            Push(create_node(data));
            break;
        }
    case 2:
        Pop();
        break;

    case 3:
        Display();
        break;

    }
}}
