#include<iostream>
using namespace std;
template<typename T> 
struct Node{
    T data;
    Node<T> * next;
    Node<T> * prev;
    Node(val): T(val) , left(nullptr),right(nullptr) {};
}
template<typename T> 
class DoubleLinkedList{
    private: 
            Node<T> * root;
    public:
        DoubleLinkedList(root=nullptr) {};
        ~DoubleLinkedList(){};
        void add(T value){
            Node<T> * new_node=new Node<T>(val);
            if(head==nullptr){
                head=tail=new_node;
            }
            else if(a%2==0){
            Node<T> * current =head;
                while(current!=nullptr && compare(current->data,value)){
                    current=current->next;
                }
                if(current==head){
                    new_node->next=head;
                    head->pre=new_node;
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
                    currrent=current->prev;
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
}
int main (){

}