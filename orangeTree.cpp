#include "Header.h"
#include "thirdParty.h"

void orangeTree() {
    auto inputs = fileRead("./in5.txt");

    const int n = stringToInt(inputs[0][0]);
    const int m = stringToInt(inputs[0][1]);
    const int TreeCnt = stringToInt(inputs[0][2]);
    const int side = stringToInt(inputs[0][3]);

    const int len = inputs.size();

    vector<int> x, y;
    for (int i = 1; i < len; ++i) {
        x.push_back(stringToInt(inputs[i][0]));
        y.push_back(stringToInt(inputs[i][1]));
    }

    int maxOrange = INT_MIN;
    const int xLen = x.size();
    const int yLen = y.size();

    for (int i = 0; i < xLen; ++i) {
        for (int j = 0; j < yLen; ++j) {
            int orangeCnt = 0;
            for (int s = 0; s <= TreeCnt; ++s) {
                if (x[s] >= x[i] && x[s] <= x[i] + side) {
                    if (y[s] >= y[j] && y[s] <= y[j] + side) {
                        ++orangeCnt;
                    }
                }
            }
            maxOrange = max(maxOrange, orangeCnt);
        }
        cout << x[i] << " °Ë»öÁß..." << endl;
    }

    cout << maxOrange;
}

  