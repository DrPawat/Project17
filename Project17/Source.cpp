#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             
using std::cout;            
using std::endl;           
using std::setprecision;  
using std::sort;           
using std::streamsize;      
using std::string;          
using std::vector;          

int main()
{
    cout << endl;

    cout << "pls scipt ^z to stop process\n ";
    cout << "Enter your numbers: ";
    vector<double> v;
    double x;
    while (cin >> x)
        v.push_back(x);
    cout << endl;
    typedef vector<double>::size_type vecSize;
    vecSize N = v.size();
    if (N == 0)
    {
        cout << "You must enter some numbers! " << endl;
        return 1;
    }

    else if (N == 1)
    {
        cout << " Only 1 number supplied. Q1, Q2, and Q3 all equate to " << v[0] << endl;
        return 0;
    }

    else
    {
        sort(v.begin(), v.end());
    }

    vecSize NMod4 = (N % 4);  
    string datumDistr = "";   
    vecSize M, ML, MU;        
    double mu,G, GT;
    int T;
    G = (3 * (N + 1.0)) / 4.0;
    T = (3 * (N + 1)) / 4;
    GT = G - T;
    if (NMod4 == 0)
    {
        M = N / 2;
        ML = M / 2;
        MU = M + ML;
    
        mu = (v[MU-1] + ((v[MU]-v[MU - 1])*GT));
    }

    else if (NMod4 == 1)
    {
        M = N / 2;
        ML = M / 2;
        MU = M + ML + 1;
                
        mu = (v[MU] + v[MU - 1]) / 2;     
    }

    else if (NMod4 == 2)
    {
        
        M = N / 2;
        ML = M / 2;
        MU = M + ML;
    
        mu = v[MU];                   
    }

    else if (NMod4 == 3)
    {
        M = N / 2;
        ML = M / 2;
        MU = M + ML + 1;                 
        mu = v[MU];                
    }

    else
    {
        cout << "Unknown pattern";
    }
    streamsize prec = cout.precision();
    cout << endl;
    cout << setprecision(3) << endl
        << " Q3= " << mu << endl
        << setprecision(prec);
}