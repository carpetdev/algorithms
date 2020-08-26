// Could have also checked if last element of a decreasing-by-1 run is 1 instead of using the extra memory.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N, K;
        cin >> N >> K;
        int count = 0;
        int A[N];
        vector<int> candidates;
        for (int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            A[i] = n;
            if (n == K && N - i >= K)
            {
                candidates.push_back(i);
            }
        }

        for (int s : candidates)
        {
            int countdown_flag = 1;
            for (int i = 1; i < K; i++)
            {
                if (A[s + i] != K - i)
                {
                    countdown_flag = 0;
                }
            }
            count += countdown_flag;
        }

        cout << "Case #" << case_num << ": " << count << endl;
    }
}