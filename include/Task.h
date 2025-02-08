#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
   public:
    Task(const string& name, const string& description);

    const string& getName() const;
    const string& getDescription() const;
    const bool isCompleted() const;

    void markAsCompleted();

   private:
    string name, description;
    bool is_completed;
};

#endif