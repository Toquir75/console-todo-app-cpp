#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "ToDoList.h"   // Maybe appear a error here but is ok!
using namespace std;

ToDoList::ToDoList(int id, string taskBody)
    : id(id), taskBody(taskBody), isDone(false)
{
}
void ToDoList::clearTerminal() {    // function to clear terminal in all OS
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    clearTerminal();
#else
    std::cout << "[!] Was not possible clear terminal.\n";
#endif
}

void ToDoList::pause()
{
    cout << "\nPress Enter to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore();
}

void ToDoList::Display()
{
    cout << "| " << id << ". " << taskBody;
    int padding = 30 - taskBody.length();
    for (int i = 0; i < padding; i++)
        cout << " ";
    cout << "| " << (isDone ? "  Done" : "  Not Done") << " |\n";
}

void ToDoList::printMenu()
{
    clearTerminal();
    cout << "\n+----------------------------------------+\n";
    cout << "|           TO-DO LIST APPLICATION       |\n";
    cout << "+----------------------------------------+\n";
    cout << "|  1.    Add Task                        |\n";
    cout << "|  2.    View Tasks                      |\n";
    cout << "|  3.    Edit Task                       |\n";
    cout << "|  4.    Delete Task                     |\n";
    cout << "|  5.    Mark Task as Done               |\n";
    cout << "|  6.    Exit                            |\n";
    cout << "+----------------------------------------+\n";
    cout << "Enter Your Choice (1-6): ";
}

void ToDoList::addTask(vector<ToDoList> &tasks)
{
    clearTerminal();
    int id = tasks.size() + 1;
    string taskText = "";
    cin.ignore();
    cout << "\nEnter Task Description: ";
    getline(cin, taskText);
    tasks.push_back(ToDoList(id, taskText));
    cout << "\n  Task Added Successfully!";
    cin.ignore();
}

void ToDoList::viewTask(vector<ToDoList> &tasks)
{
    clearTerminal();
    if (tasks.empty())
    {
        cout << "\n  No tasks to display!\n";
    }
    else
    {
        cout << "\n+----------------------------------------+\n";
        cout << "|                TASK LIST              |\n";
        cout << "+----------------------------------------+\n";
        for (auto &task : tasks)
        {
            task.Display();
        }
        cout << "+----------------------------------------+\n";
    }
    pause();
}

void ToDoList::deleteTask(vector<ToDoList> &tasks)
{
    clearTerminal();
    int id;
    cout << "\nEnter Task ID to delete: ";
    cin >> id;

    bool deleted = false;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        if (tasks[i].id == id)
        {
            tasks.erase(tasks.begin() + i);
            deleted = true;

            // Reassign IDs
            for (size_t j = 0; j < tasks.size(); ++j)
            {
                tasks[j].id = j + 1;
            }

            cout << "\n  Task deleted successfully.\n";
            break;
        }
    }

    if (!deleted)
        cout << "\n  Task not found.\n";

    pause();
}

void ToDoList::editTask(vector<ToDoList> &tasks)
{
    clearTerminal();
    int editId;
    cout << "\nEnter Task ID to Edit: ";
    cin >> editId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;
    for (auto &task : tasks)
    {
        if (task.id == editId)
        {
            found = true;
            cout << "Current Task: " << task.taskBody << endl;
            string newTask;
            cout << "Enter New Task Description: ";
            getline(cin, newTask);
            task.taskBody = newTask;
            cout << "\n  Task updated successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "\n  Task not found.\n";
    }

    cin.ignore();
}

void ToDoList::markAsDone(vector<ToDoList> &tasks)
{
    clearTerminal();
    int doneId;
    cout << "\nEnter Task ID to mark as done: ";
    cin >> doneId;

    bool found = false;
    for (auto &task : tasks)
    {
        if (task.id == doneId)
        {
            found = true;
            if (task.isDone)
            {
                cout << "\n  This task is already marked as done.\n";
            }
            else
            {
                task.isDone = true;
                cout << "\n  Task marked as done successfully!\n";
            }
            break;
        }
    }

    if (!found)
    {
        cout << "\n  Task with ID " << doneId << " not found.\n";
    }

    pause();
}
