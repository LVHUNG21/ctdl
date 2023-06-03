#include<iostream>
using namespace std;
class Stackk(
    private:
            vector<int> vt;
    public:
            Stackk();

            void push(int a){
                vt.push_back();
            }
            void pop(){
                vt.pop_back();
            }
            void top(){
                vt.back();
            }
            void clear(){
                vt.clear();
            }
            int getSize(){
                vt.size();
            };
            void print(){
                for(int i=0;i<vt.size();i++){
                    cout<<vt.at(i)<<endl;
                }
            }


);
 int main(){


 }