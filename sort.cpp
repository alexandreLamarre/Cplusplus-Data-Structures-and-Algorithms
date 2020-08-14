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
int main()
{
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