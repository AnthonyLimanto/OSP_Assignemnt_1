#include <iostream>
#include <string>
#include <pthread.h>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


#define THIRD_CHAR 2

void map3();
void* reduce3(void* arg);
bool compareIndex(int lhs, int rhs);
void* sortByThirdChar(void* arg);

// these functions each read a respective fifo then output to text file
void* fifo1(void* arg);
void* fifo2(void* arg);
void* fifo3(void* arg);
void* fifo4(void* arg);
void* fifo5(void* arg);
void* fifo6(void* arg);
void* fifo7(void* arg);
void* fifo8(void* arg);
void* fifo9(void* arg);
void* fifo10(void* arg);
void* fifo11(void* arg);
void* fifo12(void* arg);
void* fifo13(void* arg);

// vector of the index for a word in global
std::vector<int> index1;
std::vector<int> index2;
std::vector<int> index3;
std::vector<int> index4;
std::vector<int> index5;
std::vector<int> index6;
std::vector<int> index7;
std::vector<int> index8;
std::vector<int> index9;
std::vector<int> index10;
std::vector<int> index11;
std::vector<int> index12;
std::vector<int> index13;

// vectors to hold string after being read from fifos
std::vector<std::string> vec1;
std::vector<std::string> vec2;
std::vector<std::string> vec3;
std::vector<std::string> vec4;
std::vector<std::string> vec5;
std::vector<std::string> vec6;
std::vector<std::string> vec7;
std::vector<std::string> vec8;
std::vector<std::string> vec9;
std::vector<std::string> vec10;
std::vector<std::string> vec11;
std::vector<std::string> vec12;
std::vector<std::string> vec13;

// char array to hold what a fifo reads, then later turn into string
char arr1[6] = "";
char arr2[7] = "";
char arr3[8] = "";
char arr4[9] = "";
char arr5[10] = "";
char arr6[11] = "";
char arr7[12] = "";
char arr8[13] = "";
char arr9[14] = "";
char arr10[15] = "";
char arr11[16] = "";
char arr12[17] = "";
char arr13[18] = "";

    // bool finishRead[13] = false;

    pthread_mutex_t lock;


std::vector<std::string> global;

pthread_mutex_t mutexLock;

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
// custom compare for min heap
struct node_compare {
    bool operator()(const Node& lhs, const Node& rhs) const{
        return lhs.getWord()[THIRD_CHAR] > rhs.getWord()[THIRD_CHAR];
    }
};




int main (int argc, char* argv[]) {

    std::ifstream file("Cleanfile.txt");
    std::string line;

    // makes 13 fifo, one for each length word
    mkfifo("/tmp/length3fifo", 0777);
    mkfifo("/tmp/length4fifo", 0777);
    mkfifo("/tmp/length5fifo", 0777);
    mkfifo("/tmp/length6fifo", 0777);
    mkfifo("/tmp/length7fifo", 0777);
    mkfifo("/tmp/length8fifo", 0777);
    mkfifo("/tmp/length9fifo", 0777);
    mkfifo("/tmp/length10fifo", 0777);
    mkfifo("/tmp/length11fifo", 0777);
    mkfifo("/tmp/length12fifo", 0777);
    mkfifo("/tmp/length13fifo", 0777);
    mkfifo("/tmp/length14fifo", 0777);
    mkfifo("/tmp/length15fifo", 0777);


    // adds word to global from cleanfile.txt
    while(getline(file, line)) {
        global.push_back(line);
    }

    
    
    pthread_t mt1;
    printf("before reduce \n");
    pthread_create(&mt1, NULL, &reduce3, NULL);

    map3();
    

    // reads from these files then put in a min heap to do merge sort
    std::ifstream file1("Task3_wordlist/help3.txt");
    std::ifstream file2("Task3_wordlist/help4.txt");
    std::ifstream file3("Task3_wordlist/help5.txt");
    std::ifstream file4("Task3_wordlist/help6.txt");
    std::ifstream file5("Task3_wordlist/help7.txt");
    std::ifstream file6("Task3_wordlist/help8.txt");
    std::ifstream file7("Task3_wordlist/help9.txt");
    std::ifstream file8("Task3_wordlist/help10.txt");
    std::ifstream file9("Task3_wordlist/help11.txt");
    std::ifstream file10("Task3_wordlist/help12.txt");
    std::ifstream file11("Task3_wordlist/help13.txt");
    std::ifstream file12("Task3_wordlist/help14.txt");
    std::ifstream file13("Task3_wordlist/help15.txt");

    // output file
    std::ofstream output("Task3_wordlist/sorted.txt");

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
   

    return 0;

    // leaves threads running while main exits so all thread can finish their jobs first // instead of return 0
    pthread_exit(0);
}

