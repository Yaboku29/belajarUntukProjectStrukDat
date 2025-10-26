#include <iostream>
using namespace std;

/*
Pointer adalah sebuah variabel yang menyimpan alamat sebuah variabel lain,
alih-alih hanya menyimpan data yang ada pada variabel lain.

contoh:
a=10
b=a
di sini b itu meng-copy isi dari variabel a dan menjadikan hasil copy tersebut
punya si b

a=10
*b=&a
di sini b adalah sebuah pointer yang menunjuk ke alamat a(ditandai dengan '#')
karena b sebuah pointer, b hanya menunjuk alamat a yang mempunyai nilai 10
berbeda dengan contoh sebelumnya, di sini b tidak meng-copy hanya sekadar menunjuk

Semisal pakai analogi
Misal ada 3 mahasiswa A(variabel asal), B(Variabel mengcopy A), dan C(Pointer menunjuk A)
Mereka berada pada 1 kelompok
Ketika presentasi, B menyalin atau menghafalkan tentang materi yang sudah dibuat oleh A
Sedangkan C ketika ada yang dirasa kurang tahu tentang kejelasannya 
dia langsung menunjuk A yang membuat materi 

*/


int main(){
    int a=10;   //variabel biasa
    int b=a;    //variabel biasa yang mengcopy variabel lain
    int *c=&a;  //pointer yang menunjuk suatu variabel

    cout<<"nilai a: "<<a<<endl;
    cout<<"nilai b: "<<b<<endl;
    cout<<"nilai a: "<<a<<endl;
    cout<<"nilai a: "<<a<<endl;
    cout<<"nilai a: "<<a<<endl;
    cout<<"nilai a: "<<a<<endl;
    cout<<"nilai a: "<<a<<endl;

}