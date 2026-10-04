#include<iostream>
using namespace std;

#define MAX 100

class stack{
	public:
		int top;
		int arr[MAX];
		
		stack(){
			top=-1;
		}
		
		bool isempty(){
			return top==-1;
		}
		
		bool isfull(){
			return top>=MAX-1;
		}
		
		void push(int x){
			if(isfull()){
				cout<<"Stack is full"<<endl;
				return;
			}
			
			arr[++top]=x;
		}
		
		int pop(){
			if(isempty()){
				cout<<"Stack is empty"<<endl;
				return -1;
			}
			
			return arr[top--];
		}
};

class MyQueue{
	public:
		stack incoming;
		stack outgoing;
		
		void enqueue(int x){
			incoming.push(x);
		}
		
		int dequeue(){
			if(outgoing.isempty()){
				
				while(!incoming.isempty()){
					outgoing.push(incoming.pop());
				}
			}
			
			return outgoing.pop();
		}
};

int main(){
	MyQueue q;
	
	q.enqueue(1); // A
	q.enqueue(2); // B
	
	cout<<"Dequeue: "<<q.dequeue()<<endl;
	
	q.enqueue(3); // C
	
	cout<<"Dequeue: "<<q.dequeue()<<endl;
	cout<<"Dequeue: "<<q.dequeue()<<endl;
	
	return 0;
}
