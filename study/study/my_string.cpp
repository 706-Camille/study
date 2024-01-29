#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

class string {
	char* str;
	int len;


	public :
		string(char c, int n);
		string(const char* s);
		string(const string& s);
		~string();

		const char* get_string();
		void add_string(const string& s);
		void copy_string(const string& s);
		int strlen();
};

string::string(char c, int n) {
	len = n;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = 'c';
	str[len] = '\0';
}

string::string(const char* s) {
	
	len = std::strlen(s);

	str = new char[len + 1];

	for (int i = 0; i < len; i++) {
		str[i] = s[i];
	}
	str[len] = '\0';

}
string::string(const string& s) {
	len = s.len;
	str = new char[len + 1];
	
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
	str[len] = '\0';
}

string::~string(){
	if (str != NULL)
	{
		delete[] str;
	}
}

const char* string::get_string() {
	return str;
}

void string::add_string(const string& s) {
	int total_len = this->len + s.len;
	char* string_buffer = new char[total_len + 1];
	
	for (int i = 0; i < this->len; i++)
		string_buffer[i] = this->str[i];

	for (int i = this->len; i < total_len; i++)
		string_buffer[i] = s.str[i - this->len];

	string_buffer[total_len] = '\0';

	delete[] this->str;

	str = string_buffer;
}

void string::copy_string(const string& s) {
	delete[] str;
	this->len = s.len;
	
	str = new char[len + 1];
	
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
	
	str[len] = '\0';
}

int string::strlen() {
	return len;
}

int main()
{
	string str = string('a', 6);
	string str2 = string("abcdef");
	str.add_string(str2);
	str.copy_string(str2);
	std::cout << str.get_string() << "\n" << str2.get_string();
	return 0;
}


