#include "DoublyLinkedList.h"
//Node2's default constructor
DoublyLinkedList::Node2::Node2() :Node(), next2{nullptr}, prev{ nullptr }{};

//Node2's constructor with 3 parameters
DoublyLinkedList::Node2::Node2(double data, Node2* next2, Node2* prev) :Node(data, next), next2{next2}, prev{ prev }{};

//DBL's default constructor
DoublyLinkedList::DoublyLinkedList() :head2{ nullptr }, tail2{nullptr} {};	

//DBL's destructor
DoublyLinkedList::~DoublyLinkedList()
{
	if (head2 == nullptr)
	{
	}
	else
	{
		while (head2->next2 != nullptr)
		{
			this->delHead();
		}
		delete head2;
		head2 = nullptr;
	}
};

//Insert before head of DBL             
void DoublyLinkedList::insHead(double data)
{
	if (head2 == nullptr)
	{
		Node2* temp= new Node2(data, nullptr, nullptr);
		head2 = tail2 = temp;
	}
	else
	{
		Node2* newNode = new Node2(data, head2, nullptr);
		head2->prev = newNode;
		head2 = newNode;
	}
};

//Insert after tail of DBL
void DoublyLinkedList::insTail(double data)
{
	if (head2 == nullptr)
	{
		this->insHead(data);
    }
	else
	{
		Node2* temp = head2;
		while (temp->next2 != nullptr)
		{
			temp = temp->next2;
		}
		Node2* temp2 = new Node2(data, nullptr, temp);
		tail2 = temp->next2 = temp2;
	}
}

//Insert in the middle of DBL
void DoublyLinkedList::insMid(double data, int pos)
{
	assert(pos >= 1 && pos <= (this->getSize() + 1));

	if (pos == 1)
	{
		this->insHead(data);
	}
	else if (pos == (this->getSize() + 1))
	{
		this->insTail(data);
	}
	else if (pos == 2)
	{
		Node2* temp = head2;
		Node2* temp2 = new Node2(data, temp->next2, temp);
		temp->next2->prev = temp2;
		temp->next2 = temp2;
	}
	else
	{
		int k{ 1 };
		Node2* temp = head2;
		while (k != pos)
		{
			temp = temp->next2;
			k++;
		}
		Node2* temp2 = new Node2(data, temp, temp->prev);
		temp =temp->prev = temp2;
	}
}

//Delete the first element of DBL
void DoublyLinkedList::delHead()
{
	if (head2 == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	else
	{
		Node2* temp = head2;
		head2 = head2->next2;
		delete temp;
	}
}

//Delete the last element of DBL
void DoublyLinkedList::delTail()
{
	if (head2 == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	else
	{
		Node2* temp = head2;
		while (temp->next2 != nullptr)
		{
			temp = temp->next2;
		}
		tail2 = temp->prev;
		Node2* temp2 = temp;
		temp = nullptr;
		delete temp2;
	}
}

//Delete any element of DBL
void DoublyLinkedList::delMid(int pos)
{
	assert(pos >= 1 && pos <= this->getSize());
	if (pos == 1)
	{
		this->delHead();
	}
	else if (pos == this->getSize())
	{
		this->delTail();
	}
	else
	{
		int k{ 1 };
		Node2* temp = head2;
		while (k != pos - 1)
		{
			temp = temp->next2;
			k++;
		}
		Node2* temp2 = temp->next2;
		temp->next2 = temp->next2->next2;
		delete temp2;
	}
}

//Get number of elements of DBL
int DoublyLinkedList::getSize()
{
	if (head2 == nullptr)
	{
		return 0;
	}
	else
	{
		Node2* temp = head2;
		int size{ 1 };
		while (temp->next2 != nullptr)
		{
			temp = temp->next2;
			size++;
		}
		return size;
	}
}

//Get number of elements of DBL            
double DoublyLinkedList::valueOf(int pos)
{
	assert(pos >= 1 && pos <= this->getSize());
	Node2* temp = head2;
	int k{ 1 };
	while (k != pos)
	{
		temp = temp->next2;
		k++;
	}
	return temp->data;
}

//Display DBL    
void DoublyLinkedList::print()
{	
	if (head2 == nullptr)
	{
		std::cout << "Empty!";
	}
	else
	{
		std::cout << "Doubly Linked List : ";
		for (Node2* p = head2; p != nullptr; p = p->next2)
		{
			std::cout << p->data << " , ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//Overloading operator []
double& DoublyLinkedList::operator[](int pos)
{
	assert(pos >= 1 && pos <= this->getSize());
	Node2* temp = head2;
	int k{ 1 };
	while (k != pos)
	{
		temp = temp->next2;
		k++;
	}
	return temp->data;
}