#include "TaskManager.h"

/**
 * @brief Adds a new task using [name] and [description].
 * @param name Name of the new task
 * @param description Description of the new task
 * @return True on success, otherwise false
 */
bool TaskManager::addTask(const std::string& name,
                          const std::string& description) {
    tasks.emplace_back(name, description);
    return true;
}

/**
 * @brief Checks if [index] is valid for the current tasks vector.
 * @param index Zero-based index
 * @return True if [index] is within range, otherwise false
 */
bool TaskManager::isValidIndex(size_t index) const {
    // index >= 0 is always true for size_t, so only check upper bound
    return index < tasks.size();
}

/**
 * @brief Marks a task at [index] as completed.
 * @param index Zero-based index in the task list
 * @return True on success, otherwise false
 */
bool TaskManager::completeTask(size_t index) {
    if (!isValidIndex(index)) {
        return false;
    }
    tasks[index].markAsCompleted();
    return true;
}

/**
 * @brief Returns all tasks as a constant reference.
 * @return Constant reference to the tasks vector
 */
const std::vector<Task>& TaskManager::getTasks() const { return tasks; }

/**
 * @brief Removes a task at [index].
 * @param index Zero-based index in the task list
 * @return True on success, otherwise false
 */
bool TaskManager::removeTask(size_t index) {
    if (!isValidIndex(index)) {
        return false;
    }
    tasks.erase(tasks.begin() + index);
    return true;
}
