#pragma once
#include "Source.h";

// CMaterial dialog

class CMaterial : public CDialogEx
{
	DECLARE_DYNAMIC(CMaterial)

public:
	CMaterial(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMaterial();
	virtual BOOL OnInitDialog();
	bool isEmpty;
	void SetMaterial(Material* material);

// Dialog Data
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	UINT m_number;
	UINT m_price;
	afx_msg void OnBnClickedOk();
private:
	Material* m_material;
	bool Modified = false;
};
