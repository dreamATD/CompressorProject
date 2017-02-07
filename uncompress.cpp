#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

typedef basic_string<unsigned char> ustring;

#include "HuffmanNode.hpp"
#include "HuffmanTree.hpp"

string getFilename(char *filename);
string getOutFilename(string filename);
string getInFilename(string filename, string sufFile);
string getSufName(string filename);
string getCoFilename(string filename);
void getRecord(ifstream &inFile, letter *record);

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);

	string filename = getFilename(argv[1]);
	string ouFilename = argv[1];
	string inFilename = getInFilename(filename, getSufName(ouFilename));
	string coFilename = getCoFilename(filename);

	ifstream inCfgFile(coFilename);
	ifstream inOutFile(ouFilename);
	ofstream outInFile(inFilename);

	char c;
	ustring code;
	code.clear();
	letter record[256];

	int totalCounter;
	while (inCfgFile.read(reinterpret_cast<char *> (&totalCounter), sizeof(totalCounter))){
		getRecord(inCfgFile, record);
		HuffmanTree<letter> tree;
		tree.buildTree(record);
		tree.translate(inOutFile, outInFile, totalCounter);
	}
}

string getFilename(char *filename) {
	istringstream readFile(filename);
	string inFile;
	getline(readFile, inFile, '.');
	return inFile;
}

string getSufName(string filename) {
	istringstream sufFile(filename);
	string sufName;
	getline(sufFile, sufName, '.');
	getline(sufFile, sufName, '.');
	return sufName;
}

string getInFilename(string filename, string sufName) {
	return filename + "." + sufName + ".out";
}

string getCoFilename(string filename) {
	return filename + ".cfg";
}

void getRecord(ifstream &inFile, letter *record) {
	for(int i = 0; i < 256; ++i){
		inFile.read(reinterpret_cast<char *> (&record[i]), sizeof(record[i]));
	}
}
