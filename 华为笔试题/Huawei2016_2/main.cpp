#include <iostream>

using namespace std;

int main()
{
    string str;
    int index = 0;

    while(cin >> str)
    {
        getOutputString(str,index);

        index++;
        if(index == 3)
        break;
    }

    cout << "Hello world!" << endl;
    return 0;
}
