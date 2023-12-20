#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <queue>
using namespace std;


priority_queue<int, vector<int>, greater<int>> build_priority_queue(const vector<int>& v, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto i : v) {
                // If we have space, or the lowest element is lower than current.
                if (q.size() < k || q.top() < i) {
                        q.push(i);
                }
                // If we have to many elements, remove the lowest one.
                if (q.size() > k) {
                        q.pop();
                }
        }
        return q;
}
int main()
{   
    int n,k;
    cin >> n >> k;

    vector<int>v;
    for (int i=0;i<n;i++){
        int x;
        cin >>x;
        v.push_back(x);
        }
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto i:v){q.push(i);cout<<q.top() <<endl;}
    cout <<"Sort " << endl;
   /* sort(begin(v),end(v),greater<int>());
    for (auto it=v.begin();it!=v.end();it++){
        cout <<*it<<endl;
    }*/
    cout << "Partial sort" << endl;
    partial_sort(begin(v),begin(v)+k,end(v),greater<int>());
    /*v.resize(k);
     for (auto it=v.begin();it!=v.end();it++){
        cout <<*it<<endl;
    }*/
        cout <<v[k-1] << endl;


    cout <<"Hello world " <<endl; 
    priority_queue<int, vector<int>, greater<int>> pq_min_heap =build_priority_queue(v,k);
    while(!pq_min_heap.empty()){
        cout << pq_min_heap.top() << endl;
        pq_min_heap.pop();
    }
    return 0;
}