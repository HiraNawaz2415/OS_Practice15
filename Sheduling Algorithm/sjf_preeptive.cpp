#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time for P" << p[i].pid << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time for P" << p[i].pid << ": ";
        cin >> p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }

    int completed = 0, current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    while (completed != n) {
        int idx = -1;
        int min_remaining_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0 && p[i].remaining_time < min_remaining_time) {
                min_remaining_time = p[i].remaining_time;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining_time--;
            current_time++;

            if (p[idx].remaining_time == 0) {
                completed++;
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

                total_waiting_time += p[idx].waiting_time;
                total_turnaround_time += p[idx].turnaround_time;
            }
        } else {
            current_time++;
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].arrival_time << "\t" << p[i].burst_time
             << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_waiting_time / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround_time / n;

    return 0;
}
