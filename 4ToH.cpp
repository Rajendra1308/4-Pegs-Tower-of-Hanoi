#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void ToH3 (int m ,char p, char q, char r)                               // The basic 3 pegs ToH problem 
{
    if(m==1)
    {
        cout << "Move disk 1 from rod "<< p << " to rod "<< q<<endl;
        return;
    }
    ToH3(m - 1, p, r, q);
    cout <<"Move disk "<< m << " from rod " << p << " to rod "<<q<<endl;
    ToH3 (m - 1 , r, q, p);
}

void ToH4 ( int n ,char  p , char q ,char r,char s)                    // Similarly 4 pegs ToH problem solved
{
    if(n==0)
        return;
    if(n==1)
    {
        cout << "Move disk 1 from rod "<< p << " to rod " << q << endl;
        return;
    }

    ToH4 (n - 2 , p , r , s ,q );


    cout << "Move disk "<< n-1 << " from rod " << p << " to rod "<< s <<endl;
    cout << "Move disk "<< n << " from rod " << p << " to rod "<< q<<endl;
    cout << "Move disk "<< n-1 << " from rod " << s<< " to rod "<< q<<endl;

    ToH4(n - 2, r , q , p ,s);

}

void ToH41 (int i , int j , char a , char b, char c, char d)                            // Better way to solve the ToH problem efficiently using ToH4 and ToH3 functions.
{
    int m = j - i +1;
    int k = floor(m/2);                                                                 // Average case time complexity
    ToH4 (m - k ,a , d , b ,c);
    ToH3 (k , a , b , c);
    ToH4 (m- k , d ,b , a,c);
    cout << endl;
}

void ToH42 (int i , int j ,char a , char b, char c, char d, int k)                      // Much better than ToH41 by taking as input from user.
{
    int m = j - i + 1;
    if ( m <= k)
        ToH3 ( m,a,b,c);
    else
    {
        ToH4 (m - k ,a , d , b ,c);
        ToH3 (k , a , b , c);
        ToH4 (m- k , d ,b , a,c);
    }
    cout <<endl;
}
void ToH43 (int i , int j , char a, char b , char c, char d)                             // The most optimal method. Developed first by Stockmeyer.Using k=sqrt(2m).
{
    int m = j - i + 1;
    int k = sqrt(2*m);
    ToH4 (m - k ,a , d , b ,c);
    ToH3 (k , a , b , c);
    ToH4 (m- k , d ,b , a,c);
}


// UTILITY FUNCTIONS
int main()
{
    int n ,k;
    cout << "Enter the no. of disks "<< endl;
    cin >> n ;
    cout << endl;
    cout << " Enter the value of k for the second optimal method"<<endl;
    cin >>k;

    cout <<"---------------By first method---------------\n" <<endl;
    ToH41 (1, n, 'A', 'B', 'C','D');
    cout <<"\n---------------By second method---------------\n" <<endl;
    ToH42 (1, n, 'A', 'B', 'C','D' , k);
    cout <<"\n---------------By third method/ Stockmeyer's method---------------\n" <<endl;
    ToH43 (1, n, 'A' , 'B' , 'C', 'D');
    return 0;
}
