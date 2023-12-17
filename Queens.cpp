#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>


int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> c{n};
    std::vector<int> children[n];
    for (int i=0;i<n;i++){
        int x;
        std::cin >>x>>c[i];
        if (x!=-1){
            --x;
            children[x].push_back(i);
        }

    }
    std::vector<int> ans;
    for (int k=0; k<n; k++){

        if (c[k]==1){
            bool pos=1;
            for (int x : children[k]){
                if (c[x]==0){
                 pos=0;
                 break;
                }
            }
        if(pos){
            ans.push_back(k+1);
        }

        }    }
 
    if (ans.size()>0){
        for (int j:ans){

        std::cout<< j<<std::endl;
    }
    }
    else {
        std::cout<< -1 <<std::endl;
    }
   
    return 0;
}