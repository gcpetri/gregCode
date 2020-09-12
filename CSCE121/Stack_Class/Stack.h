#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    private:
        T* A;
        int capacity = 1;

    public:
        int length = 0;
        // constructor
        Stack() {
            A = new T[capacity];
        }
        // isEmpty
        bool isEmpty() {
            if (length > 0)
                return false;
            else
                return true;
        }
        // push
        void push(T userVal) {
            if (length < capacity) {
                A[length] = userVal;
                ++length;
            }
            else {
                capacity = capacity * 2;
                T* C = new T[capacity];
                for (int i = 0; i < length; i++) {
                    C[i] = A[i];
                }
                C[length] = userVal;
                delete[] A;
                A = C;
                ++length;
            }
        }
        // pop
        T pop() {
            if (!isEmpty()) {
                T popped = A[length - 1];
                --length;
                return popped;
            }
            else {
                exit(0);
            }
        }
        // destructor
        ~Stack() {
            delete[] A;
        }
};
#endif