#include <iostream>

using namespace std;

int queue_arr[100];
int end_index = 0;
int start_index  =0;

int queue_size = 0;
int current_size = 0;

int first_time = 0;
void set_size(int qsize){
    queue_size = qsize; // biggest size
}
void  queue_push(int datum)
{
    //cout<<current_size<<" "<<end_index<<" "<<datum<<endl;
    if(current_size >= queue_size)
        cout<<"Stack is full"<<endl;
    else {
        current_size++;
        queue_arr[end_index] = datum;
        if(end_index >= queue_size -1)
            end_index = 0;
        else
            end_index++;
    }
}
int queue_pop(void){
    int data = 0;
    if(current_size == 0){
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        current_size--;
        data = queue_arr[start_index];
        if(start_index >= queue_size -1)
            start_index = 0;
        else
            start_index++;
    }
    return data;
}
int main()
{
    set_size(3);
    queue_push(1);
    queue_push(2);
    queue_push(3);
    queue_push(4);
    queue_push(5);
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    queue_push(7);
    queue_push(8);
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    while(1);
    return 0;
}
