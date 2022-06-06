#include "SinglyLinkedList.h"

//Node's default constructor
List::Node::Node():data{ 0 }, next{ nullptr }{};

//Node's constructor with 2 parameters
List::Node::Node(double data, Node* next) :data{ data }, next{ next }{};

//List's default constructor
List::List() :head(nullptr) {};

//List's destructor
List::~List() {
	if (head == nullptr)
	{		
	}
	else
	{
		while (head->next != nullptr)
			this->delHead();
		delete head;
		head = nullptr;
	}
}

//Insert before head of List
void List::insHead(double data)
{
	if (head == nullptr)
	{
		head = new Node(data, nullptr);
	}
	else
	{
		Node* temp = new Node(data, head);
		head = temp;
	}
}

//Insert after tail of List
void List::insTail(double data) {
	if (head == nullptr)
	{
		this->insHead(data);
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		Node* temp2 = new Node(data, nullptr);
		temp->next = temp2;
	}
};

//Insert in the middle of List
void List::insMid(double data, int pos) {
	assert(pos >= 1 && pos <= (this->getSize() + 1));
	if (pos == 1)
	{
		this->insHead(data);
	}
	else if (pos == (this->getSize() + 1))
	{
		this->insTail(data);
	}
	else
	{
		Node* temp = head;
		int k{ 1 };
		while (k != pos-1)
		{
			temp = temp->next;
			++k;
		}
		Node* newNode = new Node(data, temp->next);
		temp->next = newNode;
	}
};

//Delete the first element of List
void List::delHead() {
	if (head == nullptr)
	{
		std::cout << "List is empty";
	}
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
};

//Delete the last element of List
void List::delTail() {
	Node *p = head;
	while (p->next->next != nullptr) {
		p = p->next;
	}
	delete p->next->next;
	p->next =nullptr ;
}

//Delete any element of List
void List::delMid(int pos) {
	assert(pos>=1&&pos<=this->getSize());
	if (pos == 1)
	{
		this->delHead();
    }
	else if(pos==this->getSize())
	{
		this->delTail();
	}
	else
	{
		int k{ 1 };
		Node* temp = head;
		while (k != pos - 1)
		{
			temp = temp->next;
			k++;
		}
		Node* temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;
	}
}

//Get number of elements of List
int List::getSize() {	
	if (head == nullptr)
	{
		return 0;
	}
	else if (head->next == nullptr)
	{
		return 1;
	}
	else
	{
		int size{ 0 };
		Node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}
}

//Get number of elements of List
double List::valueOf(int pos) {
	assert(pos >= 1 && pos <= this->getSize());
	Node* temp = head;
	int k{ 1 };
	while (k != pos)
	{
		temp = temp->next;
		k++;
	}
	return temp->data;
};

//Display List
void List::print() {

	if (head == nullptr)
	{
		std::cout << "Empty!" << std::endl;
	}
	else {
		std::cout << "Singly Linked List : ";
		for (Node* p = head; p != nullptr; p = p->next)
		{
			std::cout << p->data << " , ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//Overloading operator []
double& List::operator[](int pos)
{
	assert(pos >= 1 && pos <= this->getSize());
	Node* temp = head;
	int k{ 1 };
	while (k != pos)
	{
		temp = temp->next;
		k++;
	}
	return temp->data;
}