#pragma once
#include "afxsock.h"

class CServerSocketMFCDlg;

class CListenSocket : public CSocket
{
public:
	CListenSocket();
	CListenSocket(CServerSocketMFCDlg* pServerSocketDlg);
	virtual ~CListenSocket();

	CServerSocketMFCDlg* m_pServerSocketDlg;

public:
	virtual void OnAccept(int nErrorCode);
};

