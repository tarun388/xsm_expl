// #include <iostream>
// #include <fstream>
// #include <string>
// #include <map>
// #include <file>
#include <bits/stdc++.h>
using namespace std;

int line=0;

pair <int,int> detector(string str){
    if(str[0] != 'L' || str[str.size()-1] != ':') return {0,0};
    int label=0;
    for(auto it = str.begin()+1;it != str.end()-1;it++){
        if(*it < '0' || *it > '9') return {0,0};
        label = label*10 + *it - '0';
    }
    return {label,2056 + 2*(line)};
}

int checker1(string str){
    if(str[0] != 'L' || str[str.size()-1] != ':') return 0;
    // int label=0;
    for(auto it = str.begin()+1;it != str.end()-1;it++){
        if(*it < '0' || *it > '9') return 0;
    }
    return 1;
}

pair <int,int> checker2(string str){
    if(str[0] == 'J' && str[1] == 'M' && str[2] == 'P' && str[3] == ' ' && str[4] == 'L'){
        int label = 0;
        for(auto it = str.begin()+5;it != str.end();it++){
            label = label*10 + (*it) - '0';
        }
        return {1,label};
    }
    // cout << "hi";
    auto it = str.begin();
    for(;it != str.end() && *it != ',';it++)
    if(it == str.end()) return {0,0};
    // cout << *it;
    it++;
    // cout << *it;
    it++;
    // cout << *it;
    if(*it != 'L') return {0,0};
    // cout << "hi";
    it++;
    int label=0;
    for(;it != str.end();it++){
        if(*it < '0' || *it > '9') return {0,0};
        label = label*10 + *it - '0';
    }
    // cout << label;
    return {2,label};
}

int main(int argc,char **argv){
    if(argc < 3) exit(1);
    ifstream fs;
    ofstream ft;
    fs.open(argv[1]);
    string str;
    map <int,int> label;
    int ret;
    for(int i=0;i<8;i++){
        getline(fs,str);
    }
    // line = 0;
    while(getline(fs,str)){
        pair <int,int> ret = detector(str);
        line++;
        if(ret.second){
            label.insert(ret);
            line--;
        }
    }
    fs.close();
    // printf("done\n");
    // ft << "done\n";
    fs.open(argv[1]);
    ft.open(argv[2]);
    // ft <<"d";
    while(getline(fs,str)){
        // pair <string,int> ret = checker(str);
        // line++;
        if(!checker1(str)){
            pair <int,int> adrs = checker2(str);
            if(adrs.first == 1){
                ft << "JMP " << label[adrs.second] << "\n";
            }
            else if(adrs.first == 2){
                 // printf(stdout,"hi");
                auto it = str.begin();
                for(;it != str.end() && *it != ',';it++){
                    ft << *it;
                }
                ft << *it;
                it++;
                ft << *it;
                it+=2;
                int val=0;
                for(;it != str.end();it++){
                    val = val*10 + *it - '0';
                }
                ft << label[val] << "\n";
            }
            else{
                ft << str << "\n";
            }
        }
    }
}
