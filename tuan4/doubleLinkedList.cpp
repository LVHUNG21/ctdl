#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
    Node(T t = T(), Node<T> *p = nullptr, Node<T> *n = nullptr) : data(t), prev(p), next(n) {}
};
template <class T>
class DoubleLinkedList
{
protected:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    void print()
    {
        Node<T> *current = new Node<T>();
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
    //     Node<T> *new_node = new Node<T>(newvalue);
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
    void addFirst(const T$ newvalue){
        Node<T> * new_node=new Node<T>(newvalue);
        if(tail==nullptr && head ==nullptr){
                tail=head=new_node;
        }else{
            head->prev=new_node;
            new_node->next=head;
            head=new_node;
        }
        size++
    }
    void addLast(const T &newvalue)
    {
        Node<T> *new_node = new Node<T>(newvalue);
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
    void insert(const T& new_value,int position){
        if(position<0 || position >size){
            cout<<"Invaild Position"<<endl;
        }
        if(position==size){
            addLast(new_value);
            return;
        }
        if(position==0){
            addFirst(new_value);
            return;
        }
        Node<T> * new_node=new Node<T>(new_value);
        Node<T> * current_node=head;
        Node<T> * current_node2=new Node<T>();
        int count=0;
        while(current_node<position-1){
            current_node=current_node->next;
            count++;
        }
        current_node2=current_node->next;

        current_node->next=new_node;
        new_node->prev=current_node;

        current_node2->prev=new_node;
        new_node->next=current_node2;

        size++


    }
    void insert(const T &newvalue, int position)
    {
        position--;
        if (position < 0 || position > size)
        {
            cout << "Invaild Positon" << endl;
            return;
        }
        if (position == 0)
        {
            addFirst(newvalue);
            return;
        }
        if (position == size)
        {
            addLast(newvalue);
            return;
        }
        Node<T> *new_node = new Node<T>(newvalue);
        Node<T> *current = head;
        Node<T> *current2 = new Node<T>();
        int count = 0;
        while (count < position - 1)
        {
            current = current->next;
            count++;
        }
        // step 1;
        current2 = current->next;
        // step 2;
        current->next = new_node;
        new_node->prev = current;
        // step 3;
        current2->prev = new_node;
        new_node->next = current2;

        size++;
    }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<T> *node_delete = head;
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
        Node<T> *node_delete = tail;
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
        if (position == size-1)
        {
            deleteLast();
            return;
        }
        if (position == 0)
        {
            deleteFirst();
            return;
        }
        // Node<T> * node_delete=new Node<T> ();
        Node<T> *current_node = head;
        Node<T> *current_node2 = new Node<T>();

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
    void removeKey(const T & t){
           Node<T> * current=new Node<T>();
           current=head;
           for(int i=0 ; current!=nullptr;current=current->next){
               if(current->data == t){
                //    cout<< "i"<<i<<endl;
                   deleteAtIndex(i+1);
                   break;
               }
           }
    }
    void replace(int index_delete,const T& t){
        index_delete--;
        Node<T> * current_node=new Node<T>();
        current_node=head;
        for(int i=0 ;i<index_delete;i++){
            current_node=current_node->next;
        }
        current_node->data=t;
    }
    void replaceKey(const T &t,const T &t1){
        Node<T> * current_node= new Node<T>();
        current_node=head;
        for(int i=0;current_node!=nullptr;current_node=current_node->next){
                    if(current_node->data==t){
                        current_node->data=t1;
                    }     
        };
        
    }
    const DoubleLinkedList<T> & operator=(const DoubleLinkedList<T> &DoubleLinkedList2){
        Node<T> * current_node=head;
        current_node=DoubleLinkedList2.head;
        for(int i=0;current_node!=nullptr;current_node=current_node->next){
            // addLast()
            addLast(current_node->data);
        }
        return *this;
    }

    //the copy constructor
    DoubleLinkedList(const DoubleLinkedList & DoubleLinkedList2):head (nullptr),tail(nullptr),size(0){
        Node<T> * current_node=DoubleLinkedList2.head;
    for(int i=0;current_node!=nullptr;current_node=current_node->next){
            addLast(current_node->data);
        }
    }
    void insertSorted(const T &newvalue)
{
    Node<T> *new_node = new Node<T>(newvalue);
    Node<T> *current = head;

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
    Node<T> *prev_node = current->prev;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    new_node->next = current;
    current->prev = new_node;

    size++;
}

    // void insert(const T& newvalue, int position)
    // {
    //     // position=position+1;
    //     position--;
    //     if (position < 0 || position > size) {
    //         cout << "Invalid position.\n";
    //         return;
    //     }

    //     if (position == 0) {
    //         addFirst(newvalue);
    //         return;
    //     }

    //     if (position == size) {
    //         addLast(newvalue);
    //         return;
    //     }

    //     Node<T>* new_node = new Node<T>(newvalue);
    //     Node<T>* current = head;

    //     for (int i = 0; i < position - 1; i++) {
    //         current = current->next;
    //     }

    //     Node<T>* next_node = current->next;

    //     new_node->prev = current;
    //     new_node->next = next_node;

    //     current->next = new_node;
    //     next_node->prev = new_node;

    //     size++;
    // }
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
    // list.insert(7,0);
    li
    // list.deleteFirst();
    // list.deleteLast();
//    list.deleteAtIndex(4);
    // list.removeKey(2);
    // list.replace(4,9);
    list.replaceKey(1,6);
    list.print();
    // list2=list;
    DoubleLinkedList<int> list2=list;
    list2.print();
}
// https://github.com/OSSpk/Doubly-and-Singly-Linked-List/blob/master/Doubly%20Linked%20List%20(with%20HEAD%20and%20TAIL).cpp