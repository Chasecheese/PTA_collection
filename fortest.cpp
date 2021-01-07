#include <iostream>
#include <cmath>
using namespace std;

int getN(int a);

int main(){
    int num;
    cin >> num;
    char p;
    cin >> p;
    int x = (num+1)/2;
    int n = getN(x);
    int extra = num - 2*n*n;
    int i,j;
    for(i=n;i>=1;i--){
        int space = 2*(n-i);
        int space_perside = n-i;
        for(j=0;j<n-i;j++){
            cout <<' ';
        }
        for(j=0;j<2*i-1;j++){
            cout << p;
        }
        for(j=0;j<n-i;j++){
            cout <<' ';
        }
        cout<< endl;
    }
    for(i=2;i<=n;i++){
        int space = 2*(n-i);
        int space_perside = n-i;
        for(j=0;j<n-i;j++){
            cout <<' ';
        }
        for(j=0;j<2*i-1;j++){
            cout << p;
        }
        for(j=0;j<n-i;j++){
            cout <<' ';
        }
        cout<< endl;
    }
    if(extra+1){
        cout << extra+1 <<endl;
    }
    return 0;
}

int getN(int a){
    double b = sqrt((double)a);
    int c = (int)b;
    return c;
    
}