#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int key;
    int origin;
    Node(int nKey, int nOrigin){
        key = nKey;
        origin = nOrigin;
    }
    Node(){
        key = 0;
        origin = 0;
    }

};

class Heap{
public:
    int currentNumberOfItems;
    int size;
    Node* array;
    Heap(int newSize){
        currentNumberOfItems=0;
        size = newSize;
        array = new Node[size];
    }
    Node getMinElement(){
        Node value = array[0];
        currentNumberOfItems--;
        array[0]=array[currentNumberOfItems];
        heapifyMin(0);
        return value;
    }
    
    int getParent(int index){
        return (index-1)/2;
    }
    int getLeft(int index){
        return index*2+1;
    }
    int getRight(int index){
        return index*2+2;
    }
    int getCurrentNumberOfItems() {
        return currentNumberOfItems;
    }
    void heapifyMin(int index){
        int minIndex=index;
        int currentMin=array[index].key;
        
        if(getLeft(index) < getCurrentNumberOfItems()
           && array[getLeft(index)].key < array[index].key){
            currentMin = array[getLeft(index)].key;
            minIndex = getLeft(index);
        }
        if (getRight(index)<getCurrentNumberOfItems()
            && array[getRight(index)].key<currentMin) {
            minIndex = getRight(index);
        }
        if (minIndex!=index){
            swap(array[minIndex], array[index]);
            heapifyMin(minIndex);
        }
    }
    void insert(Node value) {
        array[currentNumberOfItems]=value;
        currentNumberOfItems++;
        int parent = currentNumberOfItems - 1;

        while (array[getParent(parent)].key > array[parent].key) {
            swap(array[getParent(parent)],array[parent]);
            parent = getParent(parent);
        }
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numberOfArrays;
    cin>> numberOfArrays;
    int * arrays[numberOfArrays];
    int key;
    int numberOfEntries;
    Heap myHeap(numberOfArrays);


    // Iterate arrays
    for(int i=0; i<numberOfArrays; i++){
        cin>> numberOfEntries;

        // Scan first element of array
        cin>>key;
        Node myNode(key,i);
        myHeap.insert(myNode);
        arrays[i]=new int[numberOfEntries];

        // Scan all other elements of array
        arrays[i][0]=numberOfEntries-1;
        for(int j=numberOfEntries-1; j>0; j--){
            cin>> key;
            arrays[i][j]=key;
        }
    }

    int original;
    int placeInArrays;

    while(myHeap.currentNumberOfItems!=0){
        Node newNode = myHeap.getMinElement();
        cout<<newNode.key<<" ";
        original = newNode.origin;
        placeInArrays = arrays[original][0];
        if(placeInArrays>0){
            Node tempNode(arrays[original][placeInArrays],original);
            arrays[original][0]--;
            myHeap.insert(tempNode);
        }
    }

    return 0;

}

