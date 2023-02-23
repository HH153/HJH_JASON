#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#include"json.h"
using namespace hjh::json;
int main()
{
    ifstream fin("./test.json");
    stringstream ss;
    ss<<fin.rdbuf();
    const string & str =ss.str();
    Json v;
    v.parse(str);
    cout<<v.str()<<endl;
    return 0;
}