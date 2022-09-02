#include <string>

class Node {
    private:
        std::string word;
        int id;
    public:
        Node(std::string line, int id);
        Node(const Node& node);
        std::string getWord() const;
        int getId() const;
};