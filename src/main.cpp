#include "ConsoleUI.h"
#include "TaskManager.h"
#include "ToDoApp.h"

/**
 * @brief Entry point for the to-do application.
 * @return Execution status
 */
int main() {
    ConsoleUI ui;
    TaskManager task_manager;
    ToDoApp app(ui, task_manager);

    app.run();
    return 0;
}
