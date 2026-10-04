#include<iostream>
using namespace std;

#define MAX 6

class stack{
	public:
		int top;
		int arr[MAX];
		
		stack(){
			top=-1;
			
		}
		
	bool isfull(){
		return top>=MAX-1;
	}
	
	bool isempty(){
		return top==-1;
	}
	
	bool push(int x){
		if(isfull()){
			cout<<"overflow condition"<<endl;
			return false;
		}
		
	arr[++top]=x;
		cout<<"value "<<x<<" pushed"<<endl;
	return true;

		
	}
	int undo(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return  -1;
		}
		
		
	return arr[top--];
		
	}
	
	int peek(){
		if(isempty()){
			cout<<"empty stack"<<endl;
			return -1;
		}
		return arr[top];
	}
	
	void display(){
		if(isempty()){
			cout<<"epty";
			
		}
		
		for(int i=top;i>=0;i--){
			cout<<arr[i]<<"  ";
		}
		cout<<endl;
	}
};
int main(){
	
	stack s;
	s.push(12);
	s.push(25);
	s.push(17);
	s.push(31);
	s.push(44);
	s.push(19);
	cout<<"undoing3 times"<<endl;
	s.undo();
	s.undo();
	s.undo();
	cout<<"top is"<<s.peek();
	s.push(52);
	cout<<"undoing2 more  times "<<endl;
	s.undo();
	s.undo();
		cout<<"top is"<<s.peek()<<endl;
	s.display()	;

	return 0;
}
