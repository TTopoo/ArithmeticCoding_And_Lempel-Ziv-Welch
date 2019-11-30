#include <cstring>
#include "Coding.hpp"

Coding::Coding(string symbol,vector<double> prob)
{
    vector<double> tmp(3);
    for (int i = 0; i < prob.size();++i) {
        m[symbol[i]].resize(3);
        m[symbol[i]][0] = prob[i];
        if (i == 0) {
            m[symbol[i]][1] = 0;
            m[symbol[i]][2] = prob[i];
        }
        else {
            m[symbol[i]][1] = m[symbol[i-1]][2];
            m[symbol[i]][2] = m[symbol[i-1]][2] + prob[i];
        }
    }
#if _DEBUG
    for (int i = 0; i < prob.size(); ++i)
        cout << m[symbol[i]][1] << " ";
    cout << "\n";
    for (int i = 0; i < prob.size(); ++i)
        cout << m[symbol[i]][2] << " ";
    cout << "\n";
#endif
}

Coding::Coding(string symbol)
{
    cnt = 258;
    for (auto i : symbol) {
        string tmp(1, i);
        dict1[tmp] = int(i);
    }
}

Coding::Coding(vector<int> input)
{
    cnt = 258;
    for (auto i : input) {
        dict2[i] = char(i);
        code.push_back(i);
    }
}

void Coding::ArithmeticCoding(string input, vector<pair<char,vector<double>>> *ans)
{
    double low = 0.0, high = 1.0, range = 1.0;
    for (auto i : input) {
        high = low + range * m[i][2];
        low = low + range * m[i][1];
        range = high - low;
        vector<double> a;
        a.push_back(low);   a.push_back(high);  a.push_back(range);
        ans->push_back(make_pair(i,a));
    }
}

void Coding::LempelZivWelchCoding(string input, vector<int>* output)
{
    vector<string> t(2);
    t[0] = input[0];

    for (int i = 1; i < input.length();++i) {
        t[1] = input[i];
        string tmp=t[0]+t[1];
        
        auto it = dict1.find(tmp);
        if (it != dict1.end()) {//找到了
            t[0] = t[0] + t[1];
        }
        else {
            dict1[tmp] = cnt++;
            output->push_back(dict1.find(t[0])->second);
            t[0] = t[1];
        }
    }
    output->push_back(dict1.find(t[0])->second);
}

void Coding::LempelZivWelchDecoding(vector<int> input, string* output)
{
    string s="";
    int k;

    for (int i = 0; i < input.size(); ++i) {
        k = input[i];
        string entry = dict2[k];
        output->insert(output->length(), entry);
        if (s!="") {
            dict2[cnt++] = s + entry[0];
        }
        s = entry;
    }
}

void Coding::PrintDict1()
{
    for (auto i : dict1)
        if (i.second >= 258)
            cout << i.first << " " << i.second<<endl;
}

void Coding::PrintDict2()
{
    for (auto i : dict2)
        if (i.first >= 258)
            cout << i.first << " " << i.second << endl;
}
