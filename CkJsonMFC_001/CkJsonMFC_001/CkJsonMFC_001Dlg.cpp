
// CkJsonMFC_001Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CkJsonMFC_001.h"
#include "CkJsonMFC_001Dlg.h"
#include "afxdialogex.h"

#include "CkJsonObject.h"
#include "CkJsonArray.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// crypt32.lib, ws2_32.lib, dnsapi.lib
//#pragma comment(lib, "ws2_32.lib")

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
	ON_BN_CLICKED(IDC_BUTTON1, &CCkJsonMFC_001Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCkJsonMFC_001Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCkJsonMFC_001Dlg::OnBnClickedButton3)
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

	success = json.AddStringAt(0, "Title", "Pan's Labyrinth");
	success = json.AddStringAt(1, "Director", "Guillermo del Toro");
	success = json.AddStringAt(2, "Original_Title", "El laberinto del fauno");
	success = json.AddIntAt(3, "Year_Released", 2006);
	success = json.AddNumberAt(4, "Year_Released", "2006.12");
	
	json.put_EmitCompact(false);
	strOut.append(json.emit());
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


void CCkJsonMFC_001Dlg::OnBnClickedButton1() // ������ ����
{

	CkJsonObject json;

	bool success;
	json.put_EmitCompact(false);
	//  The only reason for failure in the following lines of code would be an out-of-memory condition..

	//  An index value of -1 is used to append at the end.
	int index = -1;
	success = json.AddStringAt(-1, "Title", "The Cuckoo's Calling");
	success = json.AddStringAt(-1, "Author", "Robert Galbraith");
	success = json.AddStringAt(-1, "Genre", "classic crime novel");

	//  Let's create the Detail JSON object:
	success = json.AddObjectAt(-1, "Detail");
	CkJsonObject *detail = json.ObjectAt(json.get_Size() - 1);
	success = detail->AddStringAt(-1, "Publisher", "Little Brown");
	success = detail->AddIntAt(-1, "Publication_Year", 2013); // �Ҽ������� �ȵȴ�. number Ÿ�� ��õ
	success = detail->AddNumberAt(-1, "ISBN-13", "9781408704004");
	success = detail->AddStringAt(-1, "Language", "English");
	success = detail->AddIntAt(-1, "Pages", 494);
	delete detail;

	//  Add the array for Price




	success = json.AddArrayAt(-1, "Price");
	CkJsonArray *aPrice = json.ArrayAt(json.get_Size() - 1);

	//  Entry entry in aPrice will be a JSON object.

	//  Append a new/empty ojbect to the end of the aPrice array.
	success = aPrice->AddObjectAt(-1);
	//  Get the object that was just appended.
	CkJsonObject *priceObj = aPrice->ObjectAt(aPrice->get_Size() - 1);
	success = priceObj->AddStringAt(-1, "type", "Hardcover");
	success = priceObj->AddNumberAt(-1, "price", "16.65");
	delete priceObj;

	success = aPrice->AddObjectAt(-1);
	priceObj = aPrice->ObjectAt(aPrice->get_Size() - 1);
	success = priceObj->AddStringAt(-1, "type", "Kindle Edition");
	success = priceObj->AddNumberAt(-1, "price", "7.00");

	delete priceObj;
	delete aPrice;

//	json.put_EmitCompact(false);
//	AfxMessageBox(json.emit());
	SetDlgItemText(IDC_EDIT_JSONTEST, (LPTSTR)json.emit());

}


void CCkJsonMFC_001Dlg::OnBnClickedButton2() // ��ø�迭
{
	CkJsonObject json;
	CString strTemp;
	CString strTemp2;
	// This is the above JSON with whitespace chars removed (SPACE, TAB, CR, and LF chars).
	// The presence of whitespace chars for pretty-printing makes no difference to the Load
	// method. 
	const char *jsonStr = "{ \"numbers\" : [ [\"even\", 2, 4, 6, 8], [\"prime\", 2, 3, 5, 7, 11, 13] ] }";

	bool success = json.Load(jsonStr);
	if (success != true) {
		SetDlgItemText(IDC_EDIT_JSONTEST, json.lastErrorText());
		return;
	}

	// Get the value of the "numbers" object, which is an array that contains JSON arrays.
	CkJsonArray *outerArray = json.ArrayOf("numbers");
	if (json.get_LastMethodSuccess() == false) {
		SetDlgItemText(IDC_EDIT_JSONTEST, "numbers array not found.");
		return;
	}

	int numArrays = outerArray->get_Size();
	int i;

	for (i = 0; i <= numArrays - 1; i++) {

		CkJsonArray *innerArray = outerArray->ArrayAt(i);

		// The first item in the innerArray is a string
		strTemp = innerArray->stringAt(0);
		strTemp += ":\r\n";

		int numInnerItems = innerArray->get_Size();
		int j;
		for (j = 1; j <= numInnerItems - 1; j++) {

			strTemp2.Format("%d", innerArray->IntAt(0));
			strTemp += strTemp2;
			strTemp += ":\r\n";
			strTemp2 = "";			
		}
		SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);
		delete innerArray;
	}

	delete outerArray;
}


void CCkJsonMFC_001Dlg::OnBnClickedButton3() // EMP��ư
{
	CString strTemp;
	CString strNum;
	int i=0, j=0;
	bool success = false;
	CkJsonObject json;
	
	json.put_EmitCompact(false);
	

	//success = json.AddObjectAt(3, "Detail1");
	//int n = json.get_Size();
	////  Let's create the Detail JSON object:
	//CkJsonObject *detail = json.ObjectAt(json.get_Size() - 1);
	//success = detail->AddStringAt(-1, "Publisher", "Little Brown");
	//success = detail->AddIntAt(-1, "Publication_Year", 2013);
	//success = detail->AddNumberAt(-1, "ISBN-13", "9781408704004");
	//success = detail->AddStringAt(-1, "Language", "English");
	//success = detail->AddIntAt(-1, "Pages", 494);
	//delete detail;

	// ObjectAt *
	/* -1�� �ڿ� �߰��ϰ�, 0�� �������� �߰���, �׿� ���ڴ� �ε����ε� �߸������ϸ� ƨ�� */

	for (i = 0; i < 4; i++)
	{
		strNum.Format(_T("ROWNUM : %d"), i);		
		json.AddObjectAt(-1 , strNum);
		CkJsonObject *json2 = json.ObjectAt(i);

		for (j = 0; j < 4; j++)
		{
			json2->AddStringAt(-1,"�÷���","������");
			json2->AddIntAt(-1,"int", 3);
		}		
		delete json2;
	}
	
	
	strTemp = json.emit();
	SetDlgItemText(IDC_EDIT_JSONTEST, strTemp);


	if (json.WriteFile("C:\\��Ʈ�ϱ����\\Free\\CkJsonConsole_001\\JSON����\\JsonTest3.json"))
	{
		SetDlgItemText(IDC_EDIT_STATUS, _T("����!"));
	}
	else {
		SetDlgItemText(IDC_EDIT_STATUS, _T("�� �ƴϾ�^^"));
	}
}
