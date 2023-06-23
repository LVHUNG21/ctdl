#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue {
private:
    vector<T> q;
public:
    Queue() {}

    void enqueue(T data) {
        q.push_back(data);
    }

    void dequeue() {
        if (!q.empty()) {
            q.erase(q.begin());
        }
    }

    T front() {
        if (!q.empty()) {
            return q.front();
        }
    }

    T back() {
        if (!q.empty()) {
            return q.back();
        }
    }

    bool empty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }

    void print() {
        for (int i = 0; i < q.size(); i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print();

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Size of queue: " << q.size() << endl;

    q.dequeue();
    q.dequeue();

    q.print();

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Size of queue: " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return ;
}