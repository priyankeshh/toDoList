#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

void displayMenu()
{
    cout << "\n===== To-Do List Application =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Mark Task as Completed" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Display Tasks" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================" << endl;
}

int main()
{
    vector<Task> tasks;

    while (true)
    {
        displayMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Task newTask;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, newTask.description);
            newTask.completed = false;
            tasks.push_back(newTask);
            cout << "Task added successfully." << endl;
        }
        break;
        case 2:
        {
            int taskIndex;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> taskIndex;
            if (taskIndex >= 0 && taskIndex < tasks.size())
            {
                tasks[taskIndex].completed = true;
                cout << "Task marked as completed." << endl;
            }
            else
            {
                cout << "Invalid task index." << endl;
            }
        }
        break;
        case 3:
        {
            int taskIndex;
            cout << "Enter the index of the task to delete: ";
            cin >> taskIndex;
            if (taskIndex >= 0 && taskIndex < tasks.size())
            {
                tasks.erase(tasks.begin() + taskIndex);
                cout << "Task deleted successfully." << endl;
            }
            else
            {
                cout << "Invalid task index." << endl;
            }
        }
        break;
        case 4:
            cout << "\n===== Task List =====" << endl;
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                cout << "[" << i << "] ";
                if (tasks[i].completed)
                {
                    cout << "[X] ";
                }
                else
                {
                    cout << "[ ] ";
                }
                cout << tasks[i].description << endl;
            }
            cout << "=====================" << endl;
            break;
        case 5:
            cout << "Exiting the application. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
