# ifndef STACK_H
# define STACK_H

# include <iostream>

class Stack {
    private:
        int capacity;
        int* array;
        int top;
    public: 
        Stack();
        Stack(int cap);
        Stack(const Stack& s);
        Stack& operator=(const Stack& s);
        ~Stack();
        Stack(Stack&& s);
        Stack& operator=(Stack&& s);
        bool isEmpty() const;
        int topOfStack();
        int pop();
        void resize();
        int push(const int element);
        int size() const;
        void print();
        void help();
};

// function definitions
Stack::Stack() : capacity(0), top(-1), array(0) { std::cout << "default stack constructor called!\n"; }
Stack::Stack(int cap) : capacity(cap), array(new int[cap]), top(-1) { std::cout << "parametrized stack constructor called!\n"; }
Stack::Stack(const Stack& s) {
    this->capacity = s.capacity;
    this->top = s.top;
    this->array = new int[s.capacity];
    for (int i = 0; i <= this->top; i++)
        this->array[i] = s.array[i];
    std::cout << "stack copy constructor called!\n";
}
Stack& Stack::operator=(const Stack& s) {
    this->capacity = s.capacity;
    this->top = s.top;
    for (int i = 0; i <= this->top; i++) {
        this->array[i] = s.array[i];
    }
    std::cout << "stack copy assignment operator called!\n";
}
Stack::~Stack() {
    this->capacity = 0;
    this->top = 0;
    delete[] this->array;
    this->array = nullptr;
    std::cout << "stack destructor called!\n";
}
Stack::Stack(Stack&& s) {
    this->capacity = s.capacity;
    this->top = s.top;
    this->array = s.array;
    s.array = nullptr;
    std::cout << "stack move constrcutor called!\n";
}
Stack& Stack::operator=(Stack&& s) {
    if (this == &s)
        return *this;
    delete[] this->array;
    this->capacity = s.capacity;
    this->top = s.top;
    this->array = s.array;
    s.array = nullptr;
    std::cout << "stack move assignment called!\n";
    return *this;
}
bool Stack::isEmpty() const { return (this->top < 0); }
int Stack::topOfStack() {
    if (isEmpty())
        throw std::invalid_argument("Action terminated: array is empty\n");
    std::cout << "the top of the stack is: ";
    return (this->array[this->top]);
}
int Stack::pop() {
    if (isEmpty())
        throw std::invalid_argument("Action terminated: array is empty\n");
    std::cout << "stack element popped: ";
    return (this->array[this->top--]);
}
void Stack::resize() {
    int* b = new int[this->capacity*2]{0};
    for (int i = 0; i <= this->top; i++) {
        b[i] = this->array[i];
    }
    delete[] this->array;
    this->array = b;
    b = nullptr;
    this->capacity *= 2;
}
int Stack::push(const int element) {
    if (size() == this->capacity)
        resize();
    std::cout << "element pushed to stack: ";
    this->array[++this->top] = element;
}
int Stack::size() const { return (this->top + 1); }
void Stack::print() {
    for (int i = 0; i <= this->top; i++)
        std::cout << this->array[i] << ' ';
}
void Stack::help() {
    std::cout << " s.isEmpty() - returns true if the stack is empty, false otherwise\n s.topOfStack() - returns the elements at the top of the stack array (last in)\n s.pop() - returns and removes the s.topOfStack()\n";
    std::cout << " s.push() - places element at the top of the stack\n s.size() - returns the size of the stack array\n s.print() - prints the stack array elements\n";
}

# endif