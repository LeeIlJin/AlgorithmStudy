#include <iostream>
#include <memory.h>

using namespace std;

void Alg(int);
int Get(int,int);

int N;
int* nums;
int energy;
int result;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    nums = new int[N];
    for(int i=0; i<N; i++)
        cin>> nums[i];
        
    energy = 0;
    result = -1;
    Alg(N);
    
    cout << result;
    
    delete[] nums;
    return 0;
}

int Get(int index, int op)
{
    int i = index + op;
    
    if(nums[i] < 0)
        i = Get(i,op);
    
    return i;
}

void Alg(int c)
{
    if(c == 2)
    {
        if(result < energy)
            result = energy;
        return;
    }
    
    for(int i=1; i<N-1; i++)
    {
        if(nums[i] < 0)
            continue;
        
        int add = nums[Get(i,-1)] * nums[Get(i,1)];
        energy += add;
        
        nums[i] = -nums[i];
        Alg(c-1);
        nums[i] = -nums[i];
        
        energy -= add;
    }
    
    return;
}
