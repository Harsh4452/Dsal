#include <iostream>

using namespace std;

class Heap
{
	private:
		int max;
		int* marks;
		bool isMaxHeap;
		
		int* Upadjust(int i)
		{
			while(i>1 && marks[i]>marks[i/2])
			{
				int temp = marks[i];
				marks[i] = marks[i/2];
				marks[i/2] = temp;
				i = i/2;
			}
			
			return marks;
		}
		
		int* Downadjust(int i)
		{
			while(i>1 && marks[i]<marks[i/2])
			{
				int temp = marks[i];
				marks[i] = marks[i/2];
				marks[i/2] = temp;
				i = i/2;
			}
			return marks;
		}
		
	public:
		Heap()
		{
			cout<<"Enter the number of elements : ";
			cin>>max;
			marks = new int[max+1];
			marks[0] = 0; // Initialize heap size to 0
			isMaxHeap = true; // Default to max heap
		}
		
		void Max_create()
		{
			int i = 1;
			while(i <= max)
			{
				cout<<"Element "<<i<<" : ";
				cin>>marks[++marks[0]]; // Increment heap size and add the element
				this->Upadjust(marks[0]);
				i++;
			}
		}
		
		void Min_create()
		{
			int i = 1;
			while(i <= max)
			{
				cout<<"Element "<<i<<" : ";
				cin>>marks[++marks[0]]; // Increment heap size and add the element
				this->Downadjust(marks[0]);
				i++;
			}
			isMaxHeap = false; // Set to min heap
		}
		
		void printHeap()
		{
			if (isMaxHeap) 
			{
				cout << "Max Heap Elements: ";
				for (int i = 1; i <= max; ++i) // Loop up to max, not marks[0]
				{
					cout << marks[i] << " ";
				}
			} 
			else 
			{
				cout << "Min Heap Elements: ";
				for (int i = 1; i <= max; ++i) // Loop up to max, not marks[0]
				{
					cout << marks[i] << " ";
				}
			}
			cout << endl;
		}
};

int main()
{
	Heap heap;
	heap.Max_create(); // or heap.Min_create();
	heap.printHeap();
	
	return 0;
}

