#include <iostream>

using namespace std;

int fun(string string1){
    int len=string1.length();
    int count=0;
    for(int i=0;i<len;i++){
        if(string1[i]==' '){
            while (string1[i+1]==' '){
                i++;
            }
            count++;
        }
    }
    return count+1;

}

int main() {
    string string1;
    getline(cin,string1);
    cout<<fun(string1);

    return 0;
}
