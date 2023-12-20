#include <bits/stdc++.h> 
using namespace std; 


int main(){
    int n;
    priority_queue <int,vector<int>,greater<int>> pq_min;
    priority_queue <int> pq_max;
    float current_median;
    cin >>n;
    cin >> current_median;
    vector<int> median;
    median.push_back(current_median);
    pq_min.push(current_median);
    for (int i=0;i<n-1;i++){
        int x;
        cin >>x;
        if (x>current_median){
            pq_min.push(x);
        }
        else{
          pq_max.push(x);
        }
        if ((pq_max.size()-pq_min.size())>1){
                    int tmp;
                    tmp=pq_max.top();
                    pq_max.pop();
                    pq_min.push(tmp);

        }
        if ((pq_min.size()-pq_max.size())>1){
                    int tmp;
                    tmp=pq_min.top();
                    pq_min.pop();
                    pq_max.push(tmp);

        }
        if (pq_max.size()==pq_min.size()){
        median.push_back((pq_max.top()+pq_min.top())/2);
        current_median=(pq_max.top()+pq_min.top())/2;
        }
        else if (pq_max.size()>pq_min.size()){
            median.push_back(pq_max.top());
            current_median=pq_max.top();
        }
        else {
            median.push_back(pq_min.top());
            current_median=pq_min.top();
        }
    }
    for (auto s:median){cout << s <<endl;}
    return 0;
}