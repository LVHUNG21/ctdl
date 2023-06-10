
template <typename T>

struct node
{
     int value;
     node *left;
     node *right;
};
class BinaryTree
{
private:
     node *root;

public:
     bool isInternal()
     {
          return (left != nullptr || right != nullptr) ? true : false;
     }
     int countAdult()
     {
          countAdult(node * root);
     }
     int countAdult(node *root)
     {
          if (root == nullptr || (root->left == nullptr && root->right == nullptr))
          {
               return 0;
          }
          int numberNodes_of_left = countNodes(root->left);
          int numberNodes_of_right = countNodes(root->right);
          return numberNodes_of_left + numberNodes_of_right + 1;
     }
     int countNodes()
     {
          countNodes(node * root);
     }
     int countNodes(node *root)
     {
          if (root == nullptr)
          {
               return 0;
          }
          int numberNodes_of_left = countNodes(root->left);
          int numberNodes_of_right = countNodes(root->right);
          return numberNodes_of_left + numberNodes_of_right + 1;
     }

     void addRec(node *&root, int e)
     {
          if (!root)
          {
               root->value = e;
          }
          else
          {
               int left = findHeight(root->left),
                   int right = findHeight(root->right),
                   if (l <= r) addRec(root->left, e);
               else addRec(root->right, e)
          }
     }
     void deleteAll(){
          deleteTree(root);
     }
     void deleteTree(node * root){
          if(root==nullptr) return; 
           deleteTree(root->left);
           deleteTree(root->right);
           delete root;
     }
     void inOrder_print()
     {
          inOrder_print(root);
          cout << "*";
     }
     void inOrder_print(node *current_node)
     {
          if (current_node != nullptr)
          {
               inOrder_print(current_node->left);
               cout << current_node->value << ",";
               inOrder_print(current_node->right);
          }
     }
     void preOrder_print()
     {
          preOrder_print(root);
          cout << "*";
     }
     void preOrder_print(node *current_node)
     {
          if (current_node != nullptr)
          {
               cout << current_node->value << ",";
               preOrder_print(current_node->left);
               preOrder_print(current_node->right);
          }
     }
     void findHeight()
     {
          getHeight(root);
     }
     int getHeight(node *root)
     {
          if (root == nullptr)
               return 0;
          int left_height = getHeight(root->left) + 1;
          int right_height = getHeight(root->right) + 1;
          return (left_height - right_height) ? left_height : right_height;
     }

} int main()
{

     return 1;
}
