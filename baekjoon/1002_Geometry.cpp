#include <iostream>
#include <cmath>

using namespace std;
int DistanceSquare(int,int,int,int);
int Alg(int,int,int,int,int,int);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 0;
    cin >> n;
    for(int ii=0; ii<n; ii++)
    {
        int ax, ay, ar, bx, by, br;
        cin >> ax >> ay >> ar >> bx >> by >> br;
        cout << Alg(ax,ay,ar,bx,by,br) << "\n";
    }
    
    return 0;
}

int DistanceSquare(int ax, int ay, int bx, int by)
{
    int dx = bx - ax;
    int dy = by - ay;
    return (dx * dx + dy * dy);
}

int Alg(int ax, int ay, int ar, int bx, int by, int br)
{
    int ds = DistanceSquare(ax,ay,bx,by);
    if(ar > br)
    {
        int temp = br;
        br = ar;
        ar = temp;
    }
    
    int add = br + ar;
    int sub = br - ar;
    
    add *= add;
    sub *= sub;
    
    if (ds ==0)
    {
        if(ar == br)
            return -1;
        else
            return 0;
    }
    else if(ds < sub || ds > add)
        return 0;
    else if(ds < add && ds > sub)
        return 2;
    
    return 1;
}
