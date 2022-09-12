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
#define READ_WRITE 0777

void map3();
void* reduce3(void* arg);
bool compareIndex(int lhs, int rhs);
void* sortByThirdChar(void* arg) ;
void* fifo1(void* arg);
void* fifo2(void* arg);
void* fifo3(void* arg);

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




int main (int argc, char* argv[]) {
    // pthread_t t1;
    // pthread_create(&t1, NULL, &function, NULL);
    // pthread_join(t1, NULL);

    std::ifstream file("Cleanfile.txt");
    std::string line;

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



    while(getline(file, line)) {
        global.push_back(line);
    }
    
    pthread_t mt1;
    printf("before reduce \n");
    pthread_create(&mt1, NULL, &reduce3, NULL);

    printf("after reduce \n");
    map3();
   

   

    // leaves threads running while main exits so all thread can finish their jobs first // instead of return 0
    pthread_exit(0);
}

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
    
//     for (auto i : *vec) {
//         std::cout << global[i] << std::endl;
// }
    if (global[(*vec)[0]].size() == 4) {
        
        printf("map fifo before \n");
        int myFile = open("/tmp/length3fifo", O_WRONLY);
        printf("map fifo after \n");

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

        int myFile = open("/tmp/length14fifo", O_WRONLY);
        
        char line13[17] = "\n";
        for (auto i13 : *vec) {
            strcpy(line13, global[i13].c_str());
            // std::cout << line1 << std::endl;
            write(myFile, &line13 ,sizeof(line13) + 1);
        }
        close(myFile);
    }
}

