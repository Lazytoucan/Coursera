#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>

using namespace std;
template<typename t> t Sqr(const t& arg);
template<typename t> vector<t> Sqr(const vector<t>& v);
template<typename First, typename Second>
pair<First, Second> operator *(const pair<First, Second>& lhs, const pair<First, Second>& rhs);
template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p);
template<typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);

template<typename t>
t Sqr(const t& arg)
{
	return arg * arg;
}

template<typename t>
vector<t> Sqr(const vector<t>& v)
{
	vector<t> temp;
	for (const auto& a : v)
	{
		temp.push_back(Sqr(a));
	}
	return temp;
}

template<typename First, typename Second>
pair<First, Second> operator *(const pair<First, Second>& lhs, const pair<First, Second>& rhs)
{
	First f = lhs.first *rhs.first;
	Second s = lhs.second *rhs.second;
	return make_pair(f, s);
}

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p)
{
	return p * p;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m)
{
	map<Key, Value> temp;
	for (const auto& [key,value] : m)
	{
		temp[key] = Sqr(value);
	}
	return temp;
}


int main()
{	
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	
	system("pause");
	return 0;
}


