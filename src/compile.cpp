#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    if(argc==3){
    string input = argv[1];
    string output = argv[2];
    output+=".s";
    system(("bfc.exe "+ input+" "+output).c_str());
    system(("g++ -o " + output + ".exe " + output).c_str());
    }else{
        string s = argv[1];
    if(s.compare("help")==0) cout << "Brainfuck automatic compiler.\nSyntax : compile.exe <input_file> <output_file>";
    else cout << "Incorrect syntax.\nUsage : compile.exe <input_file> <output_file>";
    }
    return 0;
}
