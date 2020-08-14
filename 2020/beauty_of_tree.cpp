#include <iostream>
#include <vector>

using namespace std;

// TODO Struct or Class next time. This is ugly and bad!!!
void DFS(const int node, const vector<int>* children, vector<int>& path, const int A, vector<int>& paints_A, const int B, vector<int>& paints_B)
{
    path.push_back(node);
    for (const int child : children[node])
    {
        DFS(child, children, path, A, paints_A, B, paints_B);
    }
    paints_A[node]++;
    paints_B[node]++;
    int n = path.size();
    n--;
    if (n <= A) {
        paints_A[path[n - A]] += paints_A[node];
    }
    if (n <= B)
    {
        paints_B[path[n - B]] += paints_B[node];
    }
    path.pop_back();
}

int main()
{
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N, A, B;
        cin >> N >> A >> B;
        vector<int>* children = new vector<int>[N];
        for (int child = 1; child < N; child++)
        {
            int parent;
            cin >> parent;
            children[--parent].push_back(child);
        }

        vector<int> path;
        vector<int> paints_A (N, 0);
        vector<int> paints_B (N, 0);
        DFS(0, children, path, A, paints_A, B, paints_B);

        double Ebeauty = 0;
        for (int i = 0; i < N; i++)
        {
            Ebeauty += ((double)paints_A[i] + (double)paints_B[i] - (double)paints_A[i] * paints_B[i] / N ) / N;
        }
        cout.precision(12);  // ! OMG THIS TOOK SO LONG TO REALISE! 7 is enough.
        cout << "Case #" << case_num << ": " << Ebeauty << endl;
        delete[] children;
    }
}