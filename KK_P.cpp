#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

template <typename vector>
vector add(vector v1, int n) {
	int i = 6;
	while(1) {
		try{
			v1.push_back(i + 0.5 - i * i);
			if (i > n + 6) throw 20;
		}
		catch(int e){
			cout << "Error memory\n";
			break;
		}
		
		i++;
	}

	return v1;
}

template <typename vector>
vector coppy(vector v1) {

	vector v2;
	
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		v2.push_back(*i);
	}
	return  v2; ;
}

int main(){
	vector<float> v1;
		
	for (int i = 1; i <= 5; i++)
		v1.push_back(i+0.5 - i*i);

	cout << "Output of begin and end: ";
	for (auto i = v1.begin(); i != v1.end(); ++i)
		cout << *i << " ";
	cout << endl;

	v1 = add(v1, 3);

	cout << "Output of begin and end: ";
	for (auto i = v1.begin(); i != v1.end(); ++i)
		cout << *i << " ";
	cout << endl;

	vector <float> v2;
	v2 = coppy(v1);
	sort(v2.begin(), v2.end());

	cout << "Output of begin and end: ";
	for (auto a : v2) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
