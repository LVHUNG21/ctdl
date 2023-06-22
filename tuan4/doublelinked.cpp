#include<iostream>
using namespace std;

template<typename T> 
struct Node{
    T data;
    Node<T> * next;
    Node<T> * prev;
    Node(T t=T()): data(t) , next(nullptr),prev(nullptr) {}
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
            Node<T> * current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void deleteFirst(){
            if (head == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            Node<T> *node_delete = head;
            head = head->next;
            if (head != nullptr){
                head->prev == nullptr;
            }
            delete node_delete;
            size--;
        }

        void deleteLast(){
            if (tail == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            Node<T> *node_delete = tail;
            tail = tail->prev;
            if (tail != nullptr){
                tail->next = nullptr;
            }
            delete node_delete;
            size--;
        }

        void deleteAtIndex(int position){
            if (position < 0 || position >= size){
                cout << "Invalid Postion " << endl;
                return;
            }

            if (position == size - 1){
                deleteLast();
                return;
            }

            if (position == 0){
                deleteFirst();
                return;
            }

            Node<T> *current_node = head;

            // step 1
            for (int i = 0; i < position; i++){
                current_node = current_node->next;
            }

            // step 2
            current_node->next->prev = current_node->prev;
            current_node->prev->next = current_node->next;

            // step 3
            delete current_node;
            size--;
        }

     void removeKey(T key) {
    if (head == nullptr) {
        cout << "DL rong" << endl;
        return;
    }

    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            if (current == head && current == tail) {
                // If there is only one node
                head = tail = nullptr;
            }
            else if (current == head) {
                // If the node to be removed is the head node
                head = current->next;
                head->prev = nullptr;
            }
            else if (current == tail) {
                // If the node to be removed is the tail node
                tail = current->prev;
                tail->next = nullptr;
            }
            else {
                // If the node to be removed is in the middle
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            // Delete the node
            Node<T>* temp = current;
            current = current->next; // update current before deleting temp
            delete temp;

            size--;
        }
        else {
            current = current->next;
        }
    }

    if (size == 0) {
        head = tail = nullptr;
    }
}
        void add(T value){
            Node<T> * new_node = new Node<T>(value);

            if (head == nullptr){
                head = tail = new_node;
            }
            else if (value % 2 == 0){
                Node<T> * current = head;
                while (current != nullptr && compare(current->data, value)){
                    current = current->next;
                }
                if (current == head){
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                }
                else if (current == nullptr){
                    new_node->prev = tail;
                    tail->next = new_node;
                    tail = new_node;
                }
                else{
                    new_node->prev = current->prev;
                    new_node->next = current;
                    current->prev->next = new_node;
                    current->prev = new_node;
                }
            }
            else{
                Node<T> * current = tail;
                while (current != nullptr && compare(value, current->data)){
                    current = current->prev;
                }
                if (current == tail){
                    new_node->prev = tail;
                    tail->next = new_node;
                    tail = new_node;
                }
                else if (current == nullptr){
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                }
                else{
                    new_node->prev = current;
                    new_node->next = current->next;
                    current->next->prev = new_node;
                    current->next = new_node;
                }
            }

            size++; 
        }

        void add3(T value ){
            Node<T> * new_node=new Node<T>(value);
            if(head==nullptr){
                head=tail=new_node;
            }else{
                Node<T>  * current=head;
                while(current!=nullptr && compare3(current->data,value)){
                    current=current->next;                    
                }
                if(current==head){
                    new_node->next=head;
                    head->prev=new_node;
                    head=new_node;
                }
                if(current==nullptr){
                new_node->prev=tail;
                tail->next=new_node;
                tail=new_node;

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

        // void add3(T value){
        //     Node<T> * new_node = new Node<T>(value);

        //     if (head == nullptr){
        //         head = tail = new_node;
        //     }
        //     else{
        //         Node<T> * current = head;
        //         while (current != nullptr && compare3(value, current->data)){
        //             current = current->next;
        //         }
        //         if (current == head){
        //             new_node->next = head;
        //             head->prev = new_node;
        //             head = new_node;
        //         }
        //         else if (current == nullptr){
        //             new_node->prev = tail;
        //             tail->next = new_node;
        //             tail = new_node;
        //         }
        //         else{
        //             new_node->prev = current->prev;
        //             new_node->next = current;
        //             current->prev->next = new_node;
        //             current->prev = new_node;
        //         }
        //     }

        //     size++; 
        // };
//         void add3(T value){
//     Node<T> * new_node=new Node<T>(value);
//     if(head==nullptr) {
//         head= tail = new_node;
//     }
//     else if(value %3==2){
//         Node<T> * current= head;
//         while( current !=nullptr && compare3(value,current->data)){
//             current=current->next;
//         }
//         if(current==head){
//                 new_node->next=head;
//                 head->prev=new_node;
//                 head=new_node;
//         }
//         else if(current==nullptr){
//             new_node->prev=tail;
//             tail->next=new_node;
//             tail=new_node;
//         }
//         else {
//             new_node->next=current;
//             new_node->prev=current->prev;
//             current->prev->next=new_node;
//             current->prev=new_node;
//         }
       
//     }
//     else if(value%3 ==1){
//         Node<T> * current=tail;
//         while(current!=nullptr && compare3(current->data,value)){
//             current=current->prev;
//         }
//         if(current==tail){
//             new_node->prev=tail;
//             tail->next=new_node;
//             tail=new_node;
//         }
//         else if(current==nullptr){
//             new_node->next=head;
//             head->prev=new_node;
//             head=new_node;
//         }
//         else{
//             new_node->prev=current;
//             new_node->next=current->next;
//             current->next=new_node;
//             current->next->prev=new_node;
//         }
//     }
//     else{
//         Node<T> * current=tail;
//         while(current!= nullptr && compare3(current->data,value)){
//             current=current->prev;
//         }
//         if(current=tail){
//             new_node->prev=tail;
//             tail->next=new_node;
//             tail=new_node;
//         }
//         else if(current==nullptr){
//             new_node ->next=head;
//             head->prev=new_node;
//             head=new_node;
//         }
//         else{
//             new_node->prev=current;
//             new_node->next=current->next;
//             current->next=new_node;
//             current->next->prev=new_node;
//         }
//     }
//     delete current;

//    size++; 
// }

        void clear(){
            while(head != nullptr){
                Node<T> *current_node = head;
                head = head->next;
                delete current_node;
            }
            tail = nullptr;
            size = 0;
        }

        int getSize(){
            return size;
        }
};

int main(){
    DoubleLinkedList<int> list;
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

    cout << "Original List: ";
    list.print();

    // list.add3(6);
    // cout << "List after adding 6: ";
    // list.print();

    // list.deleteFirst();
    // cout << "List after deleting first element: ";
    // list.print();

    // list.deleteLast();
    // cout << "List after deleting last element: ";
    // list.print();

    // list.deleteAtIndex(2);
    // cout << "List after deleting element at index 2: ";
    // list.print();

    list.removeKey(9);
    list.removeKey(7);
    cout << "List after removing key : ";
    list.print();

    list.clear();
    cout << "List after clearing: ";
    list.print();

    return 0;
}