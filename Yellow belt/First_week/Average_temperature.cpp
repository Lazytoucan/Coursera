#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>

using namespace std;


int main()
{	
	vector<long int> v;
	int n;
	long int sum=0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long int t;
		cin >> t;
		v.push_back(t);
		sum += t;
	}
	sum = sum / n;
	vector<int> number_more;
	int increment=0;
	for (int i = 0; i < n; ++i)
	{
		if (v.at(i) > sum)
		{
			number_more.push_back(i);
			increment++; 
		}
	}
	cout << increment<< endl;
	for (auto a : number_more)
	{
		cout << a << " ";
	}
	system("pause");
	return 0;
}


