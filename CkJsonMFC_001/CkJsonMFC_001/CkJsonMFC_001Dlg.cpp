
// CkJsonMFC_001Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CkJsonMFC_001.h"
#include "CkJsonMFC_001Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[]	= __FILE__;
#endif

#define JSON_FILEPATH "C:\\노트북깃허브\\Free\\CkJsonMFC_001\\JSON SampleData\\"

// crypt32.lib, ws2_32.lib, dnsapi.lib
//#pragma comment(lib, "ws2_32.lib")

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
CCkJsonMFC_001Dlg::~CCkJsonMFC_001Dlg()
{
	delete m_pJsonObject;
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
	ON_BN_CLICKED(IDC_BUTTON1, &CCkJsonMFC_001Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCkJsonMFC_001Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCkJsonMFC_001Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCkJsonMFC_001Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_WRITEFILE, &CCkJsonMFC_001Dlg::OnBnClickedButtonWritefile)
	ON_BN_CLICKED(IDC_BUTTON5, &CCkJsonMFC_001Dlg::OnBnClickedButton5)
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


	m_pJsonObject = new CkJsonObjectT;
#ifndef _UNICODE
	m_pJsonObject->put_Utf8(true);
#endif

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
	CString strOut;
	CString strTemp = _T("JSON TEST");
	SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);

	CkJsonObjectT json;

	bool success;
	int index = -1;

	success = json.AddStringAt(0, _T("Title"), _T("Pan's Labyrinth"));
	success = json.AddStringAt(1, _T("Director"), _T("Guillermo del Toro"));
	success = json.AddStringAt(2, _T("Original_Title"), _T("El laberinto del fauno"));
	success = json.AddIntAt(3, _T("Year_Released"), 2006);
	success = json.AddNumberAt(4, _T("Year_Released"), _T("2006.12"));
	
	json.put_EmitCompact(false);
	strOut = json.emit();
	strOut += _T("\r\n");
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


void CCkJsonMFC_001Dlg::OnBnClickedButton1() // 복잡한 문서
{
	CkJsonObjectT json;

	bool success;
	json.put_EmitCompact(false);
	//  The only reason for failure in the following lines of code would be an out-of-memory condition..

	//  An index value of -1 is used to append at the end.
	int index = -1;
	success = json.AddStringAt(-1, _T("Title"), _T("The Cuckoo's Calling"));
	success = json.AddStringAt(-1, _T("Author"), _T("Robert Galbraith"));
	success = json.AddStringAt(-1, _T("Genre"), _T("classic crime novel"));

	//  Let's create the Detail JSON object:
	success = json.AddObjectAt(-1, _T("Detail"));
	CkJsonObjectT *detail = json.ObjectAt(json.get_Size() - 1);
	success = detail->AddStringAt(-1, _T("Publisher"), _T("Little Brown"));
	success = detail->AddIntAt(-1, _T("Publication_Year"), 2013); // 소수지원이 안된다. number 타입 추천
	success = detail->AddNumberAt(-1, _T("ISBN-13"), _T("9yu781408704004"));
	success = detail->AddStringAt(-1, _T("Language"), _T("English"));
	success = detail->AddIntAt(-1, _T("Pages"), 494);
	delete detail;

	//  Add the array for Price




	success = json.AddArrayAt(-1, _T("Price"));
	CkJsonArrayT *aPrice = json.ArrayAt(json.get_Size() - 1);

	//  Entry entry in aPrice will be a JSON object.

	//  Append a new/empty ojbect to the end of the aPrice array.
	success = aPrice->AddObjectAt(-1);
	//  Get the object that was just appended.
	CkJsonObjectT *priceObj = aPrice->ObjectAt(aPrice->get_Size() - 1);
	success = priceObj->AddStringAt(-1, _T("type"), _T("Hardcover"));
	success = priceObj->AddNumberAt(-1, _T("price"), _T("16.65"));
	delete priceObj;

	success = aPrice->AddObjectAt(-1);
	priceObj = aPrice->ObjectAt(aPrice->get_Size() - 1);
	success = priceObj->AddStringAt(-1, _T("type"), _T("Kindle Edition"));
	success = priceObj->AddNumberAt(-1, _T("price"), _T("7.00"));

	delete priceObj;
	delete aPrice;

//	json.put_EmitCompact(false);
//	AfxMessageBox(json.emit());
	SetDlgItemText(IDC_EDIT_JSONTEST, (LPTSTR)json.emit());

}


void CCkJsonMFC_001Dlg::OnBnClickedButton2() // 중첩배열
{
	CkJsonObjectT json;
	CString strTemp;
	CString strTemp2;
	// This is the above JSON with whitespace chars removed (SPACE, TAB, CR, and LF chars).
	// The presence of whitespace chars for pretty-printing makes no difference to the Load
	// method. 
	TCHAR *jsonStr = _T("{ \"numbers\" : [ [\"even\", 2, 4, 6, 8], [\"prime\", 2, 3, 5, 7, 11, 13] ] }");

	bool success = json.Load(jsonStr);
	if (success != true) {
		SetDlgItemText(IDC_EDIT_JSONTEST, json.lastErrorText());
		return;
	}

	// Get the value of the "numbers" object, which is an array that contains JSON arrays.
	CkJsonArrayT *outerArray = json.ArrayOf(_T("numbers"));
	if (json.get_LastMethodSuccess() == false) {
		SetDlgItemText(IDC_EDIT_JSONTEST, _T("numbers array not found."));
		return;
	}

	int numArrays = outerArray->get_Size();
	int i;

	for (i = 0; i <= numArrays - 1; i++) {

		CkJsonArrayT *innerArray = outerArray->ArrayAt(i);

		// The first item in the innerArray is a string
		strTemp = innerArray->stringAt(0);
		strTemp += ":\r\n";

		int numInnerItems = innerArray->get_Size();
		int j;
		for (j = 1; j <= numInnerItems - 1; j++) {

			strTemp2.Format(_T("%d"), innerArray->IntAt(0));
			strTemp += strTemp2;
			strTemp += ":\r\n";
			strTemp2 = "";			
		}
		SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);
		delete innerArray;
	}

	delete outerArray;
}


