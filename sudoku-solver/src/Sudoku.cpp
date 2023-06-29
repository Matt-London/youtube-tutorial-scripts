#include "Sudoku.hpp"

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

Sudoku::Sudoku(const std::string& path) {
    std::ifstream reader(path);

    std::size_t i = 0;
    std::size_t j = 0;

    // Loop through all lines in file
    std::string line;
    while (i < sideLength && std::getline(reader, line)) {
        std::istringstream ss(line);

        std::string token;
        // Loop through all characters (separated by space)
        while (ss >> token) {
            int num;

            // If it is blank do not convert
            if (token == std::string(1, BLANK_CHAR)) {
                num = BLANK;
            }
            // Otherwise convert
            else {
                num = std::stoi(token);
            }

            // Set on board
            board[i][j] = num;

            j++;

            // Make sure we haven't overflowed the board
            if (j >= sideLength) {
                i++;
                j = 0;
            }
        }

    }

    reader.close();
}

void Sudoku::setSquare(std::size_t i, std::size_t j, int number) {
    board[i][j] = number;
}

int Sudoku::getSquare(std::size_t i, std::size_t j) {
    return board[i][j];
}

void Sudoku::print() {
    int subLen = std::sqrt(sideLength);

    for (std::size_t i = 0; i < sideLength; i++) {
        for (std::size_t j = 0; j < sideLength; j++) {
            if (board[i][j] == BLANK) {
                std::cout << BLANK_CHAR;
            }
            else {
                std::cout << board[i][j];
            }
            std::cout << " ";

            if (((j + 1) % subLen == 0) && (j + 1) < sideLength) {
                std::cout << "| ";
            }
        }
        std::cout << "\n";

        if (((i + 1) % subLen == 0) && (i + 1 < sideLength)) {
            for (std::size_t j = 0; j < sideLength * 2 + subLen; j++) {
                std::cout << "-";
            }
            std::cout << "\n";
        }
    }

    std::cout << std::endl;
}

std::array<int, Sudoku::sideLength> Sudoku::getRow(std::size_t i) {
    std::array<int, sideLength> rowContents{};

    for (std::size_t j = 0; j < sideLength; j++) {
        rowContents[j] = board[i][j];
    }

    return rowContents;
}

std::array<int, Sudoku::sideLength> Sudoku::getCol(std::size_t j) {
    std::array<int, sideLength> colContents{};

    for (std::size_t i = 0; i < sideLength; i++) {
        colContents[i] = board[i][j];
    }

    return colContents;
}

std::array<int, Sudoku::sideLength> Sudoku::getSubsquare(std::size_t i, std::size_t j) {
    int subLen =  std::sqrt(sideLength);

    std::array<int, sideLength> subContents{};
    int numsIdx = 0;

    // Get location within subsquare
    std::size_t subI = i % subLen;
    std::size_t subJ = j % subLen;

    // Find top left location
    std::size_t topLeftI = i - subI;
    std::size_t topLeftJ = j - subJ;

    // Loop through the subsquare and add all numbers
    for (std::size_t k = topLeftI; k < topLeftI + subLen; k++) {
        for (std::size_t l = topLeftJ; l < topLeftJ + subLen; l++) {
            subContents[numsIdx++] = board[k][l];
        }
    }

    return subContents;
}
