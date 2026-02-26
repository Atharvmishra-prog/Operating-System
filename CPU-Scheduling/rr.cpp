#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> quantum;

    Process p[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter burst time of P" << i+1 << ": ";
        cin >> p[i].burstTime;
        p[i].pid = i+1;
        p[i].remainingTime = p[i].burstTime;
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);

    int currentTime = 0;

    cout << "\nGantt Chart: ";

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        // Execute process for min(quantum, remaining time)
        int execTime = min(quantum, p[i].remainingTime);
        currentTime += execTime;
        p[i].remainingTime -= execTime;

        cout << " [P" << p[i].pid << "] ";

        // For waiting time: all other processes that are still not finished wait
        for (int j = 0; j < n; j++) {
            if (j != i && p[j].remainingTime > 0) {
                p[j].waitingTime += execTime;
            }
        }

        // If still remaining, push back into queue
        if (p[i].remainingTime > 0) {
            q.push(i);
        }
    }

    // Calculate turnaround times
    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }

    // Output
    cout << "\n\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].burstTime << "\t"
             << p[i].waitingTime << "\t"
             << p[i].turnaroundTime << "\n";
    }

    return 0;
}