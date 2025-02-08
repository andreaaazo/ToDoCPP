#ifndef TODOAPP_H
#define TODOAPP_H

#include "ConsoleUI.h"
#include "TaskManager.h"

class ToDoApp {
   public:
    ToDoApp(ConsoleUI &ui, TaskManager &task_manager);
    void run();

   private:
    ConsoleUI &ui;
    TaskManager &task_manager;
};

#endif