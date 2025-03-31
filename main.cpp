#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include "Whales.h"
#include <iomanip>
using namespace std;

void stabilityTest();

int main() {
    // Get your vector of custom data type objects ready
    vector <Whale> whales;

    getDataFromFile( "../CleanedLargeWhales-2005-2015-1-27.csv", whales);
    cout <<"Vector size: "<<whales.size() <<endl;

    unsigned long reads, allocations;

    //loop through vector sizes from 1000 to 100 in decrements of 100
    for (int size = 1000; size >= 100; size -= 100) {
        vector<Whale> temp = whales;
        temp.resize(size);


        // sort the vector in four different ways (bubble, merge, heap, selection)
        // record the number of reads and allocations for each sort


        cout << "Sorting vector of size: " << size << endl;

        // Bubble Sort
        reads = allocations = 0;
        bubbleSort(temp, reads, allocations);
        cout << "Bubble Sort - Reads: " << reads << ", Allocations: " << allocations << " bytes" << endl;

        // Merge Sort
        reads = allocations = 0;
        mergeSort(temp, reads, allocations);
        cout << "Merge Sort - Reads: " << reads << ", Allocations: " << allocations << " bytes" << endl;

        // Heap Sort
        reads = allocations = 0;
        heapSort(temp, reads, allocations);
        cout << "Heap Sort - Reads: " << reads << ", Allocations: " << allocations << " bytes" << endl;

        // Selection Sort
        reads = allocations = 0;
        selectionSort(temp, reads, allocations);
        cout << "Selection Sort - Reads: " << reads << ", Allocations: " << allocations << " bytes" << endl;

        cout << " ------------------- " << endl;

    }

    stabilityTest();
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    // add other stable algorithm here
    cout << endl << "Merge Sort" << endl;
    people.sortAndPrint(mergeSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    // add other unstable algorithm here
    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort<contact>);
}