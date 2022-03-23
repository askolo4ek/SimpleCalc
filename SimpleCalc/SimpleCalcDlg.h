
// SimpleCalcDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CSimpleCalcDlg
class CSimpleCalcDlg : public CDialogEx
{
// Создание
public:
	CSimpleCalcDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMPLECALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void ActionMUL();
	afx_msg void ActionDIV();
	afx_msg void ActionSUM();
	afx_msg void ActionMIN();
	afx_msg void ActionCALC();
	CEdit EditBox;
	CString ValueBuff;
	double value1;
	double value2;
	double result;
	afx_msg void ClearLast();
	afx_msg void ClearALL();
	afx_msg void OneDivideValue();
	afx_msg void Sqrt();
	afx_msg void OnBnClickedButton21();
};
