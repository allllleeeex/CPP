#include <iostream>
#include <fstream> 

int main() {
int x;
std::ifstream num_file;
num_file.open("numbers.txt");
std::getline(num_file, x);
std::cout << "There are " <<  x << "numbers in the file.";
for (int i = 0; i < x; i ++) {
int y;
std::getline(num_file, y);
std:: cout << y;
}

}