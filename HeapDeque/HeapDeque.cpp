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
void GetIndexValue(Deque* el, int nodeIndex, int& findedValue)
{
	if (nodeIndex != 1 and nodeIndex <= el->AllSize)
	{
		Item* findValue = el->LeElem;
		Deque forValue;
		Item* forValueFinder;
		forValue.RiElem = new Item;
		forValue.RiElem->next = nullptr;
		forValue.RiElem->prev = nullptr;
		forValue.LeElem = forValue.RiElem;
		forValueFinder = forValue.RiElem;
		for (int i = 1; i < nodeIndex; i++)
		{
			if (i != 1) {
				forValue.RiElem = new Item;
				forValue.RiElem->prev = forValueFinder;
				forValueFinder->next = forValue.RiElem;
				forValue.RiElem->next = nullptr;
			}
			forValue.RiElem->item = el->LeElem->item;
			findValue = el->LeElem->next;
			delete el->LeElem;
			el->LeElem = findValue;
			findValue = el->LeElem->next;
			if (i != 1)
				forValueFinder = forValueFinder->next;
		}
		forValue.RiElem->next = el->LeElem;
		el->LeElem->prev = forValue.RiElem;
		findedValue = el->LeElem->item;
		while (el->LeElem->prev != nullptr)
			el->LeElem = el->LeElem->prev;
	}
	else if (nodeIndex == 1 and nodeIndex <= el->AllSize)
		findedValue = el->LeElem->item;
}
void SwapNodes(Deque* el, int node1, int node2)
{
	if ((node1 <= el->AllSize && node2 <= el->AllSize) && node1 > node2) {
		int memory1 = 0, memory2 = 0;
		int currentSize = el->AllSize;
		Item* helpBegin = NULL;
		Item* helpSwap;
		Deque helpSecDeq;
		Item* helpSwapSec = helpSecDeq.LeElem;
		if (node2 == 1) {
			memory2 = el->LeElem->item;
			for (int i = node2; i < node1; i++)
			{
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				el->LeElem->prev = nullptr;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
			}
			memory1 = el->LeElem->item;
			el->LeElem->item = memory2;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			el->LeElem = helpBegin;
			while (el->LeElem->prev != nullptr)
				el->LeElem = el->LeElem->prev;
			helpSecDeq.AllSize = 0;
			el->AllSize = currentSize;
			el->LeElem->item = memory1;
		}
		else if (node2 != 1)
		{
			for (int i = 1; i < node2; i++)
			{
				helpSwap = el->LeElem;
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
				}
				helpSecDeq.RiElem->item = el->LeElem->item;
				helpSecDeq.AllSize++;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				el->AllSize--;
			}
			memory2 = el->LeElem->item;
			el->LeElem->prev = nullptr;
			for (int i = node2; i < node1; i++)
			{
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				helpSwap->prev = nullptr;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
			}
			memory1 = el->LeElem->item;
			el->LeElem->item = memory2;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			while (el->LeElem->prev != nullptr)
				el->LeElem = el->LeElem->prev;
			helpSecDeq.AllSize = 0;
			el->LeElem = helpBegin;
			el->AllSize = currentSize;
			for (int i = 1; i < node2; i++)
			{
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->LeElem->prev = nullptr;
			}
			el->LeElem->item = memory1;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			while (el->LeElem->prev != nullptr)
				el->LeElem = el->LeElem->prev;
		}
	}
	else if ((node1 <= el->AllSize && node2 <= el->AllSize) && node1 < node2) {
		int memory1 = 0, memory2 = 0;
		int currentSize = el->AllSize;
		Item* helpBegin = NULL;
		Item* helpSwap;
		Deque helpSecDeq;
		Item* helpSwapSec = helpSecDeq.LeElem;
		if (node1 == 1) {
			memory1 = el->LeElem->item;
			for (int i = node1; i < node2; i++)
			{
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				el->LeElem->prev = nullptr;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
			}
			memory2 = el->LeElem->item;
			el->LeElem->item = memory1;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			el->LeElem = helpBegin;
			while (el->LeElem->prev != nullptr)
				el->LeElem = el->LeElem->prev;
			helpSecDeq.AllSize = 0;
			el->AllSize = currentSize;
			el->LeElem->item = memory2;
		}
		else if (node1 != 1)
		{
			for (int i = 1; i < node1; i++)
			{
				helpSwap = el->LeElem;
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
				}
				helpSecDeq.RiElem->item = el->LeElem->item;
				helpSecDeq.AllSize++;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				el->AllSize--;
			}
			memory1 = el->LeElem->item;
			el->LeElem->prev = nullptr;
			for (int i = node1; i < node2; i++)
			{
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				helpSwap->prev = nullptr;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
			}
			memory2 = el->LeElem->item;
			el->LeElem->item = memory1;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			while (el->LeElem->prev != nullptr)
				el->LeElem = el->LeElem->prev;
			helpSecDeq.AllSize = 0;
			el->LeElem = helpBegin;
			el->AllSize = currentSize;
			for (int i = 1; i < node1; i++)
			{
				helpSecDeq.RiElem = new Item;
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->LeElem->prev = nullptr;
			}
			el->LeElem->item = memory2;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			while (el->LeElem->prev != nullptr)
				el->LeElem = el->LeElem->prev;
		}
	}
	else if (node1 > el->AllSize || node2 > el->AllSize)
		cout << "There are only " << el->AllSize << " elements" << endl;
}
void HeapifyDeque(Deque* el, int& n, int& i)
{
	int largest = i;
	int largEl = 0, leftEl = 0, rightEl = 0;
	int leftBr = 2 * i; 
	int rightBr = 2 * i + 1;
	GetIndexValue(el, i, largEl);
	GetIndexValue(el, leftBr, leftEl);
	GetIndexValue(el, rightBr, rightEl);
	if (leftBr <= n && leftEl > largEl) {
		largest = leftBr;
		GetIndexValue(el, largest, largEl);
	}
	if (rightBr <= n && rightEl > largEl) {
		largest = rightBr;
		GetIndexValue(el, largest, largEl);
	}
	if (largest != i)
	{
		SwapNodes(el, i, largest);
		HeapifyDeque(el, n, largest);
	}
}
void HeapSort(Deque* el)
{
	int one = 1; 
	for (int i = el->AllSize/ 2; i >= 1; i--)
		HeapifyDeque(el, el->AllSize, i);
	for (int i = el->AllSize; i >= 1; i--)
	{
		HeapifyDeque(el, i, one);
		SwapNodes(el, one, i);
	}
}
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
	cout << "8. Swap nodes" << endl;
	cout << "9. Heap sort" << endl;
	cout << "10. Get index value" << endl;
	cout << "11. Exit program" << endl;
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
	if (el->AllSize != 1) {
		Item* secDeqWatch;
		Deque secDeq; 
		secDeq.RiElem = new Item;
		secDeq.RiElem->next = nullptr;
		secDeq.RiElem->prev = nullptr;
		secDeq.AllSize = el->AllSize;
		Item* deqWatch = el->LeElem; 
		secDeqWatch = secDeq.RiElem;
		secDeq.LeElem = secDeq.RiElem;
		int index = 1;
		cout << endl << "Deque will be shown from left side" << endl;
		while (index != el->AllSize) {
			deqWatch = el->LeElem->next;
		cout << index << " element is: " << el->LeElem->item << endl;
			if (index != 1)
			{
				secDeq.RiElem = new Item;
				secDeq.RiElem->prev = secDeqWatch;
				secDeqWatch->next = secDeq.RiElem;
				secDeq.RiElem->next = nullptr;
				secDeqWatch = secDeqWatch->next;
			}
			secDeq.RiElem->item = el->LeElem->item;

			delete el->LeElem;
			el->LeElem = deqWatch;
			deqWatch->prev = nullptr;

			index++;
		}
		cout << index << " element is: " << el->LeElem->item << endl << endl;

		secDeqWatch->next = el->LeElem;
		el->LeElem->prev = secDeq.RiElem;
		while (el->LeElem->prev != nullptr)
			el->LeElem = el->LeElem->prev;
	}
	else if (el->AllSize == 1)
		cout << "1 element is: " << el->LeElem->item << endl << endl;
	
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
	int command, node1, node2;
	CommandList();
	while (1)
	{
		cout << endl << "Type command for deque: " ;
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
		else if (command == 11 and IsEmpty == true)
			break;
		else if (command == 11 and IsEmpty != true) {
			DeleteAll(&node);
			break;
		}
		else if (command == 10 and IsEmpty != true) {
			int index, findedValue1;
			cout << "Type node index: ";
			cin >> index;
			GetIndexValue(&node, index, findedValue1);
			cout << "Finded value is: " << findedValue1 << endl;
		}
		else if (command == 9 and IsEmpty != true)
			HeapSort(&node);
		else if (command == 8 and IsEmpty != true)
		{
			cout << "Type nodes to swap: ";
			cin >> node1 >> node2;
			SwapNodes(&node, node1, node2);
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
