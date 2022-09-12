#include "bits/stdc++.h"

using namespace std;

void heapify(int array[], int sz, int current)
{
    int largest = current;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    if(leftChild < sz && array[leftChild] > array[largest])
    {
        largest = leftChild;
    }

    if(rightChild < sz && array[rightChild] > array[largest])
    {
        largest = rightChild;
    }

    if(largest != current)
    {
        swap(array[current], array[largest]);
        heapify(array, sz, largest);
    }
}

void printArray(int array[], int sz)
{
    cout << endl;
    for(int i = 0; i < sz; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "Before Heapify: ";
    printArray(array, n);

    // Heapify
    int nonLeafStart = (n / 2) - 1;

    for (int i = nonLeafStart; i >= 0; i--)
    {
        heapify(array, n, i);
    }
    cout << "After Heapify: ";
    printArray(array, n);
}

/*
9
2 10 1 5 4 8 3 8 7
*/