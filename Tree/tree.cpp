#include <iostream>
using namespace std;

struct node
{
    int value;
    node* right;
    node* left;
};

node* root=NULL;

void tambahChild(){
    node* child=new node;
    cout<<"Masukkan nilai: ";
    cin>>child->value;
    child->left=nullptr;
    child->right=nullptr;
    if(root==NULL){
        root=child;
        return;
    }
    
    node* temp=root;
    node* parent=NULL;
    while(temp!=NULL){
        parent=temp;
        if(child->value<=temp->value){
            temp=temp->left;
        }
        else {
            temp=temp->right;
        }
    }
    if(child->value<=parent->value){
        parent->left=child;
    }
    else{
        parent->right=child;
    }
    
}

void inorder(node* n) {
    if (n != nullptr) {
        inorder(n->left);
        cout << n->value << " ";
        inorder(n->right);
    }
    
}
void preorder(node* n) {
    if (n != nullptr) {
        cout << n->value << " ";
        preorder(n->left);
        preorder(n->right);
    }
    
}
void postorder(node* n) {
    if (n != nullptr) {
        postorder(n->left);
        postorder(n->right);
        cout << n->value << " ";
    }
    
}

void hapusTree(node* n) {
    if (n != nullptr) {
        hapusTree(n->left);
        hapusTree(n->right);
        delete n;
    }
}


int main(){
    int a;
    do
    {
        cout<<"1. Tambah Node\n";
        cout<<"2. InOrder\n";
        cout<<"3. PreOrder\n";
        cout<<"4. PostOrder\n";
        cout<<"0. Exit\n";
        cout<<"Pilih: ";
        cin>>a;
        switch (a)
        {
        case 1:
            tambahChild();
            break;
        
        case 2:
            inorder(root);
            cout<<endl;
            break;
        
        case 3:
            preorder(root);
            cout<<endl;
            break;
        
        case 4:
            postorder(root);
            cout<<endl;
            break;
        
        case 0:
            hapusTree(root);
            cout<<"Keluar dari sistem TREE";
            break;
        
        default:
            break;
        }
    } while (a!=0);
    
}