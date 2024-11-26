#include <stdio.h>
#include <stdlib.h>

// Define a structure for a process node
typedef struct Process {
    int processID;
    int burstTime;
    struct Process* next;
} Process;

// Function to create a new process node
Process* createProcess(int processID, int burstTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->processID = processID;
    newProcess->burstTime = burstTime;
    newProcess->next = NULL;
    return newProcess;
}

// Function to enqueue a process into the queue
void enqueue(Process** front, Process** rear, int processID, int burstTime) {
    Process* newProcess = createProcess(processID, burstTime);
    if (*rear == NULL) {
        *front = *rear = newProcess;
        return;
    }
    (*rear)->next = newProcess;
    *rear = newProcess;
}

// Function to dequeue a process from the queue
Process* dequeue(Process** front) {
    if (*front == NULL) {
        return NULL;
    }
    Process* temp = *front;
    *front = (*front)->next;
    return temp;
}

// Function to simulate FIFO CPU scheduling
void fifoScheduling(Process* front) {
    int currentTime = 0;
    printf("Process Execution Order:\n");
    printf("--------------------------------------------------\n");
    printf("Process ID | Burst Time | Start Time | End Time\n");
    printf("--------------------------------------------------\n");

    while (front != NULL) {
        printf("%10d | %10d | %10d | %8d\n",
               front->processID, front->burstTime, currentTime, currentTime + front->burstTime);
        currentTime += front->burstTime;
        front = front->next;
    }

    printf("--------------------------------------------------\n");
}

int main() {
    Process* front = NULL; // Front of the queue
    Process* rear = NULL;  // Rear of the queue

    // Add processes to the queue
    enqueue(&front, &rear, 1, 5); // Process ID 1, Burst Time 5
    enqueue(&front, &rear, 2, 3); // Process ID 2, Burst Time 3
    enqueue(&front, &rear, 3, 8); // Process ID 3, Burst Time 8
    enqueue(&front, &rear, 4, 6); // Process ID 4, Burst Time 6

    // Run the FIFO scheduling algorithm
    fifoScheduling(front);

    return 0;
}
