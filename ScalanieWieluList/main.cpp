#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int key;
    int origin;
    Node(int nKey, int nOrigin){
        key = nKey;
        origin = nOrigin;
    }
};

struct Heap{
    int currentNumberOfItems;
    Node * array;
    Heap(){
        currentNumberOfItems=0;
        array= new Node [];
    }
    Node getMinElement(){
        Node value = array[0];
        currentNumberOfItems--;
        array[0]=array[this.currentNumberOfItems];
        this.heapifyMin(0);
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
        int currentMin=this.array[index];
        
        if(getLeft(index) < this.getCurrentNumberOfItems()
           && this.array[getLeft(index)]->key<this.array[index]->key){
            currentMin = this.array[getLeft(index)]->key;
            minIndex = getLeft(index);
        }
        if (getRight(index)<this.getCurrentNumberOfItems()
            && this.array[getRight(index)]->key<currentMin) {
            minIndex = getRight(index);
        }
        if (minIndex!=index){
            swap(this.array[minIndex], this.array[index]);
            this.heapifyMin(minIndex);
        }
    }
    public void insert(Node value) {
        this.array[currentNumberOfItems] = value;
        this.currentNumberOfItems++;
        int parent = currentNumberOfItems - 1;
        while (array[getParent(parent)]->key > array[parent]->key) {
            swap(array[getParent(parent)],array[parent]->key);
            parent = getParent(parent);
        }
    }
};

/*
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n;
        Heap heap = new Heap();
        while(k>0){
            k--;
            n = sc.nextInt();
            while(n>0){
                n--;
                heap.insert(sc.nextInt());
            }
        }
        while (heap.getCurrentNumberOfItems()!=0){
            System.out.print(heap.getMinElement());
            System.out.print(" ");
        }
    }
}
 */


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

