#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// First Fit Memory Allocation Algorithm
void FirstFit(vector<int> block, vector<int> proc) {
    vector<int> procAllocatedBlockNumber(proc.size(), -1);
    vector<bool> isOccupiedBlock(block.size(), false);

    for (int i = 0; i < proc.size(); i++) {
        for (int j = 0; j < block.size(); j++) {
            if (block[j] >= proc[i] && !isOccupiedBlock[j] && procAllocatedBlockNumber[i] == -1) {
                procAllocatedBlockNumber[i] = j;
                isOccupiedBlock[j] = true;
            }
        }
    }

    for (int k = 0; k < proc.size(); k++) {
        cout << "Process " << k << " Size: " << proc[k] << " Allocated Block: " << procAllocatedBlockNumber[k] << endl;
    }
}

// Best Fit Memory Allocation Algorithm
void BestFit(vector<int> block, vector<int> proc) {
    vector<int> procAllocatedBlockNumber(proc.size(), -1);
    vector<bool> isBlockAllocated(block.size(), false);

    for (int i = 0; i < proc.size(); i++) {
        int bestPos = -1;
        int bestDiff = INT_MAX;
        for (int j = 0; j < block.size(); j++) {
            if (block[j] >= proc[i] && !isBlockAllocated[j] && block[j] - proc[i] < bestDiff) {
                bestPos = j;
                bestDiff = block[j] - proc[i];
            }
        }
        if (bestPos != -1) {
            procAllocatedBlockNumber[i] = bestPos;
            isBlockAllocated[bestPos] = true;
        }
    }

    for (int k = 0; k < proc.size(); k++) {
        cout << "Process " << k << " Size: " << proc[k] << " Allocated Block: " << procAllocatedBlockNumber[k] << endl;
    }
}

// Worst Fit Memory Allocation Algorithm
void WorstFit(vector<int> block, vector<int> proc) {
    vector<int> procAllocatedBlockNumber(proc.size(), -1);
    vector<bool> isBlockAllocated(block.size(), false);

    for (int i = 0; i < proc.size(); i++) {
        int bestPos = -1;
        int bestDiff = INT_MIN;
        for (int j = 0; j < block.size(); j++) {
            if (block[j] >= proc[i] && !isBlockAllocated[j] && block[j] - proc[i] > bestDiff) {
                bestPos = j;
                bestDiff = block[j] - proc[i];
            }
        }
        if (bestPos != -1) {
            procAllocatedBlockNumber[i] = bestPos;
            isBlockAllocated[bestPos] = true;
        }
    }

    for (int k = 0; k < proc.size(); k++) {
        cout << "Process " << k << " Size: " << proc[k] << " Allocated Block: " << procAllocatedBlockNumber[k] << endl;
    }
}

int main() {
    vector<int> blockSize = {5, 4, 3, 6, 7};
    vector<int> processSize = {1, 3, 5, 3};

    cout << "Using Worst Fit Memory Allocation Algorithm:" << endl;
    WorstFit(blockSize, processSize);

    return 0;
}
