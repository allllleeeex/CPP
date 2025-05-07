#include <iostream>
#include <fstream> 

int getShiftKey(ifstream& file) {
    int shift;
    file >> shift;
    return shift;

void DecryptedMessage(ifstream file, shift) {
        string message;
        (char x: file) {
            char = char + shift
        }
    }


}


int main() { 
    ifstream file("encrypted_secret.txt");
    int shift = getShiftKey(file);
    DecryptedMessage(file, shift);
    file.close();
    return 0;
}

return 1;