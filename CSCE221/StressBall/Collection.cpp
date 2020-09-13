#include "Collection.h"
#include "Stress_ball.h"
#include <string>
#include <ctime>
#include <stdlib.h>
#include <stdexcept>
// ########## Constructors ######## //
// constructor
Collection::Collection() : array(nullptr), size(0), capacity(0) {}
// parametrized constructor
Collection::Collection(int cap) : size(0), capacity(cap) {
    array = new Stress_ball[cap];
}
// ################################ //
// ############ Big 5 ############# // 
// copy constructor
Collection::Collection(const Collection& c) {
    size = c.size;
    capacity = c.capacity;
    array = new Stress_ball[capacity];
    for (int i = 0; i < c.size; i++) {
        array[i] = c.array[i];
    }
}
// copy assignment operator
Collection& Collection::operator=(const Collection& c) {
    if (this != &c) {
        if (size != 0) {
            delete[] array;
        }
        size = c.size;
        capacity = c.capacity;
        array = new Stress_ball[capacity];
        for (int i = 0; i < size; i++) {
            array[i] = c.array[i];
        }
    }
    return *this;
}
// destructor
Collection::~Collection() {
    delete[] array;
    array = nullptr;
    size, capacity = 0;
}
// move constructor
Collection::Collection(Collection&& c) {
    size = c.size;
    capacity = c.capacity;
    array = c.array;
    c.size, c.capacity = 0;
    c.array = nullptr;
}
// move operator
Collection& Collection::operator=(Collection&& c) {
    if (this != &c) {
        if (size != 0) {
            delete[] array;
        }
        size = c.size;
        capacity = c.capacity;
        array = c.array;
        c.size, c.capacity = 0;
        c.array = nullptr;
    }
    return *this;
}
// ############################ //
// ## Collection Specific Functions ## //
// resize private function to double the array's capacity
void Collection::resize() {
    if (capacity == 0) {
        capacity = 1;
        array = new Stress_ball[1];
    }
    else {
        capacity *= 2;
        Stress_ball *arr = new Stress_ball[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = array[i];
        }
        array = arr;
        arr = nullptr;
    }
}
// insering an item to the last position in the array
void Collection::insert_item(const Stress_ball& sb) {
    if (capacity == 0 || size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
}
// contains: returns true if collection has a stress ball with the same color and size as the input
bool Collection::contains(const Stress_ball& sb) const {
    for (int i = 0; i < size; i++) {
        if ((array[i].get_color() == sb.get_color()) && (array[i].get_size() == sb.get_size())) {
            return true;
        }
    }
    return false;
}
// removes and return a random stress ball
Stress_ball Collection::remove_any_item() {
    // starts a time generator
    if (size == 0 || array == nullptr) {
        throw std::invalid_argument("Collection is empty");
    }
    int temp = rand() % size;
    Stress_ball sb(array[temp].get_color(), array[temp].get_size());
    for (int i = temp + 1; i < size; i++) {
        array[i-1] = array[i];
    }
    size--;
    return sb;
}
// removes but does NOT return a specific stress ball
void Collection::remove_this_item(const Stress_ball& sb) {
    int position = 0;
    if (size == 0 || array == nullptr) {
        throw std::invalid_argument("Collection is empty");
    }
    for (int i = 0; i < size; i++) {
        if (array[i] == sb) {
            position = i;
            for (int j = position+1; j < size; j++) {
                array[j-1] = array[j];
            }
            size--;
            break;
        }
    }
}
// empties the array, sets size and capcity to 0
void Collection::make_empty() {
    size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}
// returns true if the collection is empty (size = 0)
bool Collection::is_empty() const {
    if (size == 0 || array == nullptr) {
        return true;
    }
    return false;
}
// returns number of items the collection contains
int Collection::total_items() const {
    const int sz = size;
    return sz;
}
// returns the number of stress balls in the collection with the same specified size
int Collection::total_items(Stress_ball_sizes s) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_size() == s) {
            count++;
        }
    }
    const int ct = count;
    return ct;
}
// returns the number of stress balls in the collection with the same specified color
int Collection::total_items(Stress_ball_colors c) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_color() == c) {
            count++;
        }
    }
    const int ct = count;
    return ct;
}
// prints all the stress balls in the collection
void Collection::print_items() const {
    if (size == 0 || array == nullptr) {
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << '\n';
    }
}
// overloading operator to access a stress ball from a collection class
Stress_ball& Collection::operator[](int i) {
    return array[i];
}
// overloading operator to access a stress ball from a constant collection class
const Stress_ball& Collection::operator[](int i) const {
    return array[i];
}
// ################################### //
// ### Functions outside Collection class ### //
// reads color and size data from file and creates stress balls to put in collection class instance c
istream& operator>>(istream& is, Collection& c) {
    std::string strColor;
    std::string strSize;
    c.make_empty();
    while(is >> strColor >> strSize) {
        Stress_ball_colors cor;
        Stress_ball_sizes sz;
        if (strColor == "blue") {
            cor = Stress_ball_colors::blue;
        } else if (strColor == "yellow") {
            cor = Stress_ball_colors::yellow;
        } else if (strColor == "green") {
            cor = Stress_ball_colors::green;
        } else if (strColor == "red") {
            cor = Stress_ball_colors::red;
        }  
        if (strSize == "large") {
            sz = Stress_ball_sizes::large;
        } else if (strSize == "medium") {
            sz = Stress_ball_sizes::medium;
        } else if (strSize == "small") {
            sz = Stress_ball_sizes::small;
        }
        Stress_ball sb(cor, sz);
        c.insert_item(sb);
    }
    return is;
}
// prints all items in c to cout
ostream& operator<<(ostream& os, const Collection& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << c[i];
    }
    return os;
}
// make a big collection holding c1 and c2 without altering c1 & c2
Collection make_union(const Collection& c1, const Collection& c2) {
    int sz = c1.total_items() + c2.total_items();
    Collection col(sz);
    for (int i = 0; i < c1.total_items(); i++) {
        col.insert_item(c1[i]);
    }
    for (int i = 0; i < c2.total_items(); i++) {
        col.insert_item(c2[i]);
    }
    return col;
}
// swaps collections c1 and c2
void swap(Collection& c1, Collection& c2) {
    Collection temp(c1);
    c1 = move(c2);
    c2 = move(temp);
    temp.make_empty();
}
// sorting functions
void bubbleSort(Collection& c) {
    for (int i = 0; i < c.total_items(); i++) {
        for (int j = 0; j < c.total_items() - 1; j++) {
            if ((c[j].get_size() == Stress_ball_sizes::large && c[j+1].get_size() != Stress_ball_sizes::large) || (c[j].get_size() == Stress_ball_sizes::medium && c[j+1].get_size() == Stress_ball_sizes::small)) {
                Stress_ball tempSb(c[j].get_color(), c[j].get_size());
                c[j] = c[j+1];
                c[j+1] = tempSb;
            }
        }
    }
}
void insertionSort(Collection& c) {
    for (int i = 0; i < c.total_items(); i++) {

        int j = i - 1;
        Stress_ball tempSb(c[i].get_color(), c[i].get_size());
        while (j >= 0 && ((c[j].get_size() == Stress_ball_sizes::large && tempSb.get_size() != Stress_ball_sizes::large) || (c[j].get_size() == Stress_ball_sizes::medium && tempSb.get_size() == Stress_ball_sizes::small))) {
            c[j+1] = c[j];
            j--;
        }
        c[j+1] = tempSb;
    }
}
void selectionSort(Collection& c) {
    for (int i = 0; i < c.total_items() - 1; i++) {
        int min = i;
        Stress_ball_sizes lrg = Stress_ball_sizes::large;
        Stress_ball_sizes med = Stress_ball_sizes::medium;
        Stress_ball_sizes sml = Stress_ball_sizes::small;
        for (int j = i + 1; j < c.total_items(); j++) {
            if ((c[j].get_size() != lrg && c[min].get_size() == lrg) || (c[j].get_size() == sml && c[min].get_size() == med)) {
                min = j;
            }
            Stress_ball tempSb(c[i].get_color(), c[i].get_size());
            c[i] = c[min];
            c[min] = tempSb;
        }
    }
}

// sorts the sollection by stress ball size and with the specified sorting function
void sort_by_size(Collection& c, Sort_choice sort) {
    if (c.is_empty()) {
        return;
    }
    switch (sort) {
        case (Sort_choice::bubble_sort) : bubbleSort(c);
            break;
        case (Sort_choice::insertion_sort) : insertionSort(c);
            break;
        case (Sort_choice::selection_sort) : selectionSort(c);
            break;
    }
}