/*
Patricia Bivol
2421265
bivol@chapman.edu
CPSC 350 Section 04
PA3
*/
#ifndef MONO_STACK_H
#define MONO_STACK_H

template <typename T>
class MonoStack {
    public:
        MonoStack(int initialSize, char o);
        virtual ~MonoStack();
        void push(T X);
        T pop();
        T peek();
        bool isFull();
        bool isEmpty();
        int size();

    protected:
        T* arr;
        int count;

    private:
        int maxSize;
        bool isDecreasing;
};

// constructor for MonoStack
template <typename T>
MonoStack<T>::MonoStack(int initialSize, char o) {
    maxSize = initialSize;
    count = 0;
    arr = new T[maxSize];

    // determining whether we have a decreasing or increasing MonoStack
    if (o == 'i') {
        isDecreasing = false;
    } else if (o == 'd') {
        isDecreasing = true;
    }
}

// deconstructor
template <typename T>
MonoStack<T>::~MonoStack() {
    delete[] arr;
}

// push method 
template <typename T>
void MonoStack<T>::push(T X) {
    // if the MonoStack is full, create a new one of twice the size
    // delete old one 
    if (isFull()) {
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = arr[i];
        }
        maxSize *= 2;
        delete[] arr;
        arr = temp;
    }

    // if it is a decreasing MonoStack pop numbers that are less or equal to X
    if (isDecreasing) {
        while (!isEmpty() && peek() <= X) {
            pop();
        }
    // else pop numbers greater or equal to X
    } else {
        while (!isEmpty() && peek() >= X) {
            pop();
        }
    }

    arr[count++] = X;
}

template <typename T>
T MonoStack<T>::pop() {
    return arr[count--];
}

template <typename T>
T MonoStack<T>::peek() {
    return arr[count-1];
}

template <typename T>
bool MonoStack<T>::isFull() {
    return count == maxSize;
}

template <typename T>
bool MonoStack<T>::isEmpty() {
    return count == 0;
}

template <typename T>
int MonoStack<T>::size() {
    return count;
}

#endif