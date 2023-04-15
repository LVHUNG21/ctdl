//viet chuong trinh nhap vao mot mang va dem so lan xuat hien cua moi ki tu trong chuoi bang cach su dung con tro
#include<iostream>

using namespace std;
int count[256]={0};
char str[91]={};

void convertToASCII(string letter)
{
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        cout << int(x) << endl;
    }
    if(

    )

}
int main()
{
     
    cin>>str;
    char* p=str;
    while(*p!='\0'){
        count[(int)*p]++;
        p++;
    }
    string plainText;
    cout << "Enter text to convert to ASCII: ";
    cin >> plainText;
    convertToASCII(plainText);
    return 0;
}