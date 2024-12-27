#include <iostream>
using namespace std;

void fillData(int x[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cin >> x[i];
    }
}

void print(int x[], int y[], int l)
{
    for (int i = 0; i < l; i++)
    {
        int num = x[i];
        int fact = 1;
        for (int j = 1; j <= num; j++)
        {
            fact = fact * j;
        }
        y[i] = fact;
    }
    for (int i = 0; i < l; i++)
    {
        cout << y[i] << endl;
    }
}

int main() {
    const int l = 3;
    int x[l];
    int y[l];

    fillData(x, l);
    print(x,y,l);
    return 0;
}