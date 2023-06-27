#include<iostream>
using namespace std;
template<typename T>
struct Node{
    T data;
    Node<T> * left;
    Node<T> * right;
    Node(T t=T()):data(t),left(nullptr),right(nullptr){};
};
int compare(int a,int b){
    if(a%2!=b%2){
        return a%2<b%2;
    }
    return a<b;
}
template<typename T>
class BST{ 
    private : 
            Node<T> * root;
            void copy(Node<T> * &a ,Node<T> *b){
                if(b==nullptr){
                    a=nullptr;
                }
                else{
                    a=new Node<T>(b->data);
                    copy(a->left,b->left);
                    copy(a->right,b->right);
                }
            }
            void inOrder_print(Node<T> * root){
                if(root!=nullptr){
                    inOrder_print(root->left);
                    cout<<root->data<<endl;
                    inOrder_print(root->right);
                }
            }
            void makeEmpty(Node<T> * root){
               if(root==nullptr) 
               {
                   return ;
               }
               else{
                   makeEmpty(root->left);
                   makeEmpty(root->right);
                   delete root;
               }
            }
            int coutInternal(Node<T> * root){
                if(root==nullptr || (root->left==nullptr && root->right==nullptr))
                {
                    return 0;
                }
            return 1+coutInternal(root->left)+coutInternal(root->right);
            }
            int coutLeaves(Node<T> *root){
                if(root==nullptr){
                    return 0;
                }
                else if(root->left==nullptr && root->right==nullptr){
                    return 1;
                }
                return coutLeaves(root->left)+coutInternal(root->right);
            }
           int height(Node<T> * root){
               if (root==nullptr){
                   return 0;
               }
               return max(height(root->left),height(root->right)) +1;
           } 
           void addRec1(Node<T> * &root,T value){
               Node<T> * new_node=new Node<T>(value);
               if(root==nullptr){
                    root=new_node;
               }
               else if(compare(root->data,value)){
                   addRec1(root->left,value);
               }
               else {
                   addRec1(root->right,value);
               }
           }
           Node<T> * removeKey1(Node<T> * root,T key){
               if(root==nullptr )
               {
                return root;
               }
                else if(compare(root->data,key)){
                    root->left=removeKey1(root->left,key);
                }
                else if( compare(key, root->data)){
                    root->right=removeKey1(root->right,key);
                }
                else{
                    if(root->left==nullptr){
                        Node<T> * temp=root->right;
                        delete root;
                        return temp;
                    }
                    else if(root->right==nullptr){
                        Node<T> * temp=root->left;
                        delete root;
                        return temp;
                    }
                    Node<T> *temp=findMin(root->right);
                    root->data=temp->data;
                    root->right=removeKey1(root->right,temp->data);
                }
                return root;
           }
           Node<T> * findMin(Node<T> *node){
                   Node<T> * current=node;
               if(node!=nullptr){
                   while(current!=nullptr && current->left!=nullptr){
                       current=current->left;
                   }
               }
               return current;
           }
    public:
            BST():root(nullptr){};
            ~BST(){
                makeEmpty(root);
            };
            BST(const BST &other):root(nullptr){
                copy(root,other.root);
            };
            BST & operator =(const BST & other){
                if(this!=&other){
                    makeEmpty(root);
                    copy(root,other.root); 
                }
            }
            void addRec(T value){
                addRec1(root,value);
            };
            void removeKey(T value){
                removeKey1(root,value);
            }
            void inOrder(){
                inOrder_print(root);
            }
            int getHeight(){
                return height(root);
            }
            int countInternal(){
                return coutInternal(root);
            }
            int coutnLeave(){
                return coutLeaves(root);
            }
};
int main (){
 BST<int> tree;
    tree.addRec(5);
    tree.addRec(6);
    tree.addRec(7);
    tree.addRec(8);
    tree.addRec(9);
    tree.addRec(10);
    tree.inOrder(); // in ra: 5 6 7 8 9 10
    cout << endl;
    // BinaryTree<int> tree2(tree); // sử dụng hàm copy constructor
    // tree2.inOrder(); // in ra: 5 6 7 8 9 10

    // BinaryTree<int> tree3;
    // tree3 = tree; // sử dụng toán tử gán bằng
    // tree3.inOrder(); // in ra: 5 6 7 8 9 10

    // Node<int>* node = tree.searchKey1(8);
    // if (node != nullptr) {
    //     cout << "Node with value " << node->data << " found" << endl; // in ra: Node with value 8 found
    // } else {
    //     cout << "Node not found" << endl;
    // }

    tree.removeKey(8);
    tree.inOrder(); // in ra: 5 6 7 9 10

    // Node<int> *node = tree.searchKey1(6);
    // if (node != nullptr)
    // {
    //     cout << "Node with value " << node->data << " found" << endl;
    // }
    // else
    // {
    //     cout << "Node not found" << endl; // in ra: Node not found
    // }
    BST<int> tree2(tree);
    tree2.inOrder();

    return 0;
}