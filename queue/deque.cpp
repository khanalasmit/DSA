#include<iostream>
using namespace std;

template <class T>
class Deque {
private:
    T array[1000];
    int max;
    int f;
    int r;

public:
    Deque(int m) : max(m), f(-1), r(-1) {}

    bool isFull() {
        return (f == 0 && r == max - 1);
    }

    bool isEmpty() {
        return (f == -1);
    }

    void insertion_rear(T num) {
        if (r == max - 1) {
            cout << "Queue is full from rear\n";
            return;
        }

        if (isEmpty()) {
            f = r = 0;
        } else {
            r++;
        }

        array[r] = num;
    }

    void insertion_front(T num) {
        if (f == 0) {
            cout << "Queue is full from front\n";
            return;
        }

        if (isEmpty()) {
            f = r = 0;
        } else {
            f--;
        }

        array[f] = num;
    }

    void deletion_front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        T item = array[f];
        cout << "Item dequeued from front: " << item << endl;

        if (f == r) {
            f = r = -1;
        } else {
            f++;
        }
    }

    void deletion_rear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        T item = array[r];
        cout << "Item dequeued from rear: " << item << endl;

        if (f == r) {
            f = r = -1;
        } else {
            r--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = f; i <= r; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Deque<int> dq(size);

    while (true) {
        cout << "\n1. Enqueue from rear\n2. Dequeue from rear\n3. Enqueue from front\n4. Dequeue from front\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int val;
            cout << "Enter value to enqueue at rear: ";
            cin >> val;
            dq.insertion_rear(val);
            break;
        }
        case 2:
            dq.deletion_rear();
            break;

        case 3: {
            int val;
            cout << "Enter value to enqueue at front: ";
            cin >> val;
            dq.insertion_front(val);
            break;
        }
        case 4:
            dq.deletion_front();
            break;

        case 5:
            dq.display();
            break;

        case 6:
            break;

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
