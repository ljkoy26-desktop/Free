
// ServerSocketMFCDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

#include "ListenSocket.h"
#include "ServiceSocket.h"


// CServerSocketMFCDlg 대화 상자
class CServerSocketMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CServerSocketMFCDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVERSOCKETMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
