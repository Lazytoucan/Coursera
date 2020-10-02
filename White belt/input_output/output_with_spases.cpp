#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>
#include<string>
#include<iomanip>

using namespace std;

void PrintVector(const vector<string>& v)
{
	int s = v.size();
	for (int i =0; i< (s-1);++i)
	{
		cout << setw(10) << v[i]<< ' ';
	}
	cout << setw(10) << v[s-1];
}

int main() 
{
	ifstream input("input.txt");
	int m,n;
	if (input) 
	{
		vector <string> v;
		string line;
		getline(input, line);
		istringstream iss(line);
		iss >> n >> m;
		for (int i = 0;i < n-1;++i)
		{
			vector <string> v;
			for (int j = 0; j < m-1;++j)
			{
				getline(input, line, ',');
				v.push_back(line);
			}
			getline(input, line);
			v.push_back(line);
			PrintVector(v);
			cout << endl;
		}
		vector <string> v1;
		for (int j = 0; j < m - 1;++j)
		{
			getline(input, line, ',');
			v1.push_back(line);
		}
		getline(input, line);
		v1.push_back(line);
		PrintVector(v1);
	}

	system("pause");
	return 0;
}