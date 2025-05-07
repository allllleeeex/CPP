#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> read_numbers(const std::string& filename) {
    std::ifstream num_file(filename);
    int amount;
    num_file >> amount;
    std::vector<int> num_list;
    int y;
    
    for (int i = 0; i < amount; i++) {
        num_file >> y;
        num_list.push_back(y);
    }
    num_file.close();
    return num_list;
}

int find_lowest(const std::vector<int>& nums) {
    int smallest = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[smallest]) {
            smallest = i;
        }
    }
    return smallest;
}

std::vector<int> sort(std::vector<int> num_list) {
    std::vector<int> sorted_list;

    while (!num_list.empty()) {
        int smallest = find_lowest(num_list);
        sorted_list.push_back(num_list[smallest]);
        num_list.erase(num_list.begin() + smallest);
    }

    return sorted_list;
}

int main() {
    std::string inputFile, outputFile;

    std::cout << "Enter the input filename: ";
    std::cin >> inputFile;

    std::vector<int> num_list = read_numbers(inputFile);
    std::vector<int> sorted_list = sort(num_list);

    std::cout << "Here are the ordered numbers from " << inputFile << ": \n";
    for (int num : sorted_list) {
        std::cout << num << " ";
    }

    std::cout << "\nWhat file would you like to move the sorted values to?: ";
    std::cin >> outputFile;

    std::ofstream newFile(outputFile);
    for (int num : sorted_list) {
        newFile << num << "\n";
    }

    newFile.close();
    return 0;
}