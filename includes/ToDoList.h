#ifndef TODOLIST_H
#define TODOLIST_H

#include <string>
#include <vector>
using namespace std;

class ToDoList {
public:
    int id;
    string taskBody;
    bool isDone;

    ToDoList(int id, string taskBody);
    // declaration of methods.
    void clearTerminal();
    void Display();
    void printMenu();
    void pause();
    void addTask(vector<ToDoList>& tasks);
    void viewTask(vector<ToDoList>& tasks);
    void deleteTask(vector<ToDoList>& tasks);
    void editTask(vector<ToDoList>& tasks);
    void markAsDone(vector<ToDoList>& tasks);
};

#endif
