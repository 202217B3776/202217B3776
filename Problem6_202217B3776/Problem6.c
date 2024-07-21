#include <stdio.h>

// Function prototypes
void calculateTimes(int n, int burst[], int arrival[], int waiting[], int turnaround[], float *avg_wait, float *avg_turn);

int main() {
    int n, i;
    int burst[10], arrival[10], waiting[10], turnaround[10];
    float avg_wait = 0, avg_turn = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }

    calculateTimes(n, burst, arrival, waiting, turnaround, &avg_wait, &avg_turn);

    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, waiting[i], turnaround[i]);
    }
    printf("The average waiting time is: %.2f\n", avg_wait);
    printf("The average turnaround time is: %.2f\n", avg_turn);

    return 0;
}

void calculateTimes(int n, int burst[], int arrival[], int waiting[], int turnaround[], float *avg_wait, float *avg_turn) {
    int completion[10], i;
    completion[0] = 0;

    // Calculate completion times
    for (i = 0; i < n; i++) {
        if (i == 0) {
            completion[i] = arrival[i] + burst[i];
        } else {
            if (arrival[i] > completion[i - 1]) {
                completion[i] = arrival[i] + burst[i];
            } else {
                completion[i] = completion[i - 1] + burst[i];
            }
        }
    }

    // Calculate waiting and turnaround times
    for (i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        *avg_wait += waiting[i];
        *avg_turn += turnaround[i];
    }

    *avg_wait /= n;
    *avg_turn /= n;
}
