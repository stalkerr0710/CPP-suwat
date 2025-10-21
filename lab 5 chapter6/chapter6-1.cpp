#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int V;
    cout << "Enter the value: ";
    cin >> V;
    vector<int> Cash = {1000,500,100, 50, 20,};
    vector<int> used;
    int count = 0;
    for (int c : Cash)
    {
        while (V >= c)
        {
            V -= c;
            used.push_back(c);
            count++;
        }
    }
    cout << "Minimum Cash used: " << count << endl;
    cout << "Cash: ";
    for (int c : used)
        cout << c << " ";
    cout << endl;
    return 0;
}