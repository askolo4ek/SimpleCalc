
// SimpleCalc.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSimpleCalcApp:
// Сведения о реализации этого класса: SimpleCalc.cpp
//

class CSimpleCalcApp : public CWinApp
{
public:
	CSimpleCalcApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSimpleCalcApp theApp;
