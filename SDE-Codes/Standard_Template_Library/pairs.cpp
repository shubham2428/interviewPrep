#include <iostream>
using namespace std;

int main()
{
    pair<int, int> p = {1, 2};

    cout << " printing the p1 content" << endl;
    cout << p.first << " " << p.second << endl;

    // suppose we want to make {1,{2,3}}

    pair<int, pair<int, int>> p2 = {1, {3, 4}};

    cout << "printing the p2 content" << endl;

    cout << p2.first << " " << p2.second.second;
}