#include<bits/stdc++.h>
#include<curl/curl.h> //libcurl header
#include<nlohmann/json.hpp>
#include "contest_fetcher.h"

using namespace std;
using json = nlohmann::json;//nlohmann is namespace and json class



static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
{
     output->append((char*)contents, size * nmemb);
      return size * nmemb;
}

string fetchURL(string url)//syntax for string making of whole webpage
{
    CURL* curl = curl_easy_init();
    string response = "";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
     return response;
}

void fetchContests()
{
    string fetched=fetchURL("https://codeforces.com/api/contest.list?gym=false");//string as json
    
    if (fetched.empty()) {
        cout << "\033[31m❌ Failed to fetch contests. Check internet.\033[0m" << endl;
        return;
    }


    json j=json::parse(fetched);

    auto contests=j["result"]; //contests=[{},{},{}]
    int c=0;

    cout << "\033[36m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m" << endl;
    cout << "\033[35m  🏆  Upcoming Codeforces Contests\033[0m" << endl;
    cout << "\033[36m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m" << endl;


    for (auto &contest:contests)
    {
        if(c==5) break;
        string name=contest["name"];
        string phase=contest["phase"];
        if(phase=="BEFORE")
        {
            cout<<name<<endl;
            c++;
        }
    }

    if (c == 0) cout<<"  No upcoming contests found."<<endl;
    cout<<"\033[36m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m"<<endl;


}