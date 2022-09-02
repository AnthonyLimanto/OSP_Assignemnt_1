#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <queue>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <bits/stdc++.h>



#define THIRD_CHAR 2

void map2();
void reduce2();
void mergeFiles(std::string file1, std::string file2, std::string output_file);
// node class is a container for the string from sorted
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

int main (void) {

    map2();
    reduce2();

    return EXIT_SUCCESS;
}

void map2() {
    // lambda function for custom compare in sort()
    auto compare = [&](const std::string& lhs, const std::string& rhs) -> bool {
    return lhs[THIRD_CHAR] < rhs[THIRD_CHAR];
};

    std::cout << "Enter Input File" << std::endl;
    std::string filename;
    std::cin >> filename;


    std::fstream file(filename);
    std::string line;

    std::vector <std::string> word_list_length_3;
    std::vector <std::string> word_list_length_4;
    std::vector <std::string> word_list_length_5;
    std::vector <std::string> word_list_length_6;
    std::vector <std::string> word_list_length_7;
    std::vector <std::string> word_list_length_8;
    std::vector <std::string> word_list_length_9;
    std::vector <std::string> word_list_length_10;
    std::vector <std::string> word_list_length_11;
    std::vector <std::string> word_list_length_12;
    std::vector <std::string> word_list_length_13;
    std::vector <std::string> word_list_length_14;
    std::vector <std::string> word_list_length_15;

    // makes 13 vectors each with different length words use plus 1 because it is one letter short for whatever reason i have no idea
    while(getline(file,line)) {
        if (line.size() == 3 + 1) {
            word_list_length_3.push_back(line);
        }
        if (line.size() == 4 + 1) {
            word_list_length_4.push_back(line);
        }
        if (line.size() == 5 + 1) {
            word_list_length_5.push_back(line);
        }
        if (line.size() == 6 + 1) {
            word_list_length_6.push_back(line);
        }
        if (line.size() == 7 + 1) {
            word_list_length_7.push_back(line);
        }
        if (line.size() == 8 + 1) {
            word_list_length_8.push_back(line);
        }
        if (line.size() == 9 + 1) {
            word_list_length_9.push_back(line);
        }
        if (line.size() == 10 + 1) {
            word_list_length_10.push_back(line);
        }
        if (line.size() == 11 + 1) {
            word_list_length_11.push_back(line);
        }
        if (line.size() == 12 + 1) {
            word_list_length_12.push_back(line);
        }
        if (line.size() == 13 + 1) {
            word_list_length_13.push_back(line);
        }
        if (line.size() == 14 + 1) {
            word_list_length_14.push_back(line);
        }
        if (line.size() == 15 + 1) {
            word_list_length_15.push_back(line);
        }
    }
    int process_number = 1;
    pid_t pid; 
    /* fork a child process */ 
    pid = fork(); 
    //    Makes 12 additional child processes for sort
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }
    if (pid > 0) {
        process_number++;
        pid = fork();
    }

    // each process sorts one vector depending on which process it is
    if (process_number == 1) {
        std::sort(word_list_length_3.begin(), word_list_length_3.end(), compare);
        std::ofstream myFile("Task2_wordlist/length3.txt");
        for (int i = 0; i < word_list_length_3.size(); i++) {
            myFile << word_list_length_3[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 2) {
        std::sort(word_list_length_4.begin(), word_list_length_4.end(), compare);
        std::ofstream myFile("Task2_wordlist/length4.txt");
        for (int i = 0;i <  word_list_length_4.size(); i++) {
            myFile << word_list_length_4[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 3) {
        std::sort(word_list_length_5.begin(), word_list_length_5.end(), compare);
        std::ofstream myFile("Task2_wordlist/length5.txt");
        for (int i = 0; i < word_list_length_5.size(); i++) {
            myFile << word_list_length_5[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 4) {
        std::sort(word_list_length_6.begin(), word_list_length_6.end(), compare);
        std::ofstream myFile("Task2_wordlist/length6.txt");
        for (int i = 0; i < word_list_length_6.size(); i++) {
            myFile << word_list_length_6[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 5) {
        std::sort(word_list_length_7.begin(), word_list_length_7.end(), compare);
        std::ofstream myFile("Task2_wordlist/length7.txt");
        for (int i = 0; i <  word_list_length_7.size(); i++) {
            myFile << word_list_length_7[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 6) {
        std::sort(word_list_length_8.begin(), word_list_length_8.end(), compare);
        std::ofstream myFile("Task2_wordlist/length8.txt");
        for (int i = 0; i < word_list_length_8.size(); i++) {
            myFile << word_list_length_8[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 7) {
        std::sort(word_list_length_9.begin(), word_list_length_9.end(), compare);
        std::ofstream myFile("Task2_wordlist/length9.txt");
        for (int i = 0; i < word_list_length_9.size(); i++) {
            myFile << word_list_length_9[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 8) {
        std::sort(word_list_length_10.begin(), word_list_length_10.end(), compare);
        std::ofstream myFile("Task2_wordlist/length10.txt");
        for (int i = 0; i < word_list_length_10.size(); i++) {
            myFile << word_list_length_10[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 9) {
        std::sort(word_list_length_11.begin(), word_list_length_11.end(), compare);
        std::ofstream myFile("Task2_wordlist/length11.txt");
        for (int i = 0; i < word_list_length_11.size(); i++) {
            myFile << word_list_length_11[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 10) {
        std::sort(word_list_length_12.begin(), word_list_length_12.end(), compare);
        std::ofstream myFile("Task2_wordlist/length12.txt");
        for (int i = 0; i < word_list_length_12.size(); i++) {
            myFile << word_list_length_12[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 11) {
        std::sort(word_list_length_13.begin(), word_list_length_13.end(), compare);
        std::ofstream myFile("Task2_wordlist/length13.txt");
        for (int i = 0; i < word_list_length_13.size(); i++) {
            myFile << word_list_length_13[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 12) {
        std::sort(word_list_length_14.begin(), word_list_length_14.end(), compare);
        std::ofstream myFile("Task2_wordlist/length14.txt");
        for (int i = 0;i <  word_list_length_14.size(); i++) {
            myFile << word_list_length_14[i] << std::endl;
        }
        myFile.close();
        
    }
    if (process_number == 13) {
        std::sort(word_list_length_15.begin(), word_list_length_15.end(), compare);
        std::ofstream myFile("Task2_wordlist/length15.txt");
        for (int i = 0;i <  word_list_length_15.size(); i++) {
            myFile << word_list_length_15[i] << std::endl;
        }
        myFile.close(); 
    }

    // exits for child processes
    if (pid == 0) {
        exit(EXIT_FAILURE);
    }
}

// custom compare for min heap
struct node_compare {
    bool operator()(const Node& lhs, const Node& rhs) const{
        return lhs.getWord()[THIRD_CHAR] > rhs.getWord()[THIRD_CHAR];
    }
};

void reduce2() {

    // files to read
    std::ifstream file1("Task2_wordlist/length3.txt");
    std::ifstream file2("Task2_wordlist/length4.txt");
    std::ifstream file3("Task2_wordlist/length5.txt");
    std::ifstream file4("Task2_wordlist/length6.txt");
    std::ifstream file5("Task2_wordlist/length7.txt");
    std::ifstream file6("Task2_wordlist/length8.txt");
    std::ifstream file7("Task2_wordlist/length9.txt");
    std::ifstream file8("Task2_wordlist/length10.txt");
    std::ifstream file9("Task2_wordlist/length11.txt");
    std::ifstream file10("Task2_wordlist/length12.txt");
    std::ifstream file11("Task2_wordlist/length13.txt");
    std::ifstream file12("Task2_wordlist/length14.txt");
    std::ifstream file13("Task2_wordlist/length15.txt");

    // output file
    std::ofstream output("Task2_wordlist/sorted.txt");

    // string for each file
    std::string line1;
    std::string line2;
    std::string line3;
    std::string line4;
    std::string line5;
    std::string line6;
    std::string line7;
    std::string line8;
    std::string line9;
    std::string line10;
    std::string line11;
    std::string line12;
    std::string line13;

    // gets strings to start with
    getline(file1, line1);
    getline(file2, line2);
    getline(file3, line3);
    getline(file4, line4);
    getline(file5, line5);
    getline(file6, line6);
    getline(file7, line7);
    getline(file8, line8);
    getline(file9, line9);
    getline(file10, line10);
    getline(file11, line11);
    getline(file12, line12);
    getline(file13, line13);



    // initilazing a vector to be min heap
    std::vector<Node> mh;
    mh.push_back(Node(line1, 1));
    mh.push_back(Node(line2, 2));
    mh.push_back(Node(line3, 3));
    mh.push_back(Node(line4, 4));
    mh.push_back(Node(line5, 5));
    mh.push_back(Node(line6, 6));
    mh.push_back(Node(line7, 7));
    mh.push_back(Node(line8, 8));
    mh.push_back(Node(line9, 9));
    mh.push_back(Node(line10, 10));
    mh.push_back(Node(line11, 11));
    mh.push_back(Node(line12, 12));
    mh.push_back(Node(line13, 13));

    make_heap(mh.begin(), mh.end(), node_compare());

    bool done = false;
    
    while (!done) {
        // reads lowest word then deletes
        Node tmp = mh.front();
        mh.erase(mh.begin());
        output << tmp.getWord() << std::endl;
        // for every file if not empty, finds which file the word came from then gets nextline in the same file
        if (!file1.eof()) {
            if (tmp.getId() == 1) {
                getline(file1, line1);
                mh.push_back(Node(line1, 1));
            }
        }
        if (!file2.eof()) {
            if (tmp.getId() == 2) {
                getline(file2, line2);
                mh.push_back(Node(line2, 2));
            }
        }
        if (!file3.eof()) {
            if (tmp.getId() == 3) {
                getline(file3, line3);
                mh.push_back(Node(line3, 3));
            }
        }
        if (!file4.eof()) {
            if (tmp.getId() == 4) {
                getline(file4, line4);
                mh.push_back(Node(line4, 4));
            }
        }
        if (!file5.eof()) {
            if (tmp.getId() == 5) {
                getline(file5, line5);
                mh.push_back(Node(line5, 5));
            }
        }
        if (!file6.eof()) {
            if (tmp.getId() == 6) {
                getline(file6, line6);
                mh.push_back(Node(line6, 6));
            }
        }
        if (!file7.eof()) {
            if (tmp.getId() == 7) {
                getline(file7, line7);
                mh.push_back(Node(line7, 7));
            }
        }
        if (!file8.eof()) {
            if (tmp.getId() == 8) {
                getline(file8, line8);
                mh.push_back(Node(line8, 8));
            }
        }
        if (!file9.eof()) {
            if (tmp.getId() == 9) {
                getline(file9, line9);
                mh.push_back(Node(line9, 9));
            }
        }
        if (!file10.eof()) {
            if (tmp.getId() == 10) {
                getline(file10, line10);
                mh.push_back(Node(line10, 10));
            }
        }
        if (!file11.eof()) {
            if (tmp.getId() == 11) {
                getline(file11, line11);
                mh.push_back(Node(line11, 11));
            }
        }
        if (!file12.eof()) {
            if (tmp.getId() == 12) {
                getline(file12, line12);
                mh.push_back(Node(line12, 12));
            }
        }
        if (!file13.eof()) {
            if (tmp.getId() == 13) {
                getline(file13, line13);
                mh.push_back(Node(line13, 13));
            }
        }
        // fix hea[]
        push_heap(mh.begin(), mh.end(), node_compare());
        // condition to end the loop, when every file reaches eof
        if (file1.eof() && file2.eof() && file3.eof() && file4.eof() && file5.eof() && file6.eof() && file7.eof() && file8.eof() && file9.eof() && file10.eof() && file11.eof() && file12.eof() && file13.eof()) {
            done = true;
        }
    }


}



    // bool done = false;
    // while(!done) {
    //     if(!file1.eof()){
    //         if(line1[THIRD_CHAR] < line2[THIRD_CHAR] && line1[THIRD_CHAR] < line3[THIRD_CHAR] && line1[THIRD_CHAR] < line4[THIRD_CHAR] && line1[THIRD_CHAR] < line5[THIRD_CHAR] &&line1[THIRD_CHAR] < line6[THIRD_CHAR] && line1[THIRD_CHAR] < line7[THIRD_CHAR] && line1[THIRD_CHAR] < line8[THIRD_CHAR] &&line1[THIRD_CHAR] < line9[THIRD_CHAR] && line1[THIRD_CHAR] < line10[THIRD_CHAR] &&line1[THIRD_CHAR] < line11[THIRD_CHAR] && line1[THIRD_CHAR] < line12[THIRD_CHAR] && line1[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line1 << std::endl;
    //             getline(file1, line1);
    //         }
    //     }
    //     if(!file2.eof()){
    //         if(line2[THIRD_CHAR] < line1[THIRD_CHAR] &&line2[THIRD_CHAR] < line3[THIRD_CHAR] && line2[THIRD_CHAR] < line4[THIRD_CHAR] && line2[THIRD_CHAR] < line5[THIRD_CHAR] &&line2[THIRD_CHAR] < line6[THIRD_CHAR] && line2[THIRD_CHAR] < line7[THIRD_CHAR] && line2[THIRD_CHAR] < line8[THIRD_CHAR] &&line2[THIRD_CHAR] < line9[THIRD_CHAR] && line2[THIRD_CHAR] < line10[THIRD_CHAR] &&line2[THIRD_CHAR] < line11[THIRD_CHAR] && line2[THIRD_CHAR] < line12[THIRD_CHAR] && line2[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line2 << std::endl;
    //             getline(file1, line2);
    //         }
    //     }
    //     if(!file3.eof()){
    //         if(line3[THIRD_CHAR] < line1[THIRD_CHAR] && line3[THIRD_CHAR] < line2[THIRD_CHAR] && line3[THIRD_CHAR] < line4[THIRD_CHAR] && line3[THIRD_CHAR] < line5[THIRD_CHAR] &&line3[THIRD_CHAR] < line6[THIRD_CHAR] && line3[THIRD_CHAR] < line7[THIRD_CHAR] && line3[THIRD_CHAR] < line8[THIRD_CHAR] &&line3[THIRD_CHAR] < line9[THIRD_CHAR] && line3[THIRD_CHAR] < line10[THIRD_CHAR] &&line3[THIRD_CHAR] < line11[THIRD_CHAR] && line3[THIRD_CHAR] < line12[THIRD_CHAR] && line3[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line3 << std::endl;
    //             getline(file1, line3);
    //         }
    //     }
    //     if(!file4.eof()){
    //         if(line4[THIRD_CHAR] < line1[THIRD_CHAR] &&line4[THIRD_CHAR] < line2[THIRD_CHAR] &&line4[THIRD_CHAR] < line3[THIRD_CHAR] && line4[THIRD_CHAR] < line5[THIRD_CHAR] &&line4[THIRD_CHAR] < line6[THIRD_CHAR] && line4[THIRD_CHAR] < line7[THIRD_CHAR] && line4[THIRD_CHAR] < line8[THIRD_CHAR] &&line4[THIRD_CHAR] < line9[THIRD_CHAR] && line4[THIRD_CHAR] < line10[THIRD_CHAR] &&line4[THIRD_CHAR] < line11[THIRD_CHAR] && line4[THIRD_CHAR] < line12[THIRD_CHAR] && line4[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line4 << std::endl;
    //             getline(file1, line4);
    //         }
    //     }
    //     if(!file5.eof()){
    //         if(line5[THIRD_CHAR] < line1[THIRD_CHAR] &&line5[THIRD_CHAR] < line2[THIRD_CHAR] &&line5[THIRD_CHAR] < line3[THIRD_CHAR] &&line5[THIRD_CHAR] < line4[THIRD_CHAR] &&line5[THIRD_CHAR] < line6[THIRD_CHAR] && line5[THIRD_CHAR] < line7[THIRD_CHAR] && line5[THIRD_CHAR] < line8[THIRD_CHAR] &&line5[THIRD_CHAR] < line9[THIRD_CHAR] && line5[THIRD_CHAR] < line10[THIRD_CHAR] &&line5[THIRD_CHAR] < line11[THIRD_CHAR] && line5[THIRD_CHAR] < line12[THIRD_CHAR] && line5[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line5 << std::endl;
    //             getline(file1, line5);
    //         }
    //     }
    //     if(!file6.eof()){
    //         if(line6[THIRD_CHAR] < line1[THIRD_CHAR] &&line6[THIRD_CHAR] < line2[THIRD_CHAR] &&line6[THIRD_CHAR] < line3[THIRD_CHAR] &&line6[THIRD_CHAR] < line4[THIRD_CHAR] &&line6[THIRD_CHAR] < line5[THIRD_CHAR] && line6[THIRD_CHAR] < line7[THIRD_CHAR] && line6[THIRD_CHAR] < line8[THIRD_CHAR] &&line6[THIRD_CHAR] < line9[THIRD_CHAR] && line6[THIRD_CHAR] < line10[THIRD_CHAR] &&line6[THIRD_CHAR] < line11[THIRD_CHAR] && line6[THIRD_CHAR] < line12[THIRD_CHAR] && line6[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line6 << std::endl;
    //             getline(file1, line6);
    //         }
    //     }
    //     if(!file7.eof()){
    //         if(line7[THIRD_CHAR] < line1[THIRD_CHAR] &&line7[THIRD_CHAR] < line2[THIRD_CHAR] &&line7[THIRD_CHAR] < line3[THIRD_CHAR] &&line7[THIRD_CHAR] < line4[THIRD_CHAR] &&line7[THIRD_CHAR] < line5[THIRD_CHAR] && line7[THIRD_CHAR] < line6[THIRD_CHAR] && line7[THIRD_CHAR] < line8[THIRD_CHAR] &&line7[THIRD_CHAR] < line9[THIRD_CHAR] && line7[THIRD_CHAR] < line10[THIRD_CHAR] &&line7[THIRD_CHAR] < line11[THIRD_CHAR] && line7[THIRD_CHAR] < line12[THIRD_CHAR] && line7[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line7 << std::endl;
    //             getline(file1, line7);
    //         }
    //     }
    //     if(!file8.eof()){
    //         if(line8[THIRD_CHAR] < line1[THIRD_CHAR] &&line8[THIRD_CHAR] < line2[THIRD_CHAR] &&line8[THIRD_CHAR] < line3[THIRD_CHAR] &&line8[THIRD_CHAR] < line4[THIRD_CHAR] &&line8[THIRD_CHAR] < line5[THIRD_CHAR] && line8[THIRD_CHAR] < line6[THIRD_CHAR] && line8[THIRD_CHAR] < line7[THIRD_CHAR] &&line8[THIRD_CHAR] < line9[THIRD_CHAR] && line8[THIRD_CHAR] < line10[THIRD_CHAR] &&line8[THIRD_CHAR] < line11[THIRD_CHAR] && line8[THIRD_CHAR] < line12[THIRD_CHAR] && line8[THIRD_CHAR] < line13[THIRD_CHAR]){
    //             output << line8 << std::endl;
    //             getline(file1, line8);
    //         }
    //     }













    // // first round of outputs after first merge, tmp files just for mergesort
    // std::string output1 = "Task2_wordlist/output1.txt";
    // std::string output2 = "Task2_wordlist/output2.txt";
    // std::string output3 = "Task2_wordlist/output3.txt";
    // std::string output4 = "Task2_wordlist/output4.txt";
    // std::string output5 = "Task2_wordlist/output5.txt";
    // std::string output6 = "Task2_wordlist/output6.txt";

    // // second round for mergesort
    // std::string output7 = "Task2_wordlist/output7.txt";
    // std::string output8 = "Task2_wordlist/output8.txt";
    // std::string output9 = "Task2_wordlist/output9.txt";
    // std::string output10 = "Task2_wordlist/output10.txt";

    // // third round
    // std::string output11 = "Task2_wordlist/output11.txt";
    // std::string output12 = "Task2_wordlist/output12.txt";

    // // final output file
    // std::string sorted_file = "Task2_wordlist/sorted_file.txt";

    // // round 1
    // mergeFiles("Task2_wordlist/length3.txt", "Task2_wordlist/length4.txt", output1);
    // mergeFiles("Task2_wordlist/length5.txt","Task2_wordlist/length6.txt", output2);
    // mergeFiles("Task2_wordlist/length7.txt","Task2_wordlist/length8.txt", output3);
    // mergeFiles("Task2_wordlist/length9.txt","Task2_wordlist/length10.txt", output4);
    // mergeFiles("Task2_wordlist/length11.txt","Task2_wordlist/length12.txt", output5);
    // mergeFiles("Task2_wordlist/length13.txt","Task2_wordlist/length14.txt", output6);

    // // round 2
    // mergeFiles(output1, output2, output7);
    // mergeFiles(output3, output4, output8);
    // mergeFiles(output5, output6, output9);
    // mergeFiles("Task2_wordlist/length15.txt", output9, output10);

    // // round 3
    // mergeFiles(output7, output8, output11);
    // mergeFiles(output9, output10, output12);

    // // round 4
    // mergeFiles(output11, output12, sorted_file);
    
    // // removing files
    // remove(output1.c_str());
    // remove(output2.c_str());
    // remove(output3.c_str());
    // remove(output4.c_str());
    // remove(output5.c_str());
    // remove(output6.c_str());
    // remove(output7.c_str());
    // remove(output8.c_str());
    // remove(output9.c_str());
    // remove(output10.c_str());
    // remove(output11.c_str());
    // remove(output12.c_str());


// void mergeFiles(std::string file1, std::string file2, std::string output_file) {
//     std::ifstream fin1(file1);
//     std::ifstream fin2(file2);
//     std::ofstream fout(output_file);

//     std::string line;
//     std::string line_file1;
//     std::string line_file2;

//     if(fin1) {
//         getline(fin1,line);
//         line_file1 = line;
//     }

//     if(fin2) {
//         getline(fin2,line);
//         line_file2 = line;
//     }

//     bool first = true;
//     while(!fin1.eof() && !fin2.eof()) {
//         if(line_file2[THIRD_CHAR] < line_file1[THIRD_CHAR]) {
//             fout << line_file2 << std::endl;
//             getline(fin2,line);
//             line_file2 = line;
//             }
//         else {
//             fout << line_file1 << std::endl;
//             getline(fin1,line);
//             line_file1 = line;
//             }
//         }
//     if(!fin1.eof()) {
//         while(!fin1.eof()){
//             fout << line << std::endl;
//             getline(fin1,line);
//         }
//     }
//     else if (!fin2.eof()) {
//          while(!fin2.eof()){
//             fout << line << std::endl;
//             getline(fin2,line);
//         }
//     }

//     fin1.close();
//     fin2.close();
//     fout.close();
// }


