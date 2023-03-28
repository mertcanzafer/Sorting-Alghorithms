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


/*
	 Bubble sort = pairs of adjacent elements are compered, and the elements
	 swapped if They are not in order.

	 Quadratic time O(n^2)
	 small data set = okey-ish
	 large data set = bad
*/


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


int main()
{
// Using vector class

	vector <int> vec;

	for (int i = 99; i >= 0; i--)
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

	return 0;
}