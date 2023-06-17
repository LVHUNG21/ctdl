#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *prev;
    node<T> *next;
    node(T t = T(), node<T> *p = nullptr, node<T> *n = nullptr) : data(t), prev(p), next(n) {}
};
template <class T>
class DoubleLinkedList
{
protected:
    node<T> *head;
    node<T> *tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    void print()
    {
        node<T> *current = new node<T>();
        current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
    // void addFirst(const T &newvalue)
    // {
    //     node<T> *new_node = new node<T>(newvalue);
    //     if (head == nullptr && tail == nullptr)
    //     {
    //         head = new_node;
    //         tail = new_node;
    //     }
    //     else
    //     {
    //         new_node->next = head;
    //         head->prev = new_node;
    //         head = new_node;
    //     }
    //     size++;
    // }
    void addFirst(const T &newvalue)
    {
        node<T> *new_node = new node<T>(newvalue);
        if (tail == nullptr && head == nullptr)
        {
            tail = head = new_node;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        size++;
    }
    void addLast(const T &newvalue)
    {
        node<T> *new_node = new node<T>(newvalue);
        if (head == nullptr && tail == nullptr)
        {
            addFirst(newvalue);
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }
   
    void insert(const T &new_value, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (position == size)
        {
            addLast(new_value);
            return;
        }
        if (position == 0)
        {
            addFirst(new_value);
            return;
        }
        node<T> *new_node = new node<T>(new_value);
        node<T> *current_node = head;
        int count = 0;
        while (count < position - 1)
        {
            current_node = current_node->next;
            count++;
        }
        node<T> *current_node2 = current_node->next;

        current_node->next = new_node;
        new_node->prev = current_node;

        new_node->next = current_node2;
        current_node2->prev = new_node;

        size++;
    }
    // void insert(const T &newvalue, int position)
    // {
    //     position--;
    //     if (position < 0 || position > size)
    //     {
    //         cout << "Invaild Positon" << endl;
    //         return;
    //     }
    //     if (position == 0)
    //     {
    //         addFirst(newvalue);
    //         return;
    //     }
    //     if (position == size)
    //     {
    //         addLast(newvalue);
    //         return;
    //     }
    //     node<T> *new_node = new node<T>(newvalue);
    //     node<T> *current = head;
    //     node<T> *current2 = new node<T>();
    //     int count = 0;
    //     while (count < position - 1)
    //     {
    //         current = current->next;
    //         count++;
    //     }
    //     // step 1;
    //     current2 = current->next;
    //     // step 2;
    //     current->next = new_node;
    //     new_node->prev = current;
    //     // step 3;
    //     current2->prev = new_node;
    //     new_node->next = current2;

    //     size++;
    // }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        node<T> *node_delete = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev == nullptr;
        }
        delete node_delete;
        size--;
    }
    void deleteLast()
    {
        // step1
        if (tail == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        node<T> *node_delete = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        delete node_delete;
        size--;
    }
    void deleteAtIndex(int position)
    {
        position--;
        if (position < 0 || position >= size)
        {
            cout << "Invaild Postion " << endl;
            return;
        }
        // cout<<size<<endl;
        if (position == size - 1)
        {
            deleteLast();
            return;
        }
        if (position == 0)
        {
            deleteFirst();
            return;
        }
        // node<T> * node_delete=new node<T> ();
        node<T> *current_node = head;
        node<T> *current_node2 = new node<T>();

        // step 1
        for (int i = 0; i < position; i++)
        {
            current_node = current_node->next;
        }
        // step 2
        current_node->next->prev = current_node->prev;
        current_node->prev->next = current_node->next;
        // step 3
        current_node2 = current_node;
        delete current_node2;
        size--;
    }
    void removeKey(const T &t)
    {
        node<T> *current = new node<T>();
        current = head;
        for (int i = 0; current != nullptr; current = current->next)
        {
            if (current->data == t)
            {
                //    cout<< "i"<<i<<endl;
                deleteAtIndex(i + 1);
                break;
            }
        }
    }
    void replace(int index_delete, const T &t)
    {
        index_delete--;
        node<T> *current_node = new node<T>();
        current_node = head;
        for (int i = 0; i < index_delete; i++)
        {
            current_node = current_node->next;
        }
        current_node->data = t;
    }
    void replaceKey(const T &t, const T &t1)
    {
        node<T> *current_node = new node<T>();
        current_node = head;
        for (int i = 0; current_node != nullptr; current_node = current_node->next)
        {
            if (current_node->data == t)
            {
                current_node->data = t1;
            }
        };
    }
void add(const T& value) {
    node<T>* newnode = new node<T> { value, nullptr, nullptr };

    if (head == nullptr) {
        head = tail = newnode;
    }
    else if (value % 2 == 0) {
        node<T>* current = head;
        while (current != nullptr && current->data % 2 == 0 && current->data < value) {
            current = current->next;
        }
        if (current == head) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else if (current == nullptr) {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        else {
            newnode->prev = current->prev;
            newnode->next = current;
            current->prev->next = newnode;
            current->prev = newnode;
        }
    }
    else {
        node<T>* current = tail;
        while (current != nullptr && current->data % 2 != 0 && current->data > value) {
            current = current->prev;
        }
        if (current == tail) {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        else if (current == nullptr) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else {
            newnode->prev = current;
            newnode->next = current->next;
            current->next->prev = newnode;
            current->next = newnode;
        }
    }

    size++;
}
    
    const DoubleLinkedList<T> &operator=(const DoubleLinkedList<T> &DoubleLinkedList2)
    {
        node<T> *current_node = head;
        current_node = DoubleLinkedList2.head;
        for (int i = 0; current_node != nullptr; current_node = current_node->next)
        {
            // addLast()
            addLast(current_node->data);
        }
        return *this;
    }

    // the copy constructor
    DoubleLinkedList(const DoubleLinkedList &DoubleLinkedList2) : head(nullptr), tail(nullptr), size(0)
    {
        node<T> *current_node = DoubleLinkedList2.head;
        for (int i = 0; current_node != nullptr; current_node = current_node->next)
        {
            addLast(current_node->data);
        }
    }
    void insertSorted(const T &newvalue)
    {
        node<T> *new_node = new node<T>(newvalue);
        node<T> *current = head;

        // Trường hợp danh sách rỗng
        if (head == nullptr && tail == nullptr)
        {
            addFirst(newvalue);
            return;
        }

        // Trường hợp thêm vào đầu danh sách
        if (newvalue < head->data)
        {
            addFirst(newvalue);
            return;
        }

        // Trong các trường hợp còn lại, duyệt danh sách
        while (current != nullptr && current->data < newvalue)
        {
            current = current->next;
        }

        // Trường hợp thêm vào cuối danh sách
        if (current == nullptr)
        {
            addLast(newvalue);
            return;
        }

        // Thêm vào trước node current
        node<T> *prev_node = current->prev;
        prev_node->next = new_node;
        new_node->prev = prev_node;
        new_node->next = current;
        current->prev = new_node;

        size++;
    }

 
};

int main()
{
    DoubleLinkedList<int> list;
    // DoubleLinkedList<int> list2=list;
    // list.addFirst(1);
    // list.addFirst(2);
    // list.addFirst(1);
    // list.addFirst(8);
    // list.addLast(4);
    // list.insert(7, 5);
list.add(1); 

list.add(4);
list.add(5);
list.add(8);
list.add(2);
list.add(3);
list.add(6);
list.add(9);

    // list.deleteFirst();
    // list.deleteLast();
    //    list.deleteAtIndex(4);
    // list.removeKey(2);
    // list.replace(4,9);
    // list.replaceKey(1,6);
    list.print();
    // list2=list;
    DoubleLinkedList<int> list2 = list;
    list2.print();
}
// https://github.com/OSSpk/Doubly-and-Singly-Linked-List/blob/master/Doubly%20Linked%20List%20(with%20HEAD%20and%20TAIL).cpp