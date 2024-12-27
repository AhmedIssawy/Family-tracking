#include <iostream>
#include <string>
using namespace std;

void fillData(int x[], int y[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }
}

void print(int x[], int y[], int z[], int l)
{
    for (int i = 0; i < l; i++)
    {
        z[i] = x[i] + y[i];
    }

    for (int i = 0; i<l; i++){
        cout << z[i] << endl;
    }
}

int main(){
    const int l = 3;
    int x[l];
    int y[l];
    int z[l];

    fillData(x,y,l);
    print(x,y,z,l);

    return 0;
}