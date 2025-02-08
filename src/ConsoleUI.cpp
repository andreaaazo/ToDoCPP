#include "ConsoleUI.h"

#include <iostream>

/**
 * @brief Displays [menu] to the console.
 */
void ConsoleUI::showMenu() {
    std::cout << "------ To-Do List Menu ------" << std::endl;
    std::cout << "1. Add task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Complete task" << std::endl;
    std::cout << "4. Delete task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

/**
 * @brief Returns user choice as an integer.
 * @return User's choice if valid, otherwise -1
 */
int ConsoleUI::getUserChoice() {
    std::string input;
    std::cout << "Enter your choice: ";
    std::getline(std::cin, input);

    if (input.empty()) {
        return -1;
    }

    try {
        int choice = std::stoi(input);
        return choice;
    } catch (...) {
        return -1;
    }
}

/**
 * @brief Returns [task name] from user input.
 * @return Non-empty [task name]
 */
std::string ConsoleUI::getTaskName() {
    return getInputWithPrompt("Enter task name: ");
}

/**
 * @brief Returns [task description] from user input.
 * @return Non-empty [task description]
 */
std::string ConsoleUI::getTaskDescription() {
    return getInputWithPrompt("Enter task description: ");
}

/**
 * @brief Returns [task index] chosen by the user for [action].
 * @param tasks Reference to list of [tasks]
 * @param action Action to perform (e.g., "delete" or "complete")
 * @return Index in [tasks] if valid, otherwise -1
 */
size_t ConsoleUI::getTaskIndex(const std::vector<Task>& tasks,
                               const std::string& action) {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return static_cast<size_t>(-1);
    }

    displayTasks(tasks);
    displayMessage("-----------------------------");
    std::cout << "Enter task number to " << action << ": ";

    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        return static_cast<size_t>(-1);
    }

    try {
        size_t index = static_cast<size_t>(std::stoi(input));
        if (index < 1 || index > tasks.size()) {
            return static_cast<size_t>(-1);
        }
        return index;
    } catch (...) {
        return static_cast<size_t>(-1);
    }
}

/**
 * @brief Displays [message] to the console.
 * @param message Text to display
 */
void ConsoleUI::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

/**
 * @brief Displays [tasks] to the console with details.
 * @param tasks Reference to list of [tasks]
 */
void ConsoleUI::displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "#" << i + 1 << " - " << tasks[i].getName() << std::endl;
        std::cout << "Description: " << tasks[i].getDescription() << std::endl;
        std::cout << "Status: "
                  << (tasks[i].isCompleted() ? "Completed" : "Pending")
                  << std::endl;
        if (i + 1 != tasks.size()) {
            displayMessage("-----------------------------");
        }
    }
}

/**
 * @brief Returns non-empty [input] after prompting [promptMsg].
 * @param promptMsg Prompt message for user
 * @return Non-empty user input
 */
std::string ConsoleUI::getInputWithPrompt(const std::string& promptMsg) {
    while (true) {
        std::cout << promptMsg;
        std::string userInput;
        std::getline(std::cin, userInput);

        if (!userInput.empty()) {
            return userInput;
        }
        std::cout << "Input cannot be empty. Please try again.\n";
    }
}
