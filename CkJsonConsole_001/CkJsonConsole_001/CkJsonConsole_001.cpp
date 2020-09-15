// CkJsonConsole_001.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
//#include "include\chilkat\CkJsonObject.h"
#include "CkJsonObject.h"
#include "CkJsonArray.h"
#include <iostream>

#pragma comment(lib, "ws2_32.lib")


int main()
{
	/***************************************************************************/
	CkJsonObject json;
	bool success;
	//  An index value of -1 is used to append at the end.
	int index = -1;

	//success = json.AddStringAt(-1, "Title", "The Cuckoo's Calling");
	//success = json.AddStringAt(-1, "Author", "Robert Galbraith");
	//success = json.AddStringAt(-1, "Genre", "classic crime novel");



	success = json.AddObjectAt(-1, "오브젝트At ==0");
	success = json.AddObjectAt(-1, "오브젝트At ==1");
	success = json.AddObjectAt(-1, "오브젝트At ==2");
	int n = json.get_Size();
	//  Let's create the Detail JSON object:
	CkJsonObject *detail = json.ObjectAt(1);
	success = detail->AddStringAt(-1, "Publisher", "Little Brown");
	success = detail->AddIntAt(-1, "Publication_Year", 2013);
	success = detail->AddNumberAt(-1, "ISBN-13", "9781408704004");
	success = detail->AddStringAt(-1, "Language", "English");
	success = detail->AddIntAt(2, "Pages", 494); // Language 앞으로 감
	delete detail;

	//  Add the array for Price
	success = json.AddArrayAt(-1, "Price");
	CkJsonArray *aPrice = json.ArrayAt(- 1);

	//  Entry entry in aPrice will be a JSON object.

	//  Append a new/empty ojbect to the end of the aPrice array.
	success = aPrice->AddObjectAt(-1);
	//  Get the object that was just appended.
	CkJsonObject *priceObj = aPrice->ObjectAt(aPrice->get_Size() - 1);
	success = priceObj->AddStringAt(0, "type", "Hardcover");
	success = priceObj->AddNumberAt(0, "price", "16.65");
	delete priceObj;

	success = aPrice->AddObjectAt(-1);
	priceObj = aPrice->ObjectAt(aPrice->get_Size() - 1);
	success = priceObj->AddStringAt(-1, "type", "Kindle Edition");
	success = priceObj->AddNumberAt(-1, "price", "7.00");
	delete priceObj;

	delete aPrice;

	json.put_EmitCompact(false);
	std::cout << json.emit() << "\r\n";



	/***************************************************************************/
	//CkJsonObject json;
	//json.put_EmitCompact(false);

	////  Assume the file contains the data as shown above..
	//bool success = json.LoadFile("C:\\노트북깃허브\\Free\\CkJsonConsole_001\\JSON샘플\\JsonTest2.json");
	//if (success != true) {
	//	std::cout << json.lastErrorText() << "\r\n";
	//	return -1;
	//}

	////  First navigate to the "sampleData" object:
	//CkJsonObject *sampleData = json.ObjectOf("sampleData");

	////  Demonstrate BoolAt and BoolOf
	////std::cout << "hungry: " << sampleData->BoolOf("hungry") << "\r\n";
	////std::cout << "hungry: " << sampleData->BoolAt(2) << "\r\n";

	//////  StringOf returns the value as a string regardless of it's actual type:
	////std::cout << "pi: " << sampleData->stringOf("pi") << "\r\n";
	////std::cout << "answer: " << sampleData->stringOf("answer") << "\r\n";
	////std::cout << "withoutValue: " << sampleData->stringOf("withoutValue") << "\r\n";
	////std::cout << "hungry: " << sampleData->stringOf("hungry") << "\r\n";

	//////  Demonstrate IsNullOf / IsNullAt
	////std::cout << "withoutValue is null? " << sampleData->IsNullOf("withoutValue") << "\r\n";
	////std::cout << "withoutValue is null? " << sampleData->IsNullAt(3) << "\r\n";
	////std::cout << "apple is null? " << sampleData->IsNullOf("apple") << "\r\n";
	////std::cout << "apple is null? " << sampleData->IsNullAt(1) << "\r\n";

	//////  IntOf
	////std::cout << "answer: " << sampleData->IntOf("answer") << "\r\n";

	////  SetNullAt, SetNullOf
	////  Set "pi" to null
	//success = sampleData->SetNullAt(0);
	////  Set "answer" to null
	//success = sampleData->SetNullOf("answer");

	////  Show the changes:
	//std::cout << json.emit() << "\r\n";

	////  Restore pi and apple:
	//success = sampleData->SetNumberAt(0, "3.14");
	//success = sampleData->SetNumberOf("answer", "42");

	////  Show the changes:
	//std::cout << json.emit() << "\r\n";

	////  Add a null value named "afterApple" just after "apple"
	//success = sampleData->AddNullAt(2, "afterApple");

	////  Add a boolean value just after "pi"
	//success = sampleData->AddBoolAt(1, "afterPi", false);

	//delete sampleData;

	////  Examine the changes..
	//std::cout << json.emit() << "\r\n";

	/***************************************************************************/
	//CkJsonObject json;
	//json.put_EmitCompact(false);

	//bool success = json.LoadFile("D:\\깃허브브랜치\\Free\\CkJsonConsole_001\\JsonTest.json");

	//if (success != true) 
	//{
	//	std::cout << json.lastErrorText() << "\r\n";
	//	return 0 ;
	//}


	//std::cout << json.stringOf("nestedObject.aaa.bb1.cc2") << "\r\n";
	/***************************************************************************/
    return 0;
}

