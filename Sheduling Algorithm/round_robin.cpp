#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Process {
    int pid, arrival, burst, remaining, waiting = 0, turnaround = 0;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrival;
        cout << "Burst time of process " << i + 1 << ": ";
        cin >> processes[i].burst;
        processes[i].remaining = processes[i].burst;
    }

    queue<int> q;
    int current_time = 0, completed = 0;
    vector<bool> in_queue(n, false);

    // Enqueue processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival <= current_time) {
            q.push(i);
            in_queue[i] = true;
        }
    }

    while (completed < n) {
        if (q.empty()) {
            current_time++;
            for (int i = 0; i < n; i++) {
                if (!in_queue[i] && processes[i].arrival <= current_time && processes[i].remaining > 0) {
                    q.push(i);
                    in_queue[i] = true;
                }
            }
            continue;
        }

        int idx = q.front();
        q.pop();

        int exec_time = min(quantum, processes[idx].remaining);
        processes[idx].remaining -= exec_time;
        current_time += exec_time;

        // Enqueue newly arrived processes during this time slice
        for (int i = 0; i < n; i++) {
            if (!in_queue[i] && processes[i].arrival <= current_time && processes[i].remaining > 0) {
                q.push(i);
                in_queue[i] = true;
            }
        }

        if (processes[idx].remaining == 0) {
            completed++;
            processes[idx].turnaround = current_time - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
        } else {
            q.push(idx);
        }
    }

    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.waiting << "\t" << p.turnaround << "\n";
    }

    return 0;
}
