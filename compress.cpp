#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
typedef basic_string<unsigned char> ustring;
#include "HuffmanNode.hpp"
#include "HuffmanTree.hpp"

const int TOTALLETTER = 2 * 1024 * 1024;

string getFilename(char *filename);
string getOutFilename(string filename);
string getCfgFilename(string filename);

vector<ustring> divideContent(ifstream &readFile);
void dealCompress(ustring content, ofstream &writeFile, ofstream &configFile);


int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);

	string filename = getFilename(argv[1]);
	string inFilename = argv[1];
	string ouFilename = getOutFilename(inFilename);
	string coFilename = getCfgFilename(filename);

	ifstream inInFile(inFilename);
	ofstream outOutFile(ouFilename);
	ofstream outCfgFile(coFilename);

	vector<ustring> content;
	content = divideContent(inInFile);

	for (auto oneContent = content.begin(); oneContent != content.end(); ++oneContent) {
		dealCompress(*oneContent, outOutFile, outCfgFile);
	}

	inInFile.close();
	outOutFile.close();
	outCfgFile.close();
}

string getFilename(char *filename) {
	istringstream readFile(filename);
	string inFile;
	getline(readFile, inFile, '.');
	return inFile;
}

string getOutFilename(string filename) {
	return filename + ".cpd";
}

string getCfgFilename(string filename) {
	return filename + ".cfg";
}

vector<ustring> divideContent(ifstream &readFile) {
	int pos = 0;
	ustring oneContent;
	oneContent.clear();
	vector<ustring> res;
	unsigned char cur;
	char ccur;
	while (readFile.get(ccur)) {
		cur = ccur;
		oneContent += cur;
		++pos;

		if (pos == TOTALLETTER) {
			pos = 0;
			res.push_back(oneContent);
			oneContent.clear();
		}
	}
	if(pos) res.push_back(oneContent);

	return res;
}

void dealCompress(ustring content, ofstream &writeFile, ofstream &configFile) {
	letter record[256];
	for (int i = 0; i < 256; ++i){
		record[i].initialize(i);
	}
	
	int totalCounter = 0;
	for (auto oneChar = content.begin(); oneChar != content.end(); ++oneChar) {	
		++record[(int)*oneChar];
		++totalCounter;
	}
	
	HuffmanTree<letter> tree;
	tree.buildTree(record);
	string decode[256];
	tree.getCode(tree.getRoot(), decode, "");

	configFile.write(reinterpret_cast<const char *> (&totalCounter), sizeof(totalCounter));
	for (int i = 0; i < 256; ++i) {
		configFile.write(reinterpret_cast <const char *> (&record[i]), sizeof(record[i]));
	}

	unsigned char curCode = 0;
	int pos = 0;
	for (auto oneChar = content.begin(); oneChar != content.end(); ++oneChar) {
		string nxtCode = decode[*oneChar];
		for (char oneBit: nxtCode) {
			curCode = curCode << 1 | (oneBit - '0');
			if (++pos == 8) {
				writeFile << curCode;
				pos = 0;
				curCode = 0;
			}
		}
	}
	if(pos){
		curCode <<= (8 - pos);
		writeFile << curCode;
	}
	//writeFile << writeCode;
}
