#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, const char * argv[]) {
    string expression = "2-1-1";
    int num = 0;
    char op = ' ';
    istringstream is(expression + '+');
    while(is >> num && is >> op) {
        cout<< num << " " << op << endl;
    }
    return 0;
}

