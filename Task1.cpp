#include <iostream>
#include <string>
#include <regex>
#include <fstream>

void Task1filter();


int main (void) {


    Task1filter();


    return EXIT_SUCCESS;
}

void Task1filter() {


    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 0;
    int counter7 = 0;
    int counter8 = 0;
    int counter9 = 0;
    int counter10 = 0;
    int counter11 = 0;
    int counter12 = 0;
    int counter13 = 0;
    int counter14 = 0;
    int counter15 = 0;
    
    std::cout << "Enter Input File" << std::endl;
    std::string filename;
    std::cin >> filename;


    std::fstream file(filename);
    std::string line;

    std::smatch match;
    std::regex re("^[a-z]*$");

    std::vector <std::string> word_list;
    
    while(getline(file,line)) {

        
        if (regex_search(line, match, re)) {
            word_list.push_back(match.str(0));
        }
    }
    random_shuffle(std::begin(word_list), std::end(word_list));

    std::ofstream myFile("Cleanfile.txt");

    for (long unsigned int i = 0; i < word_list.size(); i++)
    {   
        if (word_list[i].size() == 3) {
            counter3++;
        }
        if (word_list[i].size() == 4) {
            counter4++;
        }
        if (word_list[i].size() == 5) {
            counter5++;
        }
        if (word_list[i].size() == 6) {
            counter6++;
        }
        if (word_list[i].size() == 7) {
            counter7++;
        }
        if (word_list[i].size() == 8) {
            counter8++;
        }
        if (word_list[i].size() == 9) {
            counter9++;
        }
        if (word_list[i].size() == 10) {
            counter10++;
        }
        if (word_list[i].size() == 11) {
            counter11++;
        }
        if (word_list[i].size() == 12) {
            counter12++;
        }
        if (word_list[i].size() == 13) {
            counter13++;
        }
        if (word_list[i].size() == 14) {
            counter14++;
        }
        if (word_list[i].size() == 15) {
            counter15++;
        }
        myFile << word_list[i] << std::endl;
    }

    std::cout << "Number of word of 3 length" << counter3 << std::endl;
    std::cout << "Number of word of 4 length" << counter4 << std::endl;
    std::cout << "Number of word of 5 length" << counter5 << std::endl;
    std::cout << "Number of word of 6 length" << counter6 << std::endl;
    std::cout << "Number of word of 7 length" << counter7 << std::endl;
    std::cout << "Number of word of 8 length" << counter8 << std::endl;
    std::cout << "Number of word of 9 length" << counter9 << std::endl;
    std::cout << "Number of word of 10 length" << counter10 << std::endl;
    std::cout << "Number of word of 11 length" << counter11 << std::endl;
    std::cout << "Number of word of 12 length" << counter12 << std::endl;
    std::cout << "Number of word of 13 length" << counter13 << std::endl;
    std::cout << "Number of word of 14 length" << counter14 << std::endl;
    std::cout << "Number of word of 15 length" << counter15 << std::endl;

    myFile.close();
    file.close();
}

