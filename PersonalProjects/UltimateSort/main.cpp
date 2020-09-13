# include <iostream>
# include <string>
# include "overall_sort.h"

//### calls the user menu ###//
void call_menu(char& c) {
        char s;
        std::string menu_choice = "               Enter the letter corresponding to your selection here below            \n";
        std::string menu_ = "    A: selection sort   D: shell Sort   G: radix Sort   \n   B: insertion sort   E: merge sort   H: bucket sort\n   C: bubble sort   F: Counting Sort   I: All\n";
        std::cin >> s;
        c = s;
}

//### compile using g++ main.cpp to sort your data set ###//
int main() {
    //### opening program ###//
    std::cout << "                        Welcome to the Ultimate Sorting Package                           \n";
    std::cout << "   Here you can chose any one or all of the sorting algorithms below to sort your data   \n";
    std::cout << "                        what will be the size of your input array: ";
    int sz;
    std::cin >> sz;
    std::cout << "              Please input your array with the command line below to get started             \n";
    int* input = new int[sz];
    for (int i = 0; i < sz; i++) {
        std::cin >> input[i];
    }
    char selection = 'a';
    //### calls the menu once ###//
    call_menu(selection);
    //### creates a OverallSort class instance ###//
    OverallSort Sort(input, sz);
    //### bool to check if menu choice is valid ###//
    bool goodChoise = false;
    //### loops until the choice is valid ###//
    while (!goodChoise) {
        switch (selection) {
            case ('A') : Sort.selection_sort(), goodChoise = true;
                break;
            case ('B') : Sort.insertion_sort(), goodChoise = true;
                break;
            case ('C') : Sort.bubble_sort(), goodChoise = true;
                break;
            case ('D') : Sort.shell_sort(), goodChoise = true;
                break;
            //case ('E') : Sort.merge_sort(), goodChoise = true;
            //    break;
            case ('F') : Sort.counting_sort(), goodChoise = true;
                break;
            case ('G') : Sort.radix_sort(), goodChoise = true;
                break;
            //case ('H') : Sort.bucket_sort(), goodChoise = true;
            //    break;
            case ('I') : Sort.all(), goodChoise = true;
                break;
            default : call_menu(selection), goodChoise = false;
                break;
        }
    }
    std::cout << "      Wonderful, you chose " << selection << ", the results are below,\n" <<
                        "along with the real and estimated runtime of the algorithm(s)\n";

    return 0;
}