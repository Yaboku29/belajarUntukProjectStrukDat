#include <iostream>
#define MAX 11
using namespace std;

string tempat[MAX]={
                    "",
                    "Kota Aruna",
                    "Desa Meranti",
                    "Bukit Sagara",
                    "Lembah Indra",
                    "Pantai Lestari",
                    "Telaga Sunyi",
                    "Hutan Rendra",
                    "Gunung Nirmala",
                    "Kota Bayangan",
                    "Pelabuhan Timur"
                    };

struct node
{
    string nama;
    int jarak;
    node* next;
};



void addEdge(node* adj[],string asal,string tujuan, string daftar[],int jarak){
    int idx_asal=-1,idx_tujuan=-1;
    for(int i=1;i<MAX;i++){
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
    
    baruAsal->next=adj[idx_asal];
    adj[idx_asal]=baruAsal;
}

int nomorTempat(string nama){
    for(int i=1;i<MAX;i++){
        if(nama==tempat[i]){
            return i;
        }
    }
    return -1;
}

void print(node* adj[]){
    for(int i=1;i<MAX;i++){
        if(adj[i]==NULL){
            cout<<tempat[i]<<": \n";
        }
        else{
            node* temp=adj[i];
            cout<<i<<". "<<tempat[i]<<": \n";
            while(temp!=NULL){
                cout<<"   "<<nomorTempat(temp->nama)<<". "<<temp->nama<<"("<<temp->jarak<<" km)\n";
                temp=temp->next;
            }
            cout<<endl;
        }    
    }
}

void DFS(node* adj[],string nama,bool visited[],int depth=0){
    int idxNow=nomorTempat(nama);
    if(idxNow==-1){
        cout<<"Nama Tidak ada.\nMasukkan nama tempat yang sesuai.\n";
        return;
    }
    visited[idxNow]=true;
    for(int i=0;i<depth;i++)cout<<" ";
    cout<<depth<<"."<<nama<<endl;
    node* temp=adj[idxNow];
    while(temp!=NULL){
        int idxNext=nomorTempat(temp->nama);
        if(visited[idxNext]==false){
            DFS(adj,temp->nama,visited,depth+1);
        }
        temp=temp->next;
    }
}

void traversDFS(node* adj[],string sekarang,string tujuan,bool visited[],int totalJarak=0){
    int idxNow=nomorTempat(sekarang);
    int idxTujuan=nomorTempat(tujuan);
    if(idxNow==-1||idxTujuan==-1){
        cout<<"Nama Tidak ada.\nMasukkan nama tempat yang sesuai.\n";
        return;
    }
    if(sekarang==tujuan) {
        cout<<totalJarak<<endl;
    }
    visited[idxNow]=true;
    node* temp=adj[idxNow];
    while(temp!=NULL){
        int idxNext=nomorTempat(temp->nama);

        if(visited[idxNext]==false){
            traversDFS(adj,temp->nama,tujuan,visited,totalJarak+temp->jarak);
        }
        
        temp=temp->next;
    }
    visited[idxNow]=false;
}
void DFSterperdek(node* adj[],string sekarang,string tujuan,bool visited[],int pendek[],int totalJarak=0){
    int idxNow=nomorTempat(sekarang);
    int idxTujuan=nomorTempat(tujuan);
    if(idxNow==-1||idxTujuan==-1){
        cout<<"Nama Tidak ada.\nMasukkan nama tempat yang sesuai.\n";
        return;
    }
    if(sekarang==tujuan) {
        if(pendek[idxNow]==-1||totalJarak<pendek[idxNow]) pendek[idxNow]=totalJarak;
        
    }
    visited[idxNow]=true;
    node* temp=adj[idxNow];
    while(temp!=NULL){
        int idxNext=nomorTempat(temp->nama);

        if(visited[idxNext]==false){
            DFSterperdek(adj,temp->nama,tujuan,visited,pendek,totalJarak+temp->jarak);
        }
        
        temp=temp->next;
    }
    visited[idxNow]=false;
}
void DAG(node* adj[],string sekarang,string tujuan,bool visited[],int pendek[],int totalJarak=0){
    int idxNow=nomorTempat(sekarang);
    int idxTujuan=nomorTempat(tujuan);
    if(idxNow==-1||idxTujuan==-1){
        cout<<"Nama Tidak ada.\nMasukkan nama tempat yang sesuai.\n";
        return;
    }
    if(sekarang==tujuan) {
        if(pendek[idxNow]==-1||totalJarak<pendek[idxNow]) pendek[idxNow]=totalJarak;
        
    }
    visited[idxNow]=true;
    node* temp=adj[idxNow];
    while(temp!=NULL){
        int idxNext=nomorTempat(temp->nama);

        if(visited[idxNext]==false){
            DFSterperdek(adj,temp->nama,tujuan,visited,pendek,totalJarak+temp->jarak);
        }
        
        temp=temp->next;
    }
    visited[idxNow]=false;
}



int main(){
    node* adj[MAX]={nullptr};
    bool visited[MAX]={false};
    int jarakTerpendek[MAX];
    for(int i=0;i<MAX;i++) jarakTerpendek[i]=-1;
    addEdge(adj,"Kota Aruna","Desa Meranti",tempat,5);
    addEdge(adj,"Kota Aruna","Bukit Sagara",tempat,4);
    addEdge(adj,"Kota Aruna","Lembah Indra",tempat,5);
    addEdge(adj,"Desa Meranti","Pantai Lestari",tempat,9);
    addEdge(adj,"Bukit Sagara","Pantai Lestari",tempat,6);
    addEdge(adj,"Bukit Sagara","Hutan Rendra",tempat,3);
    addEdge(adj,"Lembah Indra","Telaga Sunyi",tempat,4);
    addEdge(adj,"Telaga Sunyi","Hutan Rendra",tempat,2);
    addEdge(adj,"Hutan Rendra","Gunung Nirmala",tempat,7);
    addEdge(adj,"Hutan Rendra","Kota Bayangan",tempat,6);
    addEdge(adj,"Gunung Nirmala","Kota Bayangan",tempat,5);
    addEdge(adj,"Kota Bayangan","Pelabuhan Timur",tempat,8);
    print(adj);
    cout<<endl;
    cout<<"DFS\n";
    DFS(adj,"Kota Aruna",visited);
    for(int i=1;i<MAX;i++)
        visited[i]={false};
    cout<<"\nAruna ke Sunyi\n";
    cout<<"Jarak dari Kota Aruna ke Telaga Sunyi :\n";
    traversDFS(adj,"Kota Aruna","Telaga Sunyi",visited);
    cout<<"Jarak dari Kota Aruna ke Pantai Lestari :\n";
    traversDFS(adj,"Kota Aruna","Pantai Lestari",visited);
    cout<<"Jarak dari Kota Aruna ke Pelabuhan Timur :\n";
    traversDFS(adj,"Kota Aruna","Pelabuhan Timur",visited);
    cout<<"Jarak dari Kota Aruna ke Kota Bayangan :\n";
    traversDFS(adj,"Kota Aruna","Kota Bayangan",visited);
    cout<<endl;
    DFSterperdek(adj,"Kota Aruna","Pelabuhan Timur",visited,jarakTerpendek);
    cout<<"Jarak dari Kota Aruna ke Pelabuhan Timur :"<<jarakTerpendek[nomorTempat("Pelabuhan Timur")]<<endl;
    DFSterperdek(adj,"Kota Aruna","Kota Bayangan",visited,jarakTerpendek);
    cout<<"Jarak dari Kota Aruna ke Kota Bayangan :"<<jarakTerpendek[nomorTempat("Kota Bayangan")]<<endl;
}