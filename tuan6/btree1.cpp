#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T t = T()) : data(t), left(nullptr), right(nullptr){};
};
int compare(int a, int b)
{
    if (a % 2 != b % 2)
    {
        return a % 2 < b % 2;
    }
    return a < b;
}
template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
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
    void inOrder_print(Node<T> *root)
    {
        if (root != nullptr)
        {
            inOrder_print(root->left);
            cout << root->data << endl;
            inOrder_print(root->right);
        }
    }
    void addRecc(Node<T> *&root, T value)
    {
        if (root == nullptr)
        {
            root = new Node<T>(value);
        }
        else
        {
            if (compare(root->data, value))
            {
                addRecc(root->right, value);
            }
            else
            {
                addRecc(root->left, value);
            }
        }
    }
    void copy(Node<T> *&a, Node<T> *b)
    {
        if (b == nullptr)
        {
            a = nullptr;
        }
        else
        {
            copy(a->left, b->left);
            copy(b->right, b->right);
        }
    }
    Node<T> *searchKey(Node<T> *root, T key)
    {
        if (root == nullptr || root->data == key)
        {
            return root;
        }
        else if (compare(key, root->data))
        {
            return searchKey(root->left, key);
        }
        else
        {
            return searchKey(root->right, key);
        }
    }
    Node<T> *removeKey(Node<T> *root, T key)
    {
        if (root == nullptr)
        {
            return root;
        }
        else if (compare(key, root->data))
        {
            root->left = removeKey(root->left, key);
        }
        else if (compare(root->data, key))
        {
            root->right = removeKey(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node<T> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node<T> *temp = root->left;
                delete root;
                return temp;
            }
            Node<T> *temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeKey(root->right, temp->data);
        }
        return root;
    }
    Node<T> *findMin(Node<T> *node)
    {
        Node<T> *current = node;
        while (current != nullptr && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    };
    int countLeaves(Node<T> *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return countLeaves(root->left) + countLeaves(root->right);
    }

public:
    BinaryTree() : root(nullptr){};
    ~BinaryTree()
    {
        makeEmpty(root);
    }
    void addRec(T value)
    {
        addRecc(root, value);
    }
    BinaryTree(const BinaryTree *other) : root(nullptr)
    {
        copy(root, other.root);
    }
    BinaryTree &operator=(const BinaryTree *other)
    {
        if (this != &other)
        {
            makeEmpty(root);
            copy(root, other.root);
        }
        return *this;
    }
    void inOrder()
    {
        inOrder_print(root);
    };
    Node<T> *searchKey1(T key)
    {
        return searchKey(root, key);
    };
    Node<T> *removeKey1(T key)
    {
        return removeKey(root, key);
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

    tree.removeKey1(8);
    tree.inOrder(); // in ra: 5 6 7 9 10
    B
    return 0;
}