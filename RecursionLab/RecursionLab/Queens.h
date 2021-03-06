/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: Queens.h
Project: Lab 3 - Recursion
Author: Sunghwan Cho
Creation date: 03/31/2021
******************************************************************/
#pragma once

template<int BOARDSIZE>
class Queens {
public:
	Queens();
	int FindSolutions(bool displaySolution = true);
	void SetQueen(int xPos, int yPos);
	void PrintSolution();
private:
	// Create any own private functions or private data memembers that you like

	void eightQueens(bool displaySolution, int row = 0);
	bool checkValid(int col, int row);
	bool columnCheck(int col);
	bool rowCheck(int row);
	bool diagonalCheck(int col, int row);
	
	int solutions;
	bool board[BOARDSIZE][BOARDSIZE];
};

#include "Queens.hpp"