// used to compare index
bool compareIndex(int lhs, int rhs) {
    return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
}

void* sortByThirdChar(void* arg) {
      // lambda function for custom compare in sort()
    auto compare = [&](const int& lhs, const int& rhs) -> bool {
    return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
    };
    
    
    std::vector<int>* vec = (std::vector<int>*)(arg);
    std::sort(vec->begin(), vec->end(), compare);
    
    // depending on the vec given it will open a fifo file and write to it
    if (global[(*vec)[0]].size() == 4) {
        
        int myFile = open("/tmp/length3fifo", O_WRONLY);

        char line1[5] = "\n";
        for (auto i1 : *vec) {
            strcpy(line1, global[i1].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line1 ,sizeof(line1) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 5) {

        int myFile = open("/tmp/length4fifo", O_WRONLY);
        
        char line2[6] = "\n";
        for (auto i2 : *vec) {
            strcpy(line2, global[i2].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line2 ,sizeof(line2) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 6) {

        int myFile = open("/tmp/length5fifo", O_WRONLY);
        
        char line3[7] = "\n\n\n\n\n\n";
        for (auto i3 : *vec) {
            strcpy(line3, global[i3].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line3 ,sizeof(line3) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 7) {

        int myFile = open("/tmp/length6fifo", O_WRONLY);
        
        char line4[8] = "\n";
        for (auto i4 : *vec) {
            strcpy(line4, global[i4].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line4 ,sizeof(line4) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 8) {

        int myFile = open("/tmp/length7fifo", O_WRONLY);
        
        char line5[9] = "\n";
        for (auto i5 : *vec) {
            strcpy(line5, global[i5].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line5 ,sizeof(line5) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 9) {

        int myFile = open("/tmp/length8fifo", O_WRONLY);
        
        char line6[10] = "\n";
        for (auto i6 : *vec) {
            strcpy(line6, global[i6].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line6 ,sizeof(line6) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 10) {

        int myFile = open("/tmp/length9fifo", O_WRONLY);
        
        char line7[11] = "\n";
        for (auto i7 : *vec) {
            strcpy(line7, global[i7].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line7 ,sizeof(line7) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 11) {

        int myFile = open("/tmp/length10fifo", O_WRONLY);
        
        char line8[12] = "\n";
        for (auto i8 : *vec) {
            strcpy(line8, global[i8].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line8 ,sizeof(line8) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 12) {

        int myFile = open("/tmp/length11fifo", O_WRONLY);
        
        char line9[13] = "\n";
        for (auto i9 : *vec) {
            strcpy(line9, global[i9].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line9 ,sizeof(line9) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 13) {

        int myFile = open("/tmp/length12fifo", O_WRONLY);
        
        char line10[14] = "\n";
        for (auto i10 : *vec) {
            strcpy(line10, global[i10].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line10 ,sizeof(line10) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 14) {

        int myFile = open("/tmp/length13fifo", O_WRONLY);
        
        char line11[15] = "\n";
        for (auto i11 : *vec) {
            strcpy(line11, global[i11].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line11 ,sizeof(line11) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 15) {

        int myFile = open("/tmp/length14fifo", O_WRONLY);
        
        char line12[16] = "\n";
        for (auto i12 : *vec) {
            strcpy(line12, global[i12].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line12 ,sizeof(line12) + 1);
        }
        close(myFile);
    }
    if (global[(*vec)[0]].size() == 16) {

        int myFile = open("/tmp/length15fifo", O_WRONLY);
        
        char line13[17] = "\n";
        for (auto i13 : *vec) {
            strcpy(line13, global[i13].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line13 ,sizeof(line13) + 1);
        }
        close(myFile);
    }
    return nullptr;
}

void map3() {    
    pthread_t t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;
    
    // loop through global and if the string size fits one of the if statements push the index of that string into the respective vector
    for (std::vector<std::string>::size_type i = 0; i != global.size(); i++) {
        if (global[i].size() == 3 + 1) {
            index1.push_back(i);
            // std::cout << i << std::endl;
        }
        if (global[i].size() == 4 + 1) {
            index2.push_back(i);
        }
        if (global[i].size() == 5 + 1) {
            index3.push_back(i);
        }
        if (global[i].size() == 6 + 1) {
            index4.push_back(i);
        }
        if (global[i].size() == 7 + 1) {
            index5.push_back(i);
        }
        if (global[i].size() == 8 + 1) {
            index6.push_back(i);
        }
        if (global[i].size() == 9 + 1) {
            index7.push_back(i);
        }
        if (global[i].size() == 10 + 1) {
            index8.push_back(i);
        }
        if (global[i].size() == 11 + 1) {
            index9.push_back(i);
        }
        if (global[i].size() == 12 + 1) {
            index10.push_back(i);
        }
        if (global[i].size() == 13 + 1) {
            index11.push_back(i);
        }
        if (global[i].size() == 14 + 1) {
            index12.push_back(i);
        }
        if (global[i].size() == 15 + 1) {
            index13.push_back(i);
        }
    }
    // TO DO make each of these done by a seperate thread
    pthread_create(&t1, NULL, &sortByThirdChar, &index13);
    pthread_create(&t2, NULL, &sortByThirdChar, &index12);
    pthread_create(&t3, NULL, &sortByThirdChar, &index11);
    pthread_create(&t4, NULL, &sortByThirdChar, &index10);
    pthread_create(&t5, NULL, &sortByThirdChar, &index9);
    pthread_create(&t6, NULL, &sortByThirdChar, &index8);
    pthread_create(&t7, NULL, &sortByThirdChar, &index7);
    pthread_create(&t8, NULL, &sortByThirdChar, &index6);
    pthread_create(&t9, NULL, &sortByThirdChar, &index5);
    pthread_create(&t10, NULL, &sortByThirdChar, &index4);
    pthread_create(&t11, NULL, &sortByThirdChar, &index3);
    pthread_create(&t12, NULL, &sortByThirdChar, &index2);
    pthread_create(&t13, NULL, &sortByThirdChar, &index1);


    // speed up the runtime by 50%
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);
    pthread_join(t9, NULL);
    pthread_join(t10, NULL);
    pthread_join(t11, NULL);
    pthread_join(t12, NULL);
    pthread_join(t13, NULL);

   
    
    // Testing index1
    // for (std::vector<std::string>::size_type i = 0; i != index1.size(); i++) {
    //     std::cout << global[index1[i]] << std::endl;
    // }
    
    // for (int i : index1) {
    //     std::cout << global[index1[i]] << std::endl;
    // }

}



void* reduce3(void* arg) {

    // reads from fifo into vector
    pthread_t r1, r2, r3, r4, r5, r6, r7, r8, r9, r10 ,r11 ,r12, r13;

    // these threads each read from one fifo
    pthread_create(&r1, NULL, &fifo1, NULL);
    pthread_create(&r2, NULL, &fifo2, NULL);
    pthread_create(&r3, NULL, &fifo3, NULL);
    pthread_create(&r4, NULL, &fifo4, NULL);
    pthread_create(&r5, NULL, &fifo5, NULL);
    pthread_create(&r6, NULL, &fifo6, NULL);
    pthread_create(&r7, NULL, &fifo7, NULL);
    pthread_create(&r8, NULL, &fifo8, NULL);
    pthread_create(&r9, NULL, &fifo9, NULL);
    pthread_create(&r10, NULL, &fifo10, NULL);
    pthread_create(&r11, NULL, &fifo11, NULL);
    pthread_create(&r12, NULL, &fifo12, NULL);
    pthread_create(&r13, NULL, &fifo13, NULL);

    // waits for the threads to finish
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(r4, NULL);
    pthread_join(r5, NULL);
    pthread_join(r6, NULL);
    pthread_join(r7, NULL);
    pthread_join(r8, NULL);
    pthread_join(r9, NULL);
    pthread_join(r10, NULL);
    pthread_join(r11, NULL);
    pthread_join(r12, NULL);
    pthread_join(r13, NULL);
    

    return nullptr;
}

void* fifo1(void* arg) {
    int fd1 = open("/tmp/length3fifo", O_RDONLY);
     std::ofstream files("Task3_wordlist/help3.txt");
    while (read(fd1, arr1, sizeof(arr1)) != 0) {
        std::string line1;
        for (int i = 0; i < 4 ; i++) {
            line1.push_back(arr1[i]);
        }
        vec1.push_back(line1);
        files << line1;
       
    }
    // finishRead[0] = true;
    pthread_exit(0);
    close(fd1);
}

void* fifo2(void* arg) {
    int fd2 = open("/tmp/length4fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help4.txt");
    while (read(fd2, arr2, sizeof(arr2)) != 0) {
        std::string line2;
        for (int i = 0; i < 5 ; i++) {
            line2.push_back(arr2[i]);
        }
        vec2.push_back(line2);
        files << line2;
    }
    // finishRead[1] = true;
    pthread_exit(0);
    close(fd2);
}

void* fifo3(void* arg) {
    int fd3 = open("/tmp/length5fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help5.txt");
    while (read(fd3, arr3, sizeof(arr3)) != 0) {
        std::string line;
        for (int i = 0; i < 6 ; i++) {
            line.push_back(arr3[i]);
        }
        vec3.push_back(line);
        files << line << std::endl;
        
    }
    // finishRead[3] = true;
    pthread_exit(0);
    close(fd3);
}
void* fifo4(void* arg) {
    int fd4 = open("/tmp/length6fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help6.txt");
    while (read(fd4, arr4, sizeof(arr4)) != 0) {
        std::string line;
        for (int i = 0; i < 7 ; i++) {
            line.push_back(arr4[i]);
        }
        vec4.push_back(line);
        files << line << std::endl;
    }
    // finishRead[4] = true;
    pthread_exit(0);
    close(fd4);
}
void* fifo5(void* arg) {
    int fd5 = open("/tmp/length7fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help7.txt");
    while (read(fd5, arr5, sizeof(arr5)) != 0) {
        std::string line;
        for (int i = 0; i < 8 ; i++) {
            line.push_back(arr5[i]);
        }
        vec5.push_back(line);
        files << line << std::endl;
    }
    // finishRead[5] = true;
    pthread_exit(0);
    close(fd5);
}
void* fifo6(void* arg) {
    int fd6 = open("/tmp/length8fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help8.txt");
    while (read(fd6, arr6, sizeof(arr6)) != 0) {
        std::string line;
        for (int i = 0; i < 9 ; i++) {
            line.push_back(arr6[i]);
        }
        vec6.push_back(line);
        files << line << std::endl;
    }
    // finishRead[6] = true;
    pthread_exit(0);
    close(fd6);
}
void* fifo7(void* arg) {
    int fd7 = open("/tmp/length9fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help9.txt");
    while (read(fd7, arr7, sizeof(arr7)) != 0) {
        std::string line;
        for (int i = 0; i < 10 ; i++) {
            line.push_back(arr7[i]);
        }
        vec7.push_back(line);
        files << line << std::endl;
    }
    // finishRead[7] = true;
    pthread_exit(0);
    close(fd7);
}
void* fifo8(void* arg) {
    int fd8 = open("/tmp/length10fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help10.txt");
    while (read(fd8, arr8, sizeof(arr8)) != 0) {
        std::string line;
        for (int i = 0; i < 11 ; i++) {
            line.push_back(arr8[i]);
        }
        vec8.push_back(line);
        files << line << std::endl;
    }
    // finishRead[8] = true;
    pthread_exit(0);
    close(fd8);
}
void* fifo9(void* arg) {
    int fd9 = open("/tmp/length11fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help11.txt");
    while (read(fd9, arr9, sizeof(arr9)) != 0) {
        std::string line;
        for (int i = 0; i < 12 ; i++) {
            line.push_back(arr9[i]);
        }
        vec9.push_back(line);
        files << line << std::endl;
    }
    // finishRead[9] = true;
    pthread_exit(0);
    close(fd9);
}
void* fifo10(void* arg) {
    int fd10 = open("/tmp/length12fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help12.txt");
    while (read(fd10, arr10, sizeof(arr10)) != 0) {
        std::string line;
        for (int i = 0; i < 13 ; i++) {
            line.push_back(arr10[i]);
        }
        vec10.push_back(line);
        files << line << std::endl;
    }
    // finishRead[10] = true;
    pthread_exit(0);
    close(fd10);
}
void* fifo11(void* arg) {
    int fd11 = open("/tmp/length13fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help13.txt");
    while (read(fd11, arr11, sizeof(arr11)) != 0) {
        std::string line;
        for (int i = 0; i < 14 ; i++) {
            line.push_back(arr11[i]);
        }
        vec11.push_back(line);
        files << line << std::endl;
    }
    // finishRead[11] = true;
    pthread_exit(0);
    close(fd11);
}
void* fifo12(void* arg) {
    int fd12 = open("/tmp/length14fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help14.txt");
    while (read(fd12, arr12, sizeof(arr12)) != 0) {
        std::string line;
        for (int i = 0; i < 15 ; i++) {
            line.push_back(arr12[i]);
        }
        vec12.push_back(line);
        files << line << std::endl;
    }
    // finishRead[12] = true;
    pthread_exit(0);
    close(fd12);
}
void* fifo13(void* arg) {
    int fd13 = open("/tmp/length15fifo", O_RDONLY);
    std::ofstream files("Task3_wordlist/help15.txt");
    while (read(fd13, arr13, sizeof(arr13)) != 0) {
        std::string line;
        for (int i = 0; i < 16 ; i++) {
            line.push_back(arr13[i]);
        }
        vec13.push_back(line);
        files << line << std::endl;
    }
    // finishRead[13] = true;
    pthread_exit(0);
    close(fd13);
}
