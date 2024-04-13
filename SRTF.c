#include <stdio.h>

// Function to sort processes by arrival time
void sortProcessesByArrival(float arrival[], float burst[], int n) {
    int i, j;
    float temp;
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (arrival[i] > arrival[j]) {
                // Swap arrival time
                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;
                // Swap burst time
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time using SRTF
void calculateTimesSRTF(float process[], float arrival[], float burst[], int n) {
    float remainingTime[n]; // Remaining burst time for each process
    float currentTime = 0; // Current time
    int completed = 0; // Number of processes completed
    float totalWaitingTime = 0; // Total waiting time
    float totalTurnaroundTime = 0; // Total turnaround time

    // Initialize remaining time as burst time
    for (int i = 1; i <= n; i++) {
        remainingTime[i] = burst[i];
    }

    while (completed < n) {
        int shortestProcess = -1; // Index of the process with shortest remaining time
        float shortestTime = 9999; // Initialize with a large value

        // Find the process with the shortest remaining time
        for (int j = 1; j <= n; j++) {
            if (arrival[j] <= currentTime && remainingTime[j] < shortestTime && remainingTime[j] > 0) {
                shortestProcess = j;
                shortestTime = remainingTime[j];
            }
        }

        // If no process is found, increment current time
        if (shortestProcess == -1) {
            currentTime++;
            continue;
        }

        // Reduce remaining time of the shortest process by 1 time unit
        remainingTime[shortestProcess]--;
        currentTime++;

        // If the process has completed execution
        if (remainingTime[shortestProcess] == 0) {
            completed++;
            // Calculate waiting time
            totalWaitingTime += currentTime - arrival[shortestProcess] - burst[shortestProcess];
            // Calculate turnaround time
            totalTurnaroundTime += currentTime - arrival[shortestProcess];

            // Print details of the completed process
            printf("Process %.0f:\n", process[shortestProcess]);
            printf("\tWaiting Time: %.2f\n", currentTime - arrival[shortestProcess] - burst[shortestProcess]);
            printf("\tTurnaround Time: %.2f\n", currentTime - arrival[shortestProcess]);
        }
    }
    int k;
     printf ("|process|    |ArrivalTime|\t |BurstTime|\n");
             for (k=1;k<=n;k++)
             {
                printf ("|%.1f|\t |%f|\t |%f|\n",process[k],arrival[k],burst[k]);
             }

    // Print average waiting time and turnaround time
    printf("=>Average Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("=>Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    }

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    float process[n + 1], arrival[n + 1], burst[n + 1];

    // Input process details
    for (int p = 1; p <= n; p++) {
        process[p] = p;
        printf("Enter arrival time for P%d: ", p);
        scanf("%f", &arrival[p]);
        printf("Enter burst time for P%d: ", p);
        scanf("%f", &burst[p]);
    }

    // Sort processes by arrival time
    sortProcessesByArrival(arrival, burst, n);

    // Calculate waiting time and turnaround time using SRTF
    calculateTimesSRTF(process, arrival, burst, n);

    return 0;
}
