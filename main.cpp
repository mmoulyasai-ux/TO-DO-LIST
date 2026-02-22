/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string FILE_NAME = "tasks.txt";

vector<string> loadTasks()
{
    vector<string> tasks;
    ifstream file(FILE_NAME);
    string line;

    while(getline(file, line))
    {
        if(!line.empty())
        {
            tasks.push_back(line);
        }
    }

    file.close();
    return tasks;
}

void saveTasks(const vector<string>& tasks)
{
    ofstream file(FILE_NAME);

    for(const string& task : tasks)
    {
        file << task << endl;
    }

    file.close();
}

void DisplayTasks(const vector<string>& tasks)
{
    if(tasks.empty())
    {
        cout << "\n No tasks to do!.\n";
        return;
    }

    cout << "\n Your To-Do List:\n";

    for(size_t i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void addTask(vector<string>& tasks)
{
    cout << "\n Enter the new Task: ";
    string task;
    getline(cin, task);

    if(task.empty())
    {
        cout << "Cannot add an Empty task.\n";
        return;
    }

    tasks.push_back(task);
    saveTasks(tasks);

    cout << "Task is added successfully!.\n";
}

void RemoveTask(vector<string>& tasks)
{
    if(tasks.empty())
    {
        cout << "\n No tasks to delete.\n";
        return;
    }

    DisplayTasks(tasks);

    cout << "\n Enter the number of the task to delete: ";
    int index;
    cin >> index;
    cin.ignore();

    if(index < 1 || index > static_cast<int>(tasks.size()))
    {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    saveTasks(tasks);

    cout << "Task deleted successfully.\n";
}

void MarkTaskCompleted(vector<string>& tasks)
{
    if(tasks.empty())
    {
        cout << "\n No tasks available.\n";
        return;
    }

    DisplayTasks(tasks);

    cout << "\n Enter the number of the task to mark as completed: ";
    int index;
    cin >> index;
    cin.ignore();

    if(index < 1 || index > static_cast<int>(tasks.size()))
    {
        cout << "Invalid task number.\n";
        return;
    }

    // Add completed label
    tasks[index - 1] += " [Completed]";
    saveTasks(tasks);

    cout << "Task marked as completed successfully.\n";
}

void displayMenu()
{
    cout << "\n--- To-Do List App ---\n";
    cout << "1. View Tasks\n";
    cout << "2. Add Task\n";
    cout << "3. Delete Task\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main()
{
    vector<string> tasks = loadTasks();

    while(true)
    {
        displayMenu();

        int choice;
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                DisplayTasks(tasks);
                break;

            case 2:
                addTask(tasks);
                break;

            case 3:
                RemoveTask(tasks);
                break;

            case 4:
                MarkTaskCompleted(tasks);
                break;

            case 5:
                cout << "\n That's all about Tasks.\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}