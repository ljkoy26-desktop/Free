#pragma once
#include "afxsock.h"

class CServerSocketMFCDlg;

class CServiceSocket :	public CSocket
{
public:
	CServiceSocket();
	CServiceSocket(CServerSocketMFCDlg* pServerSocketDlg);
	virtual ~CServiceSocket();

	CServerSocketMFCDlg* m_pServerSocketDlg;

};

