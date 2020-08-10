//
// Created  on 2020-08-07.
//
#include <iostream>
#include <vector>

int binary_search(std::vector<int> input, int value){
    // Assumes the input vector is sorted in ascending order
    // Search for value in input vector
    // Return the index for that value if it exists, otherwise -1
    int length = input.size();
    int pivot = (length)/2;

    if(length == 0){
        return -1;
    }
    if(input[pivot] == value){
        return pivot;
    }
    if(input[pivot] < value){
        std::vector<int> new_vector(pivot);
        for(int i = 0; i < pivot; i++){
            new_vector.push_back(input[i]);
        }
        return binary_search(new_vector, value);
    }
    if(input[pivot] > value){
        std::vector<int> new_vector(length-pivot);
        for(int i = pivot; i< length-pivot; i++){
            new_vector.push_back(input[i]);
        }
        return binary_search(new_vector, value);
    }
    return -1;

}
int main()
{
    std::cout << "Running binary search...\n";

    std::vector<int> list{1,2,3,4,5,6};
    int index = binary_search(list, 2);
    std::cout << index;
    if(index == 1){
        std::cout << "Succesful!";
    }
    else{
        std::cout << "Unsuccesful!";
    }


    return 0;
}

