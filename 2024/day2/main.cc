#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int read(std::vector<std::vector<int>> &numbers) {
  std::ifstream file("input.txt");

  if (!file.is_open()) {
    std::cerr << "Error: could not open the file." << std::endl;
    return 1;
  }

  std::string line;

  int count = 0;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<int> row;
    int num;
    count++;

    while (iss >> num) {
      row.push_back(num);
    }

    numbers.push_back(row);
  }

  file.close();

  return 0;
}
bool isSafeReport(const std::vector<int> &row) {
  bool increasing = true;
  bool decreasing = true;

  for (int i = 0; i + 1 < row.size(); i++) {
    int diff = abs(row[i] - row[i + 1]);

    if (diff < 1 || diff > 3) {
      return false;
    }

    if (row[i] > row[i + 1]) {
      increasing = false;
    }

    if (row[i] < row[i + 1]) {
      decreasing = false;
    }

    if (!increasing && !decreasing) {
      return false;
    }
  }

  return true;
}

// Function to check if a report can be made safe by removing one level
bool canBeMadeSafe(const std::vector<int> &report) {
  for (size_t i = 0; i < report.size(); i++) {
    // Create a modified report with the i-th level removed
    std::vector<int> modifiedReport = report;
    modifiedReport.erase(modifiedReport.begin() + i);

    // Check if the modified report is safe
    if (isSafeReport(modifiedReport)) {
      return true;
    }
  }
  return false; // No single removal makes the report safe
}

int main() {
  std::vector<std::vector<int>> matrix;
  int count = 0;
  read(matrix);

  for (const auto &row : matrix) {
    if (isSafeReport(row) || canBeMadeSafe(row))
      count++;
  }
  std::cout << "Results: " << count << std::endl;
  return 0;
}
