#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Various sorting functions
// When sorting functions are called, the expectation is for the output 
// data to be sorted in non-decreasing order
// Not allowed to use standard library call to sort a vector

void quicksort(vector<int>& data, int low_idx, int high_idx); // quicksort function

int quicksort_partition(vector<int>& data, int low_idx, int high_idx);  // helper function for quicksort

void bubblesort(vector<int>& data); // bubblesort function

void mergesort(vector<int>& data); // mergesort function

void merge(vector<int>& left, vector<int>& right, vector<int>& result); // helper function for mergesort

void disp(vector<int> const& numbers); // function to display the contents of a vector

void mystery_sort(vector<int>& data); // any additional sorting function of your choice

// Implementation of sorting functions

// displays the contents of a vector
void disp(vector<int> const& numbers) {
    if (numbers.size() == 0) {
        cout << "No data" << endl;
        return; // nothing to display
    }
    for (auto const v : numbers) {
        cout << " " << v; // display each element
    }
    cout << endl;
}

// quicksort function
void quicksort(vector<int>& data, int low_idx, int high_idx) {
    if (low_idx < high_idx) { // base case
        int pivot_idx = quicksort_partition(data, low_idx, high_idx); // partition the data
        quicksort(data, low_idx, pivot_idx - 1); // recursively sort the left partition
        quicksort(data, pivot_idx + 1, high_idx); // recursively sort the right partition
    }
}

// partition function for quicksort
int quicksort_partition(vector<int>& data, int low_idx, int high_idx) {
    int pivot = data[high_idx]; // choose the rightmost element as pivot
    int i = low_idx - 1; // pointer for the smaller element
    for (int j = low_idx; j < high_idx; j++) {
        if (data[j] <= pivot) { // if current element is smaller than or equal to pivot
            i++; // increment the pointer for the smaller element
            swap(data[i], data[j]); // swap the elements
        }
    }
    swap(data[i + 1], data[high_idx]); // swap the pivot element with the element at i+1
    return i + 1; // return the index of the pivot element
}

// bubblesort function
void bubblesort(vector<int>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) { // if the current element is greater than the next element
                swap(data[j], data[j + 1]); // swap the elements
            }
        }
    }
}

// mergesort function
void mergesort(vector<int>& data) {
    if (data.size() <= 1) {
        return; // base case
    }
    int mid = data.size() / 2; // find the midpoint
    // using vector constructor to create left and right subvectors
    vector<int> left(data.begin(), data.begin() + mid);
    vector<int> right(data.begin() + mid, data.end());
    // recursively sort the subvectors
    mergesort(left);
    mergesort(right);
    merge(left, right, data); // merge the sorted subvectors
}

// merge function for mergesort
void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result) {
    // ensuring result has enough space
    result.resize(left.size() + right.size());

    std::size_t i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) { // if the current element in left is smaller than or equal to the current element in right
            result[k++] = left[i++]; // add the element from left to result
        } else {
            result[k++] = right[j++]; // add the element from right to result
        }
    }
    while (i < left.size()) {
        result[k++] = left[i++]; // add remaining elements from left to result
    }
    while (j < right.size()) {
        result[k++] = right[j++]; // add remaining elements from right to result
    }
}

// mystery_sort function (insertion sort as an example)
// This function sorts the data using the insertion sort algorithm
// Avoid segfaults from index going negative or underflowing if using unsigned types
void mystery_sort(vector<int>& data) {
    int n = data.size();

    if (n < 2) {
        return; // already sorted
    }
    for (int i = 1; i < n; i++) {
        int key = data[i]; // current element to be inserted
        int j = i - 1; // index of the last sorted element
        // Move elements of data[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key; // insert the key at its correct position
    }
}



// End of sorting functions

// Example usage
int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90}; // example data

    cout << "Original array: ";
    disp(data);

    vector<int> data_quick = data; // copy of data for quicksort
    quicksort(data_quick, 0, data_quick.size() - 1);
    cout << "Sorted array with quicksort: ";
    disp(data_quick);

    vector<int> data_bubble = data; // copy of data for bubblesort
    bubblesort(data_bubble);
    cout << "Sorted array with bubblesort: ";
    disp(data_bubble);

    vector<int> data_merge = data; // copy of data for mergesort
    mergesort(data_merge);
    cout << "Sorted array with mergesort: ";
    disp(data_merge);

    vector<int> data_mystery = data; // copy of data for mystery_sort
    mystery_sort(data_mystery);
    cout << "Sorted array with mystery_sort: ";
    disp(data_mystery);

    return 0;
}

// End of example usage
// -- End of hw4-SortingAlgorithms.cpp -





