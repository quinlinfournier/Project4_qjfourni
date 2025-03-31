#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include "printVec.h"
#include <vector>
using std::vector;

// Helper function for heapSort
inline int leftChild(const int& i) {
    return 2 * i + 1;
}

// Helper function for heapSort
// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(vector<Comparable> &items, int& i, unsigned long& n, int& child, Comparable& tmp, unsigned long& reads) {
    for(tmp = items[i]; leftChild(i) < n; i = child) {
        reads++;
        child = leftChild(i);

        // choose the child with the larger value
        if (child != n - 1) {
            reads += 2;
            if (items[child] < items[child + 1]) {
                ++child;
            }
        }

        reads++;
        // if the parent is less than the child, swap them
        if (tmp < items[child]) {
            items[i] = items[child];
            reads++;
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    items[i] = tmp;
}

template <typename Comparable>
vector<Comparable> heapSort(vector<Comparable> items, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int i, child;
    Comparable temp, tmp;
    unsigned long j, n;

    // Allocations
    allocations += 2 * sizeof(int);
    allocations += 2 * sizeof(Comparable);
    allocations += 2 * sizeof(unsigned long);

    // build the heap (with max value at root)
    for (i = items.size() / 2 - 1; i >= 0; --i) {
        n = items.size();
        percolateDown(items, i, n, child, tmp, reads);
    }

    // Uncomment this line if you want to see each iteration
    //printVec(vec);

    // keep deleting the max
    for (j = items.size() - 1; j > 0; --j) {
        // swap the maximum out
        temp = items[0];
        reads++;
        items[0] = items[j];
        reads++;
        items[j] = temp;
        reads++;

        // make it into a heap again
        i = 0;
        percolateDown(items, i, j, child, tmp, reads);

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    return items;
}

#endif
