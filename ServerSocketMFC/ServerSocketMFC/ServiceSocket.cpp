#include "stdafx.h"
#include "ServerSocketMFC.h"
#include "ServiceSocket.h"

#include "ServerSocketMFCDlg.h"


CServiceSocket::CServiceSocket(CServerSocketMFCDlg* pServerSocketDlg)
{
	m_pServerSocketDlg = pServerSocketDlg;
}

CServiceSocket::CServiceSocket()
{
}


CServiceSocket::~CServiceSocket()
{
}
