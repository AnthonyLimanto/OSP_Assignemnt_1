#include <iostream>
#include <string>
#include <pthread.h>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <sys/stat.h>

#define THIRD_CHAR 2

void map3();
bool compareIndex(int lhs, int rhs);
void* sortByThirdChar(void* arg) ;
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
int aaa = 3;
std::vector<int> tests = {1,2,3,4,5,6,7,12,12,13,14,15};

std::vector<std::string> global;




int main (int argc, char* argv[]) {
    // pthread_t t1;
    // pthread_create(&t1, NULL, &function, NULL);
    // pthread_join(t1, NULL);

    std::ifstream file("Cleanfile.txt");
    std::string line;

    while(getline(file, line)) {
        global.push_back(line);
    }
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
        std::ofstream myFile("Task3_wordlist/length3.txt");
        for (auto i1 : *vec) {
        myFile << global[i1] << std::endl;
        }
        myFile.close();
    }
    if (global[(*vec)[0]].size() == 5) {
        std::ofstream myFile("Task3_wordlist/length4.txt");
        for (auto i2 : *vec) {
        myFile << global[i2] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 6) {
        std::ofstream myFile("Task3_wordlist/length5.txt");
        for (auto i3 : *vec) {
        myFile << global[i3] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 7) {
        std::ofstream myFile("Task3_wordlist/length6.txt");
        for (auto i4 : *vec) {
        myFile << global[i4] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 8) {
        std::ofstream myFile("Task3_wordlist/length7.txt");
        for (auto i5 : *vec) {
        myFile << global[i5] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 9) {
        std::ofstream myFile("Task3_wordlist/length8.txt");
        for (auto i6 : *vec) {
        myFile << global[i6] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 10) {
        std::ofstream myFile("Task3_wordlist/length9.txt");
        for (auto i7 : *vec) {
        myFile << global[i7] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 11) {
        std::ofstream myFile("Task3_wordlist/length10.txt");
        for (auto i8 : *vec) {
        myFile << global[i8] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 12) {
        std::ofstream myFile("Task3_wordlist/length11.txt");
        for (auto i9 : *vec) {
        myFile << global[i9] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 13) {
        std::ofstream myFile("Task3_wordlist/length12.txt");
        for (auto i10 : *vec) {
        myFile << global[i10] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 14) {
        std::ofstream myFile("Task3_wordlist/length13.txt");
        for (auto i11 : *vec) {
        myFile << global[i11] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 15) {
        std::ofstream myFile("Task3_wordlist/length14.txt");
        for (auto i12 : *vec) {
        myFile << global[i12] << std::endl;
        }
        myFile.close();
    } 
    if (global[(*vec)[0]].size() == 16) {
        std::ofstream myFile("Task3_wordlist/length15.txt");
        for (auto i13 : *vec) {
        myFile << global[i13] << std::endl;
        }
        myFile.close();
    } 
}
// void* sort2(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index2.begin(), index2.end(), compare);
    
//     for (auto i : index2) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort3(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index3.begin(), index3.end(), compare);
    
//     for (auto i : index3) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort4(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index4.begin(), index4.end(), compare);
    
//     for (auto i : index4) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort5(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index5.begin(), index5.end(), compare);
    
//     for (auto i : index5) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort6(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index6.begin(), index6.end(), compare);
    
//     for (auto i : index6) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort7(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index7.begin(), index7.end(), compare);
    
//     for (auto i : index7) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort8(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index8.begin(), index8.end(), compare);
    
//     for (auto i : index8) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort9(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index9.begin(), index9.end(), compare);
    
//     for (auto i : index9) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort10(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index10.begin(), index10.end(), compare);
    
//     for (auto i : index10) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort11(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index11.begin(), index11.end(), compare);
    
//     for (auto i : index11) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort12(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index12.begin(), index12.end(), compare);
    
//     for (auto i : index12) {
//         std::cout << global[i] << std::endl;
//     }
//  }
//  void* sort13(void* arg) {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
//     };
    
//     std::sort(index13.begin(), index13.end(), compare);
    
//     for (auto i : index13) {
//         std::cout << global[i] << std::endl;
//     }
//  }

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


    // pthread_create(&t2, NULL, std::sort(index2.begin(), index2.end(), compare), NULL);
    // pthread_create(&t3, NULL, std::sort(index3.begin(), index3.end(), compare), NULL);
    // pthread_create(&t4, NULL, &std::sort(index4.begin(), index4.end(), compare), NULL);
    // pthread_create(&t5, NULL, &std::sort(index5.begin(), index5.end(), compare), NULL);
    // pthread_create(&t6, NULL, &std::sort(index6.begin(), index6.end(), compare), NULL);
    // pthread_create(&t7, NULL, &std::sort(index7.begin(), index7.end(), compare), NULL);
    // pthread_create(&t8, NULL, &std::sort(index8.begin(), index8.end(), compare), NULL);
    // pthread_create(&t9, NULL, &std::sort(index9.begin(), index9.end(), compare), NULL);
    // pthread_create(&t10, NULL, &std::sort(index10.begin(), index10.end(), compare), NULL);
    // pthread_create(&t11, NULL, &std::sort(index11.begin(), index11.end(), compare), NULL);
    // pthread_create(&t12, NULL, &std::sort(index12.begin(), index12.end(), compare), NULL);
    // pthread_create(&t13, NULL, &std::sort(index13.begin(), index13.end(), compare), NULL);
    pthread_join(t1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t1, NULL);
    
    // Testing index1
    // for (std::vector<std::string>::size_type i = 0; i != index1.size(); i++) {
    //     std::cout << global[index1[i]] << std::endl;
    // }
    
    // for (int i : index1) {
    //     std::cout << global[index1[i]] << std::endl;
    // }

}