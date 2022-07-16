#include <iostream>

using namespace std;

/**
 * @brief
 * Swaps 2 elements in an array
 * @param arr pointer to the array
 * @param a index of 1st element
 * @param b index of 2nd element
 */
void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int arr[], int size) {
  bool isSorted = false;
  int lastSorted = size - 1;
  while (!isSorted) {
    isSorted = true;
    for (int i = 0; i < lastSorted; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        isSorted = false;
      }
    }
    lastSorted--;
  }
}

int main() {
  int n, elem, x;

  cout << "Bubble Sort" << endl;
  cout << "Enter number of elements(n): " << endl;
  cin >> n;
  int arr[n], temp[n];

  cout << "Enter space separated elements(numbers): " << endl;
  for (x = 0; x < n; x++) {
    cin >> elem;
    arr[x] = elem;
    temp[x] = elem;
  }

  bubbleSort(arr, n);

  cout << "Sorted output: " << endl;
  for (x = 0; x < n; x++) {
    cout << arr[x] << " ";
  }
  cout << endl;

  return 0;
}