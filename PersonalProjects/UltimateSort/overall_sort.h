# ifndef OVERALL_SORT_H
# define OVERALL_SORT_H
# include <iostream>
# include <algorithm>
# include <ctime>

class OverallSort {
    private: 
        int size;
        int* array;
    public:
        //### constructors and destructor ###//
        OverallSort();
        OverallSort(int* &arr, int sz);
        ~OverallSort();
        //### print array ###//
        void print_array();
        //### sorting functions ###//
        void selection_sort();
        void insertion_sort();
        void bubble_sort();
        void shell_sort();
        //void merge_sort();
        void counting_sort();
        void radix_sort();
        //void bucket_sort();
        void all();
};
//### constructors and destructor ###//
OverallSort::OverallSort() : size(0), array(nullptr) {}
OverallSort::OverallSort(int* &arr, int sz) : size(sz), array(arr) {}
OverallSort::~OverallSort() {
    this->size = 0;
    delete[] this->array;
    this->array = nullptr;
}
//### print array ###//
void OverallSort::print_array() {
    if (array == nullptr || size == 0) {
        std::cout << "the array is empty\n";
        return;
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}
//### selection sort ###//
//### selection sort loops through an array of data, switching the current element with the last element in the list that is less than itself ###//
//### the first element is placed first and then not considered in the following loops ###//
void OverallSort::selection_sort() {
    int num_comp;
    clock_t running_time = clock();
    for (int i = 0; i < this->size-1; i++) {
        int idx = i;
        for (int k = i+1; k < this->size; k++) {
            if (this->array[k] < this->array[idx]) {
                idx = k;
                num_comp++;
            }
        }
        int temp = array[i];
        array[i] = array[idx];
        array[idx] = temp;
        print_array();
        num_comp = num_comp + 6;
    }
    running_time = clock() - running_time;
    std::cout << "   Actual time taken to run selection sort: " << (float)running_time/CLOCKS_PER_SEC << '\n';
    std::cout << "   This process took: " << num_comp << " operations\n, and with a running-time function of f(n) = 6n + (n(n-1))/2, the estimated run time would be ";
    int est = 6*size + (size * (size - 1)) / 2;
    std:: cout << est << " operations... O(n^2)\n";
}
//### insertion sort ###//
//## insertion sort loops through an array starting with the 2nd element, checking if any element before it is greater than it and if so replacing its position with that element until the previous element is not less than itself
void OverallSort::insertion_sort() {
    int num_comp;
    clock_t running_time = clock();
    for (int i = 1; i < this->size; i++) {
        int temp = array[i];
        int j = i;
        for (; j > 0 && temp < array[j-1]; j--) {
            array[j] = array[j-1];
            num_comp++;
        }
        array[j] = temp;
        print_array();
        num_comp = num_comp + 5;
    }
    running_time = clock() - running_time;
    std::cout << "   Actual time taken to run insertion sort: " << (float)running_time/CLOCKS_PER_SEC << '\n';
    std::cout << "   This process took: " << num_comp << " operations\n, and with a running-time function of f(n) = 5(n-1) + (n(n-1))/2 in the worst case (initial decreasing order), the estimated run time would be ";
    int est = 5*(size-1) + (size * (size - 1)) / 2;
    std:: cout << est << " operations... O(n^2)\n";
}
//### bubble sort ###//
//### bubble sort loops through an array starting with position 1, checking if the current element is less than the prior element and if so swapping them and then checking that new element to the next
//### bubble sort will continue to loop through the array until it does a pass with zero swaps ###//
//### kind of sort backwards -- last position will have correct element first ###//
void OverallSort::bubble_sort() {
    int num_comp;
    clock_t running_time = clock();
    for (int i = 1; i < this->size; i++) {
        bool cont = false;
        num_comp++;
        for (int j = 0; j < this->size-i; j++) {
            if (array[j+1] < array[j]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                cont = true;
                num_comp = num_comp+4;
            }
            if (!cont)
                break;
        }
    }
    running_time = clock() - running_time;
    std::cout << "   Actual time taken to run bubble sort: " << (float)running_time/CLOCKS_PER_SEC << '\n';
    std::cout << "   This process took: " << num_comp << " operations\n, and with a running-time function of f(n) = (n-1) + 2n(n-1) in the worst and average case, the estimated run time would be ";
    int est = size-1 + 2* size * (size - 1);
    std:: cout << est << " operations... O(n^2)\n";
}
//### shell sort ###//
//### shell sort splits an array into segments by dividing the size by 2.2 and using insertion sort on the the segments ###//
inline int next_gap(int gap) {
    if (gap == 2) return 1;
    else return (int) (gap/2.2);
}
void OverallSort::shell_sort() {
    clock_t running_time = clock();
    int num_comp = 0;
    int gap = size/2;
    num_comp = num_comp + 2;
    for (; gap > 0; gap = next_gap(gap)) {
        for (int i = gap; i < size; i++) {
            int tmp = array[i];
            int j = i;
            num_comp = num_comp + 5;
            while (j >= gap && tmp < array[j-gap]) {
                array[j] = array[j-gap];
                j -= gap;
                num_comp = num_comp + 2;
            }
            array[j] = tmp;
        }
    }
    running_time = clock() - running_time;
    std::cout << "   Actual time taken to run shell sort: " << (float)running_time/CLOCKS_PER_SEC << '\n';
    std::cout << "   This process took: " << num_comp;
    std:: cout << "  operations... O(n^2/3)\n";
}
//### merge sort ###//
//### merge sort 
// void OverallSort::merge_sort() {}

//### counting sort ###//
//### counting sort is a non-comparison sorting algorithm ###//
//### 
int findRange(int* array, int sz) {
    int min, max = array[0];
    for (int i = 1; i < sz; i++) {
        if (array[i] < min)
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }
    return (max - min);
}
void OverallSort::counting_sort() {
    int i, j;
    int k = findRange(this->array, this->size);
    int *C = new int[k+1]{0};
    clock_t running_time = clock();
    int num_comp = 0;
    for (int j = 0; j < size; j++) {
        C[array[j]]++;
        num_comp++;
    }
    for (int i = 1; i < k+1; i++) {
        C[i] += C[i-1];
        num_comp++;
    }
    int* B = new int[size];
    for (j = size-1; j >= 0; j--) {
        i = C[array[j]] - 1;
        C[array[j]]--;
        B[i] = array[j];
    }
    array = B;
    delete[] B;
    delete[] C;
    B = nullptr;
    C = nullptr;
    running_time = clock() - running_time;
    std::cout << "   Actual time taken to run counting sort: " << (float)running_time/CLOCKS_PER_SEC << '\n';
    std::cout << "   This process took: " << num_comp;
    std:: cout << "  operations... O(n+k), where k is the range of the array\n";
}
//### radix sort ###//
//### radix sort uses counting sort on each digit, starting with the LSD, with base 10 (each digit can be 0 ... 9) in counting sort ###//
const int base = 10;
int digit(int k, int num) { 
    int r;
    r = num/(int)pow(base, k); /* integer division */
    return r % base;
}
int numDigits(int* array, int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (max < array[i])
            max = array[i];
    }
    int count = 0;
    while (max != 0) {
        max = max / 10;
        count++;
    }
    return count;
}
void OverallSort::radix_sort() {
    int num_comp = 0;
    clock_t running_time = clock();
    int i, j, m;
    /* temporary storage */
    int *C = new int[base];
    int *B = new int[size];
    int d = numDigits(array, size);
    for (m = 0; m < d; m++) {
        for (i = 0; i < base; i++) {
            C[i] = 0;
            num_comp++;
        }
        for (j = 0; j < size; j++) {
            C[digit(m, array[j])]++;
            num_comp++;
        }
        for (i = 1; i < base; i++) {
            C[i] += C[i-1];
            num_comp++;
        }
        for (j = size-1; j >= 0; j--) {
            i = C[digit(m, array[j])]--;
            B[i] = array[j];
            num_comp += 2;
        } /* copy B -> A */
        for (j = 0; j < size; j++) array[j] = B[j];
    }
    delete[] B;
    delete[] C;
    B = nullptr;
    C = nullptr;
    num_comp += 11;
    running_time = clock() - running_time;
    std::cout << "   Actual time taken to run radix sort: " << (float)running_time/CLOCKS_PER_SEC << '\n';
    std::cout << "   This process took: " << num_comp;
    std:: cout << "  operations... O(dn), where d is the number of digits in the array\n";
}
//### bucket sort ###//
//### bucket sort divided the range of the array into equal intervals (buckets), throws the number of the array in the buckets and uses insertion sort to sort each bucket ###//

//### all ###//
//### all sorts the given array with all the sorting functions in the class ###//
void OverallSort::all() {
    selection_sort();
    insertion_sort();
    bubble_sort();
    shell_sort();
    //merge_sort();
    counting_sort();
    radix_sort();
    //bucket_sort();
}
# endif