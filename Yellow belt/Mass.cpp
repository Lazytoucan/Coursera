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
	int n, r;
	cin >> n >> r;
	unsigned long long int mass=0;
	for (int i = 0;i < n;++i)
	{
		int w, h, d;
		cin >> w >> h >> d;
		mass += static_cast<unsigned long long int>(w)*h*d*h;
	}
	cout << mass << endl;
	system("pause");
	return 0;
}


