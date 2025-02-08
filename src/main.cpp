#include "ToDoApp.h"

int main() {
    TaskManager task_manager;
    ConsoleUI ui;
    ToDoApp app(ui, task_manager);

    app.run();

    return 0;
}