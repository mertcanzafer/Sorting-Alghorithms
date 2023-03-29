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
	cout << "\n\nCalculated time : (for " << numbers.size() << " elements) " << nanoint1.count() << "ns" << endl;


	return 0;
}