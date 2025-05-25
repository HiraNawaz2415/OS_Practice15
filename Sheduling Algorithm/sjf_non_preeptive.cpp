#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid, arrival, burst, waiting = 0, turnaround = 0, completed = 0;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrival;
        cout << "Burst time of process " << i + 1 << ": ";
        cin >> processes[i].burst;
    }

    int completed = 0, current_time = 0;
    while (completed < n) {
        int idx = -1, min_burst = 1e9;
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival <= current_time) {
                if (processes[i].burst < min_burst) {
                    min_burst = processes[i].burst;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            current_time++;
        } else {
            processes[idx].waiting = current_time - processes[idx].arrival;
            current_time += processes[idx].burst;
            processes[idx].turnaround = processes[idx].waiting + processes[idx].burst;
            processes[idx].completed = 1;
            completed++;
        }
    }

    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.waiting << "\t" << p.turnaround << "\n";
    }

    return 0;
}
