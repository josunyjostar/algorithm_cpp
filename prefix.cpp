#include "Header.h"

bool compare(std::string a, std::string b) { return a.length() < b.length(); }

void commonPrefix() {
    using namespace std;
    vector<string> vec = {};

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        string input1;
        cin >> input1;
        vec.push_back(input1);
    }

    sort(vec.begin(), vec.end(), compare);
    auto &stand = vec[0];
    int idx = 0;
    string prefix = "";

    for (int i = 0; i < vec[0].length(); ++i) {
        bool isPrefix = false;
        string temp = "";
        for (int j = 1; j < vec.size(); ++j) {
            if (vec[0][idx] == vec[j][idx]) {
                isPrefix = true;
                temp = vec[0][idx];
            } else {
                isPrefix = false;
            }
        }
        if (isPrefix) {
            prefix += temp;
            temp = "";
            idx++;
            isPrefix = false;
        }
    }

    cout << prefix;
}
