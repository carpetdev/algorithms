#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++)
    {
        int K;
        cin >> K;
        int prev_note;
        cin >> prev_note;
        int curr_note;
        int ups = 0;
        int downs = 0;
        int rule_breaks = 0;
        for (int i = 1; i < K; i++)
        {
            cin >> curr_note;
            if (curr_note < prev_note)
            {
                ups = 0;
                downs++;
            }
            else if (curr_note > prev_note)
            {
                downs = 0;
                ups++;
            }
            if (ups == 4 || downs == 4)
            {
                rule_breaks++;
                ups = downs = 0;
            }
            prev_note = curr_note;
        }
        cout << "Case #" << case_num << ": " << rule_breaks << endl;
    }
}