#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str;
    str = "1 2 3 4 5 6 7";
    int str_len = str.length();

    //printing reverse-pyramid
    cout << str << "\n";
    for (int i = 0; i < str_len; i++)
    {
        str.erase(str.begin() + 0);
        if (str == "")
            break;

        for (int j = 1; j <= i; j++)
            cout << " ";
        cout << str << "\n";

        str.erase(str.begin() + 0);
    }

    //printing pyramid
    str = "7";
    int spaces = 5;

    for (int i = 6; i > 0; i--)
    {
        for (int j = 1; j <= spaces; j++)
            cout << " ";
        spaces--;

        str = to_string(i) + " " + str;
        cout << str << "\n";
    }

    return 0;
}