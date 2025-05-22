#include <iostream>
#include <vector>
#include <limits>
#include "includes/ToDoList.h"  // add the fuctions to main
using namespace std;

int main()
{
    vector<ToDoList> tasks = {
        ToDoList(1, "Graphics wali To-Do list banani hai"),
        ToDoList(2, "CV ready krni hai"),
        ToDoList(3, "LinkedIn pr post krni hai 8 bje"),
        ToDoList(4, "Assignment submit krwani hai kal tak"),
        ToDoList(5, "DSA ka revision krna hai"),
        ToDoList(6, "Flutter ka tutorial complete krna hai"),
        ToDoList(7, "Zoiya ko call krni hai shaam 6 bje"),
        ToDoList(8, "University ka fee status check krna hai")};

    int choice;
    ToDoList todo(0, "");
    do
    {
        todo.printMenu();
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n  Invalid input. Please enter a number between 1 to 6.\n";
            todo.pause();
            continue;
        }

        switch (choice)
        {
        case 1:
            todo.addTask(tasks);
            break;
        case 2:
            todo.viewTask(tasks);
            break;
        case 3:
            todo.editTask(tasks);
            break;
        case 4:
            todo.deleteTask(tasks);
            break;
        case 5:
            todo.markAsDone(tasks);
            break;
        case 6:
            cout << "\n  Thanks for using the app. Bye!\n";
            return 0;
        default:
            cout << "\n  Invalid Choice. Try Again!";
            todo.pause();
        }

    } while (true);
}
