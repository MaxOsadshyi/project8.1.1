#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

size_t Count(char* str) {
    size_t count = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len - 2; ++i) {
        if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c') &&
            (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'c') &&
            (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'c')) {
            count++;
        }
    }

    return count;
}

char* Change(char* str) {
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len - 2) {
        if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c') &&
            (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'c') &&
            (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'c')) {
            strcat(t, "**");
            t += 2;
            i += 3;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    while (i < len) {
        *t++ = str[i++];
        *t = '\0';
    }

    // Null-terminate the final string
    *t = '\0';

    // Copy the modified string back to the original
    strcpy(str, tmp);

    return tmp;

    // Deallocate the allocated memory
    delete[] tmp;
    
    

   
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'abc'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}