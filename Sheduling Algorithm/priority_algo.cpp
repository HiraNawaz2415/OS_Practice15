#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a process
struct Process {
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

// Comparator to sort processes by priority (lower number = higher priority)
bool compareByPriority(Process a, Process b) {
    return a.priority < b.priority;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input burst time and priority for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter burst time for Process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter priority for Process " << processes[i].id << " (lower = higher priority): ";
        cin >> processes[i].priority;
    }

    // Sort processes by priority
    sort(processes.begin(), processes.end(), compareByPriority);

    // Calculate waiting time and turnaround time
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    // Display results
    cout << "\nProcess\tBT\tPriority\tWT\tTAT\n";
    int totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].id << "\t"
             << processes[i].burstTime << "\t"
             << processes[i].priority << "\t\t"
             << processes[i].waitingTime << "\t"
             << processes[i].turnaroundTime << "\n";

        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnaroundTime;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWT / n;
    cout << "\nAverage Turnaround Time: " << (float)totalTAT / n << endl;

    return 0;
}
