#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};


int main(){
    node* dataAwal=new node;
    dataAwal->value=10;
    dataAwal->next=nullptr;
}