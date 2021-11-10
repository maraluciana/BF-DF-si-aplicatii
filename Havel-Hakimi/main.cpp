#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

ifstream fin("hh.in");

int main()
{
    int n, x, sum;
    vector<int> seq;

    fin >> n;

    for(int i = 0; i < n; i++)
    {
        fin >> x;
        seq.push_back(x);
        sum += x;
    }

    if(sum % 2 != 0)
    {
        cout << "Nu, suma gradelor este impara" << endl;

        fin.close();
        fout.close();
        return 0;
    }

    for(auto i:seq)
        if(i >= n)
        {
            cout << "Nu, gradul unui varf nu poate fi mai mare sau egal cu numarul total de varfuri" << endl;

            fin.close();
            fout.close();
            return 0;
        }

    sort(seq.begin(), seq.end(), greater<int>());

    while(seq.front() > 0 && seq.back() >= 0)
    {
        n = seq.front();
        seq.erase(seq.begin());

        for(int i = 0; i < n; i++)
            seq[i] -= 1;

        sort(seq.begin(), seq.end(), greater<int>());
    }

    if(seq.back() < 0)
        cout << "Nu" << endl;

    else if(seq.front() == 0)
        cout << "Da" << endl;


    fin.close();
    fout.close();

    return 0;
}
