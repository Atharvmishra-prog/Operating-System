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

void sort(Process P[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(P[i].at > P[j].at) {
				swap(&P[i], &P[j]);
			}
		}
	}
}

int main() {
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	Process P[n];
	for(int i = 0; i < n; i++) {
		printf("Enter pid, AT, BT: ");
		scanf("%d %d %d", &P[i].pid, &P[i].at, &P[i].bt);
	}
	sort(P, n);
	int time = 0, totalTAT = 0, totalWT = 0;
	for(int i = 0; i < n; i++) {
		if(time < P[i].at)
			time = P[i].at;
		time += P[i].bt;
		P[i].ct = time;
		P[i].tat = P[i].ct - P[i].at;
		P[i].wt  = P[i].tat - P[i].bt;
		totalTAT += P[i].tat;
		totalWT  += P[i].wt;
	}
	printf("\n%-5s %-5s %-5s %-5s %-5s %-5s\n",
	       "pid", "AT", "BT", "CT", "TAT", "WT");
	for(int i = 0; i < n; i++) {
		printf("%-5d %-5d %-5d %-5d %-5d %-5d\n",
		       P[i].pid, P[i].at, P[i].bt,
		       P[i].ct, P[i].tat, P[i].wt);
	}
	printf("\nAverage TAT = %.2f\n", (float)totalTAT / n);
	printf("Average WT  = %.2f\n", (float)totalWT / n);
	return 0;
}
