# ifndef QUEUE_H
# define QUEUE_H

# include <iostream>

// a typical integer array queue in c++
class Queue {
    private:
        int capacity;
        int* array;
        int front;
        int rear;
        int count;
    public:
        Queue();
        Queue(int cap);
        Queue(const Queue& q);
        Queue& operator=(const Queue& q);
        ~Queue();
        Queue(Queue&& q);
        Queue& operator=(Queue&& q);
        // check if array is empty
        bool isEmpty() {
            if (count == 0 || array == nullptr)
                return true;
            return false;
        }
        // return first object
        int first();
        // insert object in queue
        void enqueue(const int element);
        // resize the queue
        void resize();
        // remove first object
        int dequeue();
        // number of objects
        int size() const;
        // prints the array
        void print();
        // prints the help menu
        void help();
};

// function definitions
Queue::Queue() : capacity(0), array(0), front(0), count(0), rear(0) { std::cout << "defualt queue constructor called!\n"; }
Queue::Queue(int cap) : capacity(cap), array(new int[cap]), front(0), count(0), rear(cap-1) { std::cout << "parametrized queue constructor called!\n"; }
Queue::Queue(const Queue& q) {
    this->capacity = q.capacity;
    this->front = q.front;
    this->rear = q.rear;
    this->count = q.count;
    this->array = new int[q.capacity];
    for (int i = 0; i < this->count; i++)
        this->array[i] = q.array[i];
    std::cout << "queue copy constructor called!\n";
}
Queue& Queue::operator=(const Queue& q) {
    this->capacity = q.capacity;
    this->front = q.front;
    this->rear = q.rear;
    this->count = q.count;
    for (int i = 0; i < this->count; i++)
        this->array[i] = q.array[i];
    std::cout << "queue copy assignment operator called!\n";
    return *this;
}
Queue::~Queue() {
    this->capacity = 0;
    this->front = 0;
    this->rear = 0;
    this->count = 0;
    delete[] this->array;
    this->array = nullptr;
    std::cout << "queue destructor called!\n";
}
Queue::Queue(Queue&& q) {
    this->capacity = q.capacity;
    this->front = q.front;
    this->rear = q.rear;
    this->count = q.count;
    this->array = q.array;
    q.array = nullptr;
    std::cout << "queue move constructor called!\n";
}
Queue& Queue::operator=(Queue&& q) {
    if (this == &q) 
        return *this;
    delete[] this->array;
    this->capacity = q.capacity;
    this->front = q.front;
    this->rear = q.rear;
    this->count = q.count;
    this->array = q.array;
    q.array = nullptr;
    std::cout << "queue move assignment called!\n";
    return *this;
}
int Queue::first() {
    if (this->isEmpty())
        throw std::invalid_argument("Action terminated: queue is empty\n");
    std::cout << "the first item in Queue is: ";
    return this->array[this->front];
}
void Queue::enqueue(const int element) {
    if (this->count == this->capacity)
        resize();
    this->rear = (this->rear+1) % capacity;
    this->array[this->rear] = element;
    count++;
    std::cout << "element added to queue!\n";
}
void Queue::resize() {
    int* b = new int[this->capacity+1]{0};
    for (int i = 0; i < this->count; i++) {
        b[i] = this->array[i];
    }
    delete[] this->array;
    this->array = b;
    b = nullptr;
    this->capacity++;
}
int Queue::dequeue() {
    if (this->count == 0 || this->array == nullptr)
        throw std::invalid_argument("Action terminated: queue is empty\n");
    this->count--;
    int frt = this->array[this->front];
    this->front = (this->front+1) % capacity;
    std::cout << "element removed from queue: ";
    return frt;
}
int Queue::size() const { return this->count; }
void Queue::print() {
    for (int i = 0; i < this->count; i++)
        std::cout << this->array[i] << ' ';
}
void Queue::help() {
    std::cout << " q.isEmpty() - true if queue is empty, false otherwise\n q.first() - returns first object in queue\n q.enqueue() - places elements at the back of the queue\n";
    std::cout << " q.dequeue() - removes the object next in line\n q.size() - returns the size of the queue\n q.print() - prints the array of elements that make-up the queue\n";
}

# endif