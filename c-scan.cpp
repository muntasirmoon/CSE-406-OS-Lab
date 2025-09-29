#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void c_look(vector<int>& queue, int head, int disk_size, string direction) {
    sort(queue.begin(), queue.end());

    vector<int> left, right;


    for (int request : queue) {
        if (request < head) {
            left.push_back(request);
        } else {
            right.push_back(request);
        }
    }

    vector<int> movement_order;
    int total_distance = 0;
    int previous_head = head;

    if (direction == "left") {
        reverse(left.begin(), left.end());


        for (int request : left) {
            int dist = abs(request - previous_head);
            total_distance += dist;
            movement_order.push_back(request);
            previous_head = request;
        }


        if (!right.empty()) {
            previous_head = right.back();
            total_distance += abs(movement_order.back() - previous_head);


            for (int i = right.size() - 2; i >= 0; --i) {
                int dist = abs(previous_head - right[i]);
                total_distance += dist;
                movement_order.push_back(right[i]);
                previous_head = right[i];
            }
        }
    }
    else if (direction == "right") {

        for (int request : right) {
            int dist = abs(request - previous_head);
            total_distance += dist;
            movement_order.push_back(request);
            previous_head = request;
        }


        if (!left.empty()) {
            previous_head = left.front();
            total_distance += abs(movement_order.back() - previous_head);


            for (size_t i = 1; i < left.size(); ++i) {
                int dist = abs(previous_head - left[i]);
                total_distance += dist;
                movement_order.push_back(left[i]);
                previous_head = left[i];
            }
        }
    }


    cout << "Path: " << head;
    for (int position : movement_order) {
        cout << " -> " << position;
    }
    cout << endl;
    cout << "Total distance: " << total_distance << " cylinders" << endl;
}

int main() {
    vector<int> queue = {21, 39, 64, 79, 90, 176};
    int head = 50;
    int disk_size = 200;
    string direction = "left";


    c_look(queue, head, disk_size, direction);

    return 0;
}

