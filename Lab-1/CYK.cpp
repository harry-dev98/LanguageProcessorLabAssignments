#include<bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cout<<"word: ";cin>>w;
    int npr, n = w.size();
    cout<<"no of prod. rules: ";cin>>npr;
    map<string, vector<string>> ProdRules;
    for(int i=0; i<npr; i++){
        string ip1, ip2;
        cin>>ip1>>ip2;
        ProdRules[ip1].push_back(ip2);
    }
    vector<vector<set<string>>>Mat(n, vector<set<string>>(n));
    for(int i=0; i<n; i++){
        for(auto _pr: ProdRules){
            for(auto _ip2: _pr.second){
                if(_ip2.size() == 1 && _ip2[0] == w[i]){
                    Mat[i][0].insert(_pr.first);
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(auto _: Mat[i][0]){
            cout<<_<<", ";
        }       cout<<"\n";
    }
    cout<<"\n";
    for(int len=2; len<=n; len++){
        for(int start=0; start<n-len+1; start++){
            for(int part=1; part<len; part++){
                string tmpS = w.substr(start, len);
                set<string> tmpVS1 = Mat[start][part-1];
                set<string> tmpVS2 = Mat[part][len - part-1];
                for(string _s1: tmpVS1){
                    for(string _s2: tmpVS2){
                        string tmp = _s1 + _s2;
                        for(auto _pr: ProdRules){
                            for(auto _ip2: _pr.second){
                                if(_ip2 == tmp){
                                    Mat[start][len-1].insert(_pr.first);
                                    break;
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    for(int len=1; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            for(auto __: Mat[i][len-1]){
                cout<<__;
            }
        cout<<"-";
        }cout<<"\n";
    }
    cout<<"\n";

    if(Mat[0][n-1].size() > 0){
        cout<<"exits\n";
    }

    return 0;
}

/*
baaba
8
S AB
S BC
A BA 
A a
B CC
B b
C AB
C a
*/

//BCS -> 