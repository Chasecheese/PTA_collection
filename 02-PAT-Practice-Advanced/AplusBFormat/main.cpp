#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;
    int sum = a + b;
    if (sum < 0)
    {
        cout << '-';
    }
    string s;
    s = to_string(abs(a + b));
    int size = s.length();
    int i;
    int head_length = size % 3;
    for (i = 0; i < head_length; i++)
    {
        cout << s[i];
    }
    while (i < size)
    {
        if (i != 0)
            cout << ',';
        cout << s[i] << s[i + 1] << s[i + 2];
        i = i + 3;
    }
    cout << endl;
}
