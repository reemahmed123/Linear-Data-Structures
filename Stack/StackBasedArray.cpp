#include <iostream>
using namespace std;
const long long max_size = 100000;
template <class T>
class Stack{
    int top;
    T item[max_size];
public:
    Stack(){
        top = -1;
    }
    void push(T element){
        if (top >= max_size - 1 ){
            cout<<"Stack is full";
        } else{
            top++;
            item[top] = element;
        }
    }
    bool isEmpty(){
        return top == -1;
    }
    T pop(){
        T element;
        if(isEmpty()){
            cout<<"Stack is empty on pop"<<endl;
            return -1;
        } else {
            element = item[top];
            cout<<element<<endl;
            top--;

        }
        return element;
    }
    T Top(){
        if(isEmpty()){
            cout<<"Stack is empty on Top"<<endl;
            return -1;
        }else {
            cout<<item[top]<<endl;
        }
        return item[top];
    }
    int stackSize(){
        return top + 1;
    }
    void clear(){
        top = -1;
    }
    void print(){
        if (isEmpty()) {
            cout << "Stack is empty";
        }
        for(int i = top; i >= 0; i--){
            cout<<item[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
     Stack <int> s;
     s.push(5);
     s.push(10);
     s.push(15);
     s.push(20);
     s.pop();
     s.Top();
     s.print();
    cout<<s.stackSize();

}