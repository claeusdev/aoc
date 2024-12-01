#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

int largest(const std::vector<int>&a){
	auto maxIter = std::max_element(a.begin(), a.end());
	return *maxIter;
}

int result_two(const std::vector<int>& a, const std::vector<int>& b){
	std::vector<int>::size_type vec_size = a.size();
	std::unordered_map<int, int> mp;
	int sum_of_diffs = 0;

	for (int i = 0; i < vec_size; i++) {
		mp[b[i]]++;
	}

	for (int i = 0; i < vec_size; i++) {
		sum_of_diffs += a[i] * mp[a[i]];
	}

	return sum_of_diffs;
}

int result_one(const std::vector<int>& a, const std::vector<int>& b){
	std::vector<int>::size_type vec_size = a.size();
	int sum_of_diffs = 0;

	for (int i = 0; i < vec_size; i++) {
		sum_of_diffs += abs(a[i] - b[i]);
	}

	return sum_of_diffs;
}

int main(){
	std::ifstream inputFile("input.txt");
	if (!inputFile.is_open()) {
		std::cerr << "failed to open file\n";
		return 1;
	}

	std::vector<int> first;
	std::vector<int> second;

	int a, b;
	while (inputFile >> a >> b) {
		first.push_back(a);
		second.push_back(b);
	}

	/*std::sort(first.begin(), first.end());*/
	/*std::sort(second.begin(), second.end());*/

	/*int res = result_one(first, second);*/
	int res = result_two(first, second);

	std::cout << "Final: " << res << std::endl;

	inputFile.close();
	return 0;
}
