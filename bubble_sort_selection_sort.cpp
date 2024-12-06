// bubble_sort_selection_sort.cpp

#include <iostream>
using namespace std;

const int LENGTH = 8;   // Change this to adjust the list size

// Function to print the list
void printList(int myList[]) {
    for (int i = 0; i < LENGTH; i++) {
        cout << myList[i] << " ";
    }
    cout << endl; // Always add a newline after printing
}

int main() {
    cout << "Welcome to Bubble and Selection Sort Demonstration!" << endl;

    int myList[LENGTH];

    // Uncomment this line to use a pre-defined example list
    // int myList[LENGTH] = {64, 34, 25, 12, 22, 11, 90, 42}; // Example list

    // Prompt the user to enter numbers
    cout << "Enter your list numbers (max " << LENGTH << "): ";
    for (int i = 0; i < LENGTH; i++) {
        cin >> myList[i];
    }
    getchar(); // Consume the newline character

    cout << "Original List: ";
    printList(myList);
    cout << endl;

    // Copy the original list for Bubble Sort
    int bubbleList[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        bubbleList[i] = myList[i];
    }

    // ==============================
    // Bubble Sort
    cout << "=============================" << endl;
    cout << "Starting Bubble Sort!" << endl;
    cout << "Press Enter to begin. Press Enter again after each iteration to continue." << endl;
    cout << "=============================" << endl;
    getchar();

    int comparisons = 0;
    for (int i = 0; i < LENGTH; i++) {
        cout << "\nPass " << i + 1 << " of Bubble Sort:" << endl;
        for (int j = 0; j < LENGTH - i - 1; j++) {
            comparisons++;
            if (bubbleList[j] > bubbleList[j + 1]) {
                // Swap
                int temp = bubbleList[j];
                bubbleList[j] = bubbleList[j + 1];
                bubbleList[j + 1] = temp;

                printList(bubbleList);
                cout << "  --> Total comparisons: " << comparisons << " (Swap executed!)" << endl;
            } else {
                printList(bubbleList);
                cout << "  --> Total comparisons: " << comparisons << " (No swap needed)" << endl;
            }
            getchar();
        }
    }
    cout << "\nBubble Sort completed!" << endl;
    cout << "Sorted List: ";
    printList(bubbleList);
    cout << "=============================" << endl;

    // Copy the original list for Selection Sort
    int selectionList[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        selectionList[i] = myList[i];
    }

    // ==============================
    // Selection Sort
    cout << "\n\n=============================" << endl;
    cout << "Starting Selection Sort!" << endl;
    cout << "Press Enter to begin. Press Enter again after each iteration to continue." << endl;
    cout << "=============================" << endl;
    getchar();

    comparisons = 0;
    for (int i = 0; i < LENGTH; i++) {
        int minIndex = i;
        cout << "\nPass " << i + 1 << " of Selection Sort:" << endl;
        cout << "  Current starting index: " << i << endl;

        // Find the smallest element in the remaining list
        for (int j = i + 1; j < LENGTH; j++) {
            comparisons++;
            printList(selectionList);
            cout << "  --> Total comparisons: " << comparisons;
            cout << " (Current minimum: " << selectionList[minIndex] << ")" << endl;

            if (selectionList[j] < selectionList[minIndex]) {
                minIndex = j;
            }
            getchar();
        }

        // Swap the smallest element with the current position, if necessary
        if (minIndex != i) {
            int temp = selectionList[i];
            selectionList[i] = selectionList[minIndex];
            selectionList[minIndex] = temp;

            printList(selectionList);
            cout << "  --> Total comparisons: " << comparisons;
            cout << " (End of pass - Swap executed!)" << endl;
        } else {
            printList(selectionList);
            cout << "  --> Total comparisons: " << comparisons;
            cout << " (End of pass - No change needed)" << endl;
        }
        getchar();
    }
    cout << "\nSelection Sort completed!" << endl;
    cout << "Sorted List: ";
    printList(selectionList);
    cout << "=============================" << endl;

    cout << "\nSorting Demonstration Complete. Goodbye!" << endl;
    return 0;
}
