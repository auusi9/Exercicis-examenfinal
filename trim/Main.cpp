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
	/*
	
	p2DynArray<int> a;
	p2DynArray<int> b;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushBack(5);
	a.PushBack(6);

	for (int i = 0; i < a.Count(); i++){
		cout << *a.At(i);

	}
	cout << endl;
	a.Cut(1,2);

	for (int i = 0; i < a.Count(); i++){
		cout << *a.At(i);
		
	}*/
	
	p2SString s1("hola don pepito holaholahola");
	cout << s1.Find("hola") << endl;
	cout << s1.Substitute("hola", "papagayo");
	

	cout << s1.GetString() <<endl;
	
	



//	cout << a[6];

	
	//cout << fibonacci(6);
	/*
	p2List<int> a;
	p2List<int> b;
	srand(time(NULL));
	/*for (unsigned int i = 0; i <= 10000; i++){
		int r = rand() % 100;;
		a.add(r);

	}

	b.add(9);
	b.add(8);
	b.add(7);
	a.add(6);
	a.add(5);
	a.add(4);
	a.add(3);
	a.add(6);
	a.add(5);
	a.add(4);
	a.add(3);


	a.InsertMiddle(b);


	for (int i = 0; i < a.count(); i++){
		cout << a[i];

	}

	*/
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
	p2DynArray<int> a;
	p2DynArray<int> b;
	b.PushBack(2);
	b.PushBack(8);
	b.PushBack(4);
	b.PushBack(5);
	a.PushBack(1);
	a.PushBack(3);
	a += b;
	
	for (int i = 0; i < a.Count(); i++){
		cout << *a.At(i);

	}

	*/







	/*	p2List<int> a;
	p2List<int> b;
	
	a.add(9);
	a.add(8);
	a.add(7);
	b.add(6);
	b.add(5);
	b.add(4);
	b.add(3);
	for (int i = 0; i < a.count(); i++){
		cout << a[i];

	}
	cout << endl;
	a += b;
	for (int i = 0; i < a.count(); i++){
		cout << a[i];

	}*/
	
	getchar();










	return(0);
}