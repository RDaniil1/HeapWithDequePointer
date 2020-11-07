#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
bool IsEmpty = true; //1
long long N_op = 0;
struct Item
{
	int item;
	Item* next;
	Item* prev;
};
//3
struct Deque
{
	int AllSize = 0;
	Item* LeElem = NULL;
	Item* RiElem = NULL;
};
//23 + 19 + (n - 1)(12 + 19 + 2) + 14 = 23 + 33n
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
		N_op += 23;
		for (int i = 1; i < nodeIndex; i++)
		{
			if (i != 1) {
				forValue.RiElem = new Item;
				forValue.RiElem->prev = forValueFinder;
				forValueFinder->next = forValue.RiElem;
				forValue.RiElem->next = nullptr;
				N_op += 12;
			}
			forValue.RiElem->item = el->LeElem->item;
			findValue = el->LeElem->next;
			delete el->LeElem;
			el->LeElem = findValue;
			findValue = el->LeElem->next;
			N_op += 19;
			if (i != 1) {
				forValueFinder = forValueFinder->next;
				N_op += 2;
			}
		}
		forValue.RiElem->next = el->LeElem;
		el->LeElem->prev = forValue.RiElem;
		findedValue = el->LeElem->item;
		el->LeElem = forValue.LeElem;
		N_op += 14;
	}
	else if (nodeIndex == 1 and nodeIndex <= el->AllSize) {
		findedValue = el->LeElem->item;
		N_op += 7;
	}
}
//18 + 2 + 7 + 15 + 19 + (n - 1)(7 + 15 + 19) + 7 + 3 + 18 + 18 + (n - 1)(3 + 20 + 18) + 21 + 5 + 15 + 17 + (n - 1)(5 + 20 + 17) + 14 + (n - 1)7 = 48 + 131n
void SwapNodes(Deque* el, int node1, int node2)
{
	if ((node1 <= el->AllSize && node2 <= el->AllSize) && node1 > node2) {
		int memory1 = 0, memory2 = 0;
		int currentSize = el->AllSize;
		Item* helpBegin = NULL;
		Item* helpSwap;
		Deque helpSecDeq;
		Item* helpSwapSec = helpSecDeq.LeElem;
		N_op += 17; //17
		if (node2 == 1) {
			memory2 = el->LeElem->item;
			N_op += 5; //5
			for (int i = node2; i < node1; i++)
			{
				helpSecDeq.RiElem = new Item;
				N_op += 5; //5 
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
					N_op += 20; //20
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 20; //20
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				el->LeElem->prev = nullptr;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
				N_op += 23; //23
			}
			memory1 = el->LeElem->item;
			el->LeElem->item = memory2;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			el->LeElem = helpBegin;
			helpSecDeq.AllSize = 0;
			el->AllSize = currentSize;
			el->LeElem->item = memory1;
			N_op += 26; //26
		}
		else if (node2 != 1)
		{
			N_op += 2; //2
			for (int i = 1; i < node2; i++)
			{
				helpSwap = el->LeElem;
				helpSecDeq.RiElem = new Item;
				N_op += 7; //7
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
					N_op += 15; //15
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					N_op += 15; //15
				}
				helpSecDeq.RiElem->item = el->LeElem->item;
				helpSecDeq.AllSize++;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				el->AllSize--;
				N_op += 19; //19 
			}
			memory2 = el->LeElem->item;
			el->LeElem->prev = nullptr;
			N_op += 7; //7
			for (int i = node2; i < node1; i++)
			{
				helpSecDeq.RiElem = new Item;
				N_op += 3; //3
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					N_op += 18; //18
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 20; //20
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				helpSwap->prev = nullptr;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
				N_op += 18; //18
			}
			memory1 = el->LeElem->item;
			el->LeElem->item = memory2;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			helpSecDeq.AllSize = 0;
			el->LeElem = helpBegin;
			el->AllSize = currentSize;
			N_op += 21; //21
			for (int i = 1; i < node2; i++)
			{
				helpSecDeq.RiElem = new Item;
				N_op += 5; //5
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 15; //15
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 20; //20
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->LeElem->prev = nullptr;
				N_op += 17; //17
			}
			el->LeElem->item = memory1;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			el->LeElem = helpBegin;
			N_op += 13; //13
		}
	}
	else if ((node1 <= el->AllSize && node2 <= el->AllSize) && node1 < node2) {
		int memory1 = 0, memory2 = 0;
		int currentSize = el->AllSize;
		Item* helpBegin = NULL;
		Item* helpSwap;
		Deque helpSecDeq;
		Item* helpSwapSec = helpSecDeq.LeElem;
		N_op += 17; //17
		if (node1 == 1) {
			memory1 = el->LeElem->item;
			N_op += 5; //5
			for (int i = node1; i < node2; i++)
			{
				helpSecDeq.RiElem = new Item;
				N_op += 5; //5
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
					N_op += 20; //20 
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 20; //20
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				el->LeElem->prev = nullptr;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
				N_op += 23; //23
			}
			memory2 = el->LeElem->item;
			el->LeElem->item = memory1;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			el->LeElem = helpBegin;
			helpSecDeq.AllSize = 0;
			el->AllSize = currentSize;
			el->LeElem->item = memory2;
			N_op += 26; //26
		}
		else if (node1 != 1)
		{
			N_op += 2; //2
			for (int i = 1; i < node1; i++)
			{
				helpSwap = el->LeElem;
				helpSecDeq.RiElem = new Item;
				N_op += 7; //7
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					helpBegin = helpSecDeq.RiElem;
					N_op += 15; //15
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					N_op += 15; //15
				}
				helpSecDeq.RiElem->item = el->LeElem->item;
				helpSecDeq.AllSize++;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				el->AllSize--;
				N_op += 19; //19
			}
			memory1 = el->LeElem->item;
			el->LeElem->prev = nullptr;
			N_op += 7; //7
			for (int i = node1; i < node2; i++)
			{
				helpSecDeq.RiElem = new Item;
				N_op += 3; //3
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					helpSecDeq.LeElem = helpSecDeq.RiElem;
					N_op += 18; //18
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 20; //20
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				helpSwap->prev = nullptr;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->AllSize--;
				N_op += 18; //18
			}
			memory2 = el->LeElem->item;
			el->LeElem->item = memory1;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			helpSecDeq.AllSize = 0;
			el->LeElem = helpBegin;
			el->AllSize = currentSize;
			N_op += 21; //21
			for (int i = 1; i < node1; i++)
			{
				helpSecDeq.RiElem = new Item;
				N_op += 5; //5
				if (helpSecDeq.AllSize == 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = nullptr;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 15; //15
				}
				else if (helpSecDeq.AllSize != 0)
				{
					helpSecDeq.RiElem->next = nullptr;
					helpSecDeq.RiElem->prev = helpSwapSec;
					helpSwapSec->next = helpSecDeq.RiElem;
					helpSwapSec = helpSecDeq.RiElem;
					helpSecDeq.RiElem->item = el->LeElem->item;
					N_op += 20; //20
				}
				helpSwap = el->LeElem;
				helpSwap = el->LeElem->next;
				delete el->LeElem;
				el->LeElem = helpSwap;
				helpSwap = el->LeElem->next;
				helpSecDeq.AllSize++;
				el->LeElem->prev = nullptr;
				N_op += 17; //17
			}
			el->LeElem->item = memory2;
			el->LeElem->prev = helpSecDeq.RiElem;
			helpSecDeq.RiElem->next = el->LeElem;
			N_op += 11; //11
			while (el->LeElem->prev != nullptr) {
				el->LeElem = el->LeElem->prev;
				N_op += 7; //7
			}
			N_op += 3; //3
		}
	}
	else if (node1 > el->AllSize || node2 > el->AllSize) {
		cout << "There are only " << el->AllSize << " elements" << endl;
		N_op += 6; //6
	}
}
//9 * 2 + 5(23 + 33n) + 4 * 2 + 6 + 7 + 48 + 131n + log(n) = (202 + 296n) * log(n)
void HeapifyDeque(Deque* el, int& n, int& i)
{
	int largest = i;
	int largEl = 0, leftEl = 0, rightEl = 0;
	int leftBr = 2 * i;
	int rightBr = 2 * i + 1;
	N_op += 9; //9
	GetIndexValue(el, i, largEl); //23 + 33n
	GetIndexValue(el, leftBr, leftEl); //23 + 33n
	GetIndexValue(el, rightBr, rightEl); //23 + 33n
	N_op += 9; //9
	if (leftBr <= n && leftEl > largEl) {
		largest = leftBr;
		GetIndexValue(el, largest, largEl); //23 + 33n
		N_op += 4; //4
	}
	if (rightBr <= n && rightEl > largEl) {
		largest = rightBr;
		GetIndexValue(el, largest, largEl); //23 + 33n
		N_op += 4; //4
	}
	N_op += 6; //6
	if (largest != i)
	{
		SwapNodes(el, i, largest); //48 + 131n
		HeapifyDeque(el, n, largest); 
		N_op += 7; //7
	}
}
//4 + n/2(6 + (202 + 296n) * log(n)) + 2 + n((202 + 296n) * log(n) + 48 + 131n + 8) = 444n^2 * log(n) + 131n^2 + 303n * log(n) + 59n + 6
void HeapSort(Deque* el)
{
	int one = 1;
	N_op += 4;
	for (int i = el->AllSize / 2; i >= 1; i--) {
		HeapifyDeque(el, el->AllSize, i); //(202 + 296n) * log(n)
		N_op += 6;
	}
	N_op += 2;
	for (int i = el->AllSize; i >= 1; i--)
	{
		HeapifyDeque(el, i, one); //(202 + 296n) * log(n)
		SwapNodes(el, one, i); //48 + 131n
		N_op += 8;
	}
}
//4 + 20 = 24
void CreateRightNode(Deque* el)
{
	Item* helpR;
	int num = rand() % 100 + 1;
	N_op += 4;
	if (IsEmpty == false) {
		helpR = el->RiElem;
		el->RiElem = new Item;
		helpR->next = el->RiElem;
		el->RiElem->prev = helpR;
		el->RiElem->next = nullptr;
		el->RiElem->item = num;
		el->AllSize++;
		N_op += 20;
	}
	else if (IsEmpty != false) {
		el->RiElem = new Item;
		el->RiElem->next = nullptr;
		el->RiElem->prev = nullptr;
		el->RiElem->item = num;
		el->LeElem = el->RiElem;
		el->AllSize++;
		IsEmpty = false;
		N_op += 20;
	}
}
//25 + 7 + 13 + (n - 1)(7 + 14 + 13) + 13 = 24 + 34n
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
		N_op += 25; //25
		cout << endl << "Deque will be shown from left side" << endl;
		while (index != el->AllSize) {
			deqWatch = el->LeElem->next;
			cout << index << " element is: " << el->LeElem->item << endl;
			N_op += 7; //7
			if (index != 1)
			{
				secDeq.RiElem = new Item;
				secDeq.RiElem->prev = secDeqWatch;
				secDeqWatch->next = secDeq.RiElem;
				secDeq.RiElem->next = nullptr;
				secDeqWatch = secDeqWatch->next;
				N_op += 14; //14
			}
			secDeq.RiElem->item = el->LeElem->item;
			delete el->LeElem;
			el->LeElem = deqWatch;
			deqWatch->prev = nullptr;
			index++;
			N_op += 13; //13
		}
		cout << index << " element is: " << el->LeElem->item << endl << endl;
		secDeqWatch->next = el->LeElem;
		el->LeElem->prev = secDeq.RiElem;
		el->LeElem = secDeq.LeElem;
		N_op += 13; //13
	}
	else if (el->AllSize == 1) {
		cout << "1 element is: " << el->LeElem->item << endl << endl;
		N_op += 4; //4
	}
}
// (n - 1)(17 + 2) + n(17 + 2 + 2) + 5 = 40n - 14
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
		N_op += 17;
		if (el->AllSize != 0) {
			el->AllSize--;
			N_op += 2;
		}
		N_op += 2;
	}
	delete el->LeElem;
	IsEmpty = true;
	el->AllSize--;
	N_op += 5;
}
//3 + n(24 + 1) + 24 + 34n + 1 + 444n^2 * log(n) + 131n^2 + 303n * log(n) + 59n + 6 + 1 + 24 + 34n + 1 + 40n - 14 + 1 + 1  = 444n^2 * log(n) + 131n^2 + 303n * log(n) + 192n + 48
int main()
{
	srand(time(NULL));
	Deque node;
	int size;
	cout << "Type size of this deque: ";
	cin >> size;
	N_op += 3;
	for (int i = 1; i <= size; i++)
	{
		CreateRightNode(&node); //24
		N_op++;
	}
	cout << "Current deque: " << endl;
	ShowAllNodes(&node); //24 + 34n + 1
	auto start = chrono::system_clock::now();
	HeapSort(&node); //444n^2 * log(n) + 131n^2 + 303n * log(n) + 59n + 6
	auto end = chrono::system_clock::now();
	cout << "Sorted deque: " << endl;
	ShowAllNodes(&node); // 24 + 34n + 1
	DeleteAll(&node); //40n - 14 + 1
	chrono::duration<double> elapsed = end - start;
	cout << "Heap sort time: " << elapsed.count() << " seconds" << endl;
	N_op += 4;
	cout << endl << "N_op: " << N_op << endl;
	return 0;
}
