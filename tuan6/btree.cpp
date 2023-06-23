#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T t = T()) : data(t),left(nullptr), right(nullptr){};
};
int compare(int a, int b){
    if (a%2!=b%2){
        return a%2< b%2;
    }
    return a<b;
}
template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    void inOrder_print(Node<T> *root)
    {
        if (root != nullptr)
        {
            inOrder_print(root->left);
            cout << root->data << endl;
            inOrder_print(root->right);
        }
    }
    Node<T>* searchKey(Node<T> * root,T key){
        if(root==nullptr || root->data=key){
            return root;
        }
        else{
            if(compare(key,root->data)){
                searchKey(root->left,key);
            }
            else{
                searchKey(root->right,key);
            }
        }
    }
    Node<T> * removeKey(Node<T> *root,T key){
        if(root==nullptr){
            return root;
        }
        else if(compare(key,root->data)){
            root->left=removeKey(root->left,key);
        }
        else if(compare(root->data,key)){
            root->right=removeKey(root->right,key);
        }
        else{
            if(root->left==nullptr){
                Node<T> *temp=root->right;
                delete root;
                return temp;
            }else if(root->right==nullptr){
                Node<T> * temp=root->left;
                delete root;
                return temp;
            }
            Node<T> *temp=minNode(root->right);
            root->data=temp->data;
            root->right=removeKey(root->right,temp->data);
        }
    };
    Node<T> * minNode(Node<T> * root){
        Node<T> *current=root;
        while(current!=nullptr && current->left!=nullptr){
            current=current->left;
        } 
        return current;
    }
    // void addRec1(Node<T> * & root,T value )
    void addRec1(Node<T> *&root, T value)
    {
       if (root == nullptr) {
            root = new Node<T>(value);
        } else if (compare(value, root->data)) {
            addRec1(root->left, value);
        } else {
            addRec1(root->right, value);
        }
    }
    bool isInternal1(Node<T>* root){
        return (root->left!=nullptr || root->right!=nullptr) ? true: false;
    }
    int countInternal(Node<T> * root){
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
            return 0;
        }
        int left=countInternal(root->left);
        int right=countInternal(root->right);
        return left+right+1;
    };
    
    // void copy(Node<T> * &a ,Node<T> * b){
    //     if(b==nullptr){
    //         a=nullptr;
    //     }else{
    //         a=new Node<T>(b->data);
    //         copy(a->left,a->left);
    //         copy(a->right,b->right);
    //     }
    // }
    void copy(Node<T> * &a,Node<T> *b){
        if(a==nullptr){
            a=nullptr;
        }
        else{
            a=new Node<T>(b->data);
            copy(a->left,b->left);
            copy(a->right,b->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        makeEmpty(root);
    }
    BinaryTree(const BinaryTree &other):root(nullptr){
        copy(root,other.root);
    } 
    BinaryTree& operator=(const BinaryTree &other){
        if(this!=&other){
            makeEmpty(root);
            copy(root,other.root);
        } 
        return * this;
    }
    void makeEmpty(Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
    bool isInternal(){
        return isInternal1(root);
    }
    void addRec(T value)
    {
        addRec1(root, value);
    }
    void inOrder()
    {
        inOrder_print(root);
    }
    void removeKey(T key){
        root=removeKey(root,key);
    }
};
int main()
{

    BinaryTree<int> tree;
    tree.addRec(5);
    tree.addRec(6);
    tree.addRec(7);
    tree.addRec(8);
    tree.addRec(9);
    tree.addRec(10);
    tree.inOrder();
    cout<<endl;
    tree.removeKey(8);
    tree.inOrder(); //

    // BinaryTree<int> tree2(tree); // sử dụng hàm copy constructor
    // tree2.inOrder();

    // BinaryTree<int> tree3;
    // tree3 = tree; // sử dụng toán tử gán bằng
    // tree3.inOrder();
    return 0;
}