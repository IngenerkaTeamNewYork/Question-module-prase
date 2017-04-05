#include "TXLib.h"
#include "questionmodule.h"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <vector>
#include "include\RdoQuota.hh"
#include "include\RdoIntegers.hh"
#include "src\RdoIntegers.cxx"
#include "include\RdoSequence.hh"
#include "include\RdoStrings.hh"
#include "include\RdoRandom.hh"
#include "include\RdoBytes.hh"
#include "include\RdoOptions.hh"

int main()
{
    txCreateWindow(600, 400);

    //Открыли файл
    //10 вопросов
    //записали куда-нибудь
    //файл закрыт
    int i = 0;
    questionLib::readFile();
    while (i < 3) {
        questionModule::runQuestionModule(questionLib::getNumber(i),questionLib::getQuestion(i).c_str());
        cout << i;
        i++;
    }
    RdoIntegers rdo;
    rdo.setNum(int(4096/8));
    rdo.setBase("10");
    rdo.setRange(33,126);
    rdo.setInMemory(true);
    bool failed = rdo.downloadData();
    std::vector<long int> data = rdo.cache();
    unsigned int num = data.size();
    txMessageBox(num);
    return 0;
}
