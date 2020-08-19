
// ServerSocketMFCDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#include "ListenSocket.h"
#include "ServiceSocket.h"


// CServerSocketMFCDlg ��ȭ ����
class CServerSocketMFCDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CServerSocketMFCDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVERSOCKETMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListenSocket * m_pListenSocket;
	CServiceSocket * m_pServiceSocket;
public:
	CButton m_button_start;
	CStatic m_static_status;
	void ProcessAccept();
	afx_msg void OnBnClickedButtonStart();
};
