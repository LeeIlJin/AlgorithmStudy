#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    int x,y,w,h;
    
    cin >> x >> y >> w >> h;
    
    int d = w - x;
    if(d > h - y)
        d = h - y;
    
    int a = x;
    if(a > y)
        a = y;
    
    if(d > a) cout << a;
    else cout << d;
    
    return 0;
}
