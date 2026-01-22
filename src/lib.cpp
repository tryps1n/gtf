#include "string"
#include "iostream"
#include "curl/curl.h"
#include "vector"

using namespace std;

size_t call_back(void* byte, size_t n, size_t byte_size, void* dat){
    
    string* buffer = (string*) dat;
    buffer->append((char*) byte, byte_size);
    return byte_size;
}

string url_encode(string* queries, int n){
    string url = "https://translate.googleapis.com/translate_a/single""?client=gtx&sl=de&tl=en&dt=t&q=";
    url += *(queries);
    if(n>1){
        for(int i=1; i<n; ++i){
            url += "%20" + *(queries+i);
        }
    }
    return url;
}
string fetch_url(const string& url){
    CURL* curl = curl_easy_init();

    string response;

    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, call_back);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "gtf-cli/1.0");

        CURLcode res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

    }
    return response;
}

