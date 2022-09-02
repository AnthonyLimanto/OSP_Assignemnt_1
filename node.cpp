#include "node.h"

Node::Node(std::string line, int num) {
    word = line;
    id = num;
}
Node::Node(const Node& node) {
    word = node.getWord();
    id = node.getId();
}

std::string Node::getWord() const{
    return word;
}

int Node::getId() const{
    return id;
}