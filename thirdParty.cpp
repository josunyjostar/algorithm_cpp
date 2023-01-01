#include "thirdParty.h"


vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int stringToInt(string str) { 
    int ans = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
            ans = ans * 10 + str[i] - '0';
        } else {
            return -1;
        }
    }
    return ans; 
}

vector<vector<string>> fileRead(string fileName) {
    ifstream readFile;
    vector<vector<string>> inputs;
    readFile.open(fileName);

    if (readFile.is_open()) {
        while (!readFile.eof()) {
            string str;
            getline(readFile, str);
            inputs.push_back(split(str, ' '));
        }
        readFile.close();
    }

    return inputs;
}