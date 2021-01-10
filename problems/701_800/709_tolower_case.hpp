#include <string>
using std::string;

string toLowerCase(string str) {
    for(int i = 0;i < str.size();i ++){
        if(str[i] <= 'Z' && str[i] >= 'A'){
            str[i] = str[i] + ('A' - 'a');
        }
    }

    return str;
}