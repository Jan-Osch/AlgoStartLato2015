class Node{
public:
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
    Heap(int size){
        currentNumberOfItems=0;
        array= Node[size];
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
        int currentMin=array[index];
        
        if(getLeft(index) < getCurrentNumberOfItems()
           && this->array[getLeft(index)]->key<array[index]->key){
            currentMin = array[getLeft(index)]->key;
            minIndex = getLeft(index);
        }
        if (getRight(index)<getCurrentNumberOfItems()
            && array[getRight(index)]->key<currentMin) {
            minIndex = getRight(index);
        }
        if (minIndex!=index){
            swap(array[minIndex], array[index]);
            heapifyMin(minIndex);
        }
    }
    void insert(Node * value) {
        array[currentNumberOfItems] = value;
        currentNumberOfItems++;
        int parent = currentNumberOfItems - 1;
        while (array[getParent(parent)]->key > array[parent]->key) {
            swap(array[getParent(parent)],array[parent]->key);
            parent = getParent(parent);
        }
    }
};


