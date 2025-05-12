#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class TodoList {
public:
    int id;
    string taskBody;
    bool isDone;

    TodoList(int id, string taskBody) {
        this->id = id;
        this->taskBody = taskBody;
        this->isDone = false;
    }

    void Display() {
        cout << "| " << id << ". " << taskBody;
        int padding = 30 - taskBody.length();
        for (int i = 0; i < padding; i++) cout << " ";
        cout << "| " << (isDone ? "  Done" : "  Not Done") << " |\n";
    }
};

void pause() {
    cout << "\nPress Enter to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printMenu() {
  system("cls");
    cout << "\n+----------------------------------------+\n";
    cout << "|           TO-DO LIST APPLICATION       |\n";
    cout << "+----------------------------------------+\n";
    cout << "|  1.    Add Task                        |\n";
    cout << "|  2.    View Tasks                      |\n";
    cout << "|  3.     Edit Task                      |\n";
    cout << "|  4.    Delete Task                     |\n";
    cout << "|  5.    Mark Task as Done               |\n";
    cout << "|  6.    Exit                            |\n";
    cout << "+----------------------------------------+\n";
    cout << "Enter Your Choice (1-6): ";
}

void addTask(vector<TodoList>& tasks) {
  system("cls");
    int id = tasks.size() + 1;
    string taskText = "";
    cin.ignore();
    cout << "\nEnter Task Description: ";
    getline(cin, taskText);
    tasks.push_back(TodoList(id, taskText));
    cout << "\n  Task Added Successfully!";
    pause();
}

void viewTask(vector<TodoList>& tasks) {
  system("cls");
    if (tasks.empty()) {
        cout << "\n  No tasks to display!\n";
    } else {
        cout << "\n+----------------------------------------+\n";
        cout << "|                TASK LIST              |\n";
        cout << "+----------------------------------------+\n";
        for (auto& task : tasks) {
            task.Display();
        }
        cout << "+----------------------------------------+\n";
    }
    pause();
}

void deleteTask(vector<TodoList>& tasks) {
   system("cls");
    int id;
    cout << "\nEnter Task ID to delete: ";
    cin >> id;

    bool deleted = false;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            deleted = true;

            // Reassign IDs
            for (size_t j = 0; j < tasks.size(); ++j) {
                tasks[j].id = j + 1;
            }

            cout << "\n  Task deleted successfully.\n";
            break;
        }
    }

    if (!deleted) cout << "\n  Task not found.\n";

    pause();
}

void editTask(vector<TodoList>& tasks) {
  system("cls");
    int editId;
    cout << "\nEnter Task ID to Edit: ";
    cin >> editId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;
    for (auto& task : tasks) {
        if (task.id == editId) {
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

    if (!found) {
        cout << "\n  Task not found.\n";
    }

    pause();
}

void markAsDone(vector<TodoList>& tasks) {
  system("cls");
    int doneId;
    cout << "\nEnter Task ID to mark as done: ";
    cin >> doneId;

    bool found = false;
    for (auto& task : tasks) {
        if (task.id == doneId) {
            found = true;
            if (task.isDone) {
                cout << "\n  This task is already marked as done.\n";
            } else {
                task.isDone = true;
                cout << "\n  Task marked as done successfully!\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "\n  Task with ID " << doneId << " not found.\n";
    }

    pause();
}

int main() {
    vector<TodoList> tasks = {
    TodoList(1, "Graphics wali To-Do list banani hai"),
    TodoList(2, "CV ready krni hai"),
    TodoList(3, "LinkedIn pr post krni hai 8 bje"),
    TodoList(4, "Assignment submit krwani hai kal tak"),
    TodoList(5, "DSA ka revision krna hai"),
    TodoList(6, "Flutter ka tutorial complete krna hai"),
    TodoList(7, "Zoiya ko call krni hai shaam 6 bje"),
    TodoList(8, "University ka fee status check krna hai")
};

    int choice;

    do {
        printMenu();
        cin >> choice;
        if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n  Invalid input. Please enter a number between 1 to 6.\n";
        pause();
        continue;
        }


        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTask(tasks);
                break;
            case 3:
                editTask(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                markAsDone(tasks);
                break;
            case 6:
                cout << "\n  Thanks for using the app. Bye!\n";
                return 0;
            default:
                cout << "\n  Invalid Choice. Try Again!";
                pause();
        }

    } while (true);
}
