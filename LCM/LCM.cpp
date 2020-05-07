#include <vector>
#include <iostream>
// hello edit
int findMaxIndex(std::vector<int>& vec, const unsigned int length) {
    int maxNum = vec.at(0);
    int maxIndex = 0;
    for(int i = 0; i < length - 1; i++) {
        if (vec.at(i) > maxNum) {
            maxNum = vec.at(i);
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findLCM(std::vector<int>& vec, const unsigned int length) {
    int maxIndex = findMaxIndex(vec, length);
    int i = 1;
    int nextNum = 0;
    int maxNum = vec.at(maxIndex);
    bool yOn = false;
    while(!yOn) {
        nextNum = maxNum * i;
        for (int i = 0; i < length; i++) {
            if (nextNum % vec.at(i) != 0) {
                yOn = false;
                break;
            }
            yOn = true;
        }
        i++;
    }
    return nextNum;
}

int main() {
    std::vector<int> vec;
    int input = 0;
    std::cout << "Enter a number, when done enter -1: ";
    std::cin >> input;
    while (input != -1) {
        std::cout << "Enter a number, when done enter -1: ";
        vec.push_back(input);
        std::cin >> input;
    }
    int length = vec.size();
    int lcm = findLCM(vec, length);
    std::cout << "LCM = " << lcm << '\n';
    return 0;
}
