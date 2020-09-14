# include <iostream>
# include "queue.h"
# include "stack.h"

int main() {
    std::cout << '\n';
    //### constructor demonstrations ###//
    Queue q;
    Queue q1(3);
    Stack s;
    Stack s1(3);
    std::cout << '\n';
    //### copy constructor demonstrations ###//
    Queue q2(q1);
    Queue q3 = q1;
    Stack s2(s1);
    Stack s3 = s1;
    std::cout << '\n';
    //### copy assignmnet demonstration ###//
    q3 = q1;
    s3 = s1;
    std::cout << '\n';
    //### destructor demonstration ###//
    /* when program ends, should destruct 6 Queue class and 6 Stack class objects */
    //### move constructor demonstrations ###//
    Queue q4(std::move(q2));
    Queue q5 = std::move(q3);
    Stack s4(std::move(s2));
    Stack s5 = std::move(s3);
    std::cout << '\n';
    //### move assignment demonstration ###//
    q5 = std::move(q4);
    s5 = std::move(s4);
    std::cout << '\n';
    //### enqueue() demonstrations ###//
    q5.enqueue(3);
    q5.enqueue(10);
    q5.enqueue(-3);
    s5.push(4);
    s5.push(11);
    s5.push(-2);
    std::cout << '\n';
    //### first() demonstration ###//
    std::cout << q5.first() << '\n';
    std::cout << s5.topOfStack();
    std::cout << "\n\n";
    //### dequeue() demonstration ###//
    std::cout << q5.dequeue() << '\n';
    std::cout << q5.dequeue() << '\n';
    std::cout << q5.dequeue() << '\n';
    std::cout << s5.pop() << '\n';
    std::cout << s5.pop() << '\n';
    std::cout << s5.pop() << '\n';
    std::cout << '\n';

    return 0;
}