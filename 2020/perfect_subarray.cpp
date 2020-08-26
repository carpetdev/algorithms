// Idea shamelessly stolen from the analysis - step through and store a list of the number of cumulative sums of each size seen so far.
// See if you can make any of the squares by taking away one of these sums, by iterating the squares!!! O(N*sqrt(N*max_squares)) rather than O(N^2)
// ! Was getting overflow issues, most likely just from the "number of subarrays" (obviously since this gets huge), but technically N and max/min_sum weren't big enough either.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++)
    {
        long N;
        cin >> N;
        vector<int> cum_sum(N);
        long long sum = 0;
        int max_num = 0;
        long long min_sum = 0;
        long long max_sum = 0;
        for (int i = 0; i < N; i++)
        {
            int in;
            cin >> in;
            sum += in;
            cum_sum[i] = sum;
            if (in > max_num)
            {
                max_num = in;
            }
            if (sum < min_sum)
            {
                min_sum = sum;
            }
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }

        int square_root_count = sqrt(N*max_num) + 1;
        // cout << max_square_roots << endl;
        vector<long long> squares(square_root_count);
        for (long long i = 0; i < square_root_count; i++)
        {
            squares[i] = i * i;
        }

        long long count = 0;
        vector<int> sum_count(max_sum - min_sum + 1, 0);
        sum_count[0 - min_sum] = 1; // Since the empty set has a sum of zero when taking it away from something

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < square_root_count; j++)
            {
                // cout << "i: " << i << ", j: " << j << endl;
                // cout << "sum_count: ";
                // for (int n = 0; n < sum_count.size(); n++)
                // {
                //     cout << sum_count[n] << " ";
                // }
                // cout << endl;
                if (cum_sum[i] - squares[j] < min_sum)
                {
                    break;
                }
                // cout << "adding " << sum_count[cum_sum[i] - squares[j] - min_sum] << endl << endl;
                count += sum_count[cum_sum[i] - squares[j] - min_sum];
            }
            sum_count[cum_sum[i] - min_sum] += 1;
        }

        cout << "Case #" << case_num << ": " << count << endl;
    }
}

// ! This is dumb!!! Just use an array of cumulative sums for O(1) queries, just at the cost of O(N) updates but that's fine cos we aren't updating.
// ? Note: Segment Tree is O(log n) for both queries and updates.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <set>

// using namespace std;

// void make_segment_tree(vector<int>& tree, vector<int>& A, int n, int a, int b)
// {
//     if (a == b)
//     {
//         tree[n] = A[a];
//     }
//     else
//     {
//         int m = (a + b) / 2;
//         make_segment_tree(tree, A, 2*n, a, m);
//         make_segment_tree(tree, A, 2*n+1, m+1, b);
//         tree[n] = tree[2*n] + tree[2*n+1];
//     }
// }

// long query_segment_tree(vector<int>& tree, int n, int a, int b, int start, int end)
// {
//     if (start > end)
//     {
//         return 0;
//     }
//     if (a == start && b == end)
//     {
//         return tree[n];
//     }
//     int m = (a + b) / 2;
//     return query_segment_tree(tree, 2*n, a, m, start, min(end, m)) + query_segment_tree(tree, 2*n+1, m+1, b, max(start, m+1), end);
// }

// int main()
// {
//     int T;
//     cin >> T;
//     for (int case_num = 1; case_num <= T; case_num++)
//     {
//         int N;
//         cin >> N;
//         vector<int> A(N);
//         for (int i = 0; i < N; i++)
//         {
//             cin >> A[i];
//         }
//         vector<int> tree(4*N);
//         make_segment_tree(tree, A, 1, 0, N-1);

//         long max_square_root = sqrt(N*100);
//         set<long> squares;
//         for (long i = 0; i < max_square_root; i++)
//         {
//             squares.insert(i * i);
//         }

//         int count = 0;
//         for (int start = 0; start < N; start++)
//         {
//             for (int end = start; end < N; end++)
//             {
//                 if (squares.find(query_segment_tree(tree, 1, 0, N-1, start, end)) != squares.end())
//                 {
//                     count++;
//                 }
//             }
//         }

//         cout << "Case #" << case_num << ": " << count << endl;
//     }
// }