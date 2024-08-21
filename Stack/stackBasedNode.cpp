#include <iostream>
using namespace std;
template <class t>
class stack{
    struct node{
        t item;
        node *next;
    };
    node *top,*curr;
    int size;
public:
    stack(){
        top = nullptr;
        size = 0;
    }
    void push(t value){
        node *newItem = new node;
        if(newItem == nullptr){
            cout<<"Stack push cannot allocate memory";
        }
        newItem->item = value;
        newItem->next = top;
        top = newItem;
        size++;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    t pop() {
        t element;
        if (isEmpty()) {
            cout << "Stack is empty on pop"<<endl;
            return -1;
        } else {
            element = top->item;
            node *temp = top;
            top = top->next;
            temp = temp->next = nullptr;
            delete temp;
            size--;
            cout<<element<<endl;
        }
        return element;
    }
    t Top(){
        if(isEmpty()){
            cout<<"Stack empty on Top"<<endl;
            return -1;
        }else {
            cout<<top->item<<endl;
        }
        return top->item;
    }
    int stackSize(){
        return size;
    }
    void clear(){
        while (!isEmpty()){
            node *temp = top;
            top = top->next;
            temp = temp->next = nullptr;
            delete temp;
            size--;
        }
    }
    void print(){
        if (isEmpty()) {
            cout << "Stack is empty";
        }
        curr = top;
        while (curr != nullptr){
            cout<<curr->item<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};
int main(){
    stack <int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.pop();
    s.Top();
    s.print();
    cout<<s.stackSize();
}

