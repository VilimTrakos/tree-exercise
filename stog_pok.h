#include<cstdlib>
#include<iostream>

template<typename elementtype>
class Stack{
	private:
		struct stck{
			elementtype val;
			stck *next;
		};
		stck *S;
	public:
		Stack(){
			S = new stck;
			(*S).next = NULL;
		}
		bool IsEmpty(){
			return (*S).next == NULL;
		}
		elementtype Top(){
			if((*S).next == NULL){
				std::cout << "Stog je prazan" << std::endl;
				exit(EXIT_FAILURE);
			}
			else
				return (*(*S).next).val;
		}
		void Push (elementtype x){
			stck *p = new stck;
			(*p).val = x;
			(*p).next = (*S).next;
			(*S).next = p;
		}
		void Pop(){
			if((*S).next == NULL){
				std::cout << "Stog je prazan" << std::endl;
				exit(EXIT_FAILURE);
			}
			else{
				stck *p = S;
				S = (*S).next;
				delete p;
			}
		}
		~Stack(){
			while (S != NULL){
				stck *p = S;
				S = (*S).next;
				delete p;
			}
		}
};
