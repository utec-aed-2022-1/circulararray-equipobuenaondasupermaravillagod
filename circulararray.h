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

// constructores

template <class T>
CircularArray<T>::CircularArray(){
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity){
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

// destructor

template <class T>
CircularArray<T>::~CircularArray(){
    delete[] array;
}

// prev - next - to_string

template <class T>
int CircularArray<T>::prev(int index){
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index){
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep){
    string result = "";
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;
}

// fernando - juan

template<typename T>
bool CircularArray<T> :: is_empty(){
    if(front==-1 && back==-1)
        return true;
    else
      return false;
}   /*
        evalua si front y back valen -1 (valores iniciales en el constructor)
    */

template<typename T>
bool CircularArray<T> :: is_full(){
    if(capacity==size()){
        return true;
    }
    else{
        return false;
    }
}   /*
        evalua que capacity sea igual al valor de size()
    */

template<typename T>
void CircularArray<T> :: clear(){
    front = -1;
    back = -1;
}   /*
        Vuelvo a las posiciones inciales el front y el back
    */

template<typename T>
void CircularArray<T> :: resize(){
    int* new_arr = new T[capacity * 2];

    int index = 0;
    while(true){
        new_arr[index] = array[front];

        if(front == back){
            break;
        }
      
        front = next(front);
        index++;
       
    }

    delete [] array;

    array = new_arr;
    front = 0;
    back = index;
    capacity = capacity*2;
}   /*
        1 - crea un array nuevo
        2 - bucle infinito para llenar el array nuevo (con + espacio) con los valores del array antiguo
        3 - se libera la memoria del array antiguo (que ya no sirve)
        4 - el front se reinicia a 0 y el back se vuelve el index ([0,back])
        5 - se actualiza el valor de capacity
    */

template<typename T>
void CircularArray<T> :: push_back(T data){
    if(is_empty()){
        back = front = 0;
        array[0] = data;
    }
    else{
        if(is_full()){
            resize();
        }
        back = next(back);
        array[back] = data;
    }
}   /*
        - if : evalua si esta vacio (front==back==-1) para asi poner el primer elemento en el circulararray (front y back se vuelven 0)
        - else : evalua si esta lleno para asi hacer un resize
        - el back avanza un espacio y se coloca el valor en el circulararray
    */

template<typename T>
void CircularArray<T> :: push_front(T data){
    if(front==-1 && back==-1){
        back = front = 0;
        array[0] = data;
    }
    else{
        if(is_full()){
            resize();
        }
        front = prev(front);
        array[front] = data;
    }
}   /*
        misma logica que el push_back
    */

template<typename T>
int CircularArray<T> :: size(){
    int sz = 1;
    int n_front = front;
    while(true){
        n_front = next(n_front);
        sz++;
        if(n_front == back){
            break;
        }
    }
    return sz;
}   /*
        va del n_front (front) al back mediante "next" (== ir del back al front mediante "prev") para con un contador inicializado en 1 contar la cantidad de datos que existentes
    */

template<typename T>
T CircularArray<T> :: pop_back(){

}


template<typename T>
T CircularArray<T>:: pop_front(){
    T res = array[front];

    if( front == back)
        clear();
    else
        front = next(front);
    
    return res;
}   /*
        Si verifico que el array tiene un solo elemento limpio el array, sino solo muevo el front a la siguiente posicion.
    
*/


template<typename T>
void CircularArray<T> :: sort(){
    T * new_arr = new T[size()];
    int x = 0;

    while (true){
        new_arr[x] = array[front];

        if(front == back)
            break;
    
        front = next(front);
        ++x;
    }

    delete [] array;

    array = new_arr;
    front = 0;
    back = x;

    cout << "antes de ordenar" << endl;

    imprimir();
  
    std::sort(array + front, array + back + 1);
}   /*
        Reubico los datos del array para posteriormente aplicar el algoritmo de ordenamiento. Para ello utilizo el mismo algoritmo del resize, con la diferencia
        que ahora no aumento la capacidad del array.
    */



template<typename T>
void CircularArray<T> :: reverse(){
    int temp_front = front;
    int temp_back = back;

    while (abs(temp_back - temp_front) > 1){
        T temporal = array[temp_front];
        
        array[temp_front] = array[temp_back];
        array[temp_back] = temporal;

        temp_back = prev(temp_back);
        temp_front = next(temp_front);
    }
}   /*
      
    Intercambio las posiciones de los valores extremos del array circular(front y back), siempre y cuando la diferencia entre front y back sea mayor a 1.
    */
