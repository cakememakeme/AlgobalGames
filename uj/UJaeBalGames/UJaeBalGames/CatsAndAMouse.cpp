#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<string> split_string(string);

// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
    int gapCatA = abs(x - z);
    int gapCatB = abs(y - z);

    if(gapCatA == gapCatB)
    {
        return "Mouse C";
    }
    else if(gapCatA > gapCatB)
    {
        return "Cat B";
    }

    return "Cat A";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xyz_temp;
        getline(cin, xyz_temp);

        vector<string> xyz = split_string(xyz_temp);

        int x = stoi(xyz[0]);

        int y = stoi(xyz[1]);

        int z = stoi(xyz[2]);

        string result = catAndMouse(x, y, z);

        cout << result << "\n";
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
