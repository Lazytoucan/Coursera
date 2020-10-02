#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

class Rational {
public:
    Rational() {
		p = 0;
		q = 1;
    }

    Rational(int numerator, int denominator) {
		int nod = Nod(abs(numerator), abs(denominator));
		if (denominator > 0)
		{
			p = numerator/nod;
			q = denominator/nod;
		}
		else
		{
			p = -numerator/nod;
			q = -denominator/nod;
		}
    }

    int Numerator() const {
		return p;
    }

    int Denominator() const {
		return q;
    }

private:
	int p;
	int q;
	int Nod(int a, int b) { 
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		} 
		return a + b;
	}
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	int p, q;
	q = lhs.Denominator()*rhs.Denominator();
	p = lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator();
	return Rational(p, q);
}
Rational operator-(const Rational& lhs, const Rational& rhs)
{
	int p, q;
	q = lhs.Denominator()*rhs.Denominator();
	p = lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator();
	return Rational(p, q);
}
bool operator==(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator())
	{
		return true;
	}
	return false;
}
Rational operator*(const Rational& lhs, const Rational& rhs)
{
	int p, q;
	q = lhs.Denominator()*rhs.Denominator();
	p = lhs.Numerator()*rhs.Numerator();
	return Rational(p, q);
}
Rational operator/(const Rational& lhs, const Rational& rhs)
{
	int p, q;
	p = lhs.Numerator()*rhs.Denominator();
	q = lhs.Denominator()*rhs.Numerator();
	return Rational(p, q);
}
istream& operator>>(istream& stream, Rational& r)
{
	int p, q;
	char c;
	if (stream >> p && stream>>c&& stream >> q) {
		if (c == '/')
		{
			r = { p,q };
		}
	}

	return stream;
}
ostream& operator<<(ostream& stream, const Rational& r)
{
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}
bool operator<(const Rational& lhs, const Rational& rhs)
{
	return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator();
}
bool operator>(const Rational& lhs, const Rational& rhs)
{
	return rhs < lhs;
}

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}


	cout << "OK" << endl;

	system("pause");
    return 0;
}
