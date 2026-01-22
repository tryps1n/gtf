#include "string"
#include "iostream"
#include "vector"
#include "./lib.cpp"

using namespace std;

int main(int argc, char* argv[]){

    vector<string> q;

    for(int i=1; i<argc; ++i){
        q.push_back((string){argv[i]});
    }
    
    string url = url_encode(&q[0], argc-1);

    string res_json = fetch_url(url);

    size_t start = res_json.find("\"");
    size_t end = res_json.find("\"", start+1);

    string result = res_json.substr(start+1, end-start-1);

    cout << result << endl;

    return 0;
}