/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: Queens.hpp
Project: Lab 3 - Recursion
Author: Sunghwan Cho
Creation date: 03/31/2021
******************************************************************/

template <int BOARDSIZE>
Queens<BOARDSIZE>::Queens()
{
}

template <int BOARDSIZE>
int Queens<BOARDSIZE>::FindSolutions(bool displaySolution)
{
	return 0;
}

template <int BOARDSIZE>
void Queens<BOARDSIZE>::SetQueen(int xPos, int yPos)
{
}

template <int BOARDSIZE>
void Queens<BOARDSIZE>::PrintSolution()
{
    std::cout << "-------------------------------" << std::endl;
    for (int y = 0; y < BOARDSIZE; y++) {
        for (int x = 0; x < BOARDSIZE; x++) {
            if (board[y][x] == true) {
                std::cout << "X ";
            }
            else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

