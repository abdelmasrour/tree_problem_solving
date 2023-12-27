#include <bits/stdc++.h>
#include <map>
using namespace std;


int main(){
   string orders= "up up up down left left right up up";

    map <string,string> t ;
    t["up"]="^";
    t["down"]="v";
    t["left"]="<";
    t["right"]=">";
    stringstream ss(orders);
    string token;
    vector <string>tokens;

    while(ss>>token){

        tokens.push_back(token);
    }
    string x =tokens.at(0);
    vector <vector<string>> l;
    int cmpt=1;
    for(int i=1;i<tokens.size();i++){
        if (tokens.at(i)==x){
           cmpt+=1;}
        else {
              string cmpt_mask =to_string(cmpt);
              vector <string> row={x,cmpt_mask}; 
              l.push_back(row);
              x=tokens.at(i);
              cmpt=1;   
        }  
    
    }
    string cmpt_mask =to_string(cmpt);
    vector <string> row={x,cmpt_mask}; 
    l.push_back(row);
    
    for (int i=0;i<l.size();i++){
        cout << l.at(i).at(0) <<":" <<l.at(i).at(1)<<endl;
    }
    cout <<"0000000000000000000000" <<endl;
    for (int i=0;i<l.size();i++){
        if (stoi(l.at(i).at(1))>1){
            cout <<t[l.at(i).at(0)]<<stoi(l.at(i).at(1));
        }
        else {
            cout <<t[l.at(i).at(0)];
        }
    }
    cout <<"0000000000000000000000" <<endl;
    return 0;
}