#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>

using namespace std;

enum class TaskStatus {
	NEW,          // нова€
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// ѕолучить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const
	{
		return team.at(person);
	}

	// ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
	void AddNewTask(const string& person)
	{
		++team[person][TaskStatus::NEW];
	}
	// ќбновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
	{
		try {
			TasksInfo update_tasks_of_person;

			for (int i = 0; i < task_count;++i)
			{
				if (team[person][TaskStatus::NEW] > 0)
				{
					--team[person][TaskStatus::NEW];
					++update_tasks_of_person[TaskStatus::IN_PROGRESS];
				}
				else
				{
					if (team[person][TaskStatus::IN_PROGRESS] > 0)
					{
						--team[person][TaskStatus::IN_PROGRESS];
						++update_tasks_of_person[TaskStatus::TESTING];
					}
					else
					{
						if (team[person][TaskStatus::TESTING] > 0)
						{
							--team[person][TaskStatus::TESTING];
							++update_tasks_of_person[TaskStatus::DONE];
						}
					}
				}
			}
			
			TasksInfo unupdate_tasks_of_person;
			for (auto& a : team.at(person))
			{
				if (a.first !=TaskStatus::DONE && a.second != 0)
				{
					unupdate_tasks_of_person[a.first] = a.second;
				}
			}
			tuple<TasksInfo, TasksInfo> result(update_tasks_of_person, unupdate_tasks_of_person);
			for (auto a : update_tasks_of_person)
			{
				team.at(person)[a.first] += update_tasks_of_person[a.first];
			}
			TasksInfo temp;
			for (auto a : team.at(person))
			{
				if (a.second != 0)
				{
					temp[a.first] = team.at(person)[a.first];
				}
			}
			team.at(person) = temp;
			return result;
		}
		catch (exception e)
		{
			tuple<TasksInfo, TasksInfo> result;
			return result;
		}

	}
private:
	map <string, TasksInfo> team;

};
void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{	
	TeamTasks tasks;
	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");
	}
	for (int i = 0; i < 2; ++i) {
		tasks.PerformPersonTasks("Alice",5);
	}
	tasks.PerformPersonTasks("Alice", 1);
	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");
	}
	tasks.PerformPersonTasks("Alice", 2);
	tasks.GetPersonTasksInfo("Alice");
	tasks.PerformPersonTasks("Alice", 4);
	tasks.GetPersonTasksInfo("Alice");

	system("pause");
	return 0;
}


