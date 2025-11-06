#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = new Node{v, adj[u]};
    adj[u] = newNode;

    newNode = new Node{u, adj[v]};
    adj[v] = newNode;
}

void printGraph(Node* adj[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << " terhubung ke: ";
        Node* temp = adj[i];
        while (temp) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    const int N = 4; // jumlah node
    Node* adj[N] = {nullptr}; // inisialisasi semua list kosong

    // Tambahkan edge
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    // Cetak graf
    printGraph(adj, N);

    return 0;
}
