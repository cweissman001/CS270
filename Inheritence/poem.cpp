#include "poem.h"

#include <iostream>

using namespace std;

Poem::Poem(vector<string> text, string auth, string t) :
  lines(text) {
    author = auth;
    title = t; 
}

void Poem::appendLine(string line) {
  lines.push_back(line);
}

int Poem::getLineCount() { 
  return lines.size();
}
