#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string encrypt (int s, string text)
{
    string result = "";
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);
    else
        result += char(int(text[i]+s-97)%26 +97);
    }
    return result;
}

string removeSpaces(string str) 
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}


int main ()
{
int argc = 0;
string argv = "", dummy ="";
cin >> argc;
getline(cin, dummy);
getline(cin, argv);
transform(argv.begin(), argv.end(),argv.begin(), ::toupper);
for (int i = 0, len = argv.size(); i < len; i++)
    {
        if (ispunct(argv[i]))
        {
            argv.erase(i--, 1);
            len = argv.size();
        }
    }
argv = removeSpaces(argv);
argv = encrypt(argc, argv);
int j = 0, i =0;
while (i < argv.size())
      {
	dummy = argv.substr(i,5);
	cout << dummy << " ";
	i += 5;
	j += 1;
	if (j == 10)
	{
		cout << endl;
		j = 0;
	}
	if (i == argv.size() -1)
	{
		cout << endl;
	}
      }
cout << endl;
return 0;
}
