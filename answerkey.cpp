#include "answerkey.h"
AnswerKey::AnswerKey(int i) {
    numWords = 0;
    path += to_string(i);
    for (auto& dirEntry : filesystem::recursive_directory_iterator(path)) {
        filesystem::path p = dirEntry;
        p.replace_extension("");
        answers.push_back(p.filename().string());
        numWords++;
    }
}

vector<string> AnswerKey::getAnswers() {
    return answers;
}

string AnswerKey::getRandom(string answer) {
    string random = answers[rand() % numWords];
    if (random.compare(answer) == 0) {
        getRandom(answer);
    }
    return random;
}
