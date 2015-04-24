#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int key;
    Node* next;
    Node(int k){
        key=k;
        next=this;
    }
    Node(){
        key=-1;
        next=this;
    }
};

Node*  find(Node* x){
    if(x->next==x){
        return x;
    }
    x->next=find(x->next);
    return x->next;
}

void unionSets(Node* x, Node* y) {
    find(x)->next=find(y);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int m;
    cin>> n;
    cin>> m;


    //inialize containers
    int* coordinates;
    coordinates = new int[n*m];
    Node * nodes;
    nodes = new Node[n*m];

    //scan the priorities
    int currentPriority;
    for (int i = 0; i < n * m; i++) {
        cin>>currentPriority;
        coordinates[currentPriority - 1] = i;
    }

    int currentNumber = 0;
    int currentKey;
    Node* currentNode;

    for (int i = 0; i < n * m; i++) {
        currentNumber++;
        currentKey = coordinates[i];
        currentNode = new Node(currentKey);
        nodes[currentKey] = *currentNode;

        //left
        if (currentKey % n != 0 && nodes[currentKey - 1].key != -1) {
            if (find(currentNode) != find(&nodes[currentKey - 1])) {
                currentNumber--;
                unionSets(currentNode, &nodes[currentKey - 1]);
            }
        }
        //right
        if (currentKey % n != n - 1 && nodes[currentKey + 1].key != -1) {
            if (find(currentNode) != find(&nodes[currentKey + 1])) {
                currentNumber--;
                unionSets(currentNode, &nodes[currentKey + 1]);
            }
        }
        //down
        if (currentKey - n >= 0 && nodes[currentKey - n].key != -1) {
            if (find(currentNode) != find(&nodes[currentKey - n])) {
                currentNumber--;
                unionSets(currentNode, &nodes[currentKey - n]);
            }
        }
        //up
        if (currentKey + n < n * m && nodes[currentKey + n].key != -1) {
            if (find(currentNode) != find(&nodes[currentKey + n])) {
                currentNumber--;
                unionSets(currentNode, &nodes[currentKey + n]);
            }
        }
        cout<< currentNumber<<" ";
    }

}
