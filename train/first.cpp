#include <iostream>
#include <string>
using namespace std;

void Data(string n[], float s[], int l) {
    for (int i = 0; i < l; i++) {
        cin >> n[i];
        cin >> s[i];
    }
}

void Max(string n[], float s[], int l) {
    float max = s[0];

    for (int i = 0; i < l; i++) {
        if (max < s[i]) {
            max = s[i];
        }
    }


    for (int i = 0; i < l; i++) {
        if (max == s[i]) {
            cout << n[i] << endl;
        }
    }
}

int main() {
    const int l = 3;
    string n[l];
    float s[l];

    Data(n, s, l);
    Max(n, s,l);

    return 0;
}
