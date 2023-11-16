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


int main()
{

    vector<int> blockSize = {100, 50, 30, 120, 35};
    vector<int> processSize = {20, 60, 70, 40};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    
    FirstFit2Proc1Bloc(blockSize,processSize);
    return 0;
}