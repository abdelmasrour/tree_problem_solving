#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */
int cmpt=0;

class Checker{
public:
      // complete this method
    static int comparator(vector <int> a, vector <int> b)  {
    
    if ( (a[1]<b[1])||((a[1]==b[1]) && (a[0]<b[0]))){
        return -1;
    }
    else {
        return 1;
    }
    }
};
bool compare(vector <int> a, vector <int> b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
int luckBalance(int k, vector<vector<int>> contests) {
 sort(contests.begin(), contests.end(), compare);
 int sum =0;
 for (int i=0;i<k;i++){
     sum+=contests.at(i).at(0);
 }
 cout << sum<<endl;
int n=contests.size();
for (int j=0;j<n;j++){
    cout << contests.at(j).at(1) << endl;
    if (contests.at(j).at(1)==0){
        cmpt=j;
        break;
    }
}
int j=cmpt;
int diff =0;
if(j==0){
for(int x=k;x<n;x++){
    diff -= contests.at(x).at(0);
}
}
else {
    for(int x=k;x<j;x++){
    diff -= contests.at(x).at(0);
}

}
if (j<n && j!=0){
for (int p=j;p<n;p++){

    sum+=contests.at(p).at(0);
}}
cout << "diff" << diff<<endl;
cout << "sum" << sum <<endl;
cout<<sum+diff <<endl; 
return sum + diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> contests(n);

    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        string contests_row_temp_temp;
        getline(cin, contests_row_temp_temp);

        vector<string> contests_row_temp = split(rtrim(contests_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int contests_row_item = stoi(contests_row_temp[j]);

            contests[i][j] = contests_row_item;
        }
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
