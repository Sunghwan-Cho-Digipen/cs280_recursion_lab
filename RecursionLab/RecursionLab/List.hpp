#include "List.h"
/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: List.hpp
Project: Lab 3 - Recursion
Author: Sunghwan Cho
Creation date: 03/31/2021
******************************************************************/

template <typename T>
List<T>::List(T* data, int numNode) : nextNodeIndex(0), totalNodeNum(numNode)
{
	pHead = BuildList(data, numNode, pHead);
}

template <typename T>
void List<T>::PrintList() const
{
	if(totalNodeNum <= 0)
	{
		return;
	}
	Node* curr = pHead;
	int totalNum = totalNodeNum;
	PrintNode(curr, totalNum);
}

template <typename T>
void List<T>::PrintListBackwards() const
{
	if (totalNodeNum <= 0)
	{
		return;
	}
	Node* curr = pHead;
	int firstIndex = 0;
	PrintInverseNode(curr, firstIndex);
}

template <typename T>
void List<T>::Reverse()
{
	if(totalNodeNum <= 0)
	{
		return;
	}
	Node* curr = pHead;
	int firstIndex = 0;
	ReverseHelperFunction(curr, firstIndex);
}

template<typename T>
typename List<T>::Node* List<T>::BuildList(T* data, int numNodes, Node* tempHead) {
	if(numNodes == 1) 
	{
		return new Node{ *data, tempHead , nextNodeIndex++};
	}
	return BuildList(data + 1, numNodes - 1, new Node{ *data, tempHead , nextNodeIndex++}); // (a tail recursive function).  
}

template<typename T>
void List<T>::PrintNode(Node* currentNode, int& index) const
{
	if (currentNode == nullptr)
	{
		return;
	}
	
	if(--index == 0)
	{
		std::cout << currentNode->data << std::endl;
		return;
	}
	std::cout << currentNode->data << ", ";
	PrintNode(currentNode->pNext, index);
}

template <typename T>
void List<T>::PrintInverseNode(Node* currentNode, int index) const
{
	if(currentNode == nullptr)
	{
		return;
	}
	
	PrintInverseNode(currentNode->pNext, index + 1);

	std::cout << currentNode->data;
	if(index != 0)
	{
		std::cout << ", ";
		return;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::ReverseHelperFunction(Node* currentNode, int index)
{
	if (currentNode == nullptr)
	{
		return;
	}

	if(index == totalNodeNum - 1)
	{
		return;
	}
	
	ReverseHelperFunction(currentNode->pNext, index + 1);
	Node* tempNode = currentNode;
	currentNode = currentNode->pNext;
	currentNode->pNext = tempNode;
	if(index == totalNodeNum - 2)
	{
		pHead = currentNode;
	}
	if(index == 0)
	{
		currentNode->pNext->pNext = nullptr;
	}
}
