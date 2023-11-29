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

void FCFS(vector<int> reuest, int head){
    int total_seek = 0;
    int current_head = head;
    for (int i = 0; i < reuest.size(); i++)
    {
        total_seek += abs(current_head - reuest[i]);
        current_head = reuest[i];
    }
    cout << total_seek;

}

void SCAN(vector<int> request, int head, int disk_size){
     sort(request.begin(), request.end());
     int current_head = head;
     int total_seek = 0;
     //right
     vector<int> left;
     vector<int> right;
     for (int i = 0; i < request.size(); i++)
     {
        if(request[i] < head){
            left.push_back(request[i]);
        }
        else{
            right.push_back(request[i]);
        }
     }

     //for right only
     right.push_back(disk_size -1);
    for (int k = 0; k < right.size(); k++)
    {
        cout << right[k]<< "\n";
        total_seek += abs(right[k] - current_head);
        current_head = right[k];

    }
    total_seek += (disk_size - head);
    current_head = head;
    for (int l = left.size() -1 ; l >= 0; l--)
    {
        cout << left[l] << "\n";
        total_seek += abs(left[l] - current_head);
        current_head = left[l];
    }
    cout << "total seek = " << total_seek -1;
    
     
}

void SSTF(vector<int> request, int head, int disk_size){
    int total_seek = 0;
    int current_head = head;
    sort(request.begin(), request.end());
    int ptr = 0;
   while (request[ptr] > head)
   {
        ptr++;
   }
    cout << request[ptr] << " " << ptr;
   
    
    // while (request.size() > 0)
    // {
        
    // }
    
    

}

int main(){
    vector<int> req ={ 176, 79, 34, 60, 92, 11, 41, 114 };
    int initpos = 50;
    //FCFS(req, initpos);

    SSTF(req, initpos, 200);
    //337
    return 0;
}