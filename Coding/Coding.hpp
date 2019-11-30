#pragma once
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<array>
#include<map>
using namespace std;
class Coding
{
private:
    map<char, vector<double>> m;
    map<string, int> dict1;
    map<int, string> dict2;
    int cnt = 258;
    vector<int> code;

public:
    Coding(string symbol, vector<double> prob);
    Coding(string symbol);
    Coding(vector<int> input);
    void ArithmeticCoding(string input, vector<pair<char, vector<double>>>* ans);
    void LempelZivWelchCoding(string input, vector<int>* output);
    void LempelZivWelchDecoding(vector<int> input, string* output);
    void PrintDict1();
    void PrintDict2();
};
