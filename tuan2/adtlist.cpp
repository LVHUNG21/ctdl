#include <iostream>
using namespace std;
template <class T>
class ADT_list
{
private:
    int pos;
    int max_size;
    T *p;
public:
    ADT_list(int m){
        pos=0;
        max_size=m;
        T *p = new T[max_size];
      };
      void print()const{
        for(int i=0;i<max_size;i++){
                cout<<*(p+i)<<endl;
        }
      }
      T search()const {
           return *(p+pos);   
      }
    void add(T a){
        *(p+pos)=a;
          pos++;
    }
    void insert(int i1, const T &a){
      for(int i=pos,i>i1,i--){
        *(p+i+1)=*(p+i);
        
      }
      
    }
    int getSize()const{
        return pos;
    }
    bool isEmpty()const{
      return pos==0 ? true :false;
    }
    bool isFull()const{
      return pos==max_size ? true :false;
    }
};
int main()
{
    return 0;
}