#include<bits/stdc++.h>
#include "streak_tracker.h"
#include<fstream>
#include<ctime>
#include<nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

static const string STREAK_FILE="data/streak.json";

static string getToday()
{
    time_t current=time(nullptr);
    tm* t=localtime(&current);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", t);
    return string(buffer);
}

static string getYesterday()
{
    time_t yesterday=time(nullptr)-86400;
    tm* t=localtime(&yesterday);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", t);
    return string(buffer);
}

static json loadStreak()
{
    json defaultData={
        {"streak",0},
        {"last_date",""},
        {"longest_streak",0}
    };

    ifstream file(STREAK_FILE);
    if(!file.is_open()) return defaultData;

    string content((istreambuf_iterator<char>(file)),
    istreambuf_iterator<char>());

    if(content.empty()) return defaultData;

    json j=json::parse(content,nullptr,false);

    if(j.is_discarded())
    {
        cerr<<"\033[31m⚠️ streak.json corrupted. Resetting.\033[0m"<<endl;
        return defaultData;
    }

    return j;
    
}




// int main()
// {
//    cout<< getToday();
// }