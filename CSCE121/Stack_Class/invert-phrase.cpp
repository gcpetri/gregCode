#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack<string> s;

    // YOUR CODE GOES HERE
    string userStr;
    cin >> userStr;
    while(userStr.back() != '.') {
        s.push(userStr);
        cin >> userStr;
    }
    int len = userStr.size();
    string userStrLast;
    for (int i = 0; i < len - 1; i++) {
        userStrLast += userStr[i];
    }
    s.push(userStrLast);
    for (int i = s.length; i > 0; i--) {
        if (i > 1) {
            cout << s.pop() << ' ';
        }
        else 
            cout << s.pop() << '\n';
    }
    return 0;
}
