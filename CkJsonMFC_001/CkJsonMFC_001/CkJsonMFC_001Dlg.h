
// CkJsonMFC_001Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#include "CkJsonObject.h"
#include "CkJsonObjectW.h"
#include "CkJsonArray.h"
#include "CkJsonArrayW.h"
#include "CkString.h"

// CCkJsonMFC_001Dlg ��ȭ ����
class CCkJsonMFC_001Dlg : public CDialogEx
{
// �����Դϴ�.
public:

#ifdef _UNICODE
	typedef CkJsonObjectW CkJsonObjectT;
	typedef CkJsonArrayW CkJsonArrayT;
#else
	typedef CkJsonObject CkJsonObjectT;
	typedef CkJsonArray CkJsonArrayT;
#endif

	CCkJsonMFC_001Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CKJSONMFC_001_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

private:

	CkJsonObjectT *m_pJsonObject;

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
