#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added: " << desc << std::endl;
    }

    void listTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[X] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add task" << std::endl;
        std::cout << "2. List tasks" << std::endl;
        std::cout << "3. Mark task as completed" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::string description;
            std::cin.ignore();
            std::getline(std::cin, description);
            taskManager.addTask(description);
        } else if (choice == 2) {
            taskManager.listTasks();
        } else if (choice == 3) {
            std::cout << "Enter task index to mark as completed: ";
            size_t index;
            std::cin >> index;
            taskManager.markTaskCompleted(index - 1);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please select again." << std::endl;
        }
    }

    return 0;
}
