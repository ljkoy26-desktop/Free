
// CkJsonMFC_001Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

#include "CkJsonObject.h"
#include "CkJsonObjectW.h"
#include "CkJsonArray.h"
#include "CkJsonArrayW.h"
#include "CkString.h"

// CCkJsonMFC_001Dlg 대화 상자
class CCkJsonMFC_001Dlg : public CDialogEx
{
// 생성입니다.
public:

#ifdef _UNICODE
	typedef CkJsonObjectW CkJsonObjectT;
	typedef CkJsonArrayW CkJsonArrayT;
#else
	typedef CkJsonObject CkJsonObjectT;
	typedef CkJsonArray CkJsonArrayT;
#endif

	CCkJsonMFC_001Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CKJSONMFC_001_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:

	CkJsonObjectT *m_pJsonObject;

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	virtual 
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonJsontest();
	CEdit m_EditJSONTest;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButtonWritefile();
};
