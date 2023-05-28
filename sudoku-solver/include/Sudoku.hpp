#ifndef SUDOKU_HPP_
#define SUDOKU_HPP_

#include <string>
#include <array>

class Sudoku {
private:
    static constexpr int sideLength = 9;

    std::array<std::array<int, sideLength>, sideLength> board;

public:
    /**
     * Constructs a sudoku board from an input path
    */
    Sudoku(const std::string& path);

    /**
     * Set a square to a new number
     * 
     * @param i Row index
     * @param j Column index
     * @param number New number to set
    */
    void setSquare(std::size_t i, std::size_t j, int number);

    /**
     * Get a specific square's number
     * 
     * @param i Row index
     * @param j Column index
     * @return Value at [i][j]
    */
    int getSquare(std::size_t i, std::size_t j);

    /**
     * Print the current board to the screen
    */
    void print();

    /**
     * Get all numbers in a row
     * 
     * @param i Row of interest
     * @return Array of all present numbers
    */
    std::array<int, sideLength> getRow(std::size_t i);

    /**
     * Get all numbers in a column
     * 
     * @param j Column of interest
     * @return Array of all numbers in column
    */
    std::array<int, sideLength> getCol(std::size_t j);

    /**
     * Get all numbers contained in a specific space's subsquare
     * 
     * @param i Row of index
     * @param j Column of index
     * @return Array of all values in subsquare
    */
    std::array<int, sideLength> getSubsquare(std::size_t i, std::size_t j);
};

#endif