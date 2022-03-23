
// SimpleCalcDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "SimpleCalc.h"
#include "SimpleCalcDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL PointFlag(FALSE);
int ActionFlag(0);
// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CSimpleCalcDlg



CSimpleCalcDlg::CSimpleCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIMPLECALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EditBox);
}

BEGIN_MESSAGE_MAP(CSimpleCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSimpleCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSimpleCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSimpleCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSimpleCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSimpleCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSimpleCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CSimpleCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSimpleCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CSimpleCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CSimpleCalcDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CSimpleCalcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CSimpleCalcDlg::ActionMUL)
	ON_BN_CLICKED(IDC_BUTTON13, &CSimpleCalcDlg::ActionDIV)
	ON_BN_CLICKED(IDC_BUTTON14, &CSimpleCalcDlg::ActionSUM)
	ON_BN_CLICKED(IDC_BUTTON15, &CSimpleCalcDlg::ActionMIN)
	ON_BN_CLICKED(IDC_BUTTON16, &CSimpleCalcDlg::ActionCALC)
	ON_BN_CLICKED(IDC_BUTTON17, &CSimpleCalcDlg::ClearLast)
	ON_BN_CLICKED(IDC_BUTTON18, &CSimpleCalcDlg::ClearALL)
	ON_BN_CLICKED(IDC_BUTTON19, &CSimpleCalcDlg::OneDivideValue)
	ON_BN_CLICKED(IDC_BUTTON20, &CSimpleCalcDlg::Sqrt)
	ON_BN_CLICKED(IDC_BUTTON21, &CSimpleCalcDlg::OnBnClickedButton21)
END_MESSAGE_MAP()


// Обработчики сообщений CSimpleCalcDlg

BOOL CSimpleCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CSimpleCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSimpleCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSimpleCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimpleCalcDlg::OnBnClickedButton1()
{
	if (ValueBuff == '0')
		ValueBuff = '1';
	else
		ValueBuff.Append(L"1");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton2()
{
	if (ValueBuff == '0')
		ValueBuff = '2';
	else
		ValueBuff.Append(L"2");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton3()
{
	if (ValueBuff == '0')
		ValueBuff = '3';
	else
		ValueBuff.Append(L"3");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton4()
{
	if (ValueBuff == '0')
		ValueBuff = '4';
	else
		ValueBuff.Append(L"4");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton5()
{
	if (ValueBuff == '0')
		ValueBuff = '5';
	else
		ValueBuff.Append(L"5");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton6()
{
	if (ValueBuff == '0')
		ValueBuff = '6';
	else
	ValueBuff.Append(L"6");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton7()
{
	if (ValueBuff == '0')
		ValueBuff = '7';
	else
	ValueBuff.Append(L"7");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton8()
{
	if (ValueBuff == '0')
		ValueBuff = '8';
	else
	ValueBuff.Append(L"8");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton9()
{
	if (ValueBuff == '0')
		ValueBuff = '9';
	else
	ValueBuff.Append(L"9");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton10()
{
	if (ValueBuff != '0')
	{
		ValueBuff.Append(L"0");
		EditBox.SetWindowTextW(ValueBuff);
	}
}


void CSimpleCalcDlg::OnBnClickedButton11()
{
	ValueBuff.Append(L".");
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ActionMUL()
{
	value1 = _wtof(ValueBuff);
	ValueBuff = L"0";
	ActionFlag = 1;
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ActionDIV()
{
	value1 = _wtof(ValueBuff);
	ValueBuff = L"0";
	ActionFlag = 2;
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ActionSUM()
{
	value1 = _wtof(ValueBuff);
	ValueBuff = L"0";
	ActionFlag = 3;
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ActionMIN()
{
	value1 = _wtof(ValueBuff);
	ValueBuff = L"0";
	ActionFlag = 4;
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ActionCALC()
{
	value2 = _wtof(ValueBuff);
	switch (ActionFlag)
	{
		case 1:
			value1 = value1 * value2;
			break;
		case 2:
			if (value2 == 0) MessageBox(L"Ошибка!");
			value1 = value1 / value2;
			break;
		case 3:
			value1 = value1 + value2;
			break;
		case 4:
			value1 = value1 - value2;
			break;
		case 5:
			if (value1 == 0) MessageBox(L"Ошибка!");
			value1 = 1 / value1;
			break;
		case 6:
			if (value1 < 0) MessageBox(L"Ошибка!");
			value1 = sqrt(value1);
			break;
		case 7:
			value1 = 0-value1;
			break;
	}
	ActionFlag = 0;
	ValueBuff.Format(L"%g", value1);
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ClearLast()
{
	ValueBuff = ValueBuff.Left(ValueBuff.GetLength() - 1);
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::ClearALL()
{
	ValueBuff = L"0";
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OneDivideValue()
{
	value1 = _wtof(ValueBuff);
	ActionFlag = 5;
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::Sqrt()
{
	value1 = _wtof(ValueBuff);
	ActionFlag = 6;
	EditBox.SetWindowTextW(ValueBuff);
}


void CSimpleCalcDlg::OnBnClickedButton21()
{
	value1 = _wtof(ValueBuff);
	ActionFlag = 7;
	EditBox.SetWindowTextW(ValueBuff);
}
