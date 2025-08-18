#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, head;

    cout << "Enter number of requests: ";
    cin >> n;

    int req[n];
    cout << "Enter request sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    int completed[n];
    for (int i = 0; i < n; i++)
        completed[i] = 0;

    int total_moves = 0;
    cout << "\nSeek Sequence: " ;

    for (int done = 0; done < n; done++) {
        int min_dist = 9999, index = -1;


        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                int dist = abs(req[i] - head);
                if (dist < min_dist) {
                    min_dist = dist;
                    index = i;
                }
            }
        }


        completed[index] = 1;
        total_moves += min_dist;
        head = req[index];

        cout << " -> "<<head ;
    }

    cout << "\nTotal number of moves: " << total_moves << endl;

    return 0;
}



