
// SocketMFC.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSocketMFCApp:
// �� Ŭ������ ������ ���ؼ��� SocketMFC.cpp�� �����Ͻʽÿ�.
//

class CSocketMFCApp : public CWinApp
{
public:
	CSocketMFCApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSocketMFCApp theApp;