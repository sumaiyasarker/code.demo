#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remove(int data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* prev = head;
            Node* curr = head->next;
            while (curr != nullptr && curr->data != data) {
                prev = curr;
                curr = curr->next;
            }
            if (curr != nullptr) {
                prev->next = curr->next;
                delete curr;
            }
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteFirstNode() {

        Node *temp;
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        temp = head;
        head = head->next;
        delete temp;
    }


};

int main() {
    LinkedList myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);

    myList.print(); // Output: 5 10 15

    myList.remove(10);

    myList.print(); // Output: 5 15
    myList.deleteFirstNode();
    myList.print();
    return 0;
}

