#include <fstream>
#include <iostream>
using namespace std;

int fileSize(char* path) {
	std::ifstream fin(path, std::ios::binary | std::ios::in);

	int length = 0;
	while (fin.get() != EOF) {
		length++;
	}

	fin.close();

	return length;
}
void writeData(char* path, char* data) {
	int size = 0;
	for (char* i = data; *i != '\0'; i++) {
		size++;
	}
	ofstream outfile(path, ios::binary | ios::out);
	outfile.write((char*)data, size);
	outfile.close();
}
void readData(char* path, char* data) {
	int size = fileSize(path);
	ifstream infile(path, ios::binary | ios::in);
	infile.read((char*)data, size);
	infile.close();
}
bool isLetter(char* c) {
	char unChar[] = "`~!@#$%^&*()_-+={}[];:'\",<.>/?\\|¹ ";
	for (int i = 0; i < sizeof(unChar) / sizeof(unChar[0]); i++)
	{
		if (*c == unChar[i])
		{
			return false;
		}
	}

	return true;
}
char* Result(char* path, char* data) {
	writeData(path, data);
	readData(path, data);
	int size = fileSize(path);

	char* resultData = new char[size];
	int k = 0;
	for (char* i = data; i < data + size; i++) {
		if (isLetter(i)) {
			resultData[k++] = *i;
		}
	}
	resultData[k] = '\0';
	return resultData;
}

int main() {
	char* path = new char[9]{ "data.txt" };
	char* data = new char[256]{ "asd, &gsj & Gsdg&&hjsd(" };
	data = Result(path, data);

	cout<< data<< endl;
}