#include <iostream>
using namespace std;
template <class T>
struct Node
{
    const T &data;
    Node<T> *next;
    Node() : data(T()), next(NULL){}; // data() goi ham tạo mac dinh cua T;
    Node(const T &t, Node<T> *n) : data(t), next(n){};
};

template <class T>
class SingleList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    SingleList() : head(0), size(0){};
    void addFirst(const T &new_data)
    {
        Node<T> *new_node = new Node<T>(new_data, head);
        head = new_node;
        size++;
        // Node<T> * newNode =new Node<T>(e,head);
        // head=newNode;
        // size++
    }
    void addLast(const T &new_data)
    {

        Node<T> *new_node = new Node<T>(new_data);
      
        if (head == nullptr)
            addFirst(new_data);
        else
        {
            for (Node<T> *last = head; last->next != nullptr; last = last->next)
            {
                /* code */
                last = last->next;
            }
            last->next = newNode;
        }
        // new_node->data=new_data;
    }
    void addAfter(const T &t, Node<T> *node)
    {
        if (head == nullptr)
            addFirst(t);
        else
        {
            Node<T> *new_node = Node<T>(t, node->next);
            // node->next=new_node;
            node->next = new_node;
            // new_node=node->next;
        }
    }
    void print() const
    {
        Node<T> *p = new Node<T>;
        p = head;
        for (int i = 0; i < size; i++)
        {
            cout << p->data;
            p = p->next;
        }
        // for(Node<T>* p=head;p!=NULL;p=p->next){
        //     cout<<p->data<<"";
        // }
        // Node<T> * p2=head;
        // while(p2!=NULL){
        //     p2=p2->next;
        //     cout<<p2->data;
        // }
    }
    T deleteFirst()
    {
        if (!head) // ==nullptr
            throw "danhsach rong \n";
        Node<T> *old = head;
        const T &old_data = old->data;
        head = head->next;
        delete old;
        size--;
        return old_data;
    }
    T deleteLast(){
        if(head==NULL) throw "DAnhsach rong";
        if(head->next==nullptr) deleteFirst();
        Node<T> * last=head, *secondLast;
        secondLast=head;
          while (last->next!=nullptr)
        {
            secondLast=last;
            last=last->next;
        }
        Node<T> * oldLast=last;
        // tim nut lát va gioi phong bo nho 
        for()   
    }
    T getData()
    {
        return head->data;
    }
};
// 1. addFirst 2. addLast 3.addAfter 4. RemoveFirst 5. RemoveLast 6. Remove 7.getSize 8.search 9.printtt
int main()
{
    try
    {
        SingleList<string> list;
        list.addFirst("Rome");
        list.addFirst("hung");
        list.addFirst("sdfasdf");
        // cout<<list.getData();
        list.print();
        Node<T> *vien= ;
            list.print();
        cout << endl
             << "-------------------------------------------------------" << endl;
        cout << "phantubixoadila: " << list.deleteFirst() << endl;
        list.print();
    }
    catch (const char *e)
    {
        cout << e;
    }

    return 0;
}
