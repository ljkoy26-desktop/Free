
// CkJsonMFC_001.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCkJsonMFC_001App:
// �� Ŭ������ ������ ���ؼ��� CkJsonMFC_001.cpp�� �����Ͻʽÿ�.
//

class CCkJsonMFC_001App : public CWinApp
{
public:
	CCkJsonMFC_001App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCkJsonMFC_001App theApp;