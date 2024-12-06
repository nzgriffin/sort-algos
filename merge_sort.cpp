#include <iostream>
using namespace std;

const int LENGTH = 8;

void printList(int myList[], int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << myList[i] << " ";
    }
    cout << endl;
}

void merge(int myList[], int left, int mid, int right, int &comparisons) {
    cout << "Merging subarrays: ";
    printList(myList, left, mid);
    cout << "and ";
    printList(myList, mid + 1, right);
    getchar();

    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) leftArray[i] = myList[left + i];
    for (int i = 0; i < n2; i++) rightArray[i] = myList[mid + 1 + i];

    // Merge the temporary arrays back into myList
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArray[i] <= rightArray[j]) {
            myList[k] = leftArray[i];
            i++;
        } else {
            myList[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray
    while (i < n1) {
        myList[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray
    while (j < n2) {
        myList[k] = rightArray[j];
        j++;
        k++;
    }

    cout << "After merging: ";
    printList(myList, left, right);
    cout << " - Total comparisons so far: " << comparisons << endl;
    getchar();

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int myList[], int left, int right, int &comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        cout << "Dividing subarray: ";
        printList(myList, left, right);
        cout << "into ";
        printList(myList, left, mid);
        cout << "and ";
        printList(myList, mid + 1, right);
        getchar();

        // Recursively sort first and second halves
        mergeSort(myList, left, mid, comparisons);
        mergeSort(myList, mid + 1, right, comparisons);

        // Merge the sorted halves
        merge(myList, left, mid, right, comparisons);
    }
}

int main() {
    int myList[LENGTH];

    cout << "Enter your list numbers (max " << LENGTH << "): ";
    for (int i = 0; i < LENGTH; i++) {
        cin >> myList[i];
    }
    getchar();  // Consume the newline character

    // Uncomment this to use a pre-defined list for experimentation:
    // int myList[LENGTH] = {64, 34, 25, 12, 22, 11, 90, 42};

    int comparisons = 0;

    cout << "=============================" << endl;
    cout << "Starting Merge Sort!" << endl;
    cout << "Press Enter to begin. Press Enter again after each division or merge step." << endl;
    cout << "=============================" << endl;
    getchar();

    mergeSort(myList, 0, LENGTH - 1, comparisons);

    cout << "\nMerge Sort completed!" << endl;
    cout << "Sorted array: ";
    printList(myList, 0, LENGTH - 1);
    cout << "=============================" << endl;
    cout << "Total comparisons: " << comparisons << endl;

    return 0;
}
