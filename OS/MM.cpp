#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


using namespace std;

//First fit

void FirstFit(vector<int> block, vector<int> proc){

    vector<int> procAllocatedBlockNumber(proc.size(), -1);
    vector<bool> isOccupideBlock(block.size(), false);

    for (int i = 0; i < proc.size(); i++)
    {
        for (int j = 0; j < block.size(); j++)
        {
            if(block[j] >= proc[i] && isOccupideBlock[j] == false && procAllocatedBlockNumber[i] == -1){
                procAllocatedBlockNumber[i] = j;
                isOccupideBlock[j] = true;
            }
        }
        
    }
    for (int k = 0; k < proc.size(); k++)
    {
            cout << k << " " << proc[k] << " " << procAllocatedBlockNumber[k] << std::endl;

    }
    
    

}
void FirstFit2Proc1Bloc(vector<int> block, vector<int> proc){

    vector<int> procAllocatedBlockNumber(proc.size(), -1);

    for (int i = 0; i < proc.size(); i++)
    {
        for (int j = 0; j < block.size(); j++)
        {
            if(block[j] >= proc[i] && procAllocatedBlockNumber[i] == -1 ){
                block[j] -= proc[i];
                procAllocatedBlockNumber[i] = j;
            }
        }
        
    }
     for (int k = 0; k < proc.size(); k++)
    {
            cout << k << " " << proc[k] << " " << procAllocatedBlockNumber[k] << std::endl;

    }
}

//BEst fit

void BestFit(vector<int> block, vector<int> proc){
        vector<int> procAllocatedBlockNumber(proc.size(), -1);
        vector<bool> isBlocAlloc(block.size(), false);

        for (int i = 0; i < proc.size(); i++)
        {
            int BestPos = -1;
            int bestDiff = INT16_MAX;
            for (int j = 0; j < block.size(); j++)
            {
                if(bestDiff > (block[j] - proc[i]) && isBlocAlloc[j] == false && block[j] > proc[i] ){
                    BestPos = j;
                    bestDiff =  (block[j] - proc[i]);
                }
            }
            if(BestPos != -1){
                isBlocAlloc[BestPos] = true;

            }
            procAllocatedBlockNumber[i] = BestPos;
        }

    for (int k = 0; k < proc.size(); k++)
    {
            cout << k << " " << proc[k] << " " << procAllocatedBlockNumber[k] << std::endl;

    }
        
}

void BestFit2Proc1Bloc(vector<int> block, vector<int> proc){
    vector<int> procAllocatedBlockNumber(proc.size(), -1);
    for (int i = 0; i < proc.size(); i++)
    {
        int BestPos = -1;
        int BestDifference = INT16_MAX;
        for (int j = 0; j < block.size(); j++)
        {
            if(BestDifference > (block[j] - proc[i]) && block[j] > proc[i]){
                BestDifference = block[j] - proc[i];
                BestPos = j;
            }
        }
        if(BestPos != -1){
            procAllocatedBlockNumber[i] = BestPos;
            BestPos -= proc[i];
        }
        
    }

     for (int k = 0; k < proc.size(); k++)
    {
            cout << k << " " << proc[k] << " " << procAllocatedBlockNumber[k] << std::endl;

    }
    
}

//Worst fit

void WorstFit(vector<int> block, vector<int> proc){
        vector<int> procAllocatedBlockNumber(proc.size(), -1);
        vector<bool> isBlocAlloc(block.size(), false);

        for (int i = 0; i < proc.size(); i++)
        {
            int BestPos = -1;
            int bestDiff = INT16_MIN;
            for (int j = 0; j < block.size(); j++)
            {
                if(bestDiff < (block[j] - proc[i]) && isBlocAlloc[j] == false && block[j] > proc[i] ){
                    BestPos = j;
                    bestDiff =  (block[j] - proc[i]);
                }
            }
            if(BestPos != -1){
                isBlocAlloc[BestPos] = true;

            }
            procAllocatedBlockNumber[i] = BestPos;
        }

    for (int k = 0; k < proc.size(); k++)
    {
            cout << k << " " << proc[k] << " " << procAllocatedBlockNumber[k] << std::endl;

    }
        
}

void WorstFit2Proc1Bloc(vector<int> block, vector<int> proc){
    vector<int> procAllocatedBlockNumber(proc.size(), -1);
    for (int i = 0; i < proc.size(); i++)
    {
        int BestPos = -1;
        int BestDifference = INT16_MIN;
        for (int j = 0; j < block.size(); j++)
        {
            if(BestDifference < (block[j] - proc[i]) && block[j] >= proc[i]){
                BestDifference = block[j] - proc[i];
                BestPos = j;
            }
        }
        if(BestPos != -1){
            procAllocatedBlockNumber[i] = BestPos;
            block[BestPos] -= proc[i];
        }
        
    }

     for (int k = 0; k < proc.size(); k++)
    {
            cout << k << " " << proc[k] << " " << procAllocatedBlockNumber[k] << std::endl;

    }
    
}

//next fit


int main()
{

    vector<int> blockSize = {5, 4, 3, 6, 7};
    vector<int> processSize =  {1, 3, 5, 3};
    int m = sizeof(blockSize)/sizeof(blockSize[0]); 
    int n = sizeof(processSize)/sizeof(processSize[0]);
    
    WorstFit2Proc1Bloc(blockSize,processSize);
    return 0;
}