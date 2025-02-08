#include "ToDoApp.h"

#include <iostream>
using namespace std;

ToDoApp::ToDoApp(ConsoleUI &ui, TaskManager &task_manager)
    : ui(ui), task_manager(task_manager) {}

void ToDoApp::run() {
    int choice;

    do {
        ui.showMenu();
        choice = ui.getUserChoice();
        ui.displayMessage("-----------------------------");

        switch (choice) {
            case 1: {
                const string name = ui.getTaskName();
                const string description = ui.getTaskDescription();

                if (task_manager.addTask(name, description)) {
                    ui.displayMessage("-----------------------------");
                    ui.displayMessage("Task added successfully.");
                } else {
                    ui.displayMessage("-----------------------------");
                    ui.displayMessage("Failed to add task.");
                }
                break;
            }
            case 2: {
                ui.displayTasks(task_manager.getTasks());
                break;
            }

            case 3: {
                const size_t index =
                    ui.getTaskIndex(task_manager.getTasks(), "complete");

                if (task_manager.completeTask(index - 1)) {
                    ui.displayMessage("-----------------------------");
                    ui.displayMessage("Task completed successfully.");
                } else {
                    ui.displayMessage("-----------------------------");
                    ui.displayMessage("Failed to complete task.");
                }
                break;
            }
            case 4: {
                const vector<Task> tasks = task_manager.getTasks();
                const size_t index = ui.getTaskIndex(tasks, "delete");
                if (task_manager.removeTask(index - 1)) {
                    ui.displayMessage("-----------------------------");
                    ui.displayMessage("Task deleted successfully.");
                } else {
                    ui.displayMessage("-----------------------------");
                    ui.displayMessage("Failed to delete task.");
                }
                break;
            }
            case 5: {
                ui.displayMessage("Exiting program. Bye!");
                break;
            }
            default: {
                ui.displayMessage("Invalid choice! Please try again.");
                break;
            }
        };

        ui.displayMessage(
            "-----------------------------\n-----------------------------");

    } while (choice != 5);
}