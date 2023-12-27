#include <bits/stdc++.h>
#include <map>
using namespace std;

typedef struct {
 string clothes_type;
 int clothes_size;
 string clothes_color;
}clothes;

class Checker{
public:
  	// complete this method
    static int comparator(clothes a, clothes b)  {
	
    if (a.clothes_type>b.clothes_type || a.clothes_type==b.clothes_type && a.clothes_size>b.clothes_size || a.clothes_size==b.clothes_size && a.clothes_color>b.clothes_color){
        return -1;
    }
    else if (a.clothes_type==b.clothes_type && a.clothes_size==b.clothes_size && a.clothes_color==b.clothes_color){
        return 0;
    }
    else {
        return 1;
    }
    }
};




bool compare(clothes a, clothes b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}

int main(){

int n;
cin >>n;
cin.ignore();
vector <clothes> washing;

for (int j=0;j<n;j++){
     string clothes_type;
     int clothes_size;
     string clothes_color;
     cin >>clothes_type;
     cin >>clothes_size;
     cin >>clothes_color;
     clothes c;
     c.clothes_color=clothes_color;
     c.clothes_size=clothes_size;
     c.clothes_type=clothes_type;
     washing.push_back(c);

}

sort(washing.begin(),washing.end(),compare);
for (int j=0;j<n;j++){

    cout <<" clothes type " <<washing.at(j).clothes_type << " clothes size " << washing.at(j).clothes_size <<" clothes color " << washing.at(j).clothes_color;
}

return 0;
}