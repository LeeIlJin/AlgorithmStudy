#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int Distance(int,int,int,int);
int Alg(int,int,int,int,int,int);

struct TestCase
{
    int ax, ay;
    int bx, by;
    int ar, br;
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<TestCase> tcs;
    {
        int n = 0;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            TestCase tc;
            
            cin >> tc.ax >> tc.ay >> tc.ar >> tc.bx >> tc.by >> tc.br;
            tcs.push_back(tc);
        }
    }
    
    for (size_t i=0; i<tcs.size(); i++)
    {
        cout << Alg(tcs[i].ax,tcs[i].ay,tcs[i].ar,tcs[i].bx,tcs[i].by,tcs[i].br) << "\n";
    }
    
    return 0;
}

int Distance(int ax, int ay, int bx, int by)
{
    int dx = bx - ax;
    int dy = by - ay;
    return sqrt(dx * dx + dy * dy);
}

int Alg(int ax, int ay, int ar, int bx, int by, int br)
{
    int dis = Distance(ax,ay,bx,by);
    if(dis == 0)
    {
        if(ar == br)
            return -1;
        return 0;
    }
    
    int bigr = ar;
    int smallr = br;
    if(br > ar)
    {
        bigr = br;
        smallr = ar;
    }
    
    if(dis < bigr)
    {
        int gap = bigr - dis;
        if(gap > smallr)
            return 0;
        if(gap == smallr)
            return 1;
        return 2;
    }
    
    int sumr = ar + br;
    if(dis < sumr)
        return 2;
    if(dis == sumr)
        return 1;
    return 0;
}
