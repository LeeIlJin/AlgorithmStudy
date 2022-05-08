#include <iostream>
#include <memory.h>

using namespace std;

#define Add 0
#define Sub 1
#define Mul 2
#define Div 3

void Alg(int);
int Calc(int,int,int);

int N;
int* nums;
int opers[4]; // (+ , - , * , /)

int tmin, tmax;
int total;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    nums = new int[N];
    for(int i=0; i<N; i++)
        cin>> nums[i];
    
    cin >> opers[Add] >> opers[Sub] >> opers[Mul] >> opers[Div];
    
    tmin = 2147483647;
    tmax = -2147483648;
    total = nums[0];
    
    Alg(1);
    
    cout << tmax << "\n" << tmin;
    
    delete[] nums;
    return 0;
}

int Calc(int a, int b, int oper)
{
    switch(oper)
    {
        case Add: return a + b;
        case Sub: return a - b;
        case Mul: return a * b;
        case Div: return a / b;
    }
}

void Alg(int c)
{
    if(c == N)
    {
        if(total < tmin)
            tmin = total;
        
        if(total > tmax)
            tmax = total;
        
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        if(opers[i] == 0)
            continue;
        
        int priv = total;
        total = Calc(total, nums[c], i);
        
        opers[i]--;
        Alg(c+1);
        opers[i]++;
        
        total = priv;
    }
    
    return;
}
