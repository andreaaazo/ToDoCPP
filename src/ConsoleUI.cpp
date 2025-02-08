#include "ConsoleUI.h"

#include <iostream>
#include <limits>

using namespace std;

const void ConsoleUI::showMenu() {
    cout << "------ To-Do List Menu ------" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View task" << endl;
    cout << "3. Complete task" << endl;
    cout << "4. Delete task" << endl;
    cout << "5. Exit" << endl;
}

const int ConsoleUI::getUserChoice() {
    string input;
    int choice;
    cout << "Enter your choice: ";
    getline(cin, input);

    if (input.empty()) {
        return -1;
    }

    try {
        int choice = stoi(input);
        return choice;
    } catch (...) {
        return -1;
    }
}

const string ConsoleUI::getTaskName() {
    string name;

    cout << "Enter task name: ";
    getline(cin, name);

    if (name.empty()) {
        getTaskName();
    }

    return name;
}

const string ConsoleUI::getTaskDescription() {
    string description;

    cout << "Enter task description: ";
    getline(cin, description);

    if (description.empty()) {
        getTaskDescription();
    }

    return description;
}

const size_t ConsoleUI::getTaskIndex(const vector<Task> &tasks,
                                     const string &action) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return -1;  // oppure qualche altro valore di errore
    }

    displayTasks(tasks);
    displayMessage("-----------------------------");
    cout << "Enter task number to " << action << ": ";

    string input;
    getline(cin, input);

    if (input.empty()) {
        return -1;  // nessun input, errore
    }

    try {
        size_t index = static_cast<size_t>(stoi(input));

        // Controllo che l'indice sia nelle dimensioni accettabili
        if (index < 1 || index > tasks.size()) {
            return -1;
        }
        return index;
    } catch (...) {
        return -1;
    }
}

const void ConsoleUI::displayMessage(const string &message) {
    cout << message << endl;
}

const void ConsoleUI::displayTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << "#" << i + 1 << " - " << tasks[i].getName() << endl;
        cout << "Description: " << tasks[i].getDescription() << endl;
        cout << "Status: " << (tasks[i].isCompleted() ? "Completed" : "Pending")
             << endl;
        if (i + 1 != tasks.size()) {
            displayMessage("-----------------------------");
        }
    }
}
