// About.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "About.h"
#include "afxdialogex.h"


// CAbout dialog

IMPLEMENT_DYNAMIC(CAbout, CDialogEx)

CAbout::CAbout(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAbout::IDD, pParent)
{

}

CAbout::~CAbout()
{
}

void CAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAbout, CDialogEx)
END_MESSAGE_MAP()


// CAbout message handlers
