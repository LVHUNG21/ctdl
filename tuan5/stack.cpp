#include<iostream>
using namespace std;
template<class E>
class AStack{
    protected:
            int maxSize;
            int size;
            E* arr;
    public:
        AStack(int maxSize=100){
            E * arr=new int[maxSize];
        };
        void print() {
            for(int i=0;i<size;i++){
                    cout<<arr[size-i-1]<<endl;
            }
        };
        E top(const E &e) {
            if(size==0){
                cout<<"rong";
            }
            else{
                return arr[size-1];
            }
            
        };
        void  push(const E &e) {
            size++;
            arr[size-1]=e;
        };
        void  pop() {
        if(isEmpty){cout<<"rong";}else{
            size--; }
        };
        void clear(){
            size=0;
        };
        virtual ~AStack(){

        };

        int getSize(){
            return size;
        };
        bool isEmpty() {
            return size==0 ? true : false;
        };
        bool isFull()
        {
            return size==100 ? true : false;
        };
         

        AStack(const AStack<E> &R){
            AStack<E> a=new AStack<E>();
            a.maxSize=R.maxSize;
            a.size=R.getsize;
            a.arr=R.arr;
            for(int i=0;i<R.size;i++){
                a.arr[i]=R.arr[i];
            };
        };
        const AStack<E> & operator =(const AStack <E> &);
};
int main(){
AStack<int> a1;
return 0;
}