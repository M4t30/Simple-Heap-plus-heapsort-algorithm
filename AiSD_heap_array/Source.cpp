#include <iostream>
#include <ctime>
using namespace std;

//****************************************************************************************************************************

void heapify(int *tab, int heapsize, int n);
void buildHeap(int *tab, int heapsize);
void heapSort(int *tab, int heapsize);
void show(int *tab, int heapsize);

//****************************************************************************************************************************
                                                                                                                     //main
int main()
{
	srand(time(NULL));
	int heapsize, n = 1, choice, choice2;

	do
	{
		cout << "Enter heapsize: ";
		cin >> heapsize;
	} while (heapsize <= 0);

	int *tab = new int[heapsize + 1];
	tab[0] = 0;

	for (int i = 1; i < (heapsize + 1); i++)
	{
		tab[i] = rand() % 50;
	}

	do
	{
		cout << "\n1. Show functions: " << endl
			<< "2. Choose function:" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\n1. Build heap" << endl
				 << "2. Heap sort" << endl
				 << "3. Show heap" << endl;
			break;

		case 2:
			cout << "Choose function: ";
			cin >> choice2;
			switch (choice2)
			{
				case 1:
					buildHeap(tab, heapsize);                                                            
					break;

				case 2:
					heapSort(tab, heapsize);                                                            
					break;

				case 3:
					show(tab, heapsize);                                                               
					break;
			}

		}
	} while (choice != 0);
}

//****************************************************************************************************************************
                                                                                                            
void buildHeap(int *tab, int heapsize)
{
	for (int i = (heapsize/2) ; i > 0 ; i--)
		heapify(tab, heapsize , i);
}

//****************************************************************************************************************************
                                                                                             
void heapify(int *tab, int heapsize, int n)
{
	int largest;
	int left_son = 2 * n;
	int right_son = (2 * n) + 1;

	if (left_son <= heapsize && tab[left_son] > tab[n])
		largest = left_son;
	
	else
		largest = n;

	if (right_son <= heapsize && tab[right_son] > tab[largest])
		largest = right_son;

	if (largest != n)
	{
		int tmp = tab[n];
		tab[n] = tab[largest];
		tab[largest] = tmp;
		heapify(tab, heapsize, largest);
	}
}

//****************************************************************************************************************************
                                                                                                     
void heapSort(int *tab, int heapsize)
{
	int tmp;
	buildHeap(tab, heapsize);

	for (int i = heapsize; i >= 1; i--)
	{
		tmp = tab[i];
		tab[i] = tab[1];
		tab[1] = tmp;
		heapsize--;
		heapify(tab, heapsize, 1);
	}
}

//****************************************************************************************************************************
                                                                                                          
void show(int *tab, int heapsize)
{
	for (int i = 1; i < (heapsize + 1); i++)
	{
		cout << "tab[" << i << "] = " << tab[i] << endl;
	}
}

//****************************************************************************************************************************