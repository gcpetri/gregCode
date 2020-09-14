# include <iostream>
# include <string>
# include "queue.h"
# include "stack.h"

int main() {
    std::cout << "         Welcome to the simple Queue and Stack integer data structure generator          \n";
    std::string menu = "            Please select which data structure you'd like to generate:               \n            S: for stack             Q: for queue          B: for both        \n";
    std::cout << menu;
    char selection;
    std::cin >> selection;
    while (selection != 'S' && selection != 's' && selection != 'Q' && selection != 'q' && selection != 'B' && selection != 'b') {
        std::cout << "you made an invalid selection, please choose again\n";
        std::cout << menu;
        std::cin >> selection;
    }
    std::cout << "please enter the capacity of your data structure(s): ";
    int size = 0;
    std::cin >> size;
    std::cout << "\n######log: \n";
    Stack s(size);
    Queue q(size);
    if (selection == 'S' || selection == 's') {
        q.~Queue();
        std::cout << "#######\n\nyour stack is called \"s\"\n\n";
    } else if (selection == 'Q' || selection == 'q') {
        s.~Stack();
        std::cout << "#######\n\nyour queue is called \"q\"\n\n";
    } else if (selection == 'B' || selection == 'b') {
        std::cout << "#######\n\nyour stack is called \"s\"\n\n";
        std::cout << "#######\n\nand your queue is called \"q\"\n\n";
    }
    std::cout << "            to see your options, type s or q, followed by .help()              \n";
    std::cout << "                          to quit, simply type \"quit\"                        \n";
    std::string orders = " ";
    while (orders != "quit") {
        std::cin >> orders;
        if (orders == "s.help()")
            s.help();
        else if (orders == "q.help()")
            q.help();
        else if (orders == "q.isEmpty()")
            std::cout << q.isEmpty();
        else if (orders == "q.first()")
            std::cout << q.first();
        else if (orders == "q.enqueue()") {
            std::cout << "enter a number to add to queue: ";
            int num;
            std::cin >> num;
            q.enqueue(num);
        }
        else if (orders == "q.dequeue()")
            q.dequeue();
        else if (orders == "q.size()")
            std::cout << q.size();
        else if (orders == "q.print()")
            q.print();
        else if (orders == "s.isEmpty()")
            std::cout << s.isEmpty();
        else if (orders == "s.topOfStack()")
            std::cout << s.topOfStack();
        else if (orders == "s.pop()")
            std::cout << s.pop();
        else if (orders == "s.push()") {
            int num = 0;
            std::cout << "enter a number to push to the stack: ";
            std::cin >> num;
            std::cout << s.push(num);
        }
        else if (orders == "s.size()")
            std::cout << s.size();
        else if (orders == "s.print()")
            s.print();
        else if (orders == "quit")
            std::cout << ":(\n";
        else 
            std::cout << "... invalid command ...\n";
        std::cout << '\n';
    }
    std::cout << "               Thank you for your participation!               \n\n";
    return 0;
}