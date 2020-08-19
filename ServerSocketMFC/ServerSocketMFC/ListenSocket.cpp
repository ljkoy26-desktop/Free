#include "stdafx.h"
#include "ServerSocketMFC.h"
#include "ListenSocket.h"

#include "ServerSocketMFCDlg.h"
class CServerSocketDlg;

CListenSocket::CListenSocket()
{
}
CListenSocket::CListenSocket(CServerSocketMFCDlg* pServerSocketDlg)
{
	m_pServerSocketDlg = pServerSocketDlg;
}

CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	m_pServerSocketDlg->ProcessAccept();


	CSocket::OnAccept(nErrorCode);
}
