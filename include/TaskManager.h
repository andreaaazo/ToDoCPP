#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>

#include "Task.h"

/**
 * @class TaskManager
 * @brief Manages a collection of tasks by providing CRUD-like operations.
 */
class TaskManager {
   public:
    /**
     * @brief Adds a new task using [name] and [description].
     * @param name Name of the new task
     * @param description Description of the new task
     * @return True on success, otherwise false
     */
    bool addTask(const std::string& name, const std::string& description);

    /**
     * @brief Removes a task at [index].
     * @param index Zero-based index in the task list
     * @return True on success, otherwise false
     */
    bool removeTask(size_t index);

    /**
     * @brief Marks a task at [index] as completed.
     * @param index Zero-based index in the task list
     * @return True on success, otherwise false
     */
    bool completeTask(size_t index);

    /**
     * @brief Returns all tasks as a constant reference.
     * @return Constant reference to the tasks vector
     */
    const std::vector<Task>& getTasks() const;

   private:
    std::vector<Task> tasks;

    /**
     * @brief Checks if [index] is valid for the current tasks vector.
     * @param index Zero-based index
     * @return True if [index] is within range, otherwise false
     */
    bool isValidIndex(size_t index) const;
};

#endif
