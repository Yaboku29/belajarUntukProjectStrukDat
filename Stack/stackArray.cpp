#include <iostream>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    int top=5;
    cout<<"Top;"<<top<<endl;
    for(int i=top-1;i>=0;i--){
        cout<<arr[i]<<endl;
    }
    //pop
    top--;
    cout<<"Pop 1 kali"<<endl;
    for(int i=top-1;i>=0;i--){
        cout<<arr[i]<<endl;
    }
    //pop 2 kali
    top-=2;
    cout<<"Pop 2 kali"<<endl;
    for(int i=top-1;i>=0;i--){
        cout<<arr[i]<<endl;
    }
}