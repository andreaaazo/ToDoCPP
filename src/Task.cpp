#include "Task.h"

Task::Task(const string& name, const string& description)
    : name(name), description(description), is_completed(false) {}

const string& Task::getDescription() const { return description; }

const string& Task::getName() const { return name; }

const bool Task::isCompleted() const { return is_completed; }

void Task::markAsCompleted() { is_completed = true; }