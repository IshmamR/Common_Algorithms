#include <iostream>

using namespace std;

void topDownMerge(int arr[], int temp[], int start, int middle, int end) {
  int i = start;
  int j = middle;

  // While there are elements in the left or right runs...
  for (int k = start; k < end; k++) {
    // If left run head exists and is <= existing right run head.
    if (i < middle && (j >= end || temp[i] <= temp[j])) {
      arr[k] = temp[i];
      i++;
    } else {
      arr[k] = temp[j];
      j++;
    }
  }
}

void mergeHalves(int arr[], int temp[], int leftStart, int middle, int rightEnd) {
  topDownMerge(arr, temp, leftStart, middle, rightEnd);
}

void mergeSort(int arr[], int temp[], int left, int right) {
  if (left >= right || left < 0 || right < 0) {
    return;
  }
  int middle = (left + right) / 2;
  mergeSort(arr, temp, left, middle);
  mergeSort(arr, temp, middle + 1, right);
  mergeHalves(arr, temp, left, middle, right);
}

int main() {
  int n, elem, x;

  cout << "Merge Sort" << endl;
  cout << "Enter number of elements(n): " << endl;
  cin >> n;
  int arr[n], temp[n];

  cout << "Enter space separated elements(numbers): " << endl;
  for (x = 0; x < n; x++) {
    cin >> elem;
    arr[x] = elem;
    temp[x] = elem;
  }

  mergeSort(arr, temp, 0, n - 1);

  cout << "Sorted output: " << endl;
  for (x = 0; x < n; x++) {
    cout << arr[x] << " ";
  }
  cout << endl;

  return 0;
}