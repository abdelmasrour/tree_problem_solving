#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            if (stack_oldest_on_top.size()==0 && stack_newest_on_top.size()==0){
                stack_oldest_on_top.push(x);
                
            }
            else if (stack_oldest_on_top.size()==1) {
                stack_newest_on_top.push(x); 
            }
        }

        void pop() {
            if (stack_oldest_on_top.size()==1 && stack_newest_on_top.size()==0){
                 return stack_oldest_on_top.pop();
                 
            }
            else if (stack_oldest_on_top.size()==1 && stack_newest_on_top.size()!=0){
                 return stack_oldest_on_top.pop();
                 
            }

            /*if (stack_oldest_on_top.size()==0 && stack_newest_on_top.size()==0){
                cout <<"Impossible" <<endl;
            }*/
            else if (stack_oldest_on_top.size()==0 && stack_newest_on_top.size()!=0){
                for (int i=0;i<stack_newest_on_top.size();i++){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
                stack_oldest_on_top.pop();
            }
            else if (stack_oldest_on_top.size()>1){
                stack_oldest_on_top.pop();

            }
            
        }

        int front() {

            //cout << "debug 43 ligne" <<stack_oldest_on_top.top() << endl;
            //cout << "debug 44 ligne" <<stack_newest_on_top.top() << endl;
            if (stack_oldest_on_top.size()==0){
                  for (int i=0;i<stack_newest_on_top.size();i++){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
                 
            }
                //cout <<"test"<< stack_oldest_on_top.top() <<stack_newest_on_top.size()<<endl ;
                return stack_oldest_on_top.top();

        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    cout<<endl;
    cout << "########"<< endl;
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}