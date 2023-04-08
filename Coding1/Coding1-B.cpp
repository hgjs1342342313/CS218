#include<iostream>
#include<map>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int replace_position = 0;
int main() {
	int n = 0;
	cin >> n;
	// datastructure1: vec. the first element is the price, the second element is the index
	vector<pair<int, int>> vec; //vector is used to store the index and price of the candel
	// datastructure2: mp. The use the index to find the price
	map<int, int> mp; // map is to find the price of a candel by index
	for (int i = 0; i < 9; i++) {
		int p = 0;
		cin >> p;
		vec.emplace_back(p, i+1);
		mp.emplace(i + 1, p);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (vec[i].first == vec[j].first && vec[i].second < vec[j].second) {
				// swap first element
				// as the second element is the index, we can simply change them
				auto temp = vec[i];
				vec[i] = vec[j]; vec[j] = temp;
			}
		}
	}
	//datastructure3: nar. numbers and rest money
	int num = n / vec[0].first; // first is the price
	int rest = n % vec[0].first; // num is the number of candels you can buy, rest is the rest money you have
	int answer[10005];// answer is the array to store the answer
	for (int i = 0; i < num; i++) {
		answer[i] = vec[0].second; //second is the index and vec[0] is the local best solution
	}
	// find from 9 to 0. use the bigger number to replace the number
	for (int i = 0; i < 9; i++) {
		int change = mp[9 - i];// change is the price that 9-i candel cost
		int j = num;
		while (j > 0) {
			if (rest + vec[0].first - change >= 0) {
				answer[replace_position] = (9 - i);
				// if you change a candel, update the rest money you have.
				rest = rest + vec[0].first - change;
				// and don't forget to update the position
				replace_position++;
			}
			j--;
		}
		// if you have no money, you can stop changing since every step you take is further than before and smaller than before
		if (rest == 0) {
			break;
		}
	}
	// you can use num as the label to stop since the length of your number will no longer than num
	for (int i = 0; i < num; i++) {
		cout << answer[i];
	}
	return 0;
}