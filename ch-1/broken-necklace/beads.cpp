/*
ID: your_id_here
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int find_first(string s, const char c)
{
    if(s.find_first_of(c)==string::npos) return s.size();
    return s.find_first_of(c);
}

int find_last(string s, const char c)
{
    if(s.find_last_of(c)==string::npos) return -1;
    return s.find_last_of(c);
}

int main() {
    ofstream fout ("beads.out",ios::trunc);
    ifstream fin ("beads.in");
    int n;
    string beads;
    fin>>n;
    fin>>beads;

    int maxCount=0;

    for (int i = 0; i < n; ++i)
    {
        /* code */
        string newBeads = beads.substr(i)+beads.substr(0,i);

        auto lastB = find_last(newBeads,'b');
        auto lastR = find_last(newBeads,'r');

        newBeads.replace(newBeads.begin()+min(lastB,lastR)+1,newBeads.end(),"");

        auto firstB = find_first(newBeads,'b');
        auto firstR = find_first(newBeads,'r');

        auto current=abs(firstB-firstR)+(n-1-min(lastB,lastR));
        if(maxCount<current) maxCount=current;
    }

        
    
    fout<<maxCount<<endl;
    return 0;
}