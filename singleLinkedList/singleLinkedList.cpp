#include <iostream>
using namespace std;
template<typename e>
class Node{
public:
    e data;
    Node* next;
};
template<typename e>
class linklist{
public:
    Node<e>* head;
    int size;
    linklist() {
        head=nullptr;
    }
    void clear() {
        Node<e>* temp = head;
        while (temp != nullptr) {
            Node<e>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        size = 0;
    }
    bool isEmpty() {
        if(head==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    void insertAtHead(e newvalue){
        Node<e>* newnode=new Node<e>;
        newnode->data=newvalue;
        if(isEmpty()){
            newnode->next= nullptr;
            head=newnode;
            size++;
        }
        else{
            newnode->next=head;
            head=newnode;
            size++;
        }
    }
    void print(){
        Node<e>* temp=head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    bool isfound(e key){
        bool found=false;
        Node<e>* temp=head;
        while (temp != nullptr) {
            if(temp->data==key){
                found= true;
            }
            temp=temp->next;
        }
        return found;
    }
    void insertAt(e newvalue,int index){
        if (index < 0 || index > size) {
            cout<<"Invalid index";
        }
        if (index == 0) {
            insertAtHead(newvalue);
            return;
        }
        Node<e>* newNode = new Node<e>();
        newNode->data = newvalue;
        newNode->next = nullptr;
        Node<e>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    void insertAtTail(e newvalue){
        Node<e>* newnode=new Node<e>();
        newnode->data=newvalue;
        Node<e>* temp=head;
        while(temp->next != nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next= nullptr;
    }
    void removeAt(int index) {
        Node<e>*current = head;
        if (index<0||index>=size) {
            cout<<"Invalid index";
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<e>*temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
    void removeAtHead() {
        if (isEmpty()) {
            cout<<"list is empty"<<endl;
        }
        Node<e>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void removeAtTail() {
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
        }
        else if(head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node<e>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        size--;
    }
    int retrieveAt(int index) {
        if (index<0||index>=size){
            cout<<"Invalid index"<<endl;
        }
        Node<e>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    void replaceAt(int newvalue, int index) {
        if (index<0||index>=size) {
            cout<<"Invalid index";
        }
        Node<e>* temp= head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = newvalue;
    }
    bool isItemAtEqual(int element, int index) {
        if (index < 0 || index >= size) {
            cout<<"Invalid index";
        }
        Node<e>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data == element;
    }
    int linkedListSize() {
        return size;
    }
    void swap(int firstIndex, int secondIndex) {
        if (firstIndex<0||firstIndex>size||secondIndex<0||secondIndex>size){
            cout<<"Invalid index";
        }
        Node<e>* prevFirst = nullptr;
        Node<e>* currFirst = head;
        for (int i = 0; i < firstIndex; i++) {
            prevFirst = currFirst;
            currFirst = currFirst->next;
        }
        Node<e>* prevSecond = nullptr;
        Node<e>* currSecond = head;
        for (int i = 0; i < secondIndex; i++) {
            prevSecond = currSecond;
            currSecond = currSecond->next;
        }
        if (prevFirst != nullptr) {
            prevFirst->next = currSecond;
        } else {
            head = currSecond;
        }
        if (prevSecond != nullptr) {
            prevSecond->next = currFirst;
        } else {
            head = currFirst;
        }
        Node<e>* temp = currFirst->next;
        currFirst->next = currSecond->next;
        currSecond->next = temp;
    }
};
int main(){
    linklist<int> list;
    list.insertAtHead(2);
    list.insertAtHead(4);
    list.insertAtHead(9);
    list.insertAtTail(10);
    list.insertAt(7,0);
    list.print();
    cout<<endl;
   cout<< list.retrieveAt(2)<<" retreive"<<endl;
   cout<<endl;
    list.swap(0,4);
    list.print();
    cout<<endl;
    list.removeAt(1);
    list.removeAtHead();
    list.removeAtTail();
    list.print();
    cout<<endl;
    list.swap(0,1);
    list.print();
    cout<<endl;
 cout<<boolalpha<< list.isfound(2);
list.swap(1,1);
list.replaceAt(10,2);
list.print();
}
