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
        head->next=tail;
        tail->next=head;
        
    }
    else{
        if(head->value > baru->value){
            baru->next=head;
            tail->next=baru;
            head=baru;
        }
        else if(tail->value < baru->value){
            tail->next=baru;
            baru->next=head;
            tail=baru;
        }
        else{
            node* temp=head;
            
            while(temp->next!=head){
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
    
    do{
        cout<<lihat->value<<" -> ";
        lihat=lihat->next;
    }while(lihat!=head);
    cout<<head->value<<"(Head)"<<endl;
}

int main(){
    // node* dataAwal=new node;
    // dataAwal->value=10;
    // dataAwal->next=nullptr;
    tambahNode();
    lihatNode();
    tambahNode();
    tambahNode();
    lihatNode();
}