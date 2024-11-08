/*
 * Name: Guillermo K Quiroz
 * Date: 02/10/2024
 * Course: CIS2107
 * HW #: Lab 4 1DArrays
 * Statement of Problem: Design and implement functions to process 1D Arrays, including filling arrays with random numbers, finding elements, reversing arrays, and searching for sequences.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40
#define MY_RAND_MIN 0
#define MY_RAND_MAX 100

// Function prototypes
int findWithRange(int arr[], int size, int lowSelectedRange, int highSelectedRange);
void reverseArray(int arr[], int size);
void reverseSelectedRangeWithinArray(int arr[], int startRange, int endRange);
int findSequence(int arr[], int size);

void fillArray(int array[], int size) {
// This function seeds the random number generator and uses MY_RAND_MIN and MY_RAND_MAX
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % (MY_RAND_MAX - MY_RAND_MIN + 1) + MY_RAND_MIN; //This fills array with random values within the range
    }
}

int findWithRange(int arr[], int size, int lowSelectedRange, int highSelectedRange) {
    //this function find the max value within a specific range
    if (lowSelectedRange < 0 || highSelectedRange >= size || lowSelectedRange > highSelectedRange) {
        printf("Invalid range.\n"); //checks for valid range
        return -1; 
    }
    int max = arr[lowSelectedRange]; //this initializes max with first elemnnt in range

    for (int i = lowSelectedRange + 1; i <= highSelectedRange; i++) {
        if (arr[i] > max) {
            max = arr[i];  // the updates if larger max is found
        }
    }
    return max;
}

void reverseArray(int arr[], int size) {
    //This function reverses the entire array
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i]; //makes a placeholder to hold current elemment
        arr[i] = arr[size - 1 - i]; //swaps element with itts counter partner
        arr[size - 1 - i] = temp; // finishes swap
    }
}

void reverseSelectedRangeWithinArray(int arr[], int startRange, int endRange) {
    //reverses the elements within a specific range
    while (startRange < endRange) {
        int temp = arr[startRange]; 
        arr[startRange] = arr[endRange];
        arr[endRange] = temp;
        startRange++; //moves to the next element
        endRange--; // moves to previous element
    }
}

int findSequence(int arr[], int size) {
    //Searches for a sequence of 2 numbers in the array and returns the starting index of the sequence
    int num1, num2;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == num1 && arr[i + 1] == num2) {
            return i;
        }
    }
    return -1; 
}

int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator 

    int array[SIZE]; 

    // Fill the array with random values
    fillArray(array, SIZE);
    printf("Filled Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    // test findWithRange
    int lowRange = 10, highRange = 19;
    int max = findWithRange(array, SIZE, lowRange, highRange);
    printf("\nMax in range [%d, %d]: %d\n", lowRange, highRange, max); //find max in range

    // test reverseArray
    reverseArray(array, SIZE);
    printf("\nReversed Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    // test reverseSelectedRangeWithinArray
    int startRange = 15, endRange = 24;
    reverseSelectedRangeWithinArray(array, startRange, endRange);
    printf("\nArray after reversing range [%d, %d]:\n", startRange, endRange);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    // test findSequence
    int sequenceIndex = findSequence(array, SIZE);
    if (sequenceIndex != -1) {
        printf("Sequence found at index %d\n", sequenceIndex);
    } else {
        printf("Sequence not found\n");
    }
    return 0;
}
