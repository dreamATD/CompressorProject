#ifndef _HuffmanTree_
#define _HuffmanTree_

class HuffmanTree{
private:
	HuffmanNode root;
public:
	HuffmanTree(letter* record);
	~HuffmanTree();
	translate(string code);
};

#endif
