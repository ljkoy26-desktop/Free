
// RegexTest.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CRegexTestApp:
// �� Ŭ������ ������ ���ؼ��� RegexTest.cpp�� �����Ͻʽÿ�.
//

class CRegexTestApp : public CWinApp
{
public:
	CRegexTestApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CRegexTestApp theApp;