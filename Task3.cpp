#include <iostream>
#include <string>
#include <pthread.h>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

#define THIRD_CHAR 2

void map3();
bool compareIndex(int lhs, int rhs);
void* sortByThirdChar(void* arg) ;

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
}

bool compareIndex(int lhs, int rhs) {
    return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
}
void* sortByThirdChar(void* arg) {
      // lambda function for custom compare in sort()
    auto compare = [&](const int& lhs, const int& rhs) -> bool {
    return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
    };

    std::vector<int>* vec = static_cast<std::vector<int>*>(arg);
    std::sort(vec->begin(), vec->end(), compare);

    if (vec[0].size() == 4) {
        std::ofstream myFile("Task3_wordlist/length3.txt");
        for (int i : *vec) {
            myFile << global[i];
            myFile.close();
        }
    }
    return nullptr;
 }

void map3() {
//       // lambda function for custom compare in sort()
//     auto compare = [&](const int& lhs, const int& rhs) -> bool {
//     return global[lhs][THIRD_CHAR] < global[rhs][THIRD_CHAR];
// };
   
    // index vectors
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
    pthread_create(&t1, NULL, sortByThirdChar, &index1);
    pthread_create(&t2, NULL, sortByThirdChar, &index2);
    pthread_create(&t3, NULL, sortByThirdChar, &index3);
    pthread_create(&t4, NULL, sortByThirdChar, &index4);
    pthread_create(&t5, NULL, sortByThirdChar, &index5);
    pthread_create(&t6, NULL, sortByThirdChar, &index6);
    pthread_create(&t7, NULL, sortByThirdChar, &index7);
    pthread_create(&t8, NULL, sortByThirdChar, &index8);
    pthread_create(&t9, NULL, sortByThirdChar, &index9);
    pthread_create(&t10, NULL, sortByThirdChar, &index10);
    pthread_create(&t11, NULL, sortByThirdChar, &index11);
    pthread_create(&t12, NULL, sortByThirdChar, &index12);
    pthread_create(&t13, NULL, sortByThirdChar, &index13);

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

    // Testing index1
    for (std::vector<std::string>::size_type i = 0; i != index1.size(); i++) {
        std::cout << global[index1[i]] << std::endl;
    }



    

}