#include <iostream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> DynamicCountCoins(vector<int> coins, int val) {
    vector<int> results(val + 1, 999999999);
    results[0] = 0;
    vector<vector<int>> answers(val + 1, vector<int>(coins.size() + 1, 0));

    for (int i = 1; i <= coins.size(); ++i) {
        for (int j = coins[i - 1]; j <= val; ++j) {
            if (1 + results[j - coins[i - 1]] < results[j]) {
                results[j] = 1 + results[j - coins[i - 1]];
                answers[j] = answers[j - coins[i - 1]];
                ++answers[j][i - 1];
            }
        }
    }
    return answers;
}

int main(int argc, char* argv[]) {
    int test = atoi(argv[1]);
    int denomNum = atoi(argv[2]);
    string intArray = argv[3];
    vector<int> coins;
    int savedComma = -99;
    string itemName;

    for (int i = 0; i < denomNum; ++i) {
        if (savedComma != -99) {		
            intArray = intArray.substr(savedComma);
        }
        size_t commaPos = intArray.find(",");
        if (i == 0) {
            itemName = intArray.substr(2, commaPos - 2);
        }
        else if (i == denomNum - 1) {
            size_t bracketPos = intArray.find("]");
            itemName = intArray.substr(0, bracketPos);
        }
        else {
            itemName = intArray.substr(0, commaPos);
        }
        string itemPrice = (intArray.substr(commaPos + 1));
        coins.push_back(stoi(itemName));
        savedComma = commaPos + 1;
    }
    cout << test << "\n";

    vector<vector<int>> fin;
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    fin = DynamicCountCoins(coins, test);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    for (int i = 0; i < coins.size(); ++i) {
        for (int j = 0; j < fin[test][i]; ++j) {
            cout << coins[i] << " ";
        }
    }

    std::cout << "\n" << duration.count() << " ns\n\n";
}
