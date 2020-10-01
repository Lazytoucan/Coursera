#include <iostream>
#include <map>
#include <set>
#include <exception>
#include <vector>
#include <sstream>

using namespace std;
string AskTimeServer() 
{
	throw system_error(error_code());
}

class TimeServer {
public:
	string GetCurrentTime()
	{
		try 
		{
			last_fetched_time = AskTimeServer();
			return last_fetched_time;
		}
		catch(const system_error& err)
		{
			return last_fetched_time;
		}
	}
private:
	string last_fetched_time = "00:00:00";
};


int main() {
	
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}

	system("pause");
    return 0;
}
