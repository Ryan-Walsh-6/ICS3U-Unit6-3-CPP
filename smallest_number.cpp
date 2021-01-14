// Copyright (c) 2021 Ryan Walsh All rights reserved
//
// Created by Ryan Walsh
// Created on January 13 2021
// this program picks out the smallest number out of 10 random numbers

#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <array>

template<size_t N>
int smallest_number(std::array<int, N> list_of_numbers) {
    for (int aSingleElement : list_of_numbers) {
        if (list_of_numbers[0] > aSingleElement) {
            list_of_numbers[0] = aSingleElement;
        }
    }
    return list_of_numbers[0];
}

int main() {
// this program picks out the smallest number out of 10 random numbers
    float average;
    float sum;
    int random_number;
    std::array<int, 10> my_numbers;
    int small_numb;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  //  mersenne_twister
    std::uniform_int_distribution<int> idist(1, 100);  //  [1, 100]


    for (int loop_counter = 0; loop_counter < 10; loop_counter++) {
        random_number = idist(rgen);
        my_numbers[loop_counter] = random_number;
    }
    for (int loop_counter = 0; loop_counter < 10; loop_counter++) {
        std::cout << "The random number " << loop_counter + 1 << " is: "
        << my_numbers[loop_counter] << std::endl;
    }
    small_numb = smallest_number(my_numbers);
    std::cout << std::endl;
    std::cout << "The smallest number is "<< small_numb << std::endl;
}
