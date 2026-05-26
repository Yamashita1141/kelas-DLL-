#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node () {
        data = 0;
    }
    Node (int data) {
        this->data = data;
    }
};

class DoubleLinkedList {
    int jumlah = 0; //jiks insert jumlah++,hapus maka jumlah--
    public:
    Node* head;
    Node* tail;

    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        jumlah = 0;
    }

    void insertdepan(int value);
    void insertbelakang(int value);
    void cetak();
    void hapusdepan();
    void hapusbelakang(int value);
    void hitungnode();     //hitung jumlah
    bool searchdata(int k); // loop while
    bool searchdata2(int k); // loop for karena n = sizeOf node
};

int main () {
    DoubleLinkedList dll;
    dll.insertdepan(100); //[0|100|0] output
    dll.insertbelakang(84); //[0|84|0] <--- ---> [0|100|0]
    dll.insertbelakang(5); //[0|5|0] <--- ---> [0|84|0] <--- ---> [0|100|0]
    cout << "setelah hapus depan" << endl;
    dll.hapusdepan(); //[0|84|0] <--- ---> [0|5|0]
    cout << "setelah hapus belakang" << endl;
    dll.hapusbelakang(5); //[0|84|0]
    cout << "jumlah node: ";
    dll.hitungnode();
    cout << "apakah ada angka 84? " << dll.searchdata(84) << endl;
    cout << "apakah ada angka 5? " << dll.searchdata(5) << endl;

    return 0;
}

void DoubleLinkedList::insertdepan(int value) {
    Node *temp = new Node(value);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head ->prev = temp;
        head = temp;
    }
    jumlah++;
    cetak();
}

void DoubleLinkedList::insertbelakang(int value){
    Node *temp = new Node(value);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    jumlah++;
    cetak();
}

void DoubleLinkedList::cetak() {
    Node *temp = head;
    
    while (temp != NULL) {
        cout << "[ " << temp->prev << "|" << temp->data << "|" << temp->next << " ] ";
        temp = temp->next;
        if (temp != NULL) cout << " <--- ---> ";
    }
    cout << endl;
}

void DoubleLinkedList::hapusdepan() {
    if (head != NULL) {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        jumlah--;
        cetak();
    }
}

void DoubleLinkedList::hapusbelakang(int value) {
    if (tail != NULL) {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        jumlah--;
        cetak();
    }
}

void DoubleLinkedList::hitungnode() {
    cout << "jumlah node: " << jumlah << endl;
}

bool DoubleLinkedList::searchdata(int k) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == k) return true;
        temp = temp->next;
    }
    return false;
}

bool DoubleLinkedList::searchdata2(int k) {
    for (Node *temp = head; temp != NULL; temp = temp->next) {
        if (temp->data == k) return true;
    }
    return false;
}