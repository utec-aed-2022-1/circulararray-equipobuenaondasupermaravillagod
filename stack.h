#ifndef STACK_H
#define STACK_H


#include "circularArray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
public:

    StackArray(): CircularArray<T>(){}
    StackArray(int cap): CircularArray<T>(cap){}

    bool empty();
    void push(T data);
    T pop();
    void display();
    int size_stack();
};

template<typename T>
bool StackArray<T>::empty(){
  return CircularArray<T> :: is_empty();
}

template<typename T>
int StackArray<T>::size_stack(){
  return CircularArray<T>::size();
}

template<typename T>
void StackArray<T>:: push(T data){
  CircularArray<T>::push_back(data);
}

template<typename T>
T StackArray<T>:: pop(){
    return CircularArray<T>:: pop_back();
}

template<typename T>
void StackArray<T>:: display(){
  CircularArray<T>::imprimir();
}

#endif //STACK_H