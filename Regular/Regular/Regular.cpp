#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;
int main()
{
    ifstream fin("test1.txt");
    ofstream fout("test2.txt");

    string dig, str, str1, num;
    const int CONST = 3;

    cout << "Enter digit: " << endl;
    cin >> dig;

    cmatch result;
    regex regular("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])[\.]){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");

    while (fin >> str)
    {
        str1 = str;
        if (regex_match(str1.c_str(), result, regular)) {
            num = result.str(CONST);
            if (num.find(dig) != 0) {
                fout << str << endl;
            }
        }
        else {
            cout << "Error! Impossible IP adress!" << endl;
        }
      
    }

    fin.close();
    fout.close();

    return 0;
}