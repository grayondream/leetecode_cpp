#include "ios_include.hpp"

vector<int> plusOne(vector<int>& digits) {
    char cax = 1;
    for(auto it = digits.rbegin();it != digits.rend();it ++){
        int val = *it + cax;
        *it = val % 10;
        cax = val / 10;
    }

    if(cax != 0){
        digits.insert(digits.begin(), cax);
    }

    return digits;
}