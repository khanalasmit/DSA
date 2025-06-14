#include <iostream>
using namespace std;

template <class T>
class LinearQueue {
private:
    T array[1000]; // fixed-size backing array
    int frontIndex;
    int rearIndex;
    int maxSize;

public:
    LinearQueue(int size) : frontIndex(-1), rearIndex(-1), maxSize(size) {}

    bool isEmpty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }

    bool isFull() {
        return (rearIndex == maxSize - 1);
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (frontIndex == -1) frontIndex = 0; // first element added
        array[++rearIndex] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << array[frontIndex] << endl;
        frontIndex++;
        if (frontIndex > rearIndex) {
            // Reset queue after all elements removed
            frontIndex = rearIndex = -1;
        }
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T(); // Return default value
        }
        return array[frontIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = frontIndex; i <= rearIndex; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue<int> Lr(3);
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Check Front\n4. Display Queue\n5. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to enqueue: ";
                cin >> val;
                Lr.enqueue(val);
                break;
            }
            case 2:
                Lr.dequeue();
                break;
            case 3:
                cout << "Front element: " << Lr.front() << endl;
                break;
            case 4:
                Lr.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
}
