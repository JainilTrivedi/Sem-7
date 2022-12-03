#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    string symbol;
    Node *left, *right;
    bool isleaf = true;
    Node(int v, string sym)
    {
        symbol = sym;
        val = v;
        left = right = NULL;
    }
};
void print(Node *node, string curr){
    if (node == NULL)
        return;
    if (node->isleaf)
    {
        cout << node->symbol << " " << curr << endl;
        return;
    }
    
    print(node->left, curr + "0");
    
    print(node->right, curr + "1");
};
int main()
{
    map<string, int> freq;
    int total;
    cin >> total;
    map<char, string> codes;
    for (int i = 0; i < total; i++)
    {
        string sym;
        int fre;
        cin >> sym >> fre;
        freq[sym] = fre;
    }
    auto lambda_cmp = [](Node *a, Node *b)
    { return a->val > b->val; };

    priority_queue<Node *, vector<Node *>, decltype(lambda_cmp)> pq(lambda_cmp);
    for (auto it : freq)
    {
        string sym = it.first;
        int freq = it.second;
        // cout<<sym<<" "<<freq<<endl;
        Node *newnode = new Node(freq, sym);
        pq.push(newnode);
    }
    while (pq.size() > 1)
    {
        Node *min1 = pq.top();
        pq.pop();
        Node *min2 = pq.top();
        pq.pop();
        Node *newtop = new Node(min1->val + min2->val, min2->symbol + min1-> symbol);
        newtop->left = min2;
        newtop->right = min1;
        newtop->isleaf = false;
        pq.push(newtop);
    }
    auto root = pq.top();
    cout<<"Encoding is:\n";
    print(root, "");
    return 0;
}
