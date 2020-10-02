#include <iostream>
#include <map>
#include <set>
#include <exception>
#include <sstream>
#include <iomanip>

using namespace std;

// реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	Date()
	{
		Year = 0;
		Month = 0;
		Day = 0;
	}
	Date(int year, int month, int day)
	{
		if (month < 1 || month>12)
		{
			throw out_of_range("Month value is invalid: " + to_string(month));
		}
		if (day < 1 || day>31)
		{
			throw out_of_range("Day value is invalid: " + to_string(day));
		}
		Year = year;
		Month = month;
		Day = day;
	}
	int GetYear() const
	{
		return Year;
	}
	int GetMonth() const
	{
		return Month;
	}
	int GetDay() const
	{
		return Day;
	}
private:
	int Year;
	int Month;
	int Day;
};
ostream& operator<<(ostream& stream, const Date& date)
{
	cout << setfill('0');
	cout << setw(4) << date.GetYear() << "-" << setw(2)
		<< date.GetMonth() << "-" << setw(2) << date.GetDay() << endl;
	return stream;
}

istream& operator>>(istream& stream1, Date& date)
{
	string dat;
	stream1 >> dat;

	stringstream stream(dat);

	bool flag = true;
	int year, month, day;

	flag = flag && (stream >> year);
	flag = flag && (stream.peek() == '-');
	stream.ignore(1);
	if (stream.peek() == '+')
	{
		stream.ignore(1);
	}

	flag = flag && (stream >> month);
	flag = flag && (stream.peek() == '-');
	stream.ignore(1);
	if (stream.peek() == '+')
	{
		stream.ignore(1);
	}

	flag = flag && (stream >> day);
	flag = flag && stream.eof();
	if (!flag)
	{
		throw out_of_range("Wrong date format: " + dat);
	}
	date = { year,month,day };

	return stream;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear())
	{
		return true;
	}
	else
	{
		if (lhs.GetMonth() < rhs.GetMonth() && lhs.GetYear() == rhs.GetYear())
		{
			return true;
		}
		else
		{
			if (lhs.GetDay() < rhs.GetDay() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetYear() == rhs.GetYear())
			{
				return true;
			}
		}
	}
	return false;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event)
	{
		Events[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event)
	{
		if (Events[date].find(event)!= Events[date].end())
		{
			Events[date].erase(Events[date].find(event));
			if (Events[date].size() == 0)
			{
				Events.erase(date);
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	int DeleteDate(const Date& date)
	{
		int size = Events[date].size();
		Events.erase(date);
		return size;
	}

	void Find(const Date& date) const
	{
		try {
			for (auto& a : Events.at(date))
			{
				cout << a << endl;
			}
		}
		catch (const exception& e)
		{			
		}
	}

	void Print() const
	{
		for (auto& a : Events)
		{
			for (auto b : a.second)
			{
				cout << setfill('0');
				cout << setw(4) << a.first.GetYear() << "-" << setw(2) << a.first.GetMonth()
					<< "-" << setw(2) << a.first.GetDay() << " ";
				cout << b << endl;
			}
		}
	}
private:
	map<Date, set<string>> Events;
};

int main() {
	try {
		Database db;
		string line;

		while (getline(cin, line)) {
			stringstream input(line);
			string command;
			input >> command;
			if (command == "Add")
			{
				Date date;
				string Event;
				input >> date;
				input.ignore(1);
				input>> Event;
				db.AddEvent(date, Event);
			}
			else
			{
				if (command == "Del")
				{
					Date date;
					string Event;
					input >> date;
					if (input >> Event)
					{
						if (db.DeleteEvent(date, Event))
						{
							cout << "Deleted successfully" << endl;
						}
						else
						{
							cout << "Event not found" << endl;
						}
					}
					else
					{
						int n = db.DeleteDate(date);
						cout << "Deleted " << n << " events" << endl;
					}
				}
				else
				{
					if (command == "Find")
					{
						Date date;
						input >> date;
						db.Find(date);
					}
					else
					{
						if (command == "Print")
						{
							db.Print();
						}
						else
						{
							if (command != "")
							{
								cout << "Unknown command: " << command << endl;
							}
						}
					}
				}
			}

		}
	}
	catch (const out_of_range& e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}


