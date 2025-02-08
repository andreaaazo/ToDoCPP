#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <vector>

#include "Task.h"

/**
 * @class ConsoleUI
 * @brief Manages console-based interactions.
 */
class ConsoleUI {
   public:
    /**
     * @brief Displays [menu] to the console.
     */
    void showMenu();

    /**
     * @brief Returns user choice as an integer.
     * @return User's choice if valid, otherwise -1
     */
    int getUserChoice();

    /**
     * @brief Returns [task name] from user input.
     * @return Non-empty [task name]
     */
    std::string getTaskName();

    /**
     * @brief Returns [task description] from user input.
     * @return Non-empty [task description]
     */
    std::string getTaskDescription();

    /**
     * @brief Returns [task index] chosen by the user for [action].
     * @param tasks Reference to list of [tasks]
     * @param action Action to perform (e.g., "delete" or "complete")
     * @return Index in [tasks] if valid, otherwise -1
     */
    size_t getTaskIndex(const std::vector<Task>& tasks,
                        const std::string& action);

    /**
     * @brief Displays [message] to the console.
     * @param message Text to display
     */
    void displayMessage(const std::string& message);

    /**
     * @brief Displays [tasks] to the console with details.
     * @param tasks Reference to list of [tasks]
     */
    void displayTasks(const std::vector<Task>& tasks);

   private:
    /**
     * @brief Returns non-empty [input] after prompting [promptMsg].
     * @param promptMsg Prompt message for user
     * @return Non-empty user input
     */
    std::string getInputWithPrompt(const std::string& promptMsg);
};

#endif
