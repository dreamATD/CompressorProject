#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

HuffmanNode::HuffmanNode(T_val, HuffmanNode *_left, HuffmanNode *_right):
	val(_val), left(_left), right(_right) {}
