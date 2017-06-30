#pragma once

#include "Source.h";
// CEmployee dialog

class CEmployee : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployee)

public:
	CEmployee(CWnd* pParent = NULL);   // standard constructor
	virtual ~CEmployee();
	virtual BOOL OnInitDialog();
	void SetEmployee(Employee* employee);
	bool isEmpty;
// Dialog Data
	enum { IDD = IDD_EmployeeDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	UINT m_salary;
	afx_msg void OnBnClickedOk();
private:
	Employee* m_employee;
	bool Modified = false;
	
};
