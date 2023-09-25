// CMakeTest.cpp: определяет точку входа для приложения
//

#include <iostream>
#include <vector>
#include <cassert>
#include "CMakeTest.h"

//-----------------------------------------------------------------------------------
static const int N{ 4 };             

void thinOutSequence()
{
    
    std::vector <std::pair <int, int>> sequence{
        {1, 10}, 
        {2, 11},
        {3, 11}, 
        {4, 11}, 
        {5, 11}, 
        {6, 10},
        {7, 11}, 
        {8, 11}, 
        {9, 11}, 
        {10, 11}, 
        {11, 10} 
    };

    std::cout << "Initial sequence: ";
    for (auto i : sequence)
        std::cout << '{' << i.first << ", " << i.second
        << "}";
    std::cout << "\n";


    int counter = 0;
    for (int i = 0; i < sequence.size()-1 ; i++) {                       
        if (sequence[i].second == sequence[i + 1].second) {
            counter++;
            if ((counter != 1) && counter != N) {
                sequence.erase(sequence.begin() + i);
                i--;
            }
        }
        else { counter = 0; };
    }

    std::cout << "Thined out sequence: ";
    for (auto i : sequence)
        std::cout << '{' << i.first << ", " << i.second
        << "}";
    std::cout << "\n";
}

int main()
{
    assert(N > 2);

    thinOutSequence();

    return 0;
}
