#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

//https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
/*
 * Complete the 'designerPdfViewer' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h
 *  2. STRING word
 */

int designerPdfViewer(vector<int> h, string word) {

    int highestLetterHeight = 0;

    const int wordSize = word.size();
    const int hSize = h.size();

    for(int i = 0; i < wordSize; i++)
    {
        const int hIndex = word[i] - 'a';

        if(hIndex >= 0 && hIndex < hSize)
        {
            highestLetterHeight = max(highestLetterHeight, h[hIndex]);
        }
    }

    return highestLetterHeight * wordSize;
}

int main()
{
    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

    cout << result << "\n";

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
