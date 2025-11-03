#include <iostream>
using namespace std;

const int SIZE = 5;

struct Node {
    string nama;
    int harga;
    Node* next;
};

int hashFunction(string nama) {
    int sum = 0;
    for (char c : nama) sum += c;
    return sum % SIZE;
}

void insert(Node* table[], string nama, int harga) {
    int index = hashFunction(nama);
    Node* baru = new Node{nama, harga, nullptr};
    if (!table[index]) table[index] = baru;
    else {
        Node* temp = table[index];
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

void search(Node* table[], string nama) {
    int index = hashFunction(nama);
    Node* temp = table[index];
    while (temp) {
        if (temp->nama == nama) {
            cout << "Harga " << nama << " adalah Rp" << temp->harga << endl;
            return;
        }
        temp = temp->next;
    }
    cout << nama << " tidak ditemukan di daftar menu.\n";
}

int main() {
    Node* table[SIZE] = {nullptr};

    insert(table, "Nasi Goreng", 15000);
    insert(table, "Mie Ayam", 12000);
    insert(table, "Sate", 20000);

    search(table, "Mie Ayam");
    search(table, "Bakso");

    return 0;
}
