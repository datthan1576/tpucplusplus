#include"SinglyLinkedList.h"
#include"DoublyLinkedList.h"
using List1 = List;
using List2 = DoublyLinkedList;
void testSLL();
void testDBL();

int main()
{	
	int i{};
	std::cout << "\t1.Singly Linked List\t2.Doubly Linked List" << std::endl;
	std::cout << "Choose option (1 or 2) :";
	std::cin >> i;
	if (i == 1)
	{
		testSLL();
	}
	else if (i == 2)
	{
		testDBL();
	}			
}








void testSLL()
{
	std::cout << "\t_______________________________________Singly Linked List_______________________________________" << std::endl;
	std::cout << std::endl;
	List1 l1;
	while (true)
	{
		std::cout << "\t1.Insert\t2.Delete\t3.Get size" << std::endl;
		std::cout << "\t4.Get value \t5.Quit\t        " << std::endl;
		int choice{};
		std::cout << "Choose option:";
		std::cin >> choice;
		if (choice == 1)
		{
			int pos{};
			double value{};
			std::cout << "Position ( 1 <= pos <= " << l1.getSize() + 1<<" )";
			std::cin >> pos;
			std::cout << "Value : ";
			std::cin >> value;
			l1.insMid(value, pos);
			l1.print();
		}
		else if (choice == 2)
		{
			assert(l1.getSize()>=1 && " List is empty! How to delete? ");
			int pos{};
			std::cout << "Position ( 1 <= pos <= " << l1.getSize()<<" )";
			std::cin >> pos;
			l1.delMid(pos);
			l1.print();
		}
		else if (choice == 3)
		{
			std::cout << "Size :" << l1.getSize()<<std::endl;
		}
		else if (choice == 4)
		{
			int pos{};
			std::cout << "Position ( 1 <= pos <= " << l1.getSize()<<" ):" ;
			std::cin >> pos;
			std::cout << "Value of " << pos << "-th element : " << l1.valueOf(pos) << std::endl;
		}
		else if (choice == 5)
		{
			exit(0);
		}
		else
		{
			continue;
		}
	}
}

void testDBL()
{
	std::cout << "\t_______________________________________Doubly Linked List_______________________________________" << std::endl;
	List2 l2;
	while (true)
	{
		std::cout << "\t1.Insert\t2.Delete\t3.Get size" << std::endl;
		std::cout << "\t4.Get value\t5.Quit\t        " << std::endl;
		int choice{};
		std::cout << "Choose option:";
		std::cin >> choice;
		if (choice == 1)
		{
			int pos{};
			double value{};
			std::cout << "Position ( 1 <= pos <= " << l2.getSize() + 1<<" )";
			std::cin >> pos;
			std::cout << "Value : ";
			std::cin >> value;
			l2.insMid(value, pos);
			l2.print();
		}
		else if (choice == 2)
		{
			assert(l2.getSize() >= 1 &&" List is empty! How to delete? ");
			int pos{};
			std::cout << "Position ( 1 <= pos <= " << l2.getSize() <<" )";
			std::cin >> pos;
			l2.delMid(pos);
			l2.print();
		}
		else if (choice == 3)
		{
			std::cout << "Size :" << l2.getSize()<<std::endl;
		}
		else if (choice == 4)
		{
			int pos{};
			std::cout << "Position ( 1 <= pos <= " << l2.getSize()<<" ):";
			std::cin >> pos;
			std::cout <<"Value of "<<pos<<"-th element : "<< l2.valueOf(pos)<<std::endl;
		}
		else if (choice == 5)
		{
			exit(0);
		}
		else
		{
			continue;
		}
	}
}