void map3() {
      // lambda function for custom compare in sort()
    auto compare = [&](const int& lhs, const int& rhs) -> bool {
    return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
};
   
    // index vectors

    
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

// custom compare for min heap
struct node_compare {
    bool operator()(const Node& lhs, const Node& rhs) const{
        return lhs.getWord()[THIRD_CHAR] > rhs.getWord()[THIRD_CHAR];
    }
};

void* reduce3(void* arg) {
    // try removing locks to debug and see where is wrong 
    
    // 
    // 
    // 
    // 
    // 
    // 
    // 
    

    
    
    // read(fd1, arr1, sizeof(arr1));
    // read(fd2, arr2, sizeof(arr2));
    // read(fd3, arr3, sizeof(arr3));
    // read(fd4, arr4, sizeof(arr4));
    // read(fd5, arr5, sizeof(arr5));
    // read(fd6, arr6, sizeof(arr6));
    // read(fd7, arr7, sizeof(arr7));
    // read(fd8, arr8, sizeof(arr8));
    // read(fd9, arr9, sizeof(arr9));
    // read(fd10, arr10, sizeof(arr10));
    // read(fd11, arr11, sizeof(arr11));
    // read(fd12, arr12, sizeof(arr12));
    // read(fd13, arr13, sizeof(arr13));
    // mh.push_back(arr1);
    // mh.push_back(arr2);
    // mh.push_back(arr3);
    // mh.push_back(arr4);
    // mh.push_back(arr5);
    // mh.push_back(arr6);
    // mh.push_back(arr7);
    // mh.push_back(arr8);
    // mh.push_back(arr9);
    // mh.push_back(arr10);
    // mh.push_back(arr11);
    // mh.push_back(arr12);
    // mh.push_back(arr13);

    // make_heap(mh.begin(), mh.end(), heap_compare());

    

    
    std::ofstream output("Task3_wordlist/sorted.txt");
    // reads from fifo into vector
    pthread_t r1, r2, r3, r4, r5, r6, r7, r8, r9, r10 ,r11 ,r12, r13;

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
    

    // printf("hahahaha\n");

    // std::vector<Node> mh;
    // mh.push_back(Node(vec1.front(), 1));
    // mh.push_back(Node(vec2.front(), 2));
    // mh.push_back(Node(vec3.front(), 3));
    // mh.push_back(Node(vec4.front(), 4));
    // mh.push_back(Node(vec5.front(), 5));
    // mh.push_back(Node(vec6.front(), 6));
    // mh.push_back(Node(vec7.front(), 7));
    // mh.push_back(Node(vec8.front(), 8));
    // mh.push_back(Node(vec9.front(), 9));
    // mh.push_back(Node(vec10.front(), 10));
    // mh.push_back(Node(vec11.front(), 11));
    // mh.push_back(Node(vec12.front(), 12));
    // mh.push_back(Node(vec13.front(), 13));

    // vec1.erase(vec1.begin());
    // vec2.erase(vec2.begin());
    // vec3.erase(vec3.begin());
    // vec4.erase(vec4.begin());
    // vec5.erase(vec5.begin());
    // vec6.erase(vec6.begin());
    // vec7.erase(vec7.begin());
    // vec8.erase(vec8.begin());
    // vec9.erase(vec9.begin());
    // vec10.erase(vec10.begin());
    // vec11.erase(vec11.begin());
    // vec12.erase(vec12.begin());
    // vec13.erase(vec13.begin());

    // make_heap(mh.begin(), mh.end(), node_compare());

    // bool done = false;
    
    // while (!done) {
    //     // reads lowest word then deletes
    //     Node tmp = mh.front();
    //     mh.erase(mh.begin());
    //     output << tmp.getWord() << std::endl;
    //     // for every file if not empty, finds which file the word came from then gets nextline in the same file
    //     if (vec1.size() != 1) {
    //         if (tmp.getId() == 1) {
    //             mh.push_back(Node(vec1.front(), 1));
    //             vec1.erase(vec1.begin());
    //         }
    //     }
    //     if (vec2.size() != 1) {
    //         if (tmp.getId() == 2) {
    //             mh.push_back(Node(vec2.front(), 2));
    //             vec2.erase(vec2.begin());
    //         }
    //     }
    //     if (vec3.size() != 1) {
    //         if (tmp.getId() == 3) {
    //             mh.push_back(Node(vec3.front(), 3));
    //             vec3.erase(vec3.begin());
    //         }
    //     }
    //     if (vec4.size() != 1) {
    //         if (tmp.getId() == 4) {
    //             mh.push_back(Node(vec4.front(), 4));
    //             vec4.erase(vec4.begin());
    //         }
    //     }
    //     if (vec5.size() != 1) {
    //         if (tmp.getId() == 5) {
    //             mh.push_back(Node(vec5.front(), 5));
    //             vec5.erase(vec5.begin());
    //         }
    //     }
    //     if (vec6.size() != 1) {
    //         if (tmp.getId() == 6) {
    //             mh.push_back(Node(vec6.front(), 6));
    //             vec6.erase(vec6.begin());
    //         }
    //     }
    //     if (vec7.size() != 1) {
    //         if (tmp.getId() == 7) {
    //             mh.push_back(Node(vec7.front(), 7));
    //             vec7.erase(vec7.begin());
    //         }
    //     }
    //     if (vec8.size() != 1) {
    //         if (tmp.getId() == 8) {
    //             mh.push_back(Node(vec8.front(), 8));
    //             vec8.erase(vec8.begin());
    //         }
    //     }
    //     if (vec9.size() != 1) {
    //         if (tmp.getId() == 9) {
    //             mh.push_back(Node(vec9.front(), 9));
    //             vec9.erase(vec9.begin());
    //     }
    //     if (vec10.size() != 1) {
    //         if (tmp.getId() == 10) {
    //             mh.push_back(Node(vec10.front(), 10));
    //             vec10.erase(vec10.begin());
    //         }
    //     }
    //     if (vec11.size() != 1) {
    //         if (tmp.getId() == 11) {
    //             mh.push_back(Node(vec11.front(), 11));
    //             vec11.erase(vec11.begin());
    //         }
    //     }
    //     if (vec12.size() != 1) {
    //         if (tmp.getId() == 12) {
    //             mh.push_back(Node(vec12.front(), 12));
    //             vec11.erase(vec11.begin());
    //         }
    //     }
    //     if (vec13.size() != 1) {
    //         if (tmp.getId() == 13) {
    //             mh.push_back(Node(vec13.front(), 13));
    //             vec13.erase(vec13.begin());
    //         }
    //     }
    //     // fix hea[]
    //     push_heap(mh.begin(), mh.end(), node_compare());
    //     // condition to end the loop, when every file reaches eof
    //     if ((vec1.size() == 1) && (vec2.size() == 1) && (vec3.size() == 1) && (vec4.size() == 1) && (vec5.size() == 1) && (vec6.size() == 1) && (vec7.size() == 1) && (vec8.size() == 1) && (vec9.size() == 1) && (vec10.size() == 1) && (vec11.size() == 1) && (vec12.size() == 1) && (vec13.size() == 1)) {
    //         output << vec1.front() << std::endl << vec2.front() << std::endl << vec3.front() << std::endl << vec4.front() << std::endl << vec5.front() << std::endl << vec6.front() << std::endl << vec7.front() << std::endl << vec8.front() << std::endl << vec9.front() << std::endl << vec10.front() << std::endl << vec11.front() << std::endl << vec2.front() << std::endl << vec13.front() << std::endl;
    //         done = true;
    //     }
    // }

    // }
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
    close(fd3);
}
void* fifo4(void* arg) {
    int fd4 = open("/tmp/length6fifo", O_RDONLY);
    while (read(fd4, arr4, sizeof(arr4)) != 0) {
        std::string line;
        for (int i = 0; i < 7 ; i++) {
            line.push_back(arr4[i]);
        }
        vec4.push_back(line);
    }
    close(fd4);
}
void* fifo5(void* arg) {
    int fd5 = open("/tmp/length7fifo", O_RDONLY);
    while (read(fd5, arr5, sizeof(arr5)) != 0) {
        std::string line;
        for (int i = 0; i < 8 ; i++) {
            line.push_back(arr5[i]);
        }
        vec5.push_back(line);
    }
    close(fd5);
}
void* fifo6(void* arg) {
    int fd6 = open("/tmp/length8fifo", O_RDONLY);
    while (read(fd6, arr6, sizeof(arr6)) != 0) {
        std::string line;
        for (int i = 0; i < 9 ; i++) {
            line.push_back(arr6[i]);
        }
        vec6.push_back(line);
    }
    close(fd6);
}
void* fifo7(void* arg) {
    int fd7 = open("/tmp/length9fifo", O_RDONLY);
    while (read(fd7, arr7, sizeof(arr7)) != 0) {
        std::string line;
        for (int i = 0; i < 10 ; i++) {
            line.push_back(arr7[i]);
        }
        vec7.push_back(line);
    }
    close(fd7);
}
void* fifo8(void* arg) {
    int fd8 = open("/tmp/length10fifo", O_RDONLY);
    while (read(fd8, arr8, sizeof(arr8)) != 0) {
        std::string line;
        for (int i = 0; i < 11 ; i++) {
            line.push_back(arr8[i]);
        }
        vec8.push_back(line);
    }
    close(fd8);
}
void* fifo9(void* arg) {
    int fd9 = open("/tmp/length11fifo", O_RDONLY);
    while (read(fd9, arr9, sizeof(arr9)) != 0) {
        std::string line;
        for (int i = 0; i < 12 ; i++) {
            line.push_back(arr9[i]);
        }
        vec1.push_back(line);
    }
    close(fd9);
}
void* fifo10(void* arg) {
    int fd10 = open("/tmp/length12fifo", O_RDONLY);
    while (read(fd10, arr10, sizeof(arr10)) != 0) {
        std::string line;
        for (int i = 0; i < 13 ; i++) {
            line.push_back(arr10[i]);
        }
        vec10.push_back(line);
    }
    close(fd10);
}
void* fifo11(void* arg) {
    int fd11 = open("/tmp/length13fifo", O_RDONLY);
    while (read(fd11, arr11, sizeof(arr11)) != 0) {
        std::string line;
        for (int i = 0; i < 14 ; i++) {
            line.push_back(arr11[i]);
        }
        vec11.push_back(line);
    }
    close(fd11);
}
void* fifo12(void* arg) {
    int fd12 = open("/tmp/length14fifo", O_RDONLY);
    while (read(fd12, arr12, sizeof(arr12)) != 0) {
        std::string line;
        for (int i = 0; i < 15 ; i++) {
            line.push_back(arr12[i]);
        }
        vec12.push_back(line);
    }
    close(fd12);
}
void* fifo13(void* arg) {
    int fd13 = open("/tmp/length15fifo", O_RDONLY);
    while (read(fd13, arr13, sizeof(arr13)) != 0) {
        std::string line;
        for (int i = 0; i < 4 ; i++) {
            line.push_back(arr13[i]);
        }
        vec13.push_back(line);
    }
    close(fd13);
}
