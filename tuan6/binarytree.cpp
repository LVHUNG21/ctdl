
template<typename T>

class BinaryTreeNode{
    public:
           T data;
           BinaryTreeNode<T>* left;
           BinaryTreeNode<T> * right;

           BinaryTreeNode(T Data){
             this->data=data;
             left=nullptr;
             right=nullptr;
           }

           bool isInternal(){
                return (left!=nullptr || right=nullptr) ? true : false; 
           }
           bool isNotInternal(){
                return (left==nullptr || right==nullptr) ? true : false; 
           }
}

