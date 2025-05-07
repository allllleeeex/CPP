#include <iostream>
#include <fstream> 
#include <string>

int getShiftKey(std::ifstream& file) {
    int shift;
    file >> shift;
    return shift;
}

void DecryptedMessage(std::ifstream& file, int16_t shift) {
    char ch;
    while (file.get(ch)) {
        std::cout << (char)(ch - shift);
    }
}





int main() { 
    std::ifstream file("encrypted_secret.txt");
    int shift = getShiftKey(file);
    DecryptedMessage(file, shift);
    file.close();
    return 0;
}

