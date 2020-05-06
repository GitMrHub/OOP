#include <iostream>
#include <deque>
using namespace std;

template<class T>
class Fraction {

private:
	deque<T> fraction;

public:

	void push_back(T i) {
		fraction.push_back(i);
	}

	void push_front(T i) {
		fraction.push_front(i);
	}

	void pop_back(T i) {
		fraction.pop_back(i);
	}

	void pop_front(T i) {
		fraction.pop_front(i);
	}

	void swap(T i, T j) {
		fraction.swap(i, j);
	}

	void clear() {
		fraction.clear();
	}

	T& at(int num){
		if ((num < 0) || (num >= fraction.size())){
			throw exception("This number not enter to deque");
		}
		else{
			return fraction[num];
		}
	}

	int size() {
		return fraction.size();
	}

	bool empty() {
		return fraction.empty();
	}

	int maxsize(){
		return fraction.max_size();
	}

	T& operator[](int num)
	{
		return fraction[num];
	}
};

int main(){
	Fraction <float> test;
	
	try{
		
		for (int i = 0; i < 5; i++){
			test.push_back(i+0.5);
			cout << test[i] << endl;
		}
		test.at(7);
	}

	catch (const exception& ex){
		cout << ex.what() << endl;
	}

	return 0;
}