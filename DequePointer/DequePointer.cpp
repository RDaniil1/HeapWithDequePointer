#include <iostream> 
#include <string>
using namespace std;
bool IsEmpty = true;
struct Item
{
	int item;
	Item* next;
	Item* prev;
};
struct Deque
{
	int AllSize = 0;
	Item* LeElem = NULL;
	Item* RiElem = NULL;
};
void CommandList()
{
	cout << "Available commands: " << endl << endl;
	cout << "1. Create left node" << endl;
	cout << "2. Create right node" << endl;
	cout << "3. Show current deque size" << endl;
	cout << "4. Show all nodes" << endl;
	cout << "5. Delete right node" << endl;
	cout << "6. Delete left node" << endl;
	cout << "7. Delete all nodes" << endl;
	cout << "8. Exit program" << endl;
}
void CreateRightNode(Deque* el)
{
	Item* helpR;
	int num;
	cout << "Type number for deque: ";
	cin >> num;
	if (IsEmpty == false) {
		helpR = el->RiElem;
		el->RiElem = new Item;
		helpR->next = el->RiElem;
		el->RiElem->prev = helpR;
		el->RiElem->next = nullptr;
		el->RiElem->item = num;
		cout << "Right node created" << endl;
		el->AllSize++;
	}
	else if (IsEmpty != false) {
		el->RiElem = new Item;
		el->RiElem->next = nullptr;
		el->RiElem->prev = nullptr;
		el->RiElem->item = num;
		el->LeElem = el->RiElem;
		el->AllSize++;
		IsEmpty = false;
		cout << "Right node created" << endl;
	}
}
void CreateLeftNode(Deque* el)
{
	Item* helpL;
	int num;
	cout << "Type number for deque: ";
	cin >> num;
	if (IsEmpty == false) {
		helpL = el->LeElem;
		el->LeElem = new Item;
		helpL->prev = el->LeElem;
		el->LeElem->next = helpL;
		el->LeElem->prev = nullptr;
		el->LeElem->item = num;
		cout << "Left node created" << endl;
		el->AllSize++;
	}
	else if (IsEmpty != false) {
		el->LeElem = new Item;
		el->LeElem->next = nullptr;
		el->LeElem->prev = nullptr;
		el->LeElem->item = num;
		el->RiElem = el->LeElem;
		el->AllSize++;
		IsEmpty = false;
		cout << "Left node created" << endl;
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
		cout << endl << "Right node deleted" << endl;
		el->AllSize--;
	}
	else if (el->RiElem->prev == nullptr) {
		delete el->RiElem;
		IsEmpty = true;
		el->LeElem = el->RiElem;
		el->AllSize--;
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
		cout << endl << "Left node deleted" << endl;
		el->AllSize--;
	}
	else if (el->LeElem->next == nullptr) {
		delete el->LeElem;
		IsEmpty = true;
		el->RiElem = el->LeElem;
		el->AllSize--;
		cout << endl << "Left node deleted" << endl;
	}
	else cout << "No nodes" << endl << endl;
}
void DeleteAll(Deque* el)
{
		while (el->LeElem->next != nullptr)
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
		delete el->LeElem;
		IsEmpty = true;
		el->AllSize--;
}
int main()
{
	Deque node;
	int command;
	CommandList();
	while (1)
	{
		cout << endl << "Type command for deque: " << endl;
		cin >> command;
		if (command >= 1 && command < 4)
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
		else if (command == 8 and IsEmpty == true) 
			break;
		else if (command == 8 and IsEmpty != true) {
			DeleteAll(&node);
			break;
		}
		else if (command == 7 and IsEmpty != true)
			DeleteAll(&node);
		else if (command == 6 and IsEmpty != true) 
			DeleteLeftNode(&node);
		else if (command == 5 and IsEmpty != true)
			DeleteRightNode(&node);
		else if (command == 4 and IsEmpty != true)
			ShowAllNodes(&node);
		else cout << "Error. Type number of another command again" << endl;
	}
	return 0;
}