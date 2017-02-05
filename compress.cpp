#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

const int TOTALLETTER = 2 * 1024 * 1024;

string getFilename(char *filename);
string getOutFilename(string filename);
string getCfgFilename(string filename);

vector<string> divideContent(string filename);
void dealCompress(string content, string ouFilename, string coFilename);


int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);

	string filename = getFilename(argv[1]);
	string inFilename = argv[1];
	string ouFilename = getOuFilename(inFilename);
	string coFilename = getCofilename(filename);

	vector<string> content;
	content = divideContent(inFilename);

	for (auto oneContent = content.begin(); oneContent != content.end(); ++oneContent) {
		dealCompress(*oneContent, ouFilename, coFilename);
	}
}

string getFilename(char *filename) {
	istringstream readFile(filename);
	string inFile;
	getline(readFile, inFile, '.');
	readFile.close();
	return inFile;
}

string getOuFilename(string filename) {
	return filename + ".cpd";
}

string getCoFilename(string filename) {
	return filename + ".cfg";
}

vector<string> divideContent(string filename) {
	ifstream readFile(filename);

	int pos = 0;
	string oneContent = "";
	vector<string> res;
	while (!readFile.eof()) {
		char cur;
		readFile >> cur;
		oneContent += cur;
		++pos;

		if (pos == TOTALLETTER) {
			pos = 0;
			res.push_back(oneContent);
		}
	}

	return res;
}

void dealCompress(string content, string ouFilename, string coFilename) {
	letter record[256];
	for (int i = 0; i < 256; ++i){
		record[i] = i;
		record[i].counter = 0;
	}

	for (auto oneChar = content.begin(); oneChar != content.end(); ++oneChar) {	
		++record[(int)*oneChar];
	}

	HuffmanTree tree(record);

	iofstream configFile(coFilename, ios::end);
	for (char i = 0; i < 256; ++i) {
		pair<char, int> cur = make_pair(i, record[i].counter);
		configFile.write(reinterpret_cast<const char *> (&cur), sizeof(cur));
	}
	configFile.close();

	iofstream writeFile(ouFilename, ios::end);
	char curCode = 0;
	string writeCode = "";
	pos = 0;
	for (auto oneChar = content.begin(); oneChar != content.end(); ++oneChar) {
		nxtCode = record[*onechar].code;
		for (auto oneBit = nxtCode.begin(); oneBit != nxtCode.end(); ++oneBit) {
			curCode = curCode << 1 | (*oneBit - '0');
			if (++pos == 8) {
				writeCode = writeCode + curCode;
			}
		}
	}
	writeFile << writeCode;
	writeFile.close();
}
