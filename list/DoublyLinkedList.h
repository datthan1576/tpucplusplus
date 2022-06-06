#pragma once
#include"SinglyLinkedList.h"

class DoublyLinkedList:public List
{
private:
	class Node2 :public List::Node
	{		
	public:
		Node2* prev;
		Node2* next2;
		Node2();
		Node2(double data, Node2* next, Node2* prev);
	};
	Node2* head2;
	Node2* tail2;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insHead(double);
	void insTail(double);
	void insMid(double, int);
	void delHead();
	void delTail();
	void delMid(int);
	int getSize();
	double valueOf(int);
	void print();
	double& operator[](int );
};

