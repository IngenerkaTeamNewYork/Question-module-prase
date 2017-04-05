#include "base64.h"
using namespace std;

namespace questionLib {
    int number[100];
    string question[100];
    int i,c = 0;
    string line;

    void readFile() {
        ifstream questions("D:\\questions.txt");
        while (getline(questions, line)) {
                if (line.substr(0, 1) == "#") {
                    question[i] = base64_decode(line.substr(1, 100));
                    i++;
                } else {
                    number[c] = atoi(base64_decode(line.c_str()).c_str());
                    c++;

                }
            }
        questions.close();
    }

    int getNumber(int a) {
        return number[a];
    }

    string getQuestion(int a) {
        return question[a];
    }
}
