#include <string>
using namespace std;

int main() {
    string s = "What data type is this?";
    char firstchar = s[0]; //type needs to be char not string
    // char c = "c";  this does not work since "c" is a string
    char c = 'c';
    //character are integers in C++
    char d = c + 1; // perfectly legal
}