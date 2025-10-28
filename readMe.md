# Belajar StrukDat untuk Project StrutDat
By: Ananda Rizky Setya Nugroho (Yaboku)

---

Jadi repository ini dibuat sebagai tempat belajar dan praktik <br>
dalam pembelajaran Struktur Data pada Semester 3 Informatika di UPNVYK <br>
Materi yang akan dipelajari antara lain:
### [Pointer](/pointer)
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

### [Linked List](/LinkedList)
Linked List adalah sebuah struktur data dari gabungan banyak pointer
Kegunaannya mirip dengan array yang digunakan untuk menyimpan banyak data
Bedanya Linked List ini lebih dinamis dan fleksibel
Dinamis karena batasnya berdasarkan memori device
Dan fleksibel dalam pengoperasiannya

---

#### [Singly Linked-List](/LinkedList/singlyLinkedList)
Singly Linked-List adalah linked-list yang hanya memiliki satu arah saja
Biasanya disebut <strong>next</strong> dalam deklarasinya
contoh singly linked-list :
misal ada data 10,20,30 ingin dihubungkan dalam linked-list <br>
akan menjadi 10 -> 20 -> 30 <br>
10 menjadi head <br>
30 menjadi tail <br>
Ketika ingin menambahkan data di depan, maka awalnya menghubungkan <br>
node baru ke node head, lalu memindahkan penanda head ke node baru <br>
<br>
Begitu juga untuk tail kurang lebih sama, bedanya berada di belakang <br>
<br>
Lalu untuk di tengah agak berbeda, karena perlu mengetahui harus berhenti di mana <br>
Biasanya melihat dari nilai datanya agar bisa urut <br>
Jika sudah berhenti di node yang nilai dari node next lebih besar dari nilai node yang ingin ditambahkan <br>
Node baru dihubungkan ke node yang nilainya lebih besar itu terdahulu <br>
Setelahnya menghubungkan node sebelum ke node baru <br>
Contoh : 
10 -> 20 -> 30 <br>
ingin memasukkan nilai 25 <br>
Lakukan traversal terdahulu sampai node->next->nilai > baru->nilai <br>
Jika sudah hubungkan baru->next=node->next <br>
<strong> (Hal ini dilakukan terlebih dahulu karena jika kita menghubungkan node->next=baru, <br>
kita tidak bisa akses ke node->next yang sebelumnya karena alamatnya sudah diubah ke node baru) </strong> <br>
Setelah menghubungkan node baru ke node->next, selanjutnya tinggal menghubungkan node sekarang ke node baru tadi <br>
<strong> node->next=baru </strong> <br>

---

#### [Doubly Linked-List](/LinkedList/doublyLinkedList)
Kurang lebih doubly linked-list sama/mirip dengan singly Linked-list. <br>
Bedanya di doubly linked-list terdapat pointer yang menunjukkan node sebelumnya (prev), <br>
yang di singly linked-list tidak ada atau hanya menunjuk node selanjutnya (next). <br>
<br>
Contoh: <br>
Kita punya data 10,20,30 dan ingin dihubungkan. <br>
Dalam doubly linked-list, bentuknya menjadi :  <br>
NULL <-> 10 <-> 20 <-> 30 <-> NULL <br>
<br>
Operasinya kurang lebih mirip dengan linked-list, <br>
hanya saja bisa lebih sederhana atau fleksibel karena bisa mengakses node sebelumnya. <br>

#### [Circular Linked-List](/circularLinkedList)
Circular Linked List adalah sebuah linked-list yang melingkar. <br>
Sesuai namanya "Circular", berarti data yang ada di linked-list berputar atau kembali lagi ke head. <br>
<br>
Jadi yang awalnya tail->next menunjuk nullptr menjadi menunjuk head kembali. 

---

##### [Singly Circular Linked-List](/circularLinkedList)
Singly Circular linked-list adalah Linked List yang melingkar. <br>
Artinya pointer next pada tail langsung menunjuk ke head yang sebelumnya menunjuk nullptr. <br>
<br>
Keunggulan dibanding Singly Linked List biasa adalah dapat kembali ke awal tanpa harus ada node bantuan yang lain. <br>

##### [Doubly Circular Linked-List](/circularLinkedList)
Sama halnya dengan doubly Linked List, yang menjadi pembeda adalah head bisa ke tail dan sebaliknya. <br>
Jadi dalam traversalnya lebih fleksibel dan leluasa. <br>

### [Stack](/Stack)
Stack adalah sebuah struktur data yang menggunakan konsep LIFO (Last-In First-Out)<br>
Gambarannya itu bisa dianggap sebagai tumpukan (stack) buku, jika kita ingin <br>
tumpukan buku tersebut tetap rapi, maka kita perlu mengambil buku-bukunya dari paling atas. <br>

---

### [Queue](/Queue)
Queue adalah sebuah struktur data yang menggunakan konsep FIFO (First-In First-Out) <br>
Gambarannya itu seperti antrian (Queue) ketika berbelanja, yang mengantri lebih dulu akan dilayani lebih dulu. <br>

---

#### [Circular Queue](/Queue/circularQueue)
Circular Queue adalah salah satu variasi dari Queue. Circular Queue ini lebih terfokus untuk penyelesaian issue pada normal Queue yang memakai array. <br>
Hal itu dikarenakan ketika melakukan dequeue, index yang di-dequeue tidak bisa kita pakai lagi dan sangat rentan mengalami <strong> overflow </strong>. <br>
Bisa saja dengan memindahkan isi data ke index yang kosong, tetapi hal ini membuat <br>
kompleksitas waktunya menjadi O(n) yang jika kita punya data banyak atau butuh waktu penyelesaian program cepat akan sangat mengganggu. <br>
Maka dari itu, dibuatlah <strong>Circular Queue</strong> untuk mengatasinya. <br>
Konsepnya dengan memindahkan penunjuk front dan rear tiap kali dilakukan operasi <strong>enqueue</strong> atau <strong>dequeue</strong>. <br>

#### [Double-ended Queue](/Queue/deque)
Double-ended queue (Deque) adalah variasi lainnya Queue. Untuk yang satu ini seperti menggabungkan <br>
konsep "Stack" dan "Queue". Karena dalam Deque, kita bisa tambah data dari depan atau belakang dan keluarkan data dari depan atau belakang. <br>
<br>
Deque juga punya 2 jenis yang biasanya ditemui yaitu:
1. Input-Restricted Deque (1 tempat input dan 2 tempat output)
2. Output-Restricted Deque (2 tempat input dan 1 tempat output)

---

### Rekursi
### Tree
#### Tree Traversal
### Graf 
