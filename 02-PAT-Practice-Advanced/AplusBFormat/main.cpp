#include <iostream>
#include <string>
using namespace std;

int main (){
    int a;
    int b;
    cin >> a;
    cin >> b;
    int sum = a+b;
    if(sum <0 ){
        cout << "-";
    }
    string s;
    s = to_string(abs(a+b));
    int i;
    int size =s.length();
    int head_length = size%3;
    for(i=0 ;i < head_length;i++){
        cout << s[i];
        if(size > 3)
            cout << ",";
    }
    int k =0;
    for(;i<size;i++){
        if(k%3 ==0 && k!=0){
            cout << ",";
        }
        cout << s[i];
        k++;
    }
    cout << endl;
    return 0;
}