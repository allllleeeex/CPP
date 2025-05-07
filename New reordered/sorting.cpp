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
    return nums[smallest];  // Return the smallest number, not the index
}

std::vector<int> sort(std::vector<int> num_list) {
    std::vector<int> sorted_list;

    while (!num_list.empty()) {
        int smallest = find_lowest(num_list);
        sorted_list.push_back(smallest);
        
        // Remove the smallest number from the original list
        auto it = std::find(num_list.begin(), num_list.end(), smallest);
        if (it != num_list.end()) {
            num_list.erase(it);
        }
    }

    return sorted_list;
}

int main() {
    std::string inputFile, outputFile;

    std::cout << "Enter the input filename: ";
    std::cin >> inputFile;

    std::vector<int> num_list = read_numbers(inputFile);
    std::vector<int> sorted_list = sort(num_list);
    int smallest = find_lowest(num_list);  // Use num_list here instead of inputFile

    std::cout << "Here are the ordered numbers from " << inputFile << ": \n";
    for (int num : sorted_list) {
        std::cout << num << " ";
    }

    std::cout << "\nThe smallest number is " << smallest << ".\n";

    std::cout << "\nWhat file would you like to move the sorted values to?: ";
    std::cin >> outputFile;

    std::ofstream newFile(outputFile);  // Open the output file
    for (int num : sorted_list) {
        newFile << num << "\n";  // Write sorted numbers to the output file
    }

    newFile.close();  // Close the output file
    return 0;
}