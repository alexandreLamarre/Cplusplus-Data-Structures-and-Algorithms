//
// Created by alex7 on 2020-08-14.
//

#include <iostream>
#include <vector>

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