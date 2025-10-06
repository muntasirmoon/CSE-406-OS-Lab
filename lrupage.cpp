#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of frames: ";
    cin >> capacity;
    cout << "Enter number of page references: ";
    cin >> n;
    int pages[n], frames[capacity];
    cout << "Enter page reference sequence: ";
    for (int i = 0; i < n; i++) cin >> pages[i];
    for (int i = 0; i < capacity; i++) frames[i] = -1;
    int counter[capacity], time = 0, page_faults = 0, hits = 0;
    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                counter[j] = ++time;
                found = 1;
                hits++;
                break;
            }
        }
        if (!found) {
            int pos = 0, min = 1e9;
            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
                if (counter[j] < min) {
                    min = counter[j];
                    pos = j;
                }
            }
            frames[pos] = page;
            counter[pos] = ++time;
            page_faults++;
        }
        cout << "Frames: ";
        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) cout << frames[j] << " ";
            else cout << "- ";
        }
        cout << endl;
    }
    cout << "Total Hits = " << hits << endl;
    cout << "Total Misses (Page Faults) = " << page_faults << endl;
    return 0;
}
