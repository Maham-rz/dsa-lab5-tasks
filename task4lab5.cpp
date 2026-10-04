#include<iostream>
using namespace std;

#define MAX 6

class queue{
	public:
		int arr[MAX];
		int front;
		int rear;
		int count;
		
		queue(){
			front=0;
			rear=-1;
			count=0;
		}
		
		bool isempty(){
			return count==0;
		}
		
		bool isfull(){
			return count==MAX;
		}
		
		void enqueue(int x){
			if(isfull()){
				cout<<"Queue is full"<<endl;
				return;
			}
			
			rear=(rear+1)%MAX;
			arr[rear]=x;
			count++;
		}
		
		int dequeue(){
			if(isempty()){
				cout<<"Queue is empty"<<endl;
				return -1;
			}
			
			int x=arr[front];
			front=(front+1)%MAX;
			count--;
			
			return x;
		}
		
		void display(){
			for(int i=0;i<count;i++){
				cout<<arr[(front+i)%MAX]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	queue q;
	
	q.enqueue(101);
	q.enqueue(102);
	q.enqueue(103);
	q.enqueue(104);
	q.enqueue(105);
	q.enqueue(106);
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	q.enqueue(107);
	q.enqueue(108);
	q.enqueue(109);
	
	q.dequeue();
	q.dequeue();
	
	q.enqueue(110);
	
	q.dequeue();
	
	q.enqueue(111);
	q.enqueue(112);
	
	cout<<"Final boarding queue: ";
	q.display();
	
	cout<<"Final front = "<<q.front<<endl;
	cout<<"Final rear = "<<q.rear<<endl;
	
	return 0;
}
