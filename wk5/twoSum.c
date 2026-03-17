#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// O(n^2) solution
// 1,2,3,4,5; target = 9 -> true
// 1,2,3,4,5; target = 10 -> false
bool hasTwoSum(int *arr, int n, int sum) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                return true;
            }
        }
    }
    return false;
}

// use a binary search tree
// O(n log n)
bool hasTwoSum(int *arr, int n, int sum) {
    // setOfValuesWeHaveSeenSoFar
    BSTree seen = BSTNew();  // O(1)

    for (int i = 0; i < n; i++) {  // O(n) times
        int complement = sum - arr[i];
        if (BSTSearch(seen, complement)) {  // O(log n)
            BSTFree(seen);                  // O(n)
            return true;
        }

        BSTInsert(seen, arr[i]);  // O(log n)
    }

    BSTFree(seen);  // O(n)
    return false;
}
