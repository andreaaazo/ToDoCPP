#include "TaskManager.h"

#include <vector>

bool TaskManager::addTask(const string &name, const string &descrption) {
    tasks.emplace_back(name, descrption);
    return true;
};

bool TaskManager::isValidIndex(size_t index) const {
    return index >= 0 && index < tasks.size();
}

bool TaskManager::completeTask(size_t index) {
    if (!isValidIndex(index)) {
        return false;
    }

    tasks[index].markAsCompleted();
    return true;
}

vector<Task> const &TaskManager::getTasks() const { return tasks; }

bool TaskManager::removeTask(size_t index) {
    if (!isValidIndex(index)) {
        return false;
    }

    tasks.erase(tasks.begin() + index);
    return true;
}