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
		
		bool isempty(){
			return top==-1;
		}
		
		bool isfull(){
			return top>=MAX-1;
		}
	string 	push(string word){
		if(isfull()){
			cout<<"full stack"<<endl;
		
		}
	return	arr[++top]=word;
		
		
	}
	
	string pop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			
		}
		
		return arr[top--];
	}
	
	string peek(){
		if(isempty()){
			cout<<"empty"<<endl;
		}
		
		return arr[top];
	}
	
	void clear(){
		top=-1;
	}


};

class texteditor{
	public:
		stack  undostack;
		stack redostack;
		
		void type(string word){
			undostack.push(word);
			
			redostack.clear();
		}
		
		void undo(){
			if(undostack.isempty()){
				cout<<"stack empty"<<endl;
			}
		string word=	undostack.pop();
			redostack.push(word);
					}
		
		void redo(){
			if(redostack.isempty()){
				cout<<"stack empty"<<endl;
			}
		string word=redostack.pop();
			undostack.push(word);
			
		}	
		
		void print(){
			for(int i=0;i<=undostack.top;i++){
				cout<<undostack.arr[i];
				
				if(i<undostack.top)
			{
					cout<<" ";
				}
			}
			
			if(undostack.isempty()){
				cout<<"empty";
			}
			
			cout<<endl;
		}		
};



int main(){
	texteditor s;

    s.type("Hello");
    s.print();

    s.type("World");
    s.print();

    s.undo();
    s.print();

    s.redo();
    s.print();

    s.undo();
    s.print();

    s.type("There");
    s.print();

    s.redo();
    s.print();

	
	
	
	return  0 ;
}
