#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int CountCoins(vector<int> coins, int val) {
	
	if (val == 0) {
		return 0;
	}
	int q = 9999999;
	for (int i = 0; i < coins.size(); ++i) {
		if (val >= coins[i]) {
			q = min(q, 1 + CountCoins(coins, val - coins[i]));
		}
	}
	return q;
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

	if (coins.size() == denomNum) {

	cout << test << "\n";

		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		int answer = CountCoins(coins, test);
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::nano> duration = end - start;
		std::cout << answer << "\n" << duration.count() << " ns\n\n";
	
	}
}