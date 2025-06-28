#include<iostream>
using namespace std;

struct node {
    int coef_;
    int expo_;
    node *next;
};

node *p = NULL;
node *q = NULL;
node *r = NULL;

node *create_node(int coef, int expo) {
    node *new_node = new node;
    new_node->coef_ = coef;
    new_node->expo_ = expo;
    new_node->next = NULL;
    return new_node;
}

void InsertEnd(node* &start, node *new_node) {
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

void display(node *poly) {
    if (poly == NULL) {
        cout << "0";
        return;
    }
    while (poly != NULL) {
        cout << poly->coef_ << "x^" << poly->expo_;
        poly = poly->next;
        if (poly != NULL)
            cout << " + ";
    }
    cout << endl;
}

// Function to add two polynomials
void add() {
    node *ptr1 = p;
    node *ptr2 = q;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo_ == ptr2->expo_) {
            int sum_coef = ptr1->coef_ + ptr2->coef_;
            if (sum_coef != 0) {
                InsertEnd(r, create_node(sum_coef, ptr1->expo_));
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->expo_ > ptr2->expo_) {
            InsertEnd(r, create_node(ptr1->coef_, ptr1->expo_));
            ptr1 = ptr1->next;
        } else {
            InsertEnd(r, create_node(ptr2->coef_, ptr2->expo_));
            ptr2 = ptr2->next;
        }
    }

    // Add remaining terms
    while (ptr1 != NULL) {
        InsertEnd(r, create_node(ptr1->coef_, ptr1->expo_));
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        InsertEnd(r, create_node(ptr2->coef_, ptr2->expo_));
        ptr2 = ptr2->next;
    }
}

int main() {
    int p_terms, q_terms;
    cout << "Enter the number of terms in polynomial p: ";
    cin >> p_terms;

    cout << "For polynomial p, enter the coefficient and exponent in descending order:" << endl;
    for (int i = 0; i < p_terms; i++) {
        int coef, expo;
        cout << "Term " << i + 1 << " - Coefficient: ";
        cin >> coef;
        cout << "Exponent: ";
        cin >> expo;
        InsertEnd(p, create_node(coef, expo));
    }

    cout << "\nEnter the number of terms in polynomial q: ";
    cin >> q_terms;

    cout << "For polynomial q, enter the coefficient and exponent in descending order:" << endl;
    for (int i = 0; i < q_terms; i++) {
        int coef, expo;
        cout << "Term " << i + 1 << " - Coefficient: ";
        cin >> coef;
        cout << "Exponent: ";
        cin >> expo;
        InsertEnd(q, create_node(coef, expo));
    }

    cout << "\nPolynomial p: ";
    display(p);

    cout << "Polynomial q: ";
    display(q);

    add();

    cout << "\nSum of polynomials: ";
    display(r);

    return 0;
}
