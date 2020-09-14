
// CkJsonMFC_001Dlg.cpp : 구현 파일
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

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CCkJsonMFC_001Dlg 대화 상자



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


// CCkJsonMFC_001Dlg 메시지 처리기

BOOL CCkJsonMFC_001Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCkJsonMFC_001Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCkJsonMFC_001Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCkJsonMFC_001Dlg::OnBnClickedButtonJsontest() // 테스트 버튼
{
	/* 인터페이스 구현사항
	
	1. SQL Tool (내보내기 / 불러오기)
	 * 내보내기
	  - 로우 하나를 객체로 잡고, 컬럼들을 순회하면서 데이터를 가져온다
	  - 이때, 컬럼의 타입을 검증하는 과정이 있어야할거같다 (date, varchar, number)
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
	// JSON 파일불러와서 읽기

	//CkJsonObject json;
	//json.put_EmitCompact(false);
	//bool success = json.LoadFile("D:\\깃허브브랜치\\Free\\CkJsonMFC_001\\JSON샘플\\JsonTest.json");

	//if (success != true)
	//{
	//	strTemp = json.lastErrorText();
	//}
	//strTemp = json.stringOf("nestedObject.aaa.bb1.cc2");	

	/************************/
	//SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);

}
