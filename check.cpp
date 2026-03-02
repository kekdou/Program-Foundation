#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int count = 0;
    while (count < 500) {
        count++;
        system("data.exe > input.txt");
        system("special_num.exe < input.txt > special_num.txt");
        system("test.exe < input.txt > test.txt");
        if (system("fc /b special_num.txt test.txt > nul 2>&1")) {
            cout << "Wrong #" << count << endl;
            break;
        } else {
            cout << "Passed #" << count << endl;
        }
    }
    return 0;
}