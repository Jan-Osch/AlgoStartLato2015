#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void change(char* c, int index, int & nplus, int & nminus){
    if(c[index-1]== ')'){
        nminus--;
        nplus++;
        c[index-1]='(';
        return;
    }
    nplus--;
    nminus++;
    c[index-1]=')';
}

bool check(char *c, int size, int nplus, int nminus){
    if (nplus!=nminus){
        return false;
    }
    int control = 0;
    for (int i=0; i<size; i++){
        if(c[i]==')'){
            control--;
        }else{
            control++;
        }
        if(control<0){
            return false;
        }
    }
    if(control==0){
        return true;
    }
    return false;
}

int main() {
    int n;
    int m;
    cin>>n;
    char * slowo;
    slowo = new char[n];
    int nplus=0;
    int nminus=0;
    char c;
    for(int i=0; i<n; i++){
        cin>>c;
        if(c==')'){
            nminus++;
        }else{
            nplus++;
        }
        slowo[i]=c;
    }
    cin>>m;
    int tmp;
    while(m>0){
        m--;
        cin>>tmp;
        if(tmp==0){
            if(check(slowo, n, nplus,nminus)){
                cout<<"TAK"<<endl;
            }else{
                cout<<"NIE"<<endl;
            }
        }
        else{
            change(slowo,tmp, nplus, nminus);
        }
    }
    return 0;
}

