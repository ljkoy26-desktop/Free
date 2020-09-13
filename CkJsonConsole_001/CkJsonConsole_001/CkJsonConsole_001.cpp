// CkJsonConsole_001.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include "include\chilkat\CkJsonObject.h"
#include <iostream>

#pragma comment(lib, "ws2_32.lib")


int main()
{
	CkJsonObject json;
	json.put_EmitCompact(false);

	// Assume the file contains the data as shown above..
	bool success = json.LoadFile("C:\\Users\\Warevalley\\Desktop\\JsonTest.json");
	if (success != true) 
	{
		std::cout << json.lastErrorText() << "\r\n";
		return 0 ;
	}


	//std::cout << json.stringOf("nestedObject.aaa.bb1.cc1") << "\r\n";
	std::cout << json.stringOf("nestedObject.aaa.bb1[0]") << "\r\n";

	//CkJsonObject json;
	//bool succecs;
	//int index =0;
	//succecs = json.AddStringAt(-1, "Title", "Pan's Labyrinth");
	//json.put_EmitCompact(false);
	//std::cout << json.emit() << "\r\n";

    return 0;
}

