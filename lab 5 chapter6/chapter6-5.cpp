#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};
struct Compare
{
    bool operator()(Node *a, Node *b) { return a->freq > b->freq; }
};
void printCodes(Node *root, string code)
{
    if (!root)
        return;
    if (root->ch != '#')
        cout << root->ch << ":" << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;
    cin >> n;
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < n; i++)
    {
        char ch;
        int f;
        cin >> ch >> f;
        pq.push(new Node(ch, f));
    }
    while (pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();
        Node *r = pq.top();
        pq.pop();
        Node *newNode = new Node('#', l->freq + r->freq);
        newNode->left = l;
        newNode->right = r;
        pq.push(newNode);
    }
    Node *root = pq.top();
    printCodes(root, "");
}