void CCkJsonMFC_001Dlg::OnBnClickedButton3() // EMP버튼
{
	CString strTemp;
	CString strNum;
	int i=0, j=0;
	bool success = false;
	CkJsonObjectT jsonParent;
	
	jsonParent.put_EmitCompact(false);
	jsonParent.AddObjectAt(-1, _T("asd"));
	/* -1는 뒤에 추가하고, 0은 앞쪽으로 추가함, 그외 숫자는 인덱스인데 잘못참조하면 튕김 */

	for (i = 0; i < 4; i++)
	{
		strNum.Format(_T("ROWNUM : %d"), i);		
		jsonParent.AddObjectAt(-1 , strNum);
		CkJsonObjectT *json2 = jsonParent.ObjectAt(i+1);

		for (j = 0; j < 4; j++)
		{
			//json2->AddIntAt(-1,"int", 3);
			json2->AddStringAt(-1, _T("sa"), _T("이재현"));
		}		
		delete json2;
	}
	
	
	strTemp = jsonParent.emit();
	SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);

	CString strTemp2;
	if (jsonParent.WriteFile(_T("C:\\노트북깃허브\\Free\\CkJsonMFC_001\\JSON샘플\\JsonTest_005.json"))) // 성공 1 , 실패 0
		SetDlgItemText(IDC_EDIT_STATUS, _T("성공!"));

	else {
		strTemp2 = jsonParent.lastErrorText();
		SetDlgItemText(IDC_EDIT_STATUS, jsonParent.lastErrorText());
				
	}
}


void CCkJsonMFC_001Dlg::OnBnClickedButton4() // 파일읽기
{
	CString strTemp, strLine = _T("");
	CkJsonObjectT json;
	CString strPath = _T("C:\\노트북깃허브\\Free\\CkJsonMFC_001\\JSON SampleData\\");
		
	CString strFileName = _T("Ckjsonobject(안시).json");
	strPath += strFileName;

	if (json.LoadFile(strPath))
	{
		SetDlgItemText(IDC_EDIT_STATUS, _T("성공!"));
		int i, j;
		for (i = 0; i < json.get_Size(); i++)
		{
			CkJsonObjectT *json2 = json.ObjectAt(i);			
			for (j = 0; j < json2->get_Size(); j++)
			{				
				strLine += json2->stringAt(j);
				strLine.Append(_T("\r\n"));
			}
			delete json2;
		}
		SetDlgItemText(IDC_EDIT_JSONTEST, strLine);
	}	
	else
	{
		strTemp.Format(json.lastErrorText());
		SetDlgItemText(IDC_EDIT_STATUS, strTemp);
	}		
}


void CCkJsonMFC_001Dlg::OnBnClickedButtonWritefile()
{
	CkJsonObjectT json;
	json.put_EmitCompact(false);	
	json.put_DebugLogFilePath(_T("C:\\노트북깃허브\\Free\\debug"));
	CString strNum, strLine, strTemp;
	int i, j;

	for (i = 0; i < 4; i++)
	{
		strNum.Format(_T("ROWNUM : %d"), i);
		json.AddObjectAt(-1, strNum);
		CkJsonObjectT *json2 = json.ObjectAt(i);

		for (j = 0; j < 4; j++)
		{
			//json2->AddIntAt(-1,"int", 3);
			json2->AddStringAt(-1, _T("sa"), _T("이재현"));
		}
		delete json2;
	}
	SetDlgItemText(IDC_EDIT_JSONTEST, json.emit());
	
	json.ObjectOf(_T("asdasd"));
//	json.WriteFile(L"C:\\노트북깃허\\Free\\CkJsonMFC_001\\JSON SampleData\\Ckjsonobject(안시).json");
//	json.LoadFile(L"C:\\노트북깃허\\Free\\CkJsonMFC_001\\JSON SampleData\\Ckjsonobject(안시).json");
	//strTemp.Format(json.lastErrorText());
	strTemp.Format(json.lastErrorText());

	SetDlgItemText(IDC_EDIT_STATUS, strTemp);
}


void CCkJsonMFC_001Dlg::OnBnClickedButton5() // 누수확인
{
	CArray<int*, int*> m_aItem;

	int * n1 = new int(11);
	int * n2 = new int(22);
	int * n3 = new int(33);

	m_aItem.Add(n1);
	m_aItem.Add(n2);
	m_aItem.Add(n3);

	int *nElement1 = m_aItem.GetAt(0);
	//int *nElement1 = m_aItem.ElementAt(0);

	*nElement1 += 5;
	delete nElement1;

	int* pItem;
	int nSize = m_aItem.GetSize();

	int i;
	for (i = 0; i < nSize; ++i)
	{
		pItem = m_aItem.GetAt(i);		
		delete pItem;
		pItem = NULL;
	}
	m_aItem.RemoveAll();
}
