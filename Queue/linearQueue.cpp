#include <iostream>
#define MAX 5
using namespace std;

int arr[MAX],front=-1,rear=-1;

void enqueue(int value){
    if(front+1==MAX){
        cout<<"Queue penuh\n";
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
    }
}

void dequeue(){
    if(front==-1){
        cout<<"Queue Kosong\n";
    }
    else{
        cout<<"Data sudah dihapus\n";
        front++;
    }
}

void cetak(){
    if(front==-1){
        cout<<"queue kosong\n";
    }
    else{
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<"-";
        }
        cout<<"NULL"<<endl;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    cetak();
    enqueue(30);
    dequeue();
    cetak();
    enqueue(15);
    enqueue(5);
    enqueue(1);
    cetak();
}