#include "ios_include.hpp"

/*
 * @brief 给你两个二进制字符串，返回它们的和（用二进制表示）
 * 按位从后往前加即可,O(n)
 */
char add(char a, char b, int &cax){
    if(cax == 0){
        if(a == '1' && b == '1'){
            cax = 1;
            return '0';
        }else if((a == '0' && b == '1') || (a == '1' && b == '0')){
            cax = 0;
            return '1';
        }else if(a == '0' && b == '0'){
            cax = 0;
            return '0';
        }
    }else if(cax == 1){
        if(a == '1' && b == '1'){
            cax = 1;
            return '1';
        }else if((a == '0' && b == '1') || (a == '1' && b == '0')){
            cax = 1;
            return '0';
        }else if(a == '0' && b == '0'){
            cax = 0;
            return '1';
        }
    }

    return '0';
}

string add_binary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    string ret;
    int cax = 0;
    for(;i >= 0 && j >=0;i--,j--){
        ret = string(1, add(a[i], b[j], cax)) + ret;
    }

    while(i >= 0){
        ret = string(1, add(a[i--], '0', cax)) + ret;
    }

    while(j >= 0){
        ret = string(1, add(b[j--], '0', cax)) + ret;
    }

    if(cax == 1){
        ret = string(1, '1') + ret;
    }

    return ret;
}


