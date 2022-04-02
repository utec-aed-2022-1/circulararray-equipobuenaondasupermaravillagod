#ifndef QUEUE_H
#define QUEUE_H

#include "circularArray.h"


template <typename T>
class QueueArray : public CircularArray<T> { 
public:
    QueueArray():CircularArray<T>(){}
    QueueArray(int size):CircularArray<T>(size){}

    void enqueue(T data);
    T dequeue();
    void display();

    T front();
    T back();
    bool empty();
    int size_queue();
};


template<typename T>
void QueueArray<T>:: enqueue(T data){
  CircularArray<T>:: push_back(data);
}

template<typename T>
T QueueArray<T>:: dequeue(){
  return CircularArray<T>:: pop_front();
}

template<typename T>
void QueueArray<T>:: display(){
  CircularArray<T>:: imprimir();
}

template<typename T>
T QueueArray<T>:: front(){
  return CircularArray<T>:: get_front();
}

template<typename T>
T QueueArray<T>:: back(){
  return CircularArray<T>:: get_back();
}

template<typename T>
bool QueueArray<T>::empty(){
  return CircularArray<T> :: is_empty();
}

template<typename T>
int QueueArray<T>::size_queue(){
  return CircularArray<T> :: size();
}

#endif //QUEUE_H