#include <iostream>
#include <queue>
#define PII pair<int, int>
using namespace std;


class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};

int main()
{
    // Empty Queue
    priority_queue<int> pqueue;
    pqueue.push(3);
    pqueue.push(5);
    pqueue.push(1);
    pqueue.push(2);
    // Priority queue becomes 5, 3, 2, 1
 
    // Printing content of queue
    while (!pqueue.empty()) {
        cout << ' ' << pqueue.top();
        pqueue.pop();
    }
     priority_queue<PII, vector<PII>, Compare> ds;
    ds.push({ 100, 11 });
    ds.push({ 100, 41 });
    ds.push({ 100, 21 });
    ds.push({ 300, 1 });
    ds.push({ 300, 2 });
    ds.push({ 1, 1 });
    ds.push({ 1, 2 });
    ds.push({ 1, 20 });
 
    cout << "The priority queue is : \n";
    while (!ds.empty()) {
        cout << ds.top().first << " " << ds.top().second
             << "\n";
        ds.pop(); // heapify happens
    }
}