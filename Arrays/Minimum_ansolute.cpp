#include <bits/stdc++.h>

using namespace std;


int main(){

    cout <<"heello" <<endl;
    int min_p=1e9;
    vector <int> v ={3,-7,0};
    for( int i=0;i<v.size();i++){

        for (int j=i;j<v.size()-1;j++){
            if (abs(v.at(j+1)-v.at(j))<min_p){
                min_p=abs(v.at(j+1)-v.at(j));
            }
        }
    }
    cout << min_p <<endl;
    return 0;
}