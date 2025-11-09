#include <iostream>
#define max 7
using namespace std;

string tempat[max]={"","UPN2","UPN1","KOS","Stasiun","Rumah","StasiunRumah"};

struct node
{
    string nama;
    int jarak;
    node* next;
};

void addEdge(node* adj[],string asal,string tujuan, string daftar[],int jarak){
    int idx_asal=-1,idx_tujuan=-1;
    for(int i=1;i<max;i++){
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
    for(int i=1;i<max;i++){
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

int checkNode(string nama,string daftar[]){
    for(int i=1;i<max;i++){
        if(nama==daftar[i])return i;
    }
    return -1;
}

void DFS(node* adj[],string nama,string daftar[],bool checkDFS[]){
    int idxNow=checkNode(nama,daftar);
    if(idxNow==-1){
        cout<<"Nama tidak ada";
        return;
    }
    checkDFS[idxNow]=true;
    cout<<nama;
    node* temp=adj[idxNow];

    while(temp!=NULL){
        int nextID=checkNode(temp->nama,daftar);
        if(checkDFS[nextID]==false){
            cout<<" <-"<<temp->jarak<<"-> ";    
            DFS(adj,temp->nama,daftar,checkDFS);
        }
        temp=temp->next;
    }
}

int main(){
    bool checkDFS[max]={false}; 
    node* adj[max]={nullptr};
    addEdge(adj,"UPN2","UPN1",tempat,4);
    addEdge(adj,"UPN2","KOS",tempat,1);
    addEdge(adj,"UPN1","Stasiun",tempat,3);
    addEdge(adj,"StasiunRumah","Stasiun",tempat,67);
    addEdge(adj,"Rumah","StasiunRumah",tempat,8);
    print(adj);
    cout<<"DFS dari UPN1\n";
    DFS(adj,"UPN2",tempat,checkDFS);
}