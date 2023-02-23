#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#include"json.h"
using namespace hjh::json;
string parse_json(const string& input) 
{
    string output;
    int indent_level = 0;
    bool in_string = false;
    for (char c : input) {
        if (c == '\"') {
            in_string = !in_string;
        }
        if (in_string) {
            output += c;
            continue;
        }
        switch (c) {
            case '{':
            case '[':
                output += c;
                output += '\n';
                indent_level += 2;
                output.append(indent_level, ' ');
                break;
            case '}':
            case ']':
                output += '\n';
                indent_level -= 2;
                output.append(indent_level, ' ');
                output += c;
                break;
            case ',':
                output += c;
                output += '\n';
                output.append(indent_level, ' ');
                break;
            default:
                output += c;
                break;
        }
    }
    return output;
}
int main()
{
    //将格式化数据压缩输出
    ifstream fin("./test.json");
    stringstream ss;
    ss<<fin.rdbuf();
    const string & str =ss.str();
    Json v;
    v.parse(str);
    cout<<v.str()<<endl;

    //将压缩数据格式化输出
    string output = parse_json(v.str());
    cout<<output<<endl;
    return 0;
}
