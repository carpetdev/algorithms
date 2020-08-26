#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Another unholy function :)
bool stable(const int C, const char letter, const vector<int>& positions, const vector<char>& grid, const string chosen)
{
    for (int pos : positions)
    {
        if (pos - C >= 0 && grid[pos - C] != letter && chosen.find(grid[pos - C]) == string::npos)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++)
    {
        int R, C;
        cin >> R >> C;
        vector<char> grid(R*C);
        set<char> letters;
        vector<int> positions[26];
        for (int i = 0; i < R*C; i++)
        {
            char letter;
            cin >> letter;
            grid[R*C - i - 1] = letter;
            letters.insert(letter);
            positions[letter - 'A'].push_back(R*C - i - 1);
        }

        string out;
        while (!letters.empty())
        {
            string temp;
            vector<char> iter(letters.begin(), letters.end());
            for (char letter : iter)
            {
                if (stable(C, letter, positions[letter - 'A'], grid, out + temp))
                {
                    letters.erase(letter);
                    temp += letter;
                }
            }
            if (temp.empty())
            {
                out = "-1";
                break;
            }
            out += temp;
        }

        cout << "Case #" << case_num << ": " << out << endl;
    }
}