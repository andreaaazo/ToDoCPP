#ifndef TODOAPP_H
#define TODOAPP_H

#include "ConsoleUI.h"
#include "TaskManager.h"

/**
 * @class ToDoApp
 * @brief Handles application flow for a to-do list.
 */
class ToDoApp {
   public:
    /**
     * @brief Constructs [ToDoApp] with references to [ConsoleUI] and
     * [TaskManager].
     * @param ui Reference to [ConsoleUI]
     * @param task_manager Reference to [TaskManager]
     */
    ToDoApp(ConsoleUI& ui, TaskManager& task_manager);

    /**
     * @brief Runs [ToDoApp] main loop until user chooses to exit.
     */
    void run();

   private:
    ConsoleUI& ui;
    TaskManager& task_manager;
};

#endif
