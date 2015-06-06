#include "p2SString.h"
#include "p2DynArray.h"
#include "p2List.h"
#include <iostream>
#include <time.h>
using namespace std;
int fibonacci(int position){
	int anterior = 1;
	int anterior2 = 0;
	int actual = 0;
	int actual2 = 1;
	for (int i = 0; i <= position-1; i++){

		actual = anterior + anterior2;
		actual2 = actual;
		anterior2 = anterior;
		anterior = actual;
	}
	return actual2;

}
int main(int argc, char** argv)
{
	cout << fibonacci(6);
	
	/*
	p2DynArray<int> a;
	srand(time(NULL));
	for (unsigned int i = 0; i <= 4; i++){
		int r = rand() % 10;;
		a.PushBack(r);

	}

	for (int i = 0; i < a.Count(); i++){
		cout << *a.At(i);

	}
	a.flip();
	cout << endl;
	for (int i = 0; i < a.Count(); i++){
		cout << *a.At(i);

	}*/
	
	/*
	p2List<int> a;
	srand(time(NULL));
	for (unsigned int i = 0; i <= 10000; i++){
		int r = rand() % 100;;
		a.add(r);

	}
	a.add(9);
	a.add(8);
	a.add(7);
	a.add(6);
	a.add(5);
	a.add(4);
	a.add(3);
	
	
	cout << a.BubbleSort() << endl;


	for (int i = 0; i < a.count(); i++){
		cout << a[i];

	}


	
	



	cout << a[6];


	*/







	/*p2SString s1("   Hola mundo          ");
	s1.Trim();

	cout << s1.GetString() << s1.Length();*/
	
	getchar();










	return(0);
}