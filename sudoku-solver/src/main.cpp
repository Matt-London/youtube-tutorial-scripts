#include <iostream>

#include "Sudoku.hpp"

void printArray(std::array<int, 9>& arr) {
    for (int item: arr) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;

}

int main(void) {
    Sudoku board("../input/input1.txt");

    board.print();

    std::array<int, 9> tmp = board.getCol(3);
    printArray(tmp);
    tmp = board.getRow(5);
    printArray(tmp);
    tmp = board.getSubsquare(8, 7);
    printArray(tmp);

    return 0;
}