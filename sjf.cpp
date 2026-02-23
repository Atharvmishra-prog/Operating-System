#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;
void swap(Process *a, Process *b) {
    Process t = *a;
    *a = *b;
    *b = t;
}
void sortByArrival(Process P[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(P[i].at > P[j].at)
                swap(&P[i], &P[j]);
        }
    }
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process P[n];
    int visited[n];
    for(int i = 0; i < n; i++) {
        printf("Enter pid, AT, BT: ");
        scanf("%d %d %d", &P[i].pid, &P[i].at, &P[i].bt);
        visited[i] = 0;
    }
    sortByArrival(P, n);
    int completed = 0, time = 0;
    int totalTAT = 0, totalWT = 0;
    while(completed < n) {
        int idx = -1;
        int minBT = 1e9;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && P[i].at <= time) {
                if(P[i].bt < minBT) {
                    minBT = P[i].bt;
                    idx = i;
                }
            }
        }
        if(idx == -1) {
            time++;
            continue;
        }
        time += P[idx].bt;
        P[idx].ct = time;
        P[idx].tat = P[idx].ct - P[idx].at;
        P[idx].wt  = P[idx].tat - P[idx].bt;
        totalTAT += P[idx].tat;
        totalWT  += P[idx].wt;
        visited[idx] = 1;
        completed++;
    }
    printf("\n%-5s %-5s %-5s %-5s %-5s %-5s\n",
           "PID", "AT", "BT", "CT", "TAT", "WT");
    for(int i = 0; i < n; i++) {
        printf("%-5d %-5d %-5d %-5d %-5d %-5d\n",
               P[i].pid, P[i].at, P[i].bt,
               P[i].ct, P[i].tat, P[i].wt);
    }
    printf("\nAverage TAT = %.2f\n", (float)totalTAT / n);
    printf("Average WT  = %.2f\n", (float)totalWT / n);
    return 0;
}
