#include <bits/stdc++.h>

using namespace std;

string encrypteqn(string s, int n)
{
    /*
    This function takes a hex string and returns a shuffled hex string
    */
    string s1 = "";
    int l=(rand() % 10)+1;
    char z = char(l + '0');
    //cout<<"l"<<l<<endl;
    //cout<<"z"<<z<<endl;
    int x = 1, ctr = 0, limit = n;
    set<int> numset;
    while (ctr < n)
    {
        x++;
        // This expression generates random indices within the range of the given limit for shuffling
        int y = (x ^ 3 + 3 * x ^ 2 + 7 * x + l) % limit;
        if (numset.find(abs(y)) == numset.end())
        {
            // For each unique index generated, the bit at that index in the original string is copied to the new string
            numset.insert(abs(y));
            s1 += s[abs(y)];
            ctr++;
        }
    }
    s1+=z;
    return s1;
}

string decrypteqn(string s, int n)
{
    /*
    This function takes the shuffled hex string and returns a original string.
    */
    char z1=s[s.size()-1];
    s.pop_back();

    int l1=z1-'0';
    char s1[n];
    //cout<<"l"<<l1<<endl;
    //cout<<"z"<<z1<<endl;
    int x = 1, j = 0, ctr = 0, limit = n;
    set<int> numset;
    while (ctr < n)
    {
        x++;
        int y = (x ^ 3 + 3 * x ^ 2 + 7 * x + l1) % limit;
        if (numset.find(abs(y)) == numset.end())
        {
            numset.insert(abs(y));
            s1[abs(y)] = s[j++];
            ctr++;
        }
    }
    string s2 = "";
    for (int i = 0; i < n; i++)
    {
        s2 += s1[i];
    }
    return s2;
}
