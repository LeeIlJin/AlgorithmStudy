#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TestCase
{
    int val;
    int a;
    
    TestCase(int _val): val(_val) {}
};

bool IsPrime(int n)
{
    if (n < 2) return false;
    
	int a = (int)sqrt(n);
	for (int i=2; i<=a; i++) if(n % i == 0) return false;
	return true;
}

int Alg(int,int);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<TestCase> tests;
    int value = 0;
    while(true)
    {
        cin >> value;
        if(value == 0)
            break;
        tests.push_back(TestCase(value));
    }
    
    int a = 0;
    for (size_t i=0; i<tests.size(); i++)
    {
        tests[i].a = Alg(3,tests[i].val);
        if(tests[i].a == 0)
        {
            cout << "Goldbach's conjecture is wrong." << "\n";
            continue;
        }
        
        cout << tests[i].val << " = " << tests[i].a << " + " << tests[i].val - tests[i].a << "\n";
    }
    
    return 0;
}

int Alg(int a, int val)
{
    if(a >= val)
        return 0;
    
    int b = val - a;
    if(IsPrime(b) == true)
        return a;
    
    a += 2;
    while(IsPrime(a) == false)
        a += 2;
    
    return Alg(a, val);
}
