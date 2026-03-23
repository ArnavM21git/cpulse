#include<bits/stdc++.h>
#include<curl/curl.h> //libcurl header
#include<nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;//nlohmann is namespace and json class



static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
{
     output->append((char*)contents, size * nmemb);
      return size * nmemb;
}

string fetchURL(string url)
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
    json j=json::parse(fetched);

    auto contests=j["result"];
    int c=0;
    for (auto& contest : contests)
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


}