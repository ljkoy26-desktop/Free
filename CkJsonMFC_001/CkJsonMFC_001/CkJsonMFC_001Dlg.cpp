
// CkJsonMFC_001Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CkJsonMFC_001.h"
#include "CkJsonMFC_001Dlg.h"
#include "afxdialogex.h"

#include "CkJsonObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "ws2_32.lib")

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCkJsonMFC_001Dlg ��ȭ ����



CCkJsonMFC_001Dlg::CCkJsonMFC_001Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CKJSONMFC_001_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCkJsonMFC_001Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_JSONTEST, m_EditJSONTest);
}

BEGIN_MESSAGE_MAP(CCkJsonMFC_001Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_JSONTEST, &CCkJsonMFC_001Dlg::OnBnClickedButtonJsontest)
END_MESSAGE_MAP()


// CCkJsonMFC_001Dlg �޽��� ó����

BOOL CCkJsonMFC_001Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCkJsonMFC_001Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCkJsonMFC_001Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCkJsonMFC_001Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCkJsonMFC_001Dlg::OnBnClickedButtonJsontest() // �׽�Ʈ ��ư
{
	/* �������̽� ��������
	
	1. SQL Tool (�������� / �ҷ�����)
	 * ��������
	  - �ο� �ϳ��� ��ü�� ���, �÷����� ��ȸ�ϸ鼭 �����͸� �����´�
	  - �̶�, �÷��� Ÿ���� �����ϴ� ������ �־���ҰŰ��� (date, varchar, number)
	  7369	SMITH	CLERK	7902	1980/12/17 00:00:00	800		20
	  7499	ALLEN	SALESMAN	7698	1981/02/20 00:00:00	1600	300	30

	  {
		"EMPNO":7369,
		"ENAME":"SMITH",
		"JOB":"CLERK"
	  }
	*/
	CkString strOut;
	CString strTemp = _T("JSON TEST");
	SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);

	CkJsonObject json;

	bool success;
	int index = -1;

	success = json.AddStringAt(2, "Title", "Pan's Labyrinth");
	success = json.AddStringAt(1, "Director", "Guillermo del Toro");
	success = json.AddStringAt(0, "Original_Title", "El laberinto del fauno");
	success = json.AddIntAt(3, "Year_Released", 2006);
	
	json.put_EmitCompact(false);
	strOut.append(json.emit());
	//strTemp = (LPCTSTR)strOut;
	strOut.append("\r\n");

	/************************/
	

	SetDlgItemText(IDC_EDIT_JSONTEST, strOut);
	// JSON ���Ϻҷ��ͼ� �б�

	//CkJsonObject json;
	//json.put_EmitCompact(false);
	//bool success = json.LoadFile("D:\\�����귣ġ\\Free\\CkJsonMFC_001\\JSON����\\JsonTest.json");

	//if (success != true)
	//{
	//	strTemp = json.lastErrorText();
	//}
	//strTemp = json.stringOf("nestedObject.aaa.bb1.cc2");	

	/************************/
	//SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);

}
