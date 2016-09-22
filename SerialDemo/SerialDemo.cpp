// SerialDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "SerialPort.h"  
#include <iostream>  
using namespace	 std;
int _tmain(int argc, _TCHAR* argv[])
{

	CSerialPort mySerialPort;

	if (!mySerialPort.InitPort(3))
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}

	if (!mySerialPort.OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}

	unsigned char temp;
	std::cin >> temp;

	unsigned char str[] = "12.3";

	char str2[16] = { '0' };


	if (mySerialPort.WriteData(&temp, 4))
	{
		for (char i = 0; i < 8; i++)
		{
			mySerialPort.ReadChar(str2[i]);

		}
	}
	cout << str2 << endl;

	mySerialPort.CloseListenTread();



	return 0;
}


















