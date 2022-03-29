#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();


    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear(); 
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();

    void resize();

    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}



template<typename T>
void CircularArray<T> :: push_back(T data){

    if(back == -1 || front == -1){
        back = 0; front = 0;
        array[0] = data;

    }else{
        if(is_full())
            resize();

        array[next(back)] = data;
        back = next(back);
    }
}

template<typename T>
T CircularArray<T>:: pop_front(){
    T res = array[front];

    if( front == back){
        front == -1;
        back == -1;
    }else{
        front = next(front);
    }

    return res;
}

template<typename T>
void CircularArray<T> :: resize(){
    int* new_arr = new T[capacity * 2];
    int x = 0;
    //asignando los valores anteriores

    while (true){
        new_arr[x] = array[front];
        front = next(front);
        ++x;

        if(front == back)
            break;
    }

    //eliminando el array anterior
    delete [] array;
    
    //reasignando los valores
    capacity = capacity*2;
    array = new_arr;
    front = 0;
    back = x;
}

template<typename T>
void CircularArray<T> :: clear(){
    front = -1;
    back = -1;
}

template<typename T>
void CircularArray<T> :: sort(){
    T * new_arr = new T[size()];
    int x = 0;

    while (true){
        new_arr[x] = array[front];
        front = next(front);
        ++x;

        if(front == back)
            break;
    }

    delete [] array;

    array = new_arr;
    front = 0;
    back = x;

    std::sort(array + front, array + back);
}