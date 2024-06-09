#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function for First-Come, First-Served (FCFS) disk scheduling algorithm
void FCFS(vector<int> request, int head) {
    int total_seek = 0;
    int current_head = head;

    // Iterate through the requests
    for (int i = 0; i < request.size(); i++) {
        total_seek += abs(current_head - request[i]);
        current_head = request[i];
    }

    cout << "Total seek using FCFS: " << total_seek;
}

// Function for SCAN disk scheduling algorithm
void SCAN(vector<int> request, int head, int disk_size) {
    sort(request.begin(), request.end());
    int current_head = head;
    int total_seek = 0;
    vector<int> left;
    vector<int> right;

    // Separate requests into left and right based on head position
    for (int i = 0; i < request.size(); i++) {
        if (request[i] < head)
            left.push_back(request[i]);
        else
            right.push_back(request[i]);
    }

    // Move right and then move to end of disk and move left
    right.push_back(disk_size - 1);
    for (int k = 0; k < right.size(); k++) {
        total_seek += abs(right[k] - current_head);
        current_head = right[k];
    }

    total_seek += (disk_size - head);
    current_head = head;
    for (int l = left.size() - 1; l >= 0; l--) {
        total_seek += abs(left[l] - current_head);
        current_head = left[l];
    }

    cout << "Total seek using SCAN: " << total_seek - 1;
}

// Function for Shortest Seek Time First (SSTF) disk scheduling algorithm
void SSTF(vector<int> request, int head, int disk_size) {
    int total_seek = 0;
    int current_head = head;
    sort(request.begin(), request.end());
    int ptr = 0;

    // Find the closest request to the head position
    while (request[ptr] > head)
        ptr++;

    cout << "Closest request to head: " << request[ptr] << " at position " << ptr;
}

int main() {
    vector<int> req = {176, 79, 34, 60, 92, 11, 41, 114};
    int initpos = 50;

    // FCFS(req, initpos); Uncomment to test FCFS algorithm
    // SCAN(req, initpos, 200); Uncomment to test SCAN algorithm
    SSTF(req, initpos, 200); // Uncomment to test SSTF algorithm

    return 0;
}
