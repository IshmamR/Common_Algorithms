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

/**
 * @brief
 * Partition using Lomuto's partition scheme.
 * This scheme degrades to O(n^2) when the array is already in order
 */
int lomutosPartition(int arr[], int start, int end) {
  int pivotValue = arr[end]; // last element as pivot
  int tempPivotIndex = start - 1;
  for (int j = start; j < end; j++) {
    if (arr[j] <= pivotValue) {
      // Move the temporary pivot index forward
      tempPivotIndex++;
      // Swap the current element with the element at the temporary pivot index
      swap(&arr[tempPivotIndex], &arr[j]);
    }
  }
  int pivotIndex = tempPivotIndex + 1;
  swap(&arr[pivotIndex], &arr[end]);
  return pivotIndex;
}

/**
 * @brief
 * Hoare's partitioning also would cause Quicksort to degrade to O(n2) for already sorted input,
 * if the pivot was chosen as the first or the last element.
 * With the middle element as the pivot, however, sorted data results with (almost) no swaps
 * in equally sized partitions leading to best case behavior of Quicksort, i.e. O(n log(n)).
 */
int hoaresPartition(int arr[], int start, int end) {
  int mid = (start + end) / 2;
  int pivotValue = arr[mid]; // The value in the middle of the array

  int i = start - 1; // left index
  int j = end + 1; //right index

  while (true) {
    // Move left index to right at least once and while the element at the left index is less than pivot
    do {
      i++;
    } while (arr[i] < pivotValue);

    // Move right index to left at least once and while the element at the right index is greater than pivot
    do {
      j--;
    } while (arr[j] > pivotValue);

    // If the indices crossed, return
    if (i >= j) {
      return j;
    }

    // Swap the elements at the left and right indices
    swap(&arr[i], &arr[j]);
  }
}

/**
 * @brief
 * Divides array into two partitions
 * @param scheme scheme number
 * @return partition index
 */
int partition(int arr[], int low, int high, int scheme) {
  if (scheme == 1) {
    return lomutosPartition(arr, low, high);
  } else if (scheme == 2) {
    return hoaresPartition(arr, low, high);
  }
  return 0;
}

void quickSort(int arr[], int low, int high, int scheme) {
  if (low >= high || low < 0 || high < 0) {
    return;
  }

  // There are 2 schemes to get partitioned index.
  // 1. Lomuto's partition scheme, 2. Hoare's scheme
  int pivot = partition(arr, low, high, scheme);
  if (scheme == 1) {
    quickSort(arr, low, pivot - 1, scheme);
  } else if (scheme == 2) {
    quickSort(arr, low, pivot, scheme); // Note: the pivot is now included
  }
  quickSort(arr, pivot + 1, high, scheme);
}

int main() {
  int n, elem, scheme, x;

  cout << "Quick Sort" << endl;
  cout << "Enter number of elements(n): " << endl;
  cin >> n;
  int arr[n];

  cout << "Enter space separated elements(numbers): " << endl;
  for (x = 0; x < n; x++) {
    cin >> elem;
    arr[x] = elem;
  }

  cout << "Which partition scheme do you want to use? (Enter desired scheme no. )" << endl;
  cout << "1. Lomuto's partition scheme" << endl;
  cout << "2. Hoare's scheme" << endl;
  cin >> scheme;

  quickSort(arr, 0, n - 1, scheme);

  cout << "Sorted output: " << endl;
  for (x = 0; x < n; x++) {
    cout << arr[x] << " ";
  }
  cout << endl;

  return 0;
}
