#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <iterator>
using namespace std;
bool isAnagram(string str1, string str2)
{   
    //direct indexing all characters of string and their no_of occurence
    int count[256] = {0};

    //marking occurences of characters in given string 
    for (auto i : str1)
        count[(int)i]++;

    //marking occurences of characters in substring 
    for (auto i : str2)
        count[(int)i]--;

    //verifying if characters of both strings are same and occuured equally
    for (auto i : count)
    {
        if (i != 0)
            return false;
    }

    return true;
}
int main()
{

    string str1, str2;

    //taking input
    getline(cin, str1);
    getline(cin, str2);

    //storing strings length
    int size_1 = str1.length();
    int size_2 = str2.length();

    //validating input
    if (size_2 > size_1)
        cout << "Invalid Input!";

    //using sliding window technique to check if substring of length equal to given string is anagram of it or not
    else
    {
        string curr = "";

        for (int i = 0; i < size_2; i++)
        {
            curr += str1[i];
        }
        if (isAnagram(str2, curr))
            cout << "substring " + curr + "present at index " << 0 << "\n";

        for (int i = size_2; i < size_1; i++)
        {
            curr.erase(curr.begin() + 0);
            curr += str1[i];
            if (isAnagram(str2, curr))
                cout << "substring " + curr + " present at index " << i - size_2 + 1 << "\n";
        }
    }

    return 0;
}