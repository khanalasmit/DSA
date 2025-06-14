#include <iostream>
using namespace std;

template <class T>
class CircularQueue {
private:
    T array[1000];
    int frontIndex;
    int rearIndex;
    int max;

public:
    CircularQueue(int m) : frontIndex(-1), rearIndex(-1), max(m) {}

    bool isempty() {
        return frontIndex == -1;
    }

    bool isfull() {
        return ((rearIndex + 1 == frontIndex) || (frontIndex == 0 && rearIndex == max - 1));
    }

    void enqueue(T num) {
        if (isfull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (isempty()) {
            frontIndex = rearIndex = 0;
        } else if (rearIndex == max - 1 && frontIndex != 0) {
            rearIndex = 0;  // wrap around manually
        } else {
            rearIndex++;
        }

        array[rearIndex] = num;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Removed element is: " << array[frontIndex] << endl;

        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;  // Queue becomes empty
        } else if (frontIndex == max - 1) {
            frontIndex = 0;  // wrap around manually
        } else {
            frontIndex++;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        if (frontIndex <= rearIndex) {
            for (int i = frontIndex; i <= rearIndex; i++) {
                cout << array[i] << " ";
            }
        } else {
            for (int i = frontIndex; i < max; i++) {
                cout << array[i] << " ";
            }
            for (int i = 0; i <= rearIndex; i++) {
                cout << array[i] << " ";
            }
        }
        cout << endl;
    }

    T front() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return array[frontIndex];
    }

    T rear() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return array[rearIndex];
    }
};

int main() {
    int size, choice, val;
    cout << "Enter the size of the circular queue: ";
    cin >> size;
    CircularQueue<int> q(size);

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Front\n5. Rear\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Front element: " << q.front() << endl;
                break;
            case 5:
                cout << "Rear element: " << q.rear() << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
