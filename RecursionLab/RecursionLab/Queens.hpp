/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: Queens.hpp
Project: Lab 3 - Recursion
Author: Sunghwan Cho
Creation date: 03/31/2021
******************************************************************/

#include "Queens.h"

template <int BOARDSIZE>
Queens<BOARDSIZE>::Queens() : solutions(0)
{
	for(int y = 0; y < BOARDSIZE; ++y)
	{
		for(int x = 0; x < BOARDSIZE; ++x)
		{
            board[y][x] = false;
		}
	}
}

template <int BOARDSIZE>
int Queens<BOARDSIZE>::FindSolutions(bool displaySolution)
{
    solutions = 0;

    eightQueens(displaySolution);
	
	return solutions;
}

template <int BOARDSIZE>
void Queens<BOARDSIZE>::SetQueen(int xPos, int yPos)
{
    if (xPos >= BOARDSIZE || yPos >= BOARDSIZE)
    {
        std::cout << "Queen Position (" << xPos << ", " << yPos << ") is not valid" << std::endl;
        return;
    }

    if (!rowCheck(yPos) == true)
    {
        std::cout << "row " << yPos << " already has a queen" << std::endl;
        return;
    }

    if (!(columnCheck(xPos) == true && diagonalCheck(xPos, yPos)))
    {
        std::cout << "Position (" << xPos << ", " << yPos << ") is not valid conflicts with another queen" << std::endl;
        return;
    }

    board[yPos][xPos] = true;
}

template <int BOARDSIZE>
void Queens<BOARDSIZE>::PrintSolution()
{
    std::cout << "-------------------------------" << std::endl;
    for (int y = 0; y < BOARDSIZE; y++) 
    {
        for (int x = 0; x < BOARDSIZE; x++) 
        {
            if (board[y][x] == true) 
            {
                std::cout << "X ";
            }
            else 
            {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<int BOARDSIZE>
 void Queens<BOARDSIZE>::eightQueens(bool displaySolution, int row)
{
    if (row >= BOARDSIZE)
    {
        if (displaySolution == true)
        {
            PrintSolution();
        }

        ++solutions;
        return;
    }

    for (int col = 0; col < BOARDSIZE; col++)
    {
        if (board[row][col] == true)
        {
            eightQueens(displaySolution, row + 1);
        }
        else if (checkValid(col, row) == true)
        {
            board[row][col] = true;
            eightQueens(displaySolution, row + 1);
            board[row][col] = false;
        }
    }
}

template<int BOARDSIZE>
bool Queens<BOARDSIZE>::checkValid(int col, int row)
{
    return columnCheck(col) && rowCheck(row) && diagonalCheck(col, row);
}

template<int BOARDSIZE>
bool Queens<BOARDSIZE>::columnCheck(int col)
{
    for (int row = 0; row < BOARDSIZE; ++row)
    {
        if (board[row][col] == true)
        {
            return false;
        }
    }
    return true;
}

template<int BOARDSIZE>
bool Queens<BOARDSIZE>::rowCheck(int row)
{
    for (int col = 0; col < BOARDSIZE; ++col)
    {
        if (board[row][col] == true)
        {
            return false;
        }
    }
    return true;
}

template<int BOARDSIZE>
bool Queens<BOARDSIZE>::diagonalCheck(int col, int row)
{
    for (int y = 0; y < BOARDSIZE; ++y)
	{
		for (int x = 0; x < BOARDSIZE; ++x)
		{
			if(board[y][x] == true)
			{
                const int xDistance = std::abs(x - col);
                const int yDistance = std::abs(y - row);

                if (xDistance == yDistance)
                {
                    return false;
                }
			}
		}
	}
    return true;
}

