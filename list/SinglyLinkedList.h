#pragma once
#include<cassert>
#include<iostream>
class List
{
public:
	List();
	~List();
	virtual void insHead(double);
	virtual void insTail(double);
	virtual void insMid(double, int);
	virtual void delHead();
	virtual void delTail();
	virtual void delMid(int);
	virtual int getSize();
	virtual double valueOf(int);
	virtual void print();
	virtual double& operator[](int);
protected:
	class Node
	{
	public:
		double data;
		Node* next;
		Node();
		Node(double , Node* );
	};
private:
	Node* head;
};

