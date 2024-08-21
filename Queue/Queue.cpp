#include <iostream>
using namespace std;
const int MAX=1000;
template<class b>
class arrayQueue{
private:
    int Front;
    int Back;
    int size;
    b arr[MAX];
public:
    arrayQueue(){
        Front=0;
        Back=0;
        size=0;

    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(b item){
        if(size==MAX){
            cout<<"Queueu full can not enqueue ...!/n";
        }
        else{
            arr[Back]=item;
            Back++;
            size++;
        }
    }

    b dequeue(){
        if(!isEmpty()){
            b temp=arr[Front];
            Front++;
            size--;
            return temp;
        }
    }

    b first(){
        if(!isEmpty()) {
            return arr[Front];
        }
    }

    void print(){
        if(isEmpty()){
            cout<<"Empty queue!\n";
        }
        else {
            cout << "[ ";
            for (int i = Front; i < Back; i++) {
                cout << arr[i] << " ";
            }
            cout << "]\n";
        }
    }
    void clear(){
        size=0;
        Front==Back==0;
    }
    int queueSize(){
        return size;
    }
};
template<class T>
class linkedQueue {
private:
    struct Node {
        T item;
        Node *next;
    };
    Node *Front;
    Node *Back;
    int size;
public:
    linkedQueue() {
        Front = NULL;
        Back = NULL;
        size = 0;
    }

    bool isEmpty() {
        if (size==0) { return true; }
        else { return false; }
    }

    void enqueue(T item) {
        Node *newNode = new Node;
        newNode->item = item;
        newNode->next = NULL;
        if (isEmpty()) {
            Back = Front = newNode;
        } else {
            Back->next = newNode;
            Back = newNode;
        }
        size++;
    }

    T dequeue() {
        if (!isEmpty()) {
            Node *Temp = Front;
            if (Front == Back) {
                Front = NULL;
                Back == NULL;
            } else {
                Front = Front->next;
                Temp->next = NULL;
            }
            T value = Temp->item;
            size--;
            delete Temp;
            return value;
        }
    }

    T first() {
        if (!isEmpty())
            { return Front->item; }
    }

    void clear(){
        Node *cur;
        while(Front!=NULL){
            cur=Front;
            Front=Front->next;
            delete cur;
        }
        Back=NULL;
        size=0;
    }

    void print(){
        if(isEmpty())cout<<"empty queue!\n";
        else {
            Node *cur = Front;
            cout << "Items are: [ ";
            while (cur != NULL) {
                cout << cur->item << " ";
                cur = cur->next;
            }
            cout << "]\n";
        }
    }

    int queueSize(){
        return size;
    }
};

int main() {
    linkedQueue<int> q1;
    q1.enqueue(4);
    q1.enqueue(8);
    q1.enqueue(9);
   if(q1.isEmpty()){cout<<"Empty Queue can not deque item!\n";}
   else cout<<q1.dequeue()<<"\n";
   if(q1.isEmpty()) {cout<<"Empty Queue!\n";}
   else {cout<<q1.first()<<"\n";}
    q1.print();
    cout<<q1.queueSize()<<"\n";
    q1.clear();
    q1.print();
    cout<<q1.queueSize()<<"\n";
    cout<<"-------------------------------------\n";
    /*arrayQueue<int> q2;
    q2.enqueue(4);
    q2.enqueue(8);
    q2.enqueue(9);
    if(q2.isEmpty()){cout<<"Empty Queue can not deque item!\n";}
    else cout<<q2.dequeue()<<"\n";
    if(q2.isEmpty()) {cout<<"Empty Queue!\n";}
    else {cout<<q2.first()<<"\n";}
    q2.print();
    cout<<q2.queueSize()<<"\n";
    q2.clear();
    q2.print();
    cout<<q2.queueSize()<<"\n";*/
    return 0;
}
