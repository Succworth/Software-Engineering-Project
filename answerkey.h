#ifndef ANSWERKEY_H
#define ANSWERKEY_H

#include <unordered_map>
#include<string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <random>
using namespace std;

class AnswerKey {
private:
    string path = "Assets/Common Words and Phrases ";
    vector<string> answers;
    int numWords;
public:
    AnswerKey(int i);
    vector<string> getAnswers();
    string getRandom(string answer);
};

#endif // ANSWERKEY_H
