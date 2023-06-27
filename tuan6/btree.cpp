#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T t = T()) : data(t), left(nullptr), right(nullptr) {};
};

int compare(int a, int b)
{
    if (a % 2 != b % 2) {
        return a % 2 < b % 2;
    }
    return a < b;
}

template <typename T>
class BinaryTree
{
private:
    Node<T>* root;

    void inOrder_print(Node<T>* root)
    {
        if (root != nullptr) {
            inOrder_print(root->left);
            cout << root->data << " ";
            inOrder_print(root->right);
        }
    }

    Node<T>* searchKey(Node<T>* root, T key)
    {
        if (root == nullptr || root->data == key) {
            return root;
        }
        if (compare(key, root->data)) {
            return searchKey(root->left, key);
        }
        return searchKey(root->right, key);
    }

    Node<T>* removeKey(Node<T>* root, T key)
    {
        if (root == nullptr) {
            return root;
        }
        if (compare(key, root->data)) {
            root->left = removeKey(root->left, key);
        } else if (compare(root->data, key)) {
            root->right = removeKey(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            Node<T>* temp = minNode(root->right);
            root->data = temp->data;
            root->right = removeKey(root->right, temp->data);
        }
        return root;
    }

    Node<T>* minNode(Node<T>* root)
    {
        Node<T>* current = root;
        while (current != nullptr && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void addRec1(Node<T>*& root, T value)
    {
        if (root == nullptr) {
            root = new Node<T>(value);
        } else if (compare(value, root->data)) {
            addRec1(root->left, value);
        } else {
            addRec1(root->right, value);
        }
    }

    bool isInternal1(Node<T>* root)
    {
        return (root->left != nullptr || root->right != nullptr) ? true : false;
    }

    int countInternal(Node<T>* root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        int left = countInternal(root->left);
        int right = countInternal(root->right);
        return left + right + 1;
    }

    void copy(Node<T>*& a, Node<T>* b)
    {
        if (b == nullptr) {
            a = nullptr;
        } else {
            a = new Node<T>(b->data);
            copy(a->left, b->left);
            copy(a->right, b->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
        makeEmpty(root);
    }

    BinaryTree(const BinaryTree& other) : root(nullptr)
    {
        copy(root, other.root);
    }

    BinaryTree& operator=(const BinaryTree& other)
    {
        if (this != &other) {
            makeEmpty(root);
            copy(root, other.root);
        }
        return *this;
    }

    void makeEmpty(Node<T>* root)
    {
        if (root == nullptr) {
            return;
        }
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    bool isInternal()
    {
        return isInternal1(root);
    }

    int countInternal()
    {
        return countInternal(root);
    }

    void addRec(T value)
    {
        addRec1(root, value);
    }

    void inOrder()
    {
        inOrder_print(root);
    }

    bool searchKey(T key)
    {
        return searchKey(root, key) != nullptr;
    }

    void removeKey(T key)
    {
        root = removeKey(root, key);
    }

    void makeEmpty()
    {
        makeEmpty(Node<T>*& root)
    {
        makeEmpty(root);
        root = nullptr;
    }

    void printLevelOrder()
    {
        if (root == nullptr) {
            return;
        }
        queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node<T>* current = q.front();
                q.pop();
                cout << current->data << " ";
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            cout << endl;
        }
    }

    int height()
    {
        return height(root);
    }

    int height(Node<T>* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void printPaths()
    {
        vector<T> path;
        printPaths(root, path);
    }

    void printPaths(Node<T>* root, vector<T>& path)
    {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->data);
        if (root->left == nullptr && root->right == nullptr) {
            printPath(path);
        } else {
            printPaths(root->left, path);
            printPaths(root->right, path);
        }
        path.pop_back();
    }

    void printPath(vector<T>& path)
    {
        for (T value : path) {
            cout << value << " ";
        }
        cout << endl;
    }
};};
int main()
{
    BinaryTree<int> tree;

    // Thêm các nút vào cây
    tree.addRec(8);
    tree.addRec(3);
    tree.addRec(10);
    tree.addRec(1);
    tree.addRec(6);
    tree.addRec(14);
    tree.addRec(4);
    tree.addRec(7);
    tree.addRec(13);

    // In ra các nút theo thứ tự in-order
    cout << "In-order: ";
    tree.inOrder();
    cout << endl;

    // Kiểm tra xem nút 6 có tồn tại trong cây hay không
    if (tree.searchKey(6)) {
        cout << "Node 6 exists in the tree" << endl;
    } else {
        cout << "Node 6 does not exist in the tree" << endl;
    }

    // Xóa nút 6 khỏi cây và in lại các nút theo thứ tự in-order
    tree.removeKey(6);
    cout << "In-order after removing 6: ";
    tree.inOrder();
    cout << endl;

    // In ra cây theo thứ tự của từng tầng
    cout << "Level-order: " << endl;
    tree.printLevelOrder();

    // In ra chiều cao của cây
    cout << "Height of the tree: " << tree.height() << endl;

    // In ra tất cả các đường đi từ gốc đến lá
    cout << "Paths from root to leaf: " << endl;
    tree.printPaths();

    return 0;
}