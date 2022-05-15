#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b,c;
    
    while(true)
    {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            break;
        
        if(b > c)
            Swap(b,c);
        if(a > b)
            Swap(a,b);
        if(b > c)
            Swap(b,c);
        
        if((a*a + b*b) == c*c)
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    
    
    return 0;
}
