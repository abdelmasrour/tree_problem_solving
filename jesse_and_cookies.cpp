#include <bits/stdc++.h> 
using namespace std; 





int main(){
    int n,k;
    cin >>n>>k;
    priority_queue <int,vector<int>,greater<int>> pq;
    for (int j=0;j<n;j++){int x;cin>>x;pq.push(x);}
    /*for (int i=0;i<n;i++){
        cout <<pq.top() << endl;
        pq.pop();
    }*/
    int cmpt=0;
    while(true){
        if (pq.top()>=k){break;}
        int first = pq.top();
        pq.pop();
        int second =pq.top();
        pq.pop();
        pq.push(2*second+first);
        cmpt++;
        if ((pq.size()==1 && pq.top()<k)||pq.empty()){cmpt=-1;break;}
    }
    cout <<cmpt<<endl;
    return 0;
}