#include "Task.h"

/**
 * @brief Constructs [Task] with a [name] and a [description].
 * @param name Name of the task
 * @param description Description of the task
 */
Task::Task(const std::string& name, const std::string& description)
    : name(name), description(description), is_completed(false) {}

/**
 * @brief Returns [name] of the task.
 * @return Reference to task [name]
 */
const std::string& Task::getName() const { return name; }

/**
 * @brief Returns [description] of the task.
 * @return Reference to task [description]
 */
const std::string& Task::getDescription() const { return description; }

/**
 * @brief Returns completion status of the task.
 * @return True if completed, otherwise false
 */
bool Task::isCompleted() const { return is_completed; }

/**
 * @brief Marks the task as completed.
 */
void Task::markAsCompleted() { is_completed = true; }
