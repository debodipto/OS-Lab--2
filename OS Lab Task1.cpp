#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int id[n], arrival_time[n], burst_time[n], completion_time[n], turnaround_time[n], waiting_time[n];

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        cout << "Enter arrival time and burst time for Process " << id[i] << ": ";
        cin >> arrival_time[i] >> burst_time[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j]) {
                swap(arrival_time[i], arrival_time[j]);
                swap(burst_time[i], burst_time[j]);
                swap(id[i], id[j]);
            }
        }
    }

    completion_time[0] = arrival_time[0] + burst_time[0];
    for (int i = 1; i < n; i++) {
        if (arrival_time[i] > completion_time[i - 1]) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = completion_time[i - 1] + burst_time[i];
        }
    }

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }
    cout << "\nProcess ID | Arrival Time | Burst Time | Turnaround Time | Waiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "    P" << id[i] << "     |      " << arrival_time[i]
             << "       |     " << burst_time[i] << "      |       " << turnaround_time[i]
             << "        |      " << waiting_time[i] << endl;
    }


    return 0;
}
