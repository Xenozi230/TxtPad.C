#include <stdio.h>  
#include <string.h> 


typedef struct Task {
    int id;                
    char description[100]; 
    char dueDate[20];      
    int priority;          
    int isCompleted;       
} Task;

Task tasks[100];
int taskCount = 0;

void addTask() {
    Task newTask; 
    newTask.id = taskCount + 1; 

    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);
    printf("Enter due date (DD/MM/YYYY): ");
    scanf("%s", newTask.dueDate); 
    printf("Enter priority (1-Low, 2-Medium, 3-High): ");
    scanf("%d", &newTask.priority);


    newTask.isCompleted = 0;
    tasks[taskCount] = newTask;
    taskCount++;

    printf("Task added successfully!\n");
}

void showMenu() {
    printf("\nTo-Do List Manager\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        for (int i = 0; i < taskCount; i++) {
            printf("Task ID: %d\n", tasks[i].id);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].dueDate);
            printf("Priority: %d\n", tasks[i].priority);
            printf("\n");
        }
    }
}

int main() {
    int choice; 

    while (1) {
        showMenu(); 
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                addTask(); 
                break;
            case 2:
                viewTasks(); 
                break;
            case 3:
                printf("Exiting the application.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
