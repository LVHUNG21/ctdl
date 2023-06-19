#include <iostream>
using namespace std;

template<typename T> 
struct Node
{
    T data;
    Node *left;
    Node *right;
};
class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    Node *makeEmpty(Node *t)
    {
        if (t == nullptr)
            return nullptr;
        makeEmpty(root->left);
        makeEmpty(root->right);
    }
   Node* addNode(Node* root, int val) {
    // Nếu cây rỗng, tạo một nút mới và trả về nút đó
    if (root == NULL) {
        return new Node(val);
    }

    // Nếu giá trị mới nhỏ hơn giá trị của nút gốc, chèn vào bên trái
    if (val < root->val) {
        root->left = addNode(root->left, val);
    }
    // Nếu giá trị mới lớn hơn giá trị của nút gốc, chèn vào bên phải
    else if (val > root->val) {
        root->right = addNode(root->right, val);
    }
    // Nếu giá trị mới bằng giá trị của nút gốc
    else {
        // Nếu giá trị mới là số chẵn và giá trị của nút gốc là số lẻ, chèn vào bên phải
        if (val % 2 == 0 && root->val % 2 != 0) {
            root->right = addNode(root->right, val);
        }
        // Ngược lại, chèn vào bên trái
        else {
            root->left = addNode(root->left, val);
        }
    }

    return root;
}
};
 
int main(){
    return 1;
}

    