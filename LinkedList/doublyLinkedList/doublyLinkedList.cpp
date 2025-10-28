#include <iostream>
using namespace std;
struct node
{
    int value;
    node* next;
    node* prev;
};

node* head=NULL,*tail=NULL;

void inisialisasi(){
    node* head=NULL;
    node* tail=NULL;
}

void sisip(){
    node* baru=new node;
    cout<<"Masukkan nilai baru: ";
    cin>>baru->value;
    baru->prev=NULL;
    baru->next=NULL;
    if(head==NULL){
        head=baru;
        tail=baru;
    }
    else{
        if(baru->value<head->value){
            baru->next=head;
            head->prev=baru;
            head=baru;
        }
        else if(baru->value>tail->value){
            tail->next=baru;
            baru->prev=tail;
            tail=baru;
        }
        else{
            node* temp=head;
            while(temp->next){
                if(baru->value<temp->next->value){
                    break;
                }
                temp=temp->next;
            }
            baru->next=temp->next;
            baru->prev=temp;
            temp->next->prev=baru;
            temp->next=baru;
        }
    }
}

void lihat(){
    if(head==NULL){
        cout<<"Linked List Kosong";
        return;
    }
    else{
        node* temp=head;
        while(temp){
            cout<<temp->value<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

int main(){
    inisialisasi();
    sisip();
    sisip();
    sisip();
    lihat();
    sisip();
    lihat();
}