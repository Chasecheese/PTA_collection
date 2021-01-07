#include <iostream>
#include <string>

using namespace std;

int main()
{
    string provider;
    string consumer;
    cin >> provider;
    cin >> consumer;

    int list_p[62]={ 0 };

    int i;
    for(i=0; i<consumer.length(); i++){
        int a = consumer[i];
        if(a <= '9' && a >='0' ){
            list_p[ a - '0']++;
        }else if(a <= 'Z' && a >= 'A'){
            list_p[a - 'A' + 10]++;
        }else if(a <= 'z' && a >= 'a'){
            list_p[a - 'a' + 10 + 26]++;
        }
    }
    for(i=0; i<provider.length(); i++){
        int a = provider[i];
        if(a <= '9' && a >='0' ){
            list_p[ a - '0']--;
        }else if(a <= 'Z' && a >= 'A'){
            list_p[a - 'A' + 10]--;
        }else if(a <= 'z' && a >= 'a'){
            list_p[a - 'a' + 10 + 26]--;
        }
    }
    int un_get = 0;
    int flag = 0;
    for(i =0; i< 62; i++){
        if(list_p[i] > 0){
            un_get = un_get+list_p[i];
            flag = 1;
        }
    }

    if(flag == 0){
        cout << "Yes "<<provider.length()-consumer.length() <<endl;
    }else{
        cout << "No " << un_get <<endl;
    }

    return 0;
}