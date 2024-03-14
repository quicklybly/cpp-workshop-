#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void validate_size(const int height, const int width) {
    if (height < 2) {
        throw invalid_argument("Matrix height should be >= 2");
    }
    if (width < 1) {
        throw invalid_argument("Matrix width should be >= 1");
    }
}

int** init_array(const int height, const int width) {

    int **arr = new int*[height];

    for (int i = 0; i < height; ++i) {
        arr[i] = new int[width];
    }

    return arr;
}

void fill_array_from_string(int* arr, const string& s, const int width) {
    if (s.size() != width) {
        throw invalid_argument("String length should be equal to matrix width");
    }
    for (int i = 0; i < s.size(); ++i) {
        int digit = s[i] - '0';
        if (digit < 0 || digit > 9) {
            throw invalid_argument(&"Expected number, but got " [ s[i]]);
        }
        arr[i] = digit;
    }
}

void fill_matrix(int **arr, const int height, const int width) {
    for (int i = 2; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i - 2][j];
        }
    }
}

void print_result(int** arr, const int height, const int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void clear(int** arr, const int height) {
    for (int i = 0; i < height; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int height, width;
    cin >> height >> width;

    validate_size(height, width);

    auto arr = init_array(height, width);

    string str;
    cin >> str;
    fill_array_from_string(arr[0], str, width);
    cin >> str;
    fill_array_from_string(arr[1], str, width);

    fill_matrix(arr, height, width);

    print_result(arr, height, width);
    clear(arr, height);

    return 0;
}
