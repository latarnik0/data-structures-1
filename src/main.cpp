#include <iostream>
#include <memory>
#include <stdexcept>

constexpr int DEF_SIZE = 2;

class slist{

};

class darray{
    int* data;
    int size;
    int capacity;

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
    void initArr(){
        capacity = DEF_SIZE;
        data = new int[capacity];
        size = 0;
    }

    void insf(int val){
        if(size == capacity){
            resize();
        }
        
        for(int i=size-1; i>=0; i--){
            data[i+1] = data[i];
        }
        data[0] = val;
        size++;
    }

    void insb(int val){
        if(size == capacity){
            resize();
        }
        data[size] = val;
        size++;
    }

    void insa(int val, int index){
        if(size == capacity){
            resize();
        }

        if(index == size){
            insb(val);
        }
        else if(index == 0){
            insf(val);
        }
        else{
        
            if(index > capacity){
                throw std::out_of_range("Index out of bounds!");
            }

            for(int i=size-1; i>=index; i--){
                data[i+1] = data[i];
            }
            data[index] = val;
            size++;
        }
    }

    void erasef(){
        for(int i=0; i<size; i++){
            data[i] = data[i+1];
        }
        size--;
    }

    void replaceAt(int val, int index){
        if(index > size){
                throw std::out_of_range("Index out of bounds!");
        }
        data[index] = val;
    }

    void peekAt(int index){
        std::cout<<data[index]<<'\n';
    }
    

    void printArr(){
        for(int i=0; i<capacity; i++){
            printf("%d ", data[i]);

        }
    }

};

int main(){
    darray d;
    d.initArr();
    d.insf(123);
    d.insf(987);
    d.erasef();
    d.printArr();
    return 0;
}