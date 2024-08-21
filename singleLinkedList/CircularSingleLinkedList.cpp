#include <iostream>
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
};
template<typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    int size;
public:
    CircularLinkedList() {
        head = nullptr;
        size = 0;
    }
    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>();
        newNode->data = element;
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(int element) {
        Node<T>* newNode = new Node<T>();
        newNode->data = element;
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    void insertAt(int element,int index) {
        if (index < 0 || index > size) {
            cout<<"Invalid index";
        }
        if (index == 0) {
            insertAtHead(element);
        }
        else if (index == size) {
            insertAtTail(element);
        } else {
            Node<T>* newNode = new Node<T>();
            newNode->data = element;
            Node<T>* temp = head;
            for (int i = 0; i<index-1;i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }
    void removeAtHead() {
        if (isEmpty()) {
            cout<<"No elements to delete";
        }
        Node<T>* temp = head;
        if (head->next == head) {
            head = nullptr;
        }
        else {

            Node<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            head = head->next;
            lastNode->next = head;
        }
        delete temp;
        size--;
    }
    void removeAtTail() {
        if (isEmpty()) {
            cout<<"No elements to delete";
        }
        Node<T>* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node<T>* prevNode = nullptr;
            while (temp->next != head) {
                prevNode = temp;
                temp = temp->next;
            }
            prevNode->next = head;
        }
        delete temp;
        size--;
    }
    void removeAt(int index) {
        if (index<0||index>=size){
            cout<<"Invalid index";
        }
        if (index == 0) {
            removeAtHead();
        }
        else if (index==size-1){
            removeAtTail();
        }
        else {
            Node<T>* temp = head;
            Node<T>* prevNode = nullptr;
            for (int i = 0; i < index; i++) {
                prevNode = temp;
                temp = temp->next;
            }
            prevNode->next = temp->next;
            delete temp;
            size--;
        }
    }
    int retrieveAt(int index) {
        if (index < 0 || index >= size) {
            cout<<"Invalid index";
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    void replaceAt(int newvalue, int index) {
        if (index < 0 || index >= size) {
            cout<<"Invalid index";
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = newvalue;
    }
    bool isfound(int element) {
        bool found = false;
        Node<T>* temp = head;
        if (isEmpty()) {
            found= false;
        }
        do {
            if (temp->data == element) {
                found =true;
            }
            temp = temp->next;
        } while (temp != head);
        return found;
    }
    bool isItemAtEqual(int element, int index) {
        if (index < 0 || index >= size) {
            cout<<"Invalid index";
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return (temp->data == element);
    }
    void swap(int firstIndex, int secondIndex) {
        if (firstIndex<0||firstIndex>=size||secondIndex<0||secondIndex>=size){
            cout<<"Invalid index";
        }
        Node<T>* firstNode = head;
        Node<T>* secondNode = head;
        for (int i = 0; i <firstIndex; i++) {
            firstNode = firstNode->next;
        }
        for (int i = 0; i < secondIndex; i++) {
            secondNode = secondNode->next;
        }
        int temp = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = temp;
    }
    bool isEmpty() {
        if(head==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    int linkedListSize() {
        return size;
    }
    void clear() {
        while (!isEmpty()) {
            removeAtHead();
        }
    }
    void print() {
        if (isEmpty()) {
            cout << "no elements to print"<<endl;
        }
        else {
            Node<T>* temp = head;
            do {
                cout<<temp->data<<" ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }

    }
};

int main() {
    CircularLinkedList<int> list; 
    list.insertAtHead(3);
    list.insertAtTail(5);
    list.insertAt(7, 1);
    list.insertAtHead(8);
    list.print();  
    list.removeAtTail();
    list.removeAtHead();
    list.removeAt(1);
    list.print();
    cout<< list.retrieveAt(1) <<endl;
    list.replaceAt(10, 0);

    list.print();

    cout<<boolalpha<<list.isfound(8)<<endl;
    list.swap(0, 2);
    list.print();
    list.clear();
    cout <<boolalpha << list.isEmpty() <<endl;
    return 0;
}