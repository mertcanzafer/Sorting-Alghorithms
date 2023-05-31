#include <iostream>
#include<vector>
#include <chrono>
#include <string.h>
using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::nanoseconds;

const char* BubbleSortWeb = "https://www.geeksforgeeks.org/bubble-sort/";
const char* SelectionSortWeb = "https://www.geeksforgeeks.org/selection-sort/";
const char* InsertionSortWeb = "https://www.geeksforgeeks.org/insertion-sort/";
const char* MergeSortWeb = "https://www.geeksforgeeks.org/merge-sort/";
const char* QuickSortWeb = "https://www.geeksforgeeks.org/quick-sort/";
const char* HeapSortWeb = "https://www.geeksforgeeks.org/heap-sort/";

void print_vector(const vector<int>& vec)
{
	cout << "\nThe elements are: " << endl;
	for (auto& v : vec)
	{
		cout << v << " ";
	}
}

void swapp(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void BubbleSort(vector<int>& vec)
{
	for (size_t i = 0; i < vec.size() - 1; i++)
	{
		for (size_t j = 0; j < vec.size() - 1 - i; j++)
		{
			if (vec[j] > vec[j + 1])
				swapp(vec[j], vec[j + 1]);
		}
	}
}

void SelectionSort(vector<int>& vec)
{
	for (size_t i = 0; i < vec.size() - 1; i++)
	{
		int min = i;

		for (size_t j = i + 1; j < vec.size(); j++)
		{
			if (vec[min] > vec[j])
				min = j;
		}

		swapp(vec[i], vec[min]);
	}

}

void InsertionSort(vector<int>& vec)
{

	for (int i = 1; i < vec.size(); i++)
	{
		int temp = vec[i];
		int j = i - 1;

		while (j >= 0 && temp < vec[j])
		{
			vec[j + 1] = vec[j];
			j--;
		}

		vec[j + 1] = temp;
	}

}

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array)
{
	int leftsize = array.size() / 2;
	int rightsize = array.size() - leftsize;
	int i{ 0 }, l{ 0 }, r{ 0 };//indices

	// Check the conditions for merging

	while (l < leftsize && r < rightsize)
	{
		if (leftArray[l] < rightArray[r])
		{
			array[i] = leftArray[l];
			i++;
			l++;
		}
		else {
			array[i] = rightArray[r];
			i++;
			r++;
		}
	}

	while (l < leftsize)
	{
		array[i] = leftArray[l];
		i++;
		l++;
	}
	while (r < rightsize)
	{
		array[i] = rightArray[r];
		i++;
		r++;
	}
}

void mergeSort(vector<int>& array)
{
	int length = array.size();

	if (length <= 1) return; // Base case

	int mid = length / 2;

	vector<int>leftArray(mid, 0);
	vector<int>rightArray(length - mid, 0);

	int i = 0;// Left Array index
	int j = 0;// Rigth Array index

	for (; i < length; i++)
	{
		if (i < mid)
		{
			leftArray[i] = array[i];
		}
		else {
			rightArray[j] = array[i];
			j++;
		}

	}

	// Recursive Part

	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, array);

}



int partition(vector<int>& vec, int start, int end)
{
	int pivot = vec[end];
	int i{ start - 1 };

	for (int j{ start }; j <= end - 1; j++) {

		if (vec[j] < pivot)
		{
			i++;
			swapp(vec[i], vec[j]);
		}
	}

	i++;
	swapp(vec[i], vec[end]);

	return i;
}

void quickSort(vector<int>& vec, int start, int end)
{
	if (end <= start) return; // Base case

	int pivot = partition(vec, start, end);
	// Recursion Part

	quickSort(vec, start, pivot - 1);
	quickSort(vec, pivot + 1, end);

}

void heapIfy
(
	vector<int>& vec, 
	int N, 
	int i
)
{
	int largest{ i };

	int l{ 2 * i + 1 };

	int r{ 2 * i + 2 };
	
	if (N > l && vec[l] > vec[largest])
		largest = l;

	if (r < N && vec[r] > vec[largest])
		largest = r;

	if (largest != i)
	{
		swapp(vec[i], vec[largest]);

		heapIfy(vec, N, largest);
	}

}

void heapSort(vector<int>& vec)
{
	size_t N{ vec.size() };

	for (int i = N / 2 - 1; i >= 0; i--)
		heapIfy(vec, N, i);

	for (int i = N - 1; i > 0; i--)
	{
		swapp(vec[0], vec[i]);

		heapIfy(vec, i, 0);
	}

}

int main()
{
	// Using vector class
	cout << "Bubble Sort Alghorithm:" << endl;
	vector <int> vec;

	for (int i = 100; i >= 0; i--)
		vec.push_back(i);

	cout << "Before its sorted: " << endl;

	print_vector(vec);

	BubbleSort(vec);

	cout << "After its sorted: " << endl;
	print_vector(vec);

	cout << "\nSelection Sort Alghorithm:" << endl;
	vector<int> numbers;

	for (int i = 100; i >= 0; i--)
		numbers.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(numbers);

	SelectionSort(numbers);

	cout << "\n\nAfter its sorted: ";

	print_vector(numbers);

	cout << "\nInsertion Sort Alghorithm" << endl;
	vector<int> v1;

	for (int i = 100; i >= 0; i--)
		v1.push_back(i);

	cout << "\nBefore its sorted: ";
	print_vector(v1);

	InsertionSort(v1);

	cout << "\n\nAfter its sorted: ";
	print_vector(v1);

	cout << "\nMerge Sort Alghorithm" << endl;
	vector<int> array;

	for (int i = 100; i >= 0; i--)
		array.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(array);

	mergeSort(array);
	
	cout << "\n\nAfter its sorted: ";
	print_vector(array);

	cout << "\nQuick Sort Alghorithm" << endl;
	vector<int> v2;

	for (int i = 100; i >= 0; i--)
		v2.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(v2);

	quickSort(v2, 0, v2.size() - 1);

	cout << "\n\nAfter its sorted: ";

	print_vector(v2);
	
	cout << "\nHeap Sort Alghorithm" << endl;

	vector<int> v3;

	for (int i = 100; i >= 0; i--) v3.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(v3);
	
	heapSort(v3);

	cout << "\n\nAfter its sorted: ";

	print_vector(v3);

	cout << endl;
	return 0;
}
