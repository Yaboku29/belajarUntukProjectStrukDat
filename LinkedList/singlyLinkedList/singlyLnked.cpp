#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};

node* head=NULL,*tail=NULL;

void tambahNode(){
    node* baru=new node;
    cout<<"Masukkan nilai node baru: ";
    cin>>baru->value;
    baru->next=nullptr;

    if(head==NULL){ //jika masih kosong
        head=baru;
        tail=baru;
        tail->next=nullptr;
    }
    else{
        if(head->value > baru->value){
            baru->next=head;
            head=baru;
        }
        else if(tail->value < baru->value){
            tail->next=baru;
            tail=baru;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                if(temp->next->value>baru->value){
                    break;
                }
                temp=temp->next;
            }
            baru->next=temp->next;
            temp->next=baru;
        }
    }
}

void lihatNode(){
    node* lihat=head;
    
    while(lihat!=NULL){
        cout<<lihat->value<<" -> ";
        lihat=lihat->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    // node* dataAwal=new node;
    // dataAwal->value=10;
    // dataAwal->next=nullptr;
    tambahNode();
    lihatNode();
    tambahNode();
    tambahNode();
    tambahNode();
    tambahNode();
    lihatNode();
}