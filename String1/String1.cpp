#include <iostream>
using namespace std;

void del(char*& str, int index) {
    int size = strlen(str);
    char* buff = new char[size];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == index) {
            continue;
        }
        buff[j] = str[i];
        j += 1;
    }
    delete[] str;
    str = buff;
}

void del_all(char*& str, char symbol) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size+1; i++) {
        if (str[i] != symbol) {
            str[j] = str[i];
            j += 1;
        }
    }
}

void insert(char*& str, int index, char symbol) {
    int size = strlen(str);
    char* buff = new char[size+2];
    int j = 0;
    for (int i = 0; i < index; i++) {
        buff[i] = str[i];
    }
    buff[index] = symbol;
    for (int i = index; i < size; i++) {
        buff[i + 1] = str[i];
    }
    delete[] str;
    str = buff;
}

void change(char*& str) {
    int size = strlen(str);
    for (int i = 0; i < size; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}

int find(char* str, char symbol) {
    int size = strlen(str);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == symbol) {
            count += 1;
        }
    }
    return count;
}

void check(char* str) {
    int size = strlen(str);
    int letters = 0;
    int numbers = 0;
    int symbols = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            numbers += 1;
        }
        else if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) {
            letters += 1;
        }
        else {
            symbols += 1;
        }
    }
    cout << "Letters - " << letters << endl;
    cout << "Numbers - " << numbers << endl;
    cout << "Symbols - " << symbols << endl;
}

int main()
{
    const int size = 200;
    char* str = new char[size];
    
    cout << "Input line - ";
    cin.getline(str, size);
    //change(str);
    //cout << find(str, 'h') << endl;
    check(str);


    //cout << str;
    delete[] str;
}