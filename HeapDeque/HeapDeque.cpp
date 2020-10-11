#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void heapify(vector <int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector <int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(vector <int> &arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << i + 1 << " element is: " << arr[i] << endl;
    cout << "\n";
}
void GenerateArray(int range, vector <int> &arr) 
{
    srand(time(NULL));
    for (int i = 0; i < range; i++)
    {
        int num = rand() % 20 + 1;
        arr.push_back(num);
    }
}
int main()
{
    vector <int> arr;
    int range;
    cin >> range;
    GenerateArray(range, arr);
    int n = range;
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}
