#include <iostream>
using namespace std;

template<typename T> 
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T val) : data(val), left(nullptr), right(nullptr) {}
    // Node(T val ): data(val),left(nullptr),right(nullptr){}
};
// int compare(int a , int b){
//     if(a%2!=b%2) return a%2<b%2;
//     return a<b;
// }
template<typename T>
class BinaryTree
{
private:
    Node<T> *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    Node<T> *makeEmpty(Node<T> *t)
    {
        if (t == nullptr)
            return nullptr;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return nullptr;
    }

    ~BinaryTree()
    {
        root = makeEmpty(root);
    }

    void addRec(Node<T> *&root, T &e)
    {
        if (root == nullptr)
        {
            root = new Node<T>(e);
            return;
        }
        else if (root->data % 2 == e % 2)
        {
            if (root->data > e)
            {
                addRec(root->left, e);
            }
            else
            {
                addRec(root->right, e);
            }
        }
        else if (e % 2 == 0)
        {
            addRec(root->left, e);
        }
        else
        {
            addRec(root->right, e);
        }
    }
    // void addRec(Node<T> *root,T value){
    //     if(root==nullptr){
    //         root=new Node<T> (value);
    //     }
    //     else if(root->data %2== value %2){
    //         if(root->data > value){
    //             addRec(root->right,value);
    //         }else{
    //             addRec(root->left,value);
    //         }
    //     }
    //     else if(value %2==0){
    //         addRec(root->left,value);

    //     }
    //     else{
    //         addRec(root->right,value);
    //     }
    // }

    void inOrder_print(Node<T> *current_node)
    {
        if (current_node != nullptr)
        {
            inOrder_print(current_node->left);
            // if(current_node->data %3==2){
            cout << current_node->data << ",";
            // }
            inOrder_print(current_node->right);
        }
    }
    void addRec1(T e)
    {
        addRec(root, e);
    }
    void inOrder_print()
    {
        inOrder_print(root);
        cout << "*";
    }
};
int main()
{
    BinaryTree<int> tree;
    tree.addRec1(5);
    tree.addRec1(6);
    tree.addRec1(7);
    tree.addRec1(8);
    tree.addRec1(9);
    tree.addRec1(10);
    tree.inOrder_print();
    return 0;
}