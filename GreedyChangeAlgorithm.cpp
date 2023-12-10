#include <iostream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

vector<int> answers;

int GreedyCountCoins(vector<int> coins, int val) {
	int count = 0;
	int i = coins.size() - 1;

	while (i >= 0 && coins[i] > val) {
		--i;
	}

	if (i >= 0) {
		count = 1 + GreedyCountCoins(coins, val - coins[i]);
		++answers[i];
	}
	return count;
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
		if(i == 0) {
			itemName = intArray.substr(2, commaPos -2);
		}
		else if(i == denomNum - 1) {
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

		for (int i = 0; i < coins.size(); ++i) {
			answers.push_back(0);
		}

		cout << test << "\n";
		
			std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
			int result = GreedyCountCoins(coins, test);
			std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::nano> duration = end - start;
			for (int i = 0; i < answers.size(); ++i) {
				for (int t = 0; t < answers[i]; ++t) {
					std::cout << coins[i] << " ";
				}
			}
			std::cout << "\n" << duration.count() << " ns\n\n";
			for (int i = 0; i < answers.size(); ++i) {
				answers[i] = 0;
			}
		
}