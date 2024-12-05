// bubble_sort.cpp

#include <iostream>
using namespace std;

const int LENGTH  = 8;   // can change this

void printList(int myList[]) {
	for (int i = 0; i < LENGTH; i++) {
		cout << myList[i] << " ";
	}
	// cout << endl;
}

int main() {
	cout << "Hello World" << endl;
	
	int myList[LENGTH];
	
	cout << "Enter your list numbers (max " << LENGTH << "): ";
	for (int i = 0; i < LENGTH; i++) {
		cin >> myList[i];
	}
	getchar();
	
	cout << "List: ";
	printList(myList); 
	cout << endl;
	
	int bubbleList[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		bubbleList[i] = myList[i];
	}
	
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
            cout << "  --> Total comparisons: " << comparisons << " (Swap executed!)";
        } else {
            printList(bubbleList);
            cout << "  --> Total comparisons: " << comparisons << " (No swap needed)";
        }
        getchar();
    }
}
cout << "\nBubble Sort completed!" << endl;
cout << "=============================" << endl;

// Copy list for Selection Sort
int selectionList[LENGTH];
for (int i = 0; i < LENGTH; i++) {
    selectionList[i] = myList[i];
}

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
        cout << " (Current minimum: " << selectionList[minIndex] << ")";

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
        cout << " (End of pass - Swap executed!)";
    } else {
        printList(selectionList);
        cout << "  --> Total comparisons: " << comparisons;
        cout << " (End of pass - No change needed)";
    }
    getchar();
}
cout << "\nSelection Sort completed!" << endl;
cout << "=============================" << endl;
	
	
	cout << "Over now" << endl;
	getchar();
	
	
	return(0);
}