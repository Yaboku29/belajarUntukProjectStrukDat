# Belajar StrukDat untuk Project StrutDat
By: Ananda Rizky Setya Nugroho (Yaboku)

---

Jadi repository ini dibuat sebagai tempat belajar dan praktik <br>
dalam pembelajaran Struktur Data pada Semester 3 Informatika di UPNVYK <br>
Materi yang akan dipelajari antara lain:
### Pointer
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

### Linked List
Linked List adalah sebuah struktur data dari gabungan banyak pointer
Kegunaannya mirip dengan array yang digunakan untuk menyimpan banyak data
Bedanya Linked List ini lebih dinamis dan fleksibel
Dinamis karena batasnya berdasarkan memori device
Dan fleksibel dalam pengoperasiannya

---

#### Singly Linked-List
Singly Linked-List adalah linked-list yang hanya memiliki satu arah saja
Biasanya disebut <strong>next<strong> dalam deklarasinya

---

#### Doubly Linked-List
#### Circular Linked-List
##### Singly Circular Linked-List
##### Doubly Circular Linked-List
### Stack
### Queue
#### Circular Queue
#### Double-ended Queue
### Rekursi
### Tree
#### Tree Traversal
### Graf 