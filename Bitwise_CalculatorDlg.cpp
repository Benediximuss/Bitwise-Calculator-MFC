
// Bitwise_CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bitwise_Calculator.h"
#include "Bitwise_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBitwise_CalculatorDlg dialog



CBitwise_CalculatorDlg::CBitwise_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBitwise_CalculatorDlg::IDD, pParent)
	, radioButton1Operation(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBitwise_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, radioButton1Operation);
	DDX_Control(pDX, IDC_CHECK1, checkBox1toggleShift);
	DDX_Control(pDX, IDC_COMBO1, comboBox1shiftingWay);
	DDX_Control(pDX, IDC_EDIT2, editControl3shiftingBits);
	DDX_Control(pDX, IDC_EDIT1, editControl1_operand1);
	DDX_Control(pDX, IDC_EDIT3, editControl2_operand2);
	DDX_Control(pDX, IDC_LIST1, listBox_result);
	DDX_Control(pDX, IDC_BUTTON1, button_Compute);
}

BEGIN_MESSAGE_MAP(CBitwise_CalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CBitwise_CalculatorDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CBitwise_CalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CBitwise_CalculatorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CBitwise_CalculatorDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CBitwise_CalculatorDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CBitwise_CalculatorDlg message handlers

BOOL CBitwise_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	comboBox1shiftingWay.SetCurSel(0); // left is chosen initally in combobox

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBitwise_CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBitwise_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBitwise_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
	
}

// UGUR OZTUNC 28176 CS204 HW6 BITWISE CALCULATOR USING VS MFC

bool shifting = false;
char operation = '&';
int maxSize = 0;

void CBitwise_CalculatorDlg::OnBnClickedCheck1() // clicking shift checkbox
{
	if (checkBox1toggleShift.GetCheck()) {
		comboBox1shiftingWay.EnableWindow(TRUE);
		editControl3shiftingBits.EnableWindow(TRUE);
		shifting = true;
		//listBox_result.AddString(_T("SHIFTING TRUE")); 
	}
	else {
		comboBox1shiftingWay.EnableWindow(FALSE);
		editControl3shiftingBits.EnableWindow(FALSE);
		shifting = false;
		//listBox_result.AddString(_T("SHIFTING FALSE"));
	}
}

void CBitwise_CalculatorDlg::OnBnClickedRadio1() // AND BUTTON
{
	if (operation != '&') {
		operation = '&';
	}
}

void CBitwise_CalculatorDlg::OnBnClickedRadio2() // OR BUTTON
{
	if (operation != '|') {
		operation = '|';
	}
}

void CBitwise_CalculatorDlg::OnBnClickedRadio3() // XOR BUTTON
{
	if (operation != '^') {
		operation = '^';
	}
}

void CBitwise_CalculatorDlg::OnBnClickedButton1() // compute button
{
	CString operand1cstr, operand2cstr, outputCstr;
	editControl1_operand1.GetWindowTextW(operand1cstr);
	editControl2_operand2.GetWindowTextW(operand2cstr);

	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());
	CSize cz;

	if (operand1cstr.GetLength() == 0 || operand2cstr.GetLength() == 0) { // checking both operands are entered
		outputCstr = _T("At least one operand was not entered.");
		listBox_result.AddString(outputCstr);
	}

	else {
		CString resultunsIntcstr;
		unsigned int operand1unsInt, operand2unsInt, resultunsInt;
		operand1unsInt = _tcstoul(operand1cstr,nullptr,10);
		operand2unsInt = _tcstoul(operand2cstr,nullptr,10);
		bool check = true;

		if (shifting) { // checking is there shifting 
			CString shiftingBitscstr;
			editControl3shiftingBits.GetWindowTextW(shiftingBitscstr);

			if (shiftingBitscstr.GetLength() == 0) {
				outputCstr = _T("Specify how many bits you want to shift");
				listBox_result.AddString(outputCstr);
				check = false;
			}

			else {
				CString shiftingWay;
				int shiftingBitsint;
				comboBox1shiftingWay.GetWindowTextW(shiftingWay);
				shiftingBitsint =_ttoi(shiftingBitscstr);

				if (shiftingWay == "Left") {
					operand1unsInt <<= shiftingBitsint;
					operand2unsInt <<= shiftingBitsint;
				}
				else if (shiftingWay == "Right") {
					operand1unsInt >>= shiftingBitsint;
					operand2unsInt >>= shiftingBitsint;
				}
			}
		}

		if (check) {
			CString operationName;
			if (operation == '&') {
				resultunsInt = operand1unsInt & operand2unsInt;
				operationName = _T("AND");
			}
			else if (operation == '|') {
				resultunsInt = operand1unsInt | operand2unsInt;
				operationName = _T("OR");
			}
			else if (operation == '^') {
				resultunsInt = operand1unsInt ^ operand2unsInt;
				operationName = _T("XOR");
			}

			operand1cstr.Format(_T("%u"), operand1unsInt);
			operand2cstr.Format(_T("%u"), operand2unsInt);

			resultunsIntcstr.Format(_T("%u"), resultunsInt);
			outputCstr = operand1cstr + _T(" ") + operationName + _T(" ") + operand2cstr + _T(" = ") + resultunsIntcstr;
			listBox_result.AddString(outputCstr);
		}
	}

	cz = pDC->GetTextExtent(outputCstr);
	if(cz.cx > maxSize) {
		maxSize = cz.cx;
	}

	listBox_result.SetHorizontalExtent(maxSize);
}