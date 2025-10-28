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
        head->next=tail;
        head->prev=tail;
        tail->next=head;
        tail->prev=head;
    }
    else{
        if(baru->value<head->value){
            baru->next=head;
            baru->prev=tail;
            head->prev=baru;
            tail->next=baru;
            head=baru;
        }
        else if(baru->value>tail->value){
            tail->next=baru;
            baru->prev=tail;
            baru->next=head;
            head->prev=baru;
            tail=baru;
        }
        else{
            node* temp=head;
            while(temp->next!=head){
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
        do{
            cout<<temp->value<<" -> ";
            temp=temp->next;
        }while(temp!=head);
        cout<<head->value<<"(Head)"<<endl;
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