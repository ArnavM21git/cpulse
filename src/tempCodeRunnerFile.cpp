#include<bits/stdc++.h>
#include "streak_tracker.h"
#include<fstream>
#include<ctime>
// #include<nlohmann/json.hpp>

using namespace std;
// using json=nlohmann::json;


static string getToday()
{
    time_t current=time(nullptr);
    tm* t=localtime(&current);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", t);
    return string(buffer);
}
int main()
{
   cout<< getToday();
}