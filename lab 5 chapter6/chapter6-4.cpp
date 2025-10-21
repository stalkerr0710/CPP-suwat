#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(A[i] - B[i]);
    cout << "Min sum=" << sum << endl;
}