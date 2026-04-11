#pragma once
#include <string>
#include <vector>

using namespace std;

string fetchURL(const string& url);//public api so this cf
string fetchURLWithHeaders(const string& url,const vector<pair<string,string>>& headers);//private api so this github
string postURL(const string& url, const string& body, const vector<pair<string,string>>& headers);
string patchURL(const string& url, const string& body, const vector<pair<string,string>>& headers);