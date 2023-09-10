#include<bits/stdc++.h>
class minHeap {
    public:

    // Constructor for the class.
    vector<int> arr;
    int size, capacity;
    minHeap(int n) {
        arr.resize(n);
        size = 0;
        capacity = n;
    }

    void heapify(int i){
        int smallest = i;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
        if(leftChild < size && arr[leftChild] < arr[smallest]){
            smallest = leftChild;
        }
        if(rightChild < size && arr[rightChild] < arr[smallest]){
            smallest = rightChild;
        }
        if(i!=smallest){
            swap(arr[smallest], arr[i]);
            heapify(smallest);
        }
    }
    // Implement the function to remove minimum element.
    int extractMinElement() {
        if(size==0) return -1;
        int ans = arr[0];
        swap(arr[0], arr[size-1]);
        size--;
        heapify(0);
        return ans;
        // Write you code here.
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if(ind >= size) return;
        swap(arr[size-1], arr[ind]);
        size--;
        heapify(ind);
        // Write you code here.
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        if(size == capacity) return;
        arr[size] = val;
        size++;
        int index = size-1;
        while(index >= 0){
            int parent = (index-1)/2;
            if(arr[parent]> arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }

        // Write you code here.
    }
};