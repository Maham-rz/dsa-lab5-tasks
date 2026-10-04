#include<iostream>
using namespace std;
#define MAX 100

class stack{
	public:
		int top;
		string arr[MAX];
		
		stack(){
			top=-1;
			
		}
		
	bool isfull(){
		return top>=MAX-1;
	}
	
	bool isempty(){
		return top==-1;
	}
	
	bool push(string x){
		if(isfull()){
			cout<<"overflow condition"<<endl;
			return false;
		}
		
	arr[++top]=x;
		cout<<"value "<<x<<" pushed"<<endl;
	return true;

		
	}
	string pop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
		  
		}
		
		
	return arr[top--];
		
	}
};

class queue{
	public :
		string arr[MAX];
		int front;
		int rear;
		int count;
		
		queue(){
			front=0;
			count=0;
			rear=-1;
			
		}
		
		bool isempty(){
			return count==0;
		}
		
		bool isfull(){
			return count==MAX;
		}
		
		void enqueue(string x){
			if(isfull()){
				cout<<"full q"<<endl;
			}
			
			rear=(rear+1)%MAX;
			arr[rear]=x;
			count++;
		}
		
		string dequeue(){
			if(isempty()){
				cout<<"q is empty"<<endl;
				
			}
			string x=arr[front];
			front =(front+1)%MAX;
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

void reversefirstK(queue &q,int k){
	if(k<=0||k>MAX){
        return;
    }
    
    stack s;
    for(int i=0;i<k;i++){
    	s.push(q.dequeue());
	}
	
	while(!s.isempty()){
		q.enqueue(s.pop());
	}
	
	int rem=q.count-k;
	for (int i=0;i<rem;i++){
		q.enqueue(q.dequeue());
	}

	
}


int main(){
	  queue q;

    q.enqueue("J1");
    q.enqueue("J2");
    q.enqueue("J3");
    q.enqueue("J4");
    q.enqueue("J5");
    q.enqueue("J6");
    q.enqueue("J7");

    cout<<"Original queue: ";
    q.display();

    int k=3;
    reversefirstK(q,k);

    cout<<"Queue after reversing first "<<k<<" elements: ";
    q.display();

    return 0;
	
}
