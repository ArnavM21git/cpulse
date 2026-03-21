#include<bits/stdc++.h>
using namespace std;

int main(int argc,char* argv[])
{
    if(argc<2)
    {
        cout<<"\033[31mError: No command given\033[0m"<<endl;
        cout<<"\033[31mUsage: cpulse ...... [contests|streak|push]\033[0m"<<endl;
        return 0;
    }

    string cmd=argv[1];

    if (cmd == "contests") {
        cout << "Fetching contests..." << endl;
    } else if (cmd == "streak") {
        cout << "Showing streak..." << endl;
    } else if (cmd == "push") {
        cout << "Pushing to GitHub..." << endl;
    } else {
        cout << "Unknown command: " << cmd << endl;
    }

    return 0;
}

