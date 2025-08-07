#include<iostream>
using namespace std;

struct node_tree{
    int data;
    node_tree *left;
    node_tree *right;
};
//node_tree *findlargestnode(node_tree* tree);
void insert(node_tree* &node, int val) {
    if (node == NULL) {
        node = new node_tree;
        node->data = val;
        node->left = node->right = NULL;
    }
    else if (val < node->data) {
        insert(node->left, val);
    }
    else {
        insert(node->right, val);
    }
}

void preorder(node_tree *node){
    if(node !=NULL){
        cout<<node->data<<"\t";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(node_tree *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

void postorder(node_tree *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}

int main() {
    node_tree* root = NULL;
    int choice, val, tchoice;
    while (true) {
        cout << "\n1. Insert\n2. Traversal\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insert(root, val);
                cout << "Inserted " << val << endl;
                break;
            case 2:
                cout << "Traversal options:\n1. Preorder\n2. Inorder\n3. Postorder\nEnter your choice: ";
                cin >> tchoice;
                switch (tchoice) {
                    case 1:
                        cout << "Preorder: ";
                        preorder(root);
                        cout << endl;
                        break;
                    case 2:
                        cout << "Inorder: ";
                        inorder(root);
                        cout << endl;
                        break;
                    case 3:
                        cout << "Postorder: ";
                        postorder(root);
                        cout << endl;
                        break;
                    default:
                        cout << "Invalid traversal choice.\n";
                }
                break;
            case 3:
                cout << "\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}