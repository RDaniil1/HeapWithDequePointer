#include <iostream>
#include <string>
using namespace std;
struct Item
{
	int item;
	Item* next;
	Item* prev;
};
struct Deque
{
	int AllSize = 0;
	Item* LeElem;
	Item* RiElem;
};
void Inicialization(Deque* el)
{
	int num;
	cout << "Type first item for the first node: ";
	cin >> num;
	el->LeElem = new Item;
	el->LeElem->next = nullptr;
	el->LeElem->prev = nullptr;
	el->LeElem->item = num;
	el->RiElem = el->LeElem;
}
void CreateRightNode(Deque* el)
{
	Item* helpR;
	int num;
	cout << "Type number for deque: ";
	cin >> num;
	if ((el->RiElem->next == nullptr and el->RiElem->prev == nullptr) or el->RiElem->next == nullptr) {
		helpR = el->RiElem;
		el->RiElem = new Item;
		helpR->next = el->RiElem;
		el->RiElem->prev = helpR;
		el->RiElem->next = nullptr;
		el->RiElem->item = num;
		cout << "Node created" << endl;
		el->AllSize++;
	}
}
void CreateLeftNode(Deque* el)
{
	Item* helpL;
	int num;
	cout << "Type number for deque: ";
	cin >> num;
	if ((el->LeElem->next == nullptr and el->LeElem->prev == nullptr) or el->LeElem->prev == nullptr) {
		helpL = el->LeElem;
		el->LeElem = new Item;
		helpL->prev = el->LeElem;
		el->LeElem->next = helpL;
		el->LeElem->prev = nullptr;
		el->LeElem->item = num;
		cout << "Node created" << endl;
		el->AllSize++;
	}
}
void DequeSize(Deque* el)
{
	cout << "Size of this deque is: " << el->AllSize << endl << endl;
}
void ShowAllNodes(Deque* el)
{
	Item* helpWatch = el->LeElem;
	int index = 1;
	cout << "Deque will be shown from left side" << endl;
	while (helpWatch->next != nullptr) {
		cout << index << " element is: " << helpWatch->item << endl;
		helpWatch = helpWatch->next;
		index++;
	}
	cout << index << " element is: " << helpWatch->item << endl << endl;
	helpWatch = el->LeElem;
}
void DeleteRightNode(Deque* el)
{
	if (el->RiElem->prev != nullptr) {
		Item* helpR = el->RiElem;
		helpR = el->RiElem->prev;
		delete el->RiElem;
		el->RiElem = helpR;
		helpR = helpR->prev;
		el->RiElem->next = nullptr;
		el->AllSize--;
	}
	else if (el->RiElem->prev == nullptr) {
		delete el->RiElem;
		cout << endl << "Right node deleted" << endl;
	}
	else cout << "No nodes" << endl << endl;
}
void DeleteLeftNode(Deque* el)
{
	if (el->LeElem->next != nullptr) {
		Item* helpL = el->LeElem;
		helpL = el->LeElem->next;
		delete el->LeElem;
		el->LeElem = helpL;
		helpL = helpL->next;
		el->LeElem->prev = nullptr;
		el->AllSize--;
	}
	else if (el->LeElem->next == nullptr) {
		delete el->LeElem;
		cout << endl << "Left node deleted" << endl;
	}
	else cout << "No nodes" << endl << endl;
}
void DeleteAll(Deque* el)
{
		while (el->LeElem->prev == nullptr && el->RiElem->next != nullptr)
		{
			Item* helpL = el->LeElem;
			helpL = el->LeElem->next;
			delete el->LeElem;
			el->LeElem = helpL;
			helpL = helpL->next;
			el->LeElem->prev = nullptr;
			if (el->AllSize != 0)
				el->AllSize--;
		}
		if ((el->LeElem->prev == nullptr and el->LeElem->next == nullptr)
			or (el->RiElem->next == nullptr and el->RiElem->prev == nullptr))
			delete el->LeElem;
}
int main()
{
	Deque node;
	int command;
	Inicialization(&node);
	cout << "Available commands: " << endl << endl;
	cout << "1. Create left node" << endl;
	cout << "2. Create right node" << endl;
	cout << "3. Show current deque size" << endl;
	cout << "4. Show all nodes" << endl;
	cout << "5. Delete right node" << endl;
	cout << "6. Delete left node" << endl;
	cout << "7. Exit program" << endl;
	while (1)
	{
		cout << endl << "Type command for deque: " << endl;
		cin >> command;
		if (command >= 1 && command < 7)
			switch (command) {
			case 1:
				CreateLeftNode(&node);
				break;
			case 2:
				CreateRightNode(&node);
				break;
			case 3:
				DequeSize(&node);
				break;
			}
		else if (command == 7 and node.LeElem->item) {
			DeleteAll(&node);
			break;
		}
		else if (command == 6 and node.LeElem->item) {
			DeleteLeftNode(&node);
			continue;
		}
		else if (command == 5 and node.LeElem->item)
			DeleteRightNode(&node);
		else if (command == 4 and node.LeElem->item)
			ShowAllNodes(&node);
		else cout << "Incorrect command" << endl;
	}
	return 0;
}