//
// Created by alex7 on 2020-08-14.
//

#include <iostream>
#include <vector>

class BinaryHeap{
    //Binary Heap for integers
public:
    int length; //number of elements actually in the heap
    int heapsize; //number of possible elements in the heap
    int container[]; //the container of the binary heap

    BinaryHeap(int size){
        heapsize = size;
        container [size];
        length = 0;
    }

    int parent(int i){
        return i/2;
    }

    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }

    void max_heapify(int i){
        //Assumes that LEft(i) and Right(i) are max heaps
        int l = left(i);
        int r = right(i);
        int largest;
        if(l<= heapsize && container[l]>container[i]){
            largest = l;
        }
        else{
            largest = i;
        }
        if(r<= heapsize && container[r] >container[largest]){
            largest = r;
        }
        if(largest != i){
            int temp = container[i];
            container[i] = container[largest];
            container[largest] = temp;
            max_heapify(largest);
        }
    }

    void min_heapify(int i){
        //Assumes that Left(i) an Right(i) are min heaps
        int l = left(i);
        int r = right(i);
        int smallest;
        if(l <= heapsize && container[l] < container[i]){
            smallest = l;
        }
        else{
            smallest = i;
        }
        if(r<= heapsize && container[r] < container[smallest]){
            smallest = r;
        }
        if(smallest != i){
            int temp = container[i];
            container[i] = container[smallest];
            container[smallest] = temp;
            min_heapify(smallest);
        }
    }
    void BuildMaxHeap(int A[]){
        // builds an Heap using an integer array
        heapsize = sizeof(A)/sizeof(A[0]);
        for(int i = 0; i < heapsize; i++){
            container[i] = A[i];
            length ++;
        }
        for(int i = heapsize/2;i>1;i--){
            max_heapify(i);
        }
    }

    void BuildMinHeao(int A[]){
        //builds a Heap using an integer array
        heapsize = sizeof(A)/sizeof(A[0]);
        for(int i = 0; i <heapsize; i++){
            container[i] = A[i];
            length++;
        }
        for(int i = heapsize; i>1; i--){
            min_heapify(i);
        }
    }
};

int * heapsort(int A[]){
    //TODO might not be correct
    int length = sizeof(A)/sizeof(A[0]);

    BinaryHeap heap = BinaryHeap(length);
    heap.BuildMaxHeap(A);
    return heap.container;
}
int *min_heapsort(int A[]){
    int length = sizeof(A)/sizeof(A[0]);
    BinaryHeap heap = BinaryHeap(length);
    heap.BuildMinHeao(A);
    return heap.container;
}

int binary_search(std::vector<int> input, int value, int pivot){
    // Assumes the input vector is sorted in ascending order
    // Search for value in input vector
    // Return the index for that value if it exists, otherwise -1
    int length = input.size();

    if(length == 0){
        return -1;
    }
    if(input[pivot] == value){
        return pivot;
    }
    if(input[pivot] < value){
        return binary_search(input, value, pivot+(pivot-1)/2);
    }
    if(input[pivot] > value){
        return binary_search(input, value, pivot/2);
    }
    return -1;
}

void insertion_sort(std::vector<int> input){
    //Sorts the vector of integers in place.
    for(int j = 2; j < input.size(); j++){
        int key = input[j];
        int i = j-1;
        while(i>0 && input[i]>key){
            input[i+1] = input[i];
            i = i-1;
        }
        input[i+1] = key;
    }
}


int main()
{
    std::cout << "Running insertion sort... \n";

    std::vector<int> to_sort{1,4,5,9,3};
    insertion_sort(to_sort);
    std::cout << "Test1 ";
    if(to_sort[0] == 1  && to_sort[1] == 3 && to_sort[2] == 4 && to_sort[3] == 5 && to_sort[4] == 9){
        std::cout << "Successful \n";
    }
    else{
        std::cout << "Unsuccessful \n";
        for(int i = 0; i < to_sort.size(); i++){
            std::cout << to_sort[i];
        }
    }
    std::cout << "Running binary search...\n";

    std::vector<int> search_list{1,2,3,4,5,6};
    int index = binary_search(search_list, 2, (search_list.size())/2);
    std::cout << "Test1 ";
    if(index == 1){
        std::cout << "Succesful!\n";
    }
    else{
        std::cout << "Unsuccesful!\n";
    }

    index = binary_search(search_list, 6, search_list.size()/2);

    std::cout << "Test2 ";
    if(index == 5){
        std::cout << "Succesful!\n";
    }
    else{
        std::cout << "Unsuccesful!\n";
    }

    index = binary_search(search_list, 6, search_list.size()/2);

    std::cout << "Test3 ";
    if(index == 5){
        std::cout << "Succesful!\n";
    }
    else{
        std::cout << "Unsuccesful!\n";
    }
    return 0;
}