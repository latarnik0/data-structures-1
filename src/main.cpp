#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <chrono>

// -------------- DOUBLY LINKED LIST --------------

// NODE
class node{
public:
    int data;
    node* next;
    node* prev;

    node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

// LIST 
class dlist{
private:
    node* head;

public:
    dlist(){
        head = nullptr;
    };
    
    void addFront(int val){
        node* new_node = new node(val);
        if(head == nullptr){
            head = new_node;
            new_node->prev = nullptr;
            new_node->next = nullptr;
        }
        else{
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            new_node->prev = nullptr;
        }
    }

    void rmFront(){
        if(head == nullptr){
            throw std::out_of_range("List already empty!");
        }
        node* del = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete del;
    }

    void addBack(int val){
        node* new_node = new node(val);
        if(head == nullptr){
            head = new_node;
            head->next = nullptr;
            head->prev = nullptr;
        }
        else{
            node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            new_node->next = nullptr;
            temp->next = new_node;
            new_node->prev = temp;
        }
    }

    void rmBack(){ 
        if(head == nullptr){
            throw std::out_of_range("List already empty!");
        }
        if (head->next == nullptr){
            delete head;
        }

        node* temp = head;;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        if (temp->prev != nullptr){
            temp->prev->next = nullptr;
        }
        delete temp;
    }

    void addAt(int val, int index){
        if(head == nullptr){
            addFront(val);
        }
        else{
            node* new_node = new node(val);
            node* temp = head;
            for(int i=0; i<index; ++i){
                temp = temp->next;
            }
            new_node->next = temp->next;
            new_node->prev = temp;
            if(temp->next != nullptr){
                temp->next->prev = new_node;
            }
            temp->next = new_node;
        }
    }

    void rmAt(int index){
        if(head == nullptr){
            throw std::out_of_range("List already empty!");
        }

        if(index == 0){
            rmFront();
        }
        else{
            node* temp = head;
            for(int i=0; i<index; ++i){
                temp = temp->next;
                if (temp == nullptr){
                    throw std::out_of_range("Invalid index!");
                }
            }

            if(temp->prev != nullptr){
                temp->prev->next = temp->next;
            }

            if(temp->next != nullptr){
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
    }

    void lookAt(int index){
        if(index<0){
            throw std::out_of_range("Invalid index!");
        }
        if(head == nullptr){
            throw std::out_of_range("List is empty!");
        }

        node* temp = head;
        for(int i=0; i<index; ++i){
            temp = temp->next;
            if(temp == nullptr){
                throw std::out_of_range("Invalid index!");
            }
        }
        if(temp == nullptr){
            throw std::out_of_range("Invalid index!");
        }
        int x = temp->data;
    }
};


// -------------- SINGLY LINKED LIST --------------

// NODE
class snode{
public:
    int data;
    snode* next;

    snode(int d) {
        data = d;
        next = nullptr;
    }
};

// LIST
class slist{
private:
    snode* head;

public:
    slist(){
        head = nullptr;
    };
    
    void addFront(int val){
        snode* new_node = new snode(val);
        new_node->next = head;
        head = new_node;
    }

    void rmFront(){
        if(head == nullptr){
            throw std::out_of_range("List already empty!");
        }
        snode* temp = head;
        head = head->next;
        delete temp;
    }

    void addBack(int val){
        snode* new_node = new snode(val);

        if(head == nullptr){
            head = new_node;
            head->next = nullptr;
            return;
        }

        snode* temp = head;

        while(temp->next != nullptr){      
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = nullptr;
    }

    void rmBack(){ 
        snode* temp = head;

        while(temp->next->next != nullptr){      
            temp = temp->next;
        }
        snode* del;
        del = temp->next;
        temp = nullptr;
        delete del;
    }

    void addAt(int val, int index){
        snode* temp = head;
        snode* new_node = new snode(val);
        for(int i=0; i<index; ++i){
            if(temp == nullptr){
                throw std::out_of_range("Invalid index");
            }
            else{
                temp = temp->next;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void rmAt(int index){
        snode* temp = head;
        for(int i=0; i<index; ++i){
            if(temp == nullptr){
                throw std::out_of_range("Invalid index");
            }
            else{
                temp = temp->next;
            }
        }
        snode* del;
        del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void lookAt(int index){
        if(index<0){
            throw std::out_of_range("Invalid index!");
        }
        if(head == nullptr){
            throw std::out_of_range("List is empty!");
        }

        snode* temp = head;
        for(int i=0; i<index; ++i){
            temp = temp->next;
            if(temp == nullptr){
                throw std::out_of_range("Invalid index!");
            }
        }
        if(temp == nullptr){
            throw std::out_of_range("Invalid index!");
        }
        int x = temp->data;
    }
};

//-------------------- DYNAMIC ARRAY ----------------------

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
    darray() {
        capacity = 1;          
        size = 0;                   
        data = new int[capacity];   
    }

    void insFront(int val){
        if(size == capacity){
            resize();
        }
        
        for(int i=size-1; i>=0; i--){
            data[i+1] = data[i];
        }
        data[0] = val;
        size++;
    }

    void insBack(int val){
        if(size == capacity){
            resize();
        }
        data[size] = val;
        size++;
    }

    void insAt(int val, int index){
        if(size == capacity){
            resize();
        }

        if(index == size){
            insBack(val);
        }
        else if(index == 0){
            insFront(val);
        }
        else{
        
            if(index > capacity){
                throw std::out_of_range("Index out of bounds");
            }

            for(int i=size-1; i>=index; i--){
                data[i+1] = data[i];
            }
            data[index] = val;
            size++;
        }
    }

    void eraseFront(){
        for(int i=0; i<size; i++){
            data[i] = data[i+1];
        }
        size--;
    }

    void eraseBack(){
        data[size-1] = 0;
        size--;
    }

    void eraseAt(int index){
        data[index] = 0;
        for(int i=index+1; i<size; i++){
            data[i-1] = data[i];
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
        if(index<0 || index>size){
            throw std::out_of_range("Index out of bounds!");
        }
        data[index];
    }
};

// -------------- TESTS --------------

void test(){
    std::cout << "N;ARR;SLL;DLL\n";

    std::vector<int> v = {10, 100, 1000, 10000};
    int samples = 100;

    for (int N : v){
        long long ARR_TIME = 0, SL_TIME = 0, DL_TIME = 0;

        for(int i=0; i<samples; ++i) {
            darray arr;
            slist sl;
            dlist dl;
            
            for(int j=0; j<N; ++j) {
                arr.insBack(i);
                sl.addBack(i);
                dl.addBack(i);
            }

            // ARRAY MEASUREMENT
            auto start = std::chrono::high_resolution_clock::now();
            arr.peekAt(N/2);
            auto end = std::chrono::high_resolution_clock::now();
            ARR_TIME += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            // SINGLY LINKED LIST MEASUREMENT
            start = std::chrono::high_resolution_clock::now();
            sl.lookAt(N/2);
            end = std::chrono::high_resolution_clock::now();
            SL_TIME += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            // DOUBLY LINKED LIST MEASUREMENT
            start = std::chrono::high_resolution_clock::now();
            dl.lookAt(N/2);
            end = std::chrono::high_resolution_clock::now();
            DL_TIME += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }

        // RESULTS
        std::cout<<N<<";"<<(ARR_TIME/samples)<<";"<<(SL_TIME/samples)<<";"<<(DL_TIME/samples)<<"\n";
    }
    std::cout << "\n";
}

int main(){
    test();
    return 0;
}