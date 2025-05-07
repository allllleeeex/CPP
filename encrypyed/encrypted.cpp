#include <iostream>
#include <fstream> 
#include <string>
int getShiftKey(ifstream& file) {
    int shift;
    file >> shift;
    return shift;
}

void DecryptedMessage(ifstream file, shift) {
    char ch;
    while (file.get(ch)) {
        cout << (char)(ch - shift);
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

