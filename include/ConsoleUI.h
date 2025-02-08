#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <vector>

#include "Task.h"

class ConsoleUI {
   public:
    const void showMenu();
    const int getUserChoice();
    const string getTaskName();
    const string getTaskDescription();
    const size_t getTaskIndex(const vector<Task> &tasks, const string &action);
    const void displayMessage(const string &message);
    const void displayTasks(const vector<Task> &tasks);
};

#endif