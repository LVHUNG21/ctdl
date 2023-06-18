#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stackk {
private:
    vector<T> vt;
public:
    Stackk() {}

    void push(T a) {
        vt.push_back(a);
    }

    void pop() {
        vt.pop_back();
    }

    T top() {
        return vt.back();
    }

    void clear() {
        vt.clear();
    }

    int getSize() {
        return vt.size();
    }

    void print() {
        for (int i = 0; i < vt.size(); i++) {
            cout << vt.at(i) << endl;
        }
    }
};

int main() {
    Stackk<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.pop();
    cout << "Top element: " << s.top() << endl;
    cout << "Size of stack: " << s.getSize() << endl;
    s.clear();

    return 0;
}