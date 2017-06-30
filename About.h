#pragma once


// CAbout dialog

class CAbout : public CDialogEx
{
	DECLARE_DYNAMIC(CAbout)

public:
	CAbout(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAbout();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
