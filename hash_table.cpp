#include <iostream>
#include <climits>
#include <map>
#include <string>
#include <vector>
using namespace std;








int main()
{
    vector<string> magazine{"two","times","three","is","not","four"};
    vector<string> note{"two","times","two","is","four"};
    map < string,int> freq_magazine;
    map <string,int> freq_note;
    for (auto s:magazine){
        if (freq_magazine.count(s)){
            freq_magazine[s]++;
        }
        else{
            freq_magazine.insert({s,1});
        }
    }
    for (auto s:note){
        if (freq_note.count(s)){
            freq_note[s]++;
        }
        else{
            freq_note.insert({s,1});
        }
    }
    for (auto it = freq_note.begin(); it != freq_note.end(); ++it){
               if (freq_magazine.count(it->first)==0 ||freq_magazine[it->first]<it->second){
                cout << "NO"<<endl;
               }
               cout << "YES" <<endl;
    }

    cout << 5 << endl;
    return 0;
}