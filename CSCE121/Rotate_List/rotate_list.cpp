#include <iostream>
// not other include files are allowed

using std::cin, std::cout, std::endl;

// PUT YOUR FUNCTION HERE
template <typename T>
T* rotate(const T oldArray[], const int length, int n) {
  T* newArray = new T[length];
  if (n > length) {
    while (n > length) {
      n = n - length;
    }
  }
  else if (n*-1 > length) {
    while (n*-1 > length) {
      n = n + length;
    }
  }
  if (n == 0) {
    for (int i = 0; i < length; i++) {
      newArray[i] = oldArray[i];
    }
    return newArray;
  }
  if (n > 0) {
    for (int i = n; i < length; i++) {
      newArray[i] = oldArray[i-n];
    }
    for (int j = 0; j < n; j++) {
      newArray[j] = oldArray[length-n+j];
    }
  }
  if (n < 0) {
    for (int i = 0; i < length + n; i++) {
      newArray[i] = oldArray[i-n];
    }
    for (int j = length + n; j < length; j++) {
      newArray[j] = oldArray[j-length-n];
    }
  }
  return newArray;
}

int main() {
  
  {
    int A[] = {1, 2, 3, 4, 5};
    int expected[] = {4, 5, 1, 2, 3};
    int* actual = rotate(A, 5, 2);
    for (size_t i = 0; i < 5; ++i) {
      if (actual[i] != expected[i]) {
        cout << "[FAIL] expected actual["<<i<<"] to be " << expected[i] << endl;
        return;
      }
    }
    cout << "Passed\n";
  }
  return 0;
}
