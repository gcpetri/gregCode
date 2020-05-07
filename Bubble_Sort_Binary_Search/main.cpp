#include <iostream>
#include <vector>

void bubSort(std::vector<int>& vecOrdered, const unsigned int length) {
        for (int i = 0; i < length; i++) {
            for (int j = i+1; j < length; j++) {
                if (vecOrdered.at(j) < vecOrdered.at(i)) {
                    int holder = vecOrdered.at(i);
                    vecOrdered.at(i) = vecOrdered.at(j);
                    vecOrdered.at(j) = holder;
                }
            }
        }
}

int binSearch(std::vector<int> vecOrdered, const unsigned int length, int numSearch) {
    int currIndex = (length - 1) / 2;
    int upperIndex = length - 1;
    int lowerIndex = 0;
    while (numSearch != vecOrdered.at(currIndex)) {
        if (numSearch > vecOrdered.at(currIndex)) {
            lowerIndex = currIndex;
            currIndex = currIndex + ((upperIndex - lowerIndex) / 2);
        }
        else {
            upperIndex = currIndex;
            currIndex = (upperIndex - lowerIndex) / 2;
        }
    }
    return currIndex;
}

int main() {
    std::cout << "When done enter -1\n";	    
    std::vector<int> vec;
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    int i = 0;
    while(input != -1) {
        vec.push_back(input);
        std::cout << "Enter a number: ";
        std::cin >> input;
    }
    const unsigned int length = vec.size();
    std::cout << "Enter number to search for: ";
    int numSearch;
    std::cin >> numSearch;
    std::vector<int> vecOrdered = vec;
    bubSort(vecOrdered, length);
    std::cout << "Ordered List of your Numbers: \n";
    for (int i = 0; i < length; i++) {
        std::cout << vecOrdered.at(i) << ' ';
    }
    int sortedIndex = binSearch(vecOrdered, length, numSearch) << '\n';
    std::cout << "Index of " << numSearch << " in the ordered list:   " << sortedIndex << std::endl;
    return 0;
}
