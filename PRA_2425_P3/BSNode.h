#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
    	T elem;
    	BSNode* left;
    	BSNode* right;

    	BSNode(T elem, BSNode* left = nullptr, BSNode* right = nullptr)
        	: elem(elem), left(left), right(right) {}

    	~BSNode() = default;

    	friend std::ostream& operator<<(std::ostream& out, const BSNode& node) {
        	out << node.elem;
        	return out;
   	 }
};

#endif
