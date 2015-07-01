#ifndef __p2SString_H__
#define __p2SString_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#define TMP_STRING_SIZE	4096

class p2SString
{
private:

	char* str;
	unsigned int size;

public:

	// Constructors
	p2SString()
	{
		Alloc(1);
		Clear();
	}

	p2SString(unsigned int size)
	{
		if(size > 0)
			Alloc(size);
		else
			Alloc(1);

		Clear();
	}

	p2SString(const p2SString& string)
	{
		Alloc(string.size);
		strcpy_s(str, size, string.str);
	}

	p2SString(const char *format, ...)
	{
		size = 0;

		if(format != NULL)
		{
			static char tmp[TMP_STRING_SIZE];
			static va_list  ap;

			// Construct the string from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);

			if(res > 0)
			{
				Alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if(size == 0)
		{
			Alloc(1);
			Clear();
		}
	}
	


	
	
	// Destructor
	virtual ~p2SString()
	{
		if(str != NULL)
			delete[] str;
	}

	// Operators
	bool operator== (const p2SString& string) const
	{
		return strcmp(string.str, str) == 0;
	}

	bool operator== (const char* string) const
	{
		if(string != NULL)
			return strcmp(string, str) == 0;
		return false;
	}

	bool operator!= (const p2SString& string) const
	{
		return strcmp(string.str, str) != 0;
	}

	bool operator!= (const char* string) const
	{
		if(string != NULL)
			return strcmp(string, str) != 0;
		return true;
	}
	
	const p2SString& operator= (const p2SString& string)
	{
		if(string.Length() + 1 > size)
		{
			delete[] str;
			Alloc(string.Length() + 1);
		}
		else
			Clear();

		strcpy_s(str, size, string.str);

		return(*this);
	}

	const p2SString& operator= (const char* string)
	{
		if(string != NULL)
		{
			if(strlen(string) + 1 > size)
			{
				delete[] str;
				Alloc(strlen(string)+1);
			}
			else
				Clear();

			strcpy_s(str, size, string);
		}
		else
		{
			Clear();
		}

		return(*this);
	}
	
	const p2SString& operator+= (const p2SString& string)
	{
		unsigned int need_size = string.Length() + Length() + 1;

		if(need_size > size)
		{
			char* tmp = str;
			Alloc(need_size);
			strcpy_s(str, size, tmp);
			delete[] tmp;
		}

		strcat_s(str, size, string.str);

		return(*this);
	}

	const p2SString& operator+= (const char* string)
	{
		if(string != NULL)
		{
			unsigned int need_size = strlen(string) + Length() + 1;

			if(need_size > size)
			{
				char* tmp = str;
				Alloc(need_size);
				strcpy_s(str, size, tmp);
				delete[] tmp;
			}

			strcat_s(str, size, string);
		}

		return(*this);
	}

	unsigned int Find(const char* string) const{
		unsigned int ret=0;
		if (string != NULL)
		{
			unsigned int len = strlen(string);

			for (unsigned int i = 0; i < size - len; ++i)
			{
				if (strncmp(string, &str[i], len) == 0)
				{
					i += len-1;
					ret++;
				}
			}
			
		}
		return ret;
	}

	void Substitute(const char* string, const char* string2){

		unsigned int num =  Find(string);
		int len = strlen(string);
		int len2 = strlen(string2);

		if (strlen(string) < strlen(string2)){

			int dif = len2 - len;
			Alloc(size + (dif*num)-1);

		}

		while (num != 0){
			

			for (unsigned int i = 0; i < size - len; ++i)
			{
				if (strncmp(string, &str[i], len) == 0)
				{
					char* tmp = str;
					for (int j =0; j < len2; j++){

						str[i + j] = string2[j];
					}
					for (int j = 0; j < len2; j++){

						str[i + j+len2] = tmp[i+len+j];
					}
					
				}
			}





			num--;
		}


	}

	void Cut(unsigned int pos1, unsigned int pos2){

		if (pos2 == 0){ str[pos1] = '\0'; return; }

		if (pos2 < pos1){ return;}

			for (int i = 0; i < Length(); i++){

				str[pos1 + i] = str[pos2 + i + 1];

			}//exercici pasar un caracter i que s'esborrin tots les lletres, intercanviar paraules, incrementar espais
	}	

	void Deletechar(const char leter){
		
		for (int i = 0; i < Length(); i++){

			if (str[i] == leter){

				for (int j = i; j < Length(); j++){

					str[j] = str[j + 1];
					
				}
				i--;
			}

		}



	}
	void Trim(){


		 int j=0;
		for (unsigned int i = 0; i < size; i++){

			if (str[i] == ' '){
				j++;
			}
			else   i = size;
		}

		char* tmp = str;

		for (unsigned int k = 0; k < size; k++){
			str[k] = tmp[j + k];
		}
		for ( int i = strlen(str)-1; i > 0; --i){

			if (str[i] == ' '){
				str[i] = '\0';
			}
			else  i = -1;
		}


		

	}

	// Utils
	unsigned int Length() const
	{
		return strlen(str);
	}

	void Clear()
	{
		str[0] = '\0';
	}

	const char* GetString() const
	{
		return str;
	}

	unsigned int GetCapacity() const
	{
		return size;
	}

private:

	void Alloc(unsigned int requiered_memory)
	{
		size = requiered_memory;
		str = new char[size];
	}

};

#endif // __p2SString_H__