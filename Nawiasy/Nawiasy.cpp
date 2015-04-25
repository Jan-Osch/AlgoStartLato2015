#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int key;
    Node * left;
    Node* right;
    Node(int k){
        key=k;
        left= nullptr;
        right= nullptr;
    }
};

Node*  insert(Node *n, Node *k){
    if( n== nullptr){
        return k;
    }
    if(k->key==1){
        n->right=insert(n->right,k);
        return n;
    }
    if(n->left!= nullptr){
        n->right=insert(n->right,k);
        return n;
    }
    n->left=insert(n->left, k);
    return n;
}

bool isLeaf(Node *n){
    return (n->right== nullptr && n->left== nullptr);
}
int sum(Node *n){
    if(n== nullptr){
        return 0;
    }
    if(isLeaf(n)){
        return n->key;
    }
    return sum(n->left)+sum(n->right);
}
bool check(Node *n){

}


void change(char* c, int index){
    if(c[index-1]== ')'){
        c[index-1]='(';
        return;
    }
    c[index-1]=')';
}

bool check(char *c, int size){
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
    for(int i=0; i<n; i++){
        cin>>slowo[i];
    }
    cin>>m;
    int tmp;
    while(m>0){
        m--;
        cin>>tmp;
        if(tmp==0){
            if(check(slowo, n)){
                cout<<"TAK"<<endl;
            }else{
                cout<<"NIE"<<endl;
            }
        }
        else{
            change(slowo,tmp);
        }
    }
    return 0;
}

