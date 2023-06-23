#include<iostream>
using namespace std;
template<typename T>
struct Node{
    T data;
    Node<T> * next;
    Node<T> * prev;
    Node(T t=T()):data(t),next(nullptr),prev(nullptr){};
};
int compare(int a, int b){
    if(a%2!=b%2){
        return a%2<b%2;
    }
    return a<b;
};
template<typename T> 
class DL{
    private: 
            Node<T> *head;
            Node<T> *tail;
            int size;
    public:
           DL():head(nullptr),tail(nullptr),size(0){};
           ~DL(){
           }
           void add3(T value){
            Node<T> * new_node=new Node<T>(value);
            if(head==nullptr){
                head=tail=new_node;
            }
            else{
                Node<T> * current=head;
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
                else {
                    new_node->prev=current->prev;
                    new_node->next=current;
                    current->prev->next=new_node;
                    current->prev=new_node;
                }
            }
            size++;
           }
           void removeKey(T key){
            if(head==nullptr){
                cout<<"DL rong"<<endl;
                return;
            }else {
                Node<T>* current=head;
            while(current!=nullptr){
                    if(current->data==key){
                        if(current==head && current==tail){
                            head=tail=nullptr;
                        }
                        if(current==head){
                            head=head->next;
                            head->prev=nullptr;
                        }
                        else if(current==tail){
                            tail=tail->prev;
                            tail->next=nullptr;
                        }
                        else{
                            current->next->prev=current->prev;
                            current->prev->next=current->next;

                        }
                        Node<T> *temp=current;
                        current=current->next;
                        delete temp;
                        size--;
                    }
                    else{
                        current=current->next;
                    }
                }
            }
           }
           void print(){
                Node<T> * current=head;
            while(current!=nullptr){
                cout<<current->data;
                current=current->next;
            }
           }
            
};
int main(){
    DL<int> list;
    list.add3(9); 

list.add3(1);
list.add3(2);
list.add3(2);
list.add3(7);
list.add3(1);
list.add3(7);
list.add3(7);
list.add3(6);
list.add3(8);
list.add3(2);
list.add3(5);
list.add3(5);
list.removeKey(7);

    cout << "Original List: ";
    list.print();

}