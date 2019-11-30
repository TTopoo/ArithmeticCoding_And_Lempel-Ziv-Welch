#include <iostream>
#include "Coding.hpp"
using namespace std;

int main()
{
    vector<int> ans3;

    auto X1 = [] {
        cout << endl << "\t\t\tQ1:\n";
        string A1 = "ABCDEF$", A2 = "ABCD";
        string in1 = "CAEE$", in2 = "CADACDB";
        vector<double> prob1 = { 0.2,0.1,0.2,0.05,0.3,0.05,0.1 };
        vector<double> prob2 = { 0.1,0.4,0.2,0.3 };

        Coding sample1(A1, prob1);
        Coding sample2(A2, prob2);

        vector<pair<char, vector<double>>> ans1, ans2;

        sample1.ArithmeticCoding(in1, &ans1);
        for (auto i : ans1) {
            cout << i.first << " "
                << i.second[0] << " " << i.second[1] << " " << i.second[2] << "\n";
        }

        sample2.ArithmeticCoding(in2, &ans2);
        cout << endl;
        for (auto i : ans2) {
            cout << i.first << " "
                << i.second[0] << " " << i.second[1] << " " << i.second[2] << "\n";
        }
    };

    auto X2 = [&ans3] {
        cout << endl << "\t\t\tQ2:\n";
        string A3 = "/WED/WE/WEE/WEB/";
        Coding sample3(A3);
        
        sample3.LempelZivWelchCoding(A3, &ans3);
        for (auto i : ans3)
            cout << i << " ";
        cout << endl;
        sample3.PrintDict1();
    };
    auto X3 = [&ans3] {
        cout << endl << "\t\t\tQ3:\n";
        Coding sample4(ans3);
        string ans4 = "";
        sample4.LempelZivWelchDecoding(ans3,&ans4);
        cout << ans4 << endl;
        sample4.PrintDict2();
    };
    X1();
    X2();
    X3();
}
