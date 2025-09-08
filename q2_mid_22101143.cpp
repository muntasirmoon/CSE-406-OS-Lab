#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void scanDiskSchedule(int request[], int n, int head, int direction) {
    int seekCount = 0;
    int left[100], right[100];
    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (request[i] < head)
            left[l++] = request[i];
        else
            right[r++] = request[i];
    }

    sort(left, left + l);
    sort(right, right + r);

    cout << "Seek sequence: \n";

    if (direction == 1) {
        for (int i = 0; i < r; i++) {
            int curTrack = right[i];
            seekCount += abs(curTrack - head);
            head = curTrack;
            cout << curTrack << " ";
        }

        for (int i = l - 1; i >= 0; i--) {
            int curTrack = left[i];
            seekCount += abs(curTrack - head);
            head = curTrack;
            cout << curTrack << " ";
        }
    } else {
        for (int i = l - 1; i >= 0; i--) {
            int curTrack = left[i];
            seekCount += abs(curTrack - head);
            head = curTrack;
            cout << curTrack << " ";
        }

        for (int i = 0; i < r; i++) {
            int curTrack = right[i];
            seekCount += abs(curTrack - head);
            head = curTrack;
            cout << curTrack << " ";
        }
    }

    cout << "\nTotal seek count: " << seekCount << endl;
}

int main() {
    int n, head, direction;

    cout << "Enter number of requests: ";
    cin >> n;

    int request[100];
    cout << "Enter request queue: ";
    for (int i = 0; i < n; i++) {
        cin >> request[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter direction (1 = right, 0 = left): ";
    cin >> direction;

    cout << "Initial head position: " << head << endl;
    cout << "Request queue: ";
    for (int i = 0; i < n; i++) {
        cout << request[i] << " ";
    }
    cout << "\n";

    scanDiskSchedule(request, n, head, direction);

    return 0;
}
