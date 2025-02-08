#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>

#include "Task.h"

class TaskManager {
   public:
    bool addTask(const string &name, const string &descrption);
    bool removeTask(size_t index);
    bool completeTask(size_t index);

    const vector<Task> &getTasks() const;

   private:
    vector<Task> tasks;

    bool isValidIndex(size_t index) const;
};

#endif