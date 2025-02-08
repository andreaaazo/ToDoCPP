#ifndef TASK_H
#define TASK_H

#include <string>

/**
 * @class Task
 * @brief Represents an individual task with a name, description, and completion
 * status.
 */
class Task {
   public:
    /**
     * @brief Constructs [Task] with a [name] and a [description].
     * @param name Name of the task
     * @param description Description of the task
     */
    Task(const std::string& name, const std::string& description);

    /**
     * @brief Returns [name] of the task.
     * @return Reference to task [name]
     */
    const std::string& getName() const;

    /**
     * @brief Returns [description] of the task.
     * @return Reference to task [description]
     */
    const std::string& getDescription() const;

    /**
     * @brief Returns completion status of the task.
     * @return True if completed, otherwise false
     */
    bool isCompleted() const;

    /**
     * @brief Marks the task as completed.
     */
    void markAsCompleted();

   private:
    std::string name;
    std::string description;
    bool is_completed;
};

#endif
