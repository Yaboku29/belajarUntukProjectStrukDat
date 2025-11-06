#include <iostream>
using namespace std;

string tempat[6]={"","UPN2","UPN1","KOS","Stasiun","Rumah"};

struct node
{
    string nama;
    int jarak;
    node* next;
};



void addEdge(node* adj[],string asal,string tujuan, string daftar[],int jarak){
    int idx_asal=-1,idx_tujuan=-1;
    for(int i=1;i<6;i++){
        if(daftar[i]==asal) idx_asal=i;
        if(daftar[i]==tujuan) idx_tujuan=i;
    }
    if(idx_asal==-1||idx_tujuan==-1){
        cout<<"Tidak ditemukan asal atau Tujuan.\nInputkan nama dengan kapital dan benar!!\n";
        return;
    }
    
    node* baruAsal= new node;
    baruAsal->nama=tujuan;
    baruAsal->jarak=jarak;
    node* baruTujuan=new node;
    baruTujuan->nama=asal;
    baruTujuan->jarak=jarak;
    
    baruAsal->next=adj[idx_asal];
    baruTujuan->next=adj[idx_tujuan];
    adj[idx_asal]=baruAsal;
    adj[idx_tujuan]=baruTujuan;
}

void print(node* adj[]){
    for(int i=1;i<6;i++){
        if(adj[i]==NULL){
            cout<<tempat[i]<<": \n";
        }
        else{
            node* temp=adj[i];
            cout<<tempat[i]<<": \n";
            int point=1;
            while(temp!=NULL){
                cout<<point<<". "<<temp->nama<<"("<<temp->jarak<<" km)\n";
                temp=temp->next;
                point++;
            }
        }    
    }
}

int main(){
    node* adj[6]={nullptr};
    addEdge(adj,"UPN2","UPN1",tempat,4);
    addEdge(adj,"UPN2","KOS",tempat,1);
    addEdge(adj,"UPN1","KOS",tempat,3);
    addEdge(adj,"KOS","Stasiun",tempat,10);
    print(adj);
}