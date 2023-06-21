#include<iostream>
using namespace std;
template<typename T> 
struct Node{
    T data;
    Node<T> * next;
    Node<T> * prev;
    Node(T val): data(val) , next(nullptr),prev(nullptr) {}
};
bool compare3(int a,int b){
    if(a%3!=b%3){
        return a%3<b%3;
    }
    return a<b;
}
bool compare(int a, int b){
    if(a%2!=b%2){
        return a%2<b%2;
    }
    return a<b;
}
template<typename T> 
class DoubleLinkedList{
    private: 
            Node<T> * head;
            Node<T> * tail;
            int size;
    public:
        DoubleLinkedList():head(nullptr),tail(nullptr),size(0) {};
        ~DoubleLinkedList(){};
        void print(){
            Node<T> * current=head;
            while(current!=nullptr){
                cout<<current->data;
                current=current->next;
            }
            cout<<endl;
        }
        void add(T value){
            Node<T> * new_node=new Node<T>(value);
            if(head==nullptr){
                head=tail=new_node;
            }
            else if(value%2==0){
            Node<T> * current =head;
                while(current!=nullptr && compare(current->data,value)){
                    current=current->next;
                }
                if(current==head){
                    new_node->next=head;
                    head->prev=new_node;
                    head=new_node;
                }
               else if(current==nullptr){
                    new_node->prev=tail;
                    tail->next=new_node;
                    tail=new_node;
                }
                else{

                }
            }
            else{
                Node<T> * current=tail;
                while(current!=nullptr && compare(value,current->data)){
                    current=current->prev;
                }
                if(current==tail){
                    new_node->prev=tail;
                    tail->next=new_node;
                    tail=new_node;
                }
                else if(current=nullptr){
                    new_node->next=head;
                    head->prev=new_node;
                    head=new_node;
                }
                else{
                    new_node->prev=current;
                    new_node->next=current->next;
                    current->next=new_node;
                    current->next->prev=new_node;
                }
            }
        }
void add3(T value){
    Node<T> * new_node=new Node<T>(value);
    if(head==nullptr) {
        head= tail = new_node;
    }
    else if(value %3==2){
        Node<T> * current= head;
        while( current !=nullptr && compare3(value,current->data)){
            current=current->next;
        }
        if(current==head){
                new_node->next=head;
                head->prev=new_node;
                head=new_node;
        }
        else if(current==nullptr){
            new_node->prev=tail;
            tail->next=new_node;
            tail=new_node;
        }
        else {
            new_node->next=current;
            new_node->prev=current->prev;
            current->prev->next=new_node;
            current->prev=new_node;
        }
    }
    else if(value%3 ==1){
        Node<T> * current=tail;
        while(current!=nullptr && compare3(current->data,value)){
            current=current->prev;
        }
        if(current==tail){
            new_node->prev=tail;
            tail->next=new_node;
            tail=new_node;
        }
        else if(current==nullptr){
            new_node->next=head;
            head->prev=new_node;
            head=new_node;
        }
        else{
            new_node->prev=current;
            new_node->next=current->next;
            current->next=new_node;
            current->next->prev=new_node;
        }
    }
    else{
        Node<T> * current=tail;
        while(current!= nullptr && compare3(current->data,value)){
            current=current->prev;
        }
        if(current=tail){
            new_node->prev=tail;
            tail->next=new_node;
            tail=new_node;
        }
        else if(current==nullptr){
            new_node ->next=head;
            head->prev=new_node;
            head=new_node;
        }
        else{
            new_node->prev=current;
            new_node->next=current->next;
            current->next=new_node;
            current->next->prev=new_node;
        }
    }

   size++; 
}
};
int main (){
  DoubleLinkedList<int> list;
    // DoubleLinkedList<int> list2=list;
    // list.addFirst(1);
    // list.addFirst(2);
    // list.addFirst(1);
    // list.addFirst(8);
    // list.addLast(4);
    // list.insert(7, 5);
list.add3(9); 

list.add3(4);
list.add3(1);
list.add3(7);
list.add3(3);
list.add3(6);
list.add3(8);
list.add3(2);
list.add3(5);

    // list.deleteFirst();
    // list.deleteLast();
    //    list.deleteAtIndex(4);
    // list.removeKey(2);
    // list.replace(4,9);
    // list.replaceKey(1,6);
    list.print();
}