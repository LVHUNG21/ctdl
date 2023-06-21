template<typename T> 
struct Node{
    T data;
    Node * left;
    Node * right;
    Node(T value):T(value),left(nullptr),right(nullptr) {}
}
class BinaryTree{
    private:
          Node<T> * root;

    public:
            BinaryTree():root(nullptr){};
            ~BinaryTree(){
                ClearTree();
            }
            void ClearTree(Node<T> * root){
                if(root==nullptr)
                    return nullptr;
                    ClearTree(root->left);
                    ClearTree(root->right);
               delete  root;
            }
            void inOrder_print(Node<T> *root){
                if(root!=nullptr){
                    inOrder_print(root->left);
                    cout<<root->data<<endl;
                    inOrder_print(root->right);
                }
            }
            void addRec(Node<T> * root,T &value){
                if(root=nullptr){
                    root=new Node<T>(value);
                }else if(root->data%2==value%2){
                    if(root->data<value)
                        addRec(root->right,value);
                    else
                        addRec(root->left,value);
                }else
                    if(root->data%2==0)
                        addRec(root->left,value);
                else 
                        addRec(root->right,value);
                
            }
}