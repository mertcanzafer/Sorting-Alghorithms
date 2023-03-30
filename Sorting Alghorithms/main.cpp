#include <iostream>
#include<vector>
#include <chrono>
using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::nanoseconds;


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

		swapp(vec[i],vec[min]);
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

	vector<int>leftArray(mid,0);
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



int main()
{
// Using vector class

	vector <int> vec;

	for (int i = 100; i >= 0; i--)
		vec.push_back(i);
	
	cout << "Before its sorted: " << endl;

	print_vector(vec);

//Mesures the certain function performance

	auto t1 = high_resolution_clock::now();
	BubbleSort(vec);
	auto t2 = high_resolution_clock::now();

	cout << "After its sorted: " << endl;
	print_vector(vec);

	auto nanoint1 = duration_cast<nanoseconds>(t2 - t1);
	cout << "\n\nCalculated time : (for "<<vec.size()<<" elements) " << nanoint1.count() << "ns" << endl;

	/*
	                   Selection Sort Alghorithm
	*/


	vector<int> numbers;
	
	// The worst case vector of integers.

	for (int i = 100; i >= 0; i--)
		numbers.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(numbers);

	//Mesures the certain function performance

	auto t3 = high_resolution_clock::now();
	SelectionSort(numbers);
	auto t4 = high_resolution_clock::now();

	cout << "\n\nAfter its sorted: ";
	
	print_vector(numbers);


	auto nanoint2 = duration_cast<nanoseconds>(t4 - t3);
	cout << "\n\nCalculated time : (for " << numbers.size() << " elements) " << nanoint2.count() << "ns" << endl;


	
	/*
					   Insertion Sort Alghorithm
	*/

	vector<int> v1;

	for (int i = 100; i >= 0; i--)
		v1.push_back(i);

	cout << "\nBefore its sorted: ";
	print_vector(v1);

	auto t5 = high_resolution_clock::now();
	InsertionSort(v1);
	auto t6 = high_resolution_clock::now();

	cout << "\n\nAfter its sorted: ";
	print_vector(v1);

	auto nanoint3 = duration_cast<nanoseconds>(t6 - t5);
	cout << "\n\nCalculated time : (for " << numbers.size() << " elements) " << nanoint3.count() << "ns" << endl;

	/*
	
	              Merge Sort Alghorithm
				  It is faster than insertion, bubble, selection sort alghorithms
				  However, It requires more places than those.
	              Runtime Complexity : O(n log n)
	              Space Complexity: O(n)
	*/


	vector<int> array;

	for (int i = 100; i >= 0; i--)
		array.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(array);

	auto t7 = high_resolution_clock::now();
	mergeSort(array);
	auto t8 = high_resolution_clock::now();

	cout << "\n\nAfter its sorted: ";
	print_vector(array);

	auto nanoint4 = duration_cast<nanoseconds>(t8 - t7);
	cout << "\n\nCalculated time : (for " << array.size() << " elements) " << nanoint4.count() << "ns" << endl;



	/*
					   Quick sort Alghorithm
	*/

	

	vector<int> v2;

	for (int i = 100; i >= 0; i--)
		v2.push_back(i);

	cout << "\n\nBefore its sorted: ";
	print_vector(v2);

	auto t9 = high_resolution_clock::now();
	quickSort(v2, 0, v2.size() - 1);
	auto t10 = high_resolution_clock::now();

	cout << "\n\nAfter its sorted: ";

	print_vector(v2);


	auto nanoint5 = duration_cast<nanoseconds>(t10 - t9);
	cout << "\n\nCalculated time : (for " << v2.size() << " elements) " << nanoint5.count() << "ns" << endl;



	return 0;
}