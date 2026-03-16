#include <iostream>
#include <memory>

class darray{
    int* data;
    int size;
    int capacity;

    void init(int c){
        capacity = c;
        data = new int[capacity];
        size = 0;
    }

    void resize(){
        capacity *= 2;
        int * data_new = new int[capacity];
        for(int i=0; i<size; i++){
            data_new[i] = data[i];
        }
        delete[] data;
        data = data_new;
    }
    
public:
    void front(int val){
        if(size == capacity){
            resize();
        }
        
        for(int i=size-1; i>=0; i--){
            data[i+1] = data[i];
        }
        data[0] = val;
        size++;
    }
};

int main(){
    darray d;
    return 0;
}