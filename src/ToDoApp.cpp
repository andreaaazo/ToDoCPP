#include "ToDoApp.h"

#include <iostream>

/**
 * @brief Constructs [ToDoApp] with references to [ConsoleUI] and [TaskManager].
 * @param ui Reference to [ConsoleUI]
 * @param task_manager Reference to [TaskManager]
 */
ToDoApp::ToDoApp(ConsoleUI& ui, TaskManager& task_manager)
    : ui(ui), task_manager(task_manager) {}

/**
 * @brief Runs [ToDoApp] main loop until user chooses to exit.
 */
void ToDoApp::run() {
    int choice;

    do {
        ui.showMenu();
        choice = ui.getUserChoice();
        ui.displayMessage("-----------------------------");

        switch (choice) {
            case 1: {
                std::string name = ui.getTaskName();
                std::string description = ui.getTaskDescription();
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
                size_t index =
                    ui.getTaskIndex(task_manager.getTasks(), "complete");
                // Index in code is 1-based; manager expects 0-based
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
                const std::vector<Task> tasks = task_manager.getTasks();
                size_t index = ui.getTaskIndex(tasks, "delete");
                // Index in code is 1-based; manager expects 0-based
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
        }

        ui.displayMessage(
            "-----------------------------\n-----------------------------");

    } while (choice != 5);
}
