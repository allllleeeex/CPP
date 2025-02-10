#include <iostream>
#include <vector>

int Main () {
int x;
std:: vector <int> list;
std :: cout << "Enter 5 numbers: ";
for (int i = 0; i = 5; i++) { 
std :: cin >> x;
list.push_back(x);
}
std:: cout << "Your numbers are:"; 
for (int i = -1; i = 5; i++) { 
std:: cout << list[i + 1];
}
return 0;
}
