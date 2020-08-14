#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N;
        cin >> N;
        int V[N+1];
        V[N] = -1;
        for (int i = 0; i < N; i++)
        {
            cin >> V[i];
        }

        int count = 0;
        int record = -1;
        for (int i = 0; i < N; i++)
        {
            if (V[i] > record)
            {
                record = V[i];
                if (V[i] > V[i+1])
                {
                    count++;
                }
            }
        }
        cout << "Case #" << case_num << ": " << count << endl;
    }
}