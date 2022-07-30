#include <bits/stdc++.h>

using namespace std;

const char *delim=" ";

vector<string> processLogs(vector<string> logs, int threshold) {
    map<unsigned int, int> out_map;
    for (auto s:logs){
        char *token = strtok(const_cast<char *>(s.c_str()), delim); 
        string sender_id=string(token);
        token = strtok(nullptr, delim); 
        string receiver_id=string(token);
        //cout<<sender_id<<", "<<receiver_id<<endl;
        const unsigned int rec_id=stoul(receiver_id);
        const unsigned int sen_id=stoul(sender_id);
        out_map[rec_id] += 1;
        if (receiver_id!=sender_id)
            out_map[sen_id] += 1;
    }
    vector<string> out_str;
    for (auto s:out_map){
        if (s.second >= threshold){
            out_str.push_back(to_string(s.first));
        }
    }
    
    return out_str;
}

int main(){
    vector<string> input={"10 10 55", "10 4 55", "4 4 655", "100 3 4455"};
    vector<string> out=clasificar (input, 0);
    
    for(auto s:out)
        cout<<s<<endl;
    cout<<endl;    
        
    return 0;
}


