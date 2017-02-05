#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string getFilename(char *filename);
string getOutFilename(string filename);
string getInFilename(string filename);
string getSufName(string filename);
void getRecord(ifstream &inFile, string filename, letter *record);

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);

	string filename = getFilename(argv[1]);
	string ouFilename = argv[1];
	string inFilename = getInFilename(filename, getSufName(ouFilename));
	string coFilename = getCoFilename(filename);

	string code = "";
	istringstream readCode(ouFilename);
	ifstream inFile(coFilename);
	char c;
	letter record[256];
	while(readCode.get(c)){
		code += c;
		if(code.length() == 256 || (readCode.eof() && code.length())){
			getRecord(inFile, coFilename, record);
			HuffmanTree tree(record);
			tree.translate(code);
		}
	}
}

string getFilename(char *filename) {
	istringstream readFile(filename);
	string inFile;
	getline(readFile, inFile, '.');
	readFile.close();
	return inFile;
}

string getSufName(string filename) {
	istringstream sufFile(filename);
	string sufName;
	getline(sufFile, sufName, '.');
	getline(suffile, sufName, '.');
	return sufName;
}

string getInFilename(string filename, string sufName) {
	return filename + "." + sufName;
}

string getCoFilename(string filename) {
	return filename + ".cfg";
}

void getRecord(ifstream &inFile, string filename, letter *record) {
	for(int i = 0; i < 256; ++i){
		inFile.read(reinterpret_cast<char *> (&record[i]), sizeof(record[i]));
	}
}
