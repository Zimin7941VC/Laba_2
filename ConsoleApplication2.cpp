#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	ifstream fin("text.txt", ios::in);
	if (!fin)
	{
		cout << "Oshibka otkritija faila" << endl;
		return 1;
	}
	fin.seekg(0, ios::end);
	long len = fin.tellg();
	char *buf = new char[len + 1];
	fin.seekg(0, ios::beg);
	fin.read(buf, len);
	buf[len] = '\0';
	long n = 0, i = 0, j = 0, flag = -1;
	while (buf[i])
	{
		if (buf[i] == '"')
			if (flag < 0)
				flag = i;
			else
			{
				for (j = flag; j <= i; j++)
					cout << buf[j];
				flag = -1;
			}


		if (buf[i] == '.' || buf[i] == '!')
			n = i + 1;
		i++;
	}
	fin.close();
	cout << endl;
	return 0;
}