// ----------------------------------------------------
// Array that resizes dynamically   -------------------
// ----------------------------------------------------

#ifndef __P2DYNARRAY_H__
#define __P2DYNARRAY_H__

#include <assert.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class VALUE>
class p2DynArray
{
private:

	VALUE*			data;
	unsigned int	mem_capacity;
	unsigned int	num_elements;

public:

	// Constructors
	p2DynArray() : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	p2DynArray(unsigned int capacity) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(capacity);
	}

	// Destructor
	~p2DynArray()
	{
		delete[] data;
	}

	// Operators
	VALUE& operator[](unsigned int index)
	{
		assert(index < num_elements);
		return data[index];
	}

	const VALUE& operator[](unsigned int index) const
	{
		assert(index < num_elements);
		return data[index];
	}

	const p2DynArray<VALUE>& operator +=(const p2DynArray<VALUE>& dynarray ){

		for (int i = 0; i < dynarray.Count(); i++){

			PushBack(dynarray[i]);
		}

		return (*this);// Exercicis cut array dynamic, operador dasignacio, += llista enllaçada, prefix.
		//Exercicis arbres trobar una dada, propagar valors :cada fill suma el valor del seu pare, llista dels nodes que no tenen fill.agafar un node del arbre i que sigui fill d'un altre node. buscar per amplada(no es recursiu i sha de fer servir una cua).detectar paraules que comencin i acabin igual recursiu palindromes clase cadena.
	}


	// Data Management
	void PushBack(const VALUE& element)
	{
		if(num_elements >= mem_capacity)
		{
			Alloc(mem_capacity + DYN_ARRAY_BLOCK_SIZE);
		}

		data[num_elements++] = element;
	}
	void swap(VALUE& a, VALUE& b)
	{
		VALUE tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	int fibonacci(int position){
		int anterior = 1;
		int anterior2  = 0 ;
		int actual = 0 ;
		int actual2 = 0;
		for (int i = 0; i < position; i++){

			actual = anterior + anterior2;
			actual2 = actual;
			anterior2 = anterior;
			anterior = actual;
		}
		return actual2;

	}
	void Middle(const p2DynArray<VALUE>& mitg){

		int j = num_elements / 2;
		for (int i = 0; i < mitg.num_elements; i++){
			Insert(mitg.data[i], i + (j));
		}
	}

	void flip(){

		for (unsigned int i = 0; i < num_elements; i++){
			if (i == (num_elements - i-1)) return;
			swap(data[i], data[num_elements - i-1]);}
	}

	bool Pop(VALUE& value)
	{
		if(num_elements > 0)
		{
			value = data[--num_elements];
			return true;
		}
		return false;
	}
	void Cut(unsigned int pos1, unsigned int pos2){

		if (pos2 == 0){

			num_elements = pos1;

		}

		else if (pos2 < pos1)return;

		else{

			for (int i = 0; i+pos2  < num_elements; i++){

				data[pos1 + i] = data[pos2 + i + 1];
				
			}
			num_elements-=(pos2-pos1+1);
		}
	}

	void Clear()
	{
		num_elements = 0;
	}

	bool Insert(const VALUE& element, unsigned int position)
	{
		if(position > num_elements)
			return false;

		if(position == num_elements)
		{
			PushBack(element);
			return true;
		}

		if(num_elements + 1 > mem_capacity)
			Alloc(mem_capacity + DYN_ARRAY_BLOCK_SIZE);

		for(unsigned int i = num_elements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++num_elements;

		return true;
	}

	VALUE* At(unsigned int index)
	{
		VALUE* result = NULL;
		
		if(index < num_elements)
			return result = &data[index];
		
		return result;
	}

	const VALUE* At(unsigned int index) const
	{
		VALUE* result = NULL;

		if(index < num_elements)
			return result = &data[index];

		return result;
	}

	// Utils
	unsigned int GetCapacity() const
	{
		return mem_capacity;
	}

	unsigned int Count() const
	{
		return num_elements;
	}

private:
	
	// Private Utils
	void Alloc(unsigned int mem)
	{
		VALUE* tmp = data;

		mem_capacity = mem;
		data = new VALUE[mem_capacity];

		if(num_elements > mem_capacity)
			num_elements = mem_capacity;

		if(tmp != NULL)
		{
			for(unsigned int i = 0; i < num_elements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}
};

#endif // __P2DYNARRAY_H__