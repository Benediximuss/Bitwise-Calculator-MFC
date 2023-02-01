
// Bitwise_CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CBitwise_CalculatorDlg dialog
class CBitwise_CalculatorDlg : public CDialogEx
{
// Construction
public:
	CBitwise_CalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BITWISE_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int radioButton1Operation;
	CButton checkBox1toggleShift;
	CComboBox comboBox1shiftingWay;
	CEdit editControl3shiftingBits;
	afx_msg void OnBnClickedCheck1();
	CEdit editControl1_operand1;
	CEdit editControl2_operand2;
	CListBox listBox_result;
	CButton button_Compute;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
};
