#include <stdio.h>

typedef struct {
    int pid, at, bt, pr;
    int ct, tat, wt;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process P[n];
    int visited[n];
    printf("Enter PID, AT, BT, Priority: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &P[i].pid, &P[i].at, &P[i].bt, &P[i].pr);
        visited[i] = 0;
    }

    int completed = 0, time = 0;
    int totalTAT = 0, totalWT = 0;

    while(completed < n) {
        int idx = -1;
        int bestPriority = 999999;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && P[i].at <= time) {
                if(P[i].pr < bestPriority) {
                    bestPriority = P[i].pr;
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

    printf("\nPID  AT  BT  PR  CT  TAT  WT\n");
    for(int i = 0; i < n; i++) {
        printf("%d    %d   %d   %d   %d   %d    %d\n",
               P[i].pid, P[i].at, P[i].bt, P[i].pr,
               P[i].ct, P[i].tat, P[i].wt);
    }
    printf("\nAverage TAT = %.2f\n", (float)totalTAT / n);
    printf("Average WT  = %.2f\n", (float)totalWT / n);
    return 0;
}
