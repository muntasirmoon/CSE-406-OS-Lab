#include<iostream>
using namespace std;


int main()
{
     int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100];
    int art[100];
    int brt[100];
    int prt[100];
    int ct[100];
    int tat[100];
    int wt[100];
    bool done[100] = {false}; // Process completion status

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for Process " << pid[i] << ": ";
        cin >> art[i];
        cout << "Enter Burst Time for Process " << pid[i] << ": ";
        cin >> brt[i];
        cout << "Enter Priority for Process " << pid[i] << ": ";
        cin >> prt[i];
    }

    int completed = 0, current_time = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        // Find the highest priority process
        for (int i = 0; i < n; i++) {
            if (art[i] <= current_time && !done[i]) {
                if (prt[i] < highest_priority || (prt[i] == highest_priority && art[i] < art[idx])) {
                    highest_priority = prt[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Schedule the process
            current_time += brt[idx];
            ct[idx] = current_time;
            tat[idx] = ct[idx] - art[idx];
            wt[idx] = tat[idx] - brt[idx];
            done[idx] = true;
            completed++;
        } else {
            // If no process is available, increment time
            current_time++;
        }
    }

    // Display result
    cout << "\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << art[i] << "\t" << brt[i] << "\t" << prt[i]
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    return 0;
}
