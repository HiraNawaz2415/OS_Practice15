#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid, arrival, burst, waiting = 0, turnaround = 0;
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

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival)
            current_time = processes[i].arrival;
        processes[i].waiting = current_time - processes[i].arrival;
        current_time += processes[i].burst;
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
    }

    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.waiting << "\t" << p.turnaround << "\n";
    }
    return 0;
}
