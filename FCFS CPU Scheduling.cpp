#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,i ,j;

    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival_time[n], burst_time[n], completion_time[n], turnaround_time[n], waiting_time[n], id[n];

    for (i = 0; i < n; i++) {
        id[i] = i + 1;  //P1, P2, P3
        cout << "Enter arrival time and burst time for Process " << i + 1 << ": ";
        cin >> arrival_time[i] >> burst_time[i];
    }

    // Sort the processes based on their arrival time
    for ( i = 0; i < n - 1; i++) {
        for ( j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j]) {
                swap(arrival_time[i], arrival_time[j]);   //arrival times
                swap(burst_time[i], burst_time[j]);    //brust times
                swap(id[i], id[j]);   // ids er jonno
            }
        }
    }

    completion_time[0] = arrival_time[0] + burst_time[0]; //first process er jonno
// baki process gular jonno completion times
    for ( i = 1; i < n; i++) {
        if (arrival_time[i] > completion_time[i - 1]) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = completion_time[i - 1] + burst_time[i];
        }
    }

    int total_wt = 0, total_tat = 0;     // wt = Waiting time   tat = turnaround time

    for ( i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    // Calculate average waiting time and turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // Output the results
    cout << "\nProcess ID | Arrival Time| Burst Time|Turnaround Time|Waiting Time \n";
    for (i = 0; i < n; i++) {
        cout << "   P" << id[i] << "      |      " << arrival_time[i]
             << "      |     " << burst_time[i] << "     |     " << turnaround_time[i]
             << "      |       " << waiting_time[i] << endl;
    }
    return 0;
}
