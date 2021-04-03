/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: LargestSubset.cpp
Project: Lab 3 - Recursion
Author: Sunghwan Cho
Creation date: 03/31/2021
******************************************************************/

#include <iostream>
#include "LargestSubset.h"

int FindTotal(int* values, int startIndex, int endIndex)
{
	int total = 0;
	if (startIndex > endIndex) {
		return 0x80000000;
	}
	for (int i = startIndex; i < endIndex; i++) {
		std::cout << values[i] << " + ";
		total += values[i];
	}
	total += values[endIndex];
	std::cout << values[endIndex] << " = " << total << std::endl;
	return total;
}

int FindLargestSubset(int* values, int count)
{
	return 0;
}
