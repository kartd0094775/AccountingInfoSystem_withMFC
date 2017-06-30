
// AccountingInfoSystem_withMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "AccountingInfoSystem_withMFCDlg.h"
#include "resource.h"
#include "afxdialogex.h"
#include "afxwin.h"

using namespace::std;

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
public:
	CButton m_name_label;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_name_label);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAccountingInfoSystem_withMFCDlg dialog



CAccountingInfoSystem_withMFCDlg::CAccountingInfoSystem_withMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAccountingInfoSystem_withMFCDlg::IDD, pParent)
	, m_name(_T(""))
	, m_assets(0)
	, m_liabilities(0)
	, m_revenue(0)
	, m_expenses(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	selected = 0;
	m_company = new Company[MAX_COMPANY_NUMBER];
	m_company_number = 0;
}

void CAccountingInfoSystem_withMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT2, m_liabilities);
	DDX_Text(pDX, IDC_EDIT4, m_revenue);
	DDX_Text(pDX, IDC_EDIT5, m_expenses);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_assets);
	DDX_Control(pDX, IDC_LIST3, m_EmployeeList);
	DDX_Control(pDX, IDC_LIST2, m_MaterialList);
	DDX_Control(pDX, IDC_LIST1, m_ProductList);
	DDX_Control(pDX, IDC_COMBO1, m_NameComboBox);
}


BEGIN_MESSAGE_MAP(CAccountingInfoSystem_withMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton5)
	ON_COMMAND(ID_FILE_OPEN, &CAccountingInfoSystem_withMFCDlg::OnFileOpen)

	ON_CBN_SELENDOK(IDC_COMBO1, &CAccountingInfoSystem_withMFCDlg::OnCbnSelendokCombo1)
	ON_COMMAND(ID_HELP_ABOUT, &CAccountingInfoSystem_withMFCDlg::OnHelpAbout)
	ON_BN_CLICKED(IDC_BUTTON7, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton12)

	ON_BN_CLICKED(IDC_BUTTON6, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON16, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton16)
	ON_COMMAND(ID_FILE_SAVE, &CAccountingInfoSystem_withMFCDlg::OnFileSave)
	ON_BN_CLICKED(IDC_BUTTON13, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CAccountingInfoSystem_withMFCDlg::OnBnClickedButton15)
END_MESSAGE_MAP()


// CAccountingInfoSystem_withMFCDlg message handlers

BOOL CAccountingInfoSystem_withMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// Add "About..." menu item to system menu.
	

	// initial List Control

	m_EmployeeList.InsertColumn(0, _T("Employee"), LVCFMT_LEFT, 60);
	m_EmployeeList.InsertColumn(1, _T("Salary"), LVCFMT_LEFT, 60);
	m_EmployeeList.InsertColumn(2, _T("Record Date"), LVCFMT_LEFT, 90);

	m_MaterialList.InsertColumn(0, _T("Material"), LVCFMT_LEFT, 60);
	m_MaterialList.InsertColumn(1, _T("Number"), LVCFMT_LEFT, 60);
	m_MaterialList.InsertColumn(2, _T("Price"), LVCFMT_LEFT, 60);
	m_MaterialList.InsertColumn(3, _T("Record Date"), LVCFMT_LEFT, 90);

	m_ProductList.InsertColumn(0, _T("Product"), LVCFMT_LEFT, 60);
	m_ProductList.InsertColumn(1, _T("Number"), LVCFMT_LEFT, 60);
	m_ProductList.InsertColumn(2, _T("Price"), LVCFMT_LEFT, 60);
	m_ProductList.InsertColumn(3, _T("Record Date"), LVCFMT_LEFT, 90);


	// setting style
	DWORD dwStyle;
	dwStyle = m_EmployeeList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_EmployeeList.SetExtendedStyle(dwStyle);
	m_MaterialList.SetExtendedStyle(dwStyle);
	m_ProductList.SetExtendedStyle(dwStyle);

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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAccountingInfoSystem_withMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAccountingInfoSystem_withMFCDlg::OnPaint()
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
HCURSOR CAccountingInfoSystem_withMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// Dialog: Create 
void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton1()
{
	m_CreateDlg = new CCreateDlg();
	m_CreateDlg->DoModal();
	if (!m_CreateDlg->isEmpty) {

		char* tmpname = new char[m_name.GetLength() + 1];
		sprintf_s(tmpname, m_CreateDlg->m_name.GetLength() + 1, "%S", m_CreateDlg->m_name);
		Company* company = (m_company + m_company_number);
		company->set_name(tmpname);
		company->set_assets(m_CreateDlg->m_assets);
		company->set_liabilities(m_CreateDlg->m_liabilities);


		m_NameComboBox.InsertString(m_company_number, m_CreateDlg->m_name);
		m_NameComboBox.SetCurSel(m_company_number);
		selected = m_company_number++;
		display_company();
		//delete company;
	}
	// TODO: Add your control notification handler code here
}

//  Dialog: Add Employee 
void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton3()
{
	m_EmployeeDlg = new CEmployee();
	m_EmployeeDlg->DoModal();
	if (!m_EmployeeDlg->isEmpty) {
		char* tmpname = new char[m_EmployeeDlg->m_name.GetLength() + 1];
		sprintf_s(tmpname, m_EmployeeDlg->m_name.GetLength() + 1, "%S", m_EmployeeDlg->m_name);
		CString salary;
		salary.Format(_T("%u"), m_EmployeeDlg->m_salary);
		// set 
		(m_company + selected)->set_employees(tmpname, m_EmployeeDlg->m_salary);

		int nindex = m_EmployeeList.InsertItem(0, m_EmployeeDlg->m_name);
		m_EmployeeList.SetItemText(nindex, 1, salary);
		m_EmployeeList.SetItemText(nindex, 2, (CString)(m_company + selected)->get_Date("Employee"));
		m_expenses += m_EmployeeDlg->m_salary;
		UpdateData(false);

		//delete[] tmpname;
	}
	
	// TODO: Add your control notification handler code here
}

// Dialog: Add Material
void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton4()
{
	m_Material = new CMaterial();
	m_Material->DoModal();
	if (!m_Material->isEmpty) {
		char* tmpname = new char[m_Material->m_name.GetLength() + 1];
		sprintf_s(tmpname, m_Material->m_name.GetLength() + 1, "%S", m_Material->m_name);
		CString number;
		number.Format(_T("%u"), m_Material->m_number);
		CString price;
		price.Format(_T("%u"), m_Material->m_price);

		//set
		(m_company + selected)->set_materials(tmpname, m_Material->m_number, m_Material->m_price);

		int nindex = m_MaterialList.InsertItem(0, m_Material->m_name);
		m_MaterialList.SetItemText(nindex, 1, number);
		m_MaterialList.SetItemText(nindex, 2, price);
		m_MaterialList.SetItemText(nindex, 3, (CString)(m_company + selected)->get_Date("Material"));
		m_expenses += m_Material->m_price * m_Material->m_number;
		UpdateData(false);
		//delete[] tmpname;
	}
	// TODO: Add your control notification handler code here
}

// Dialog: Add Product
void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton5()
{
	m_Product = new CProduct();
	m_Product->SetCompany(m_company + selected);
	m_Product->DoModal();
	if (!m_Product->isEmpty) {
		// setting list control
		CString number;
		number.Format(_T("%u"), m_Product->m_number);
		CString price;
		price.Format(_T("%u"), m_Product->m_price);
		int nindex = m_ProductList.InsertItem(0, m_Product->m_name);
		m_ProductList.SetItemText(nindex, 1, number);
		m_ProductList.SetItemText(nindex, 2, price);
		m_ProductList.SetItemText(nindex, 3, (CString)(m_company + selected)->get_Date("Product"));

		m_revenue += m_Product->m_price * m_Product->m_number;
		UpdateData(false);
	}
	// TODO: Add your control notification handler code here
}
// Dialog: Order, to purchase product
void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton6()
{
	m_Order = new COrder();
	m_Order->SetCompany(m_company + selected);
	m_Order->DoModal();
	// TODO: Add your control notification handler code here
}

void CAccountingInfoSystem_withMFCDlg::OnFileOpen()
{
	CString szFilter = _T("text|*.txt|All|*.*||");
	CFileDialog FileDialog(TRUE, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY, szFilter, this);
	if (FileDialog.DoModal() == IDOK) {
		m_NameComboBox.ResetContent();
		CString szFileName = FileDialog.GetPathName();
		char* filename = new char[szFileName.GetLength() + 1];
		sprintf_s(filename, szFileName.GetLength() + 1, "%S", szFileName);
		readFile(filename);
		// setting combo box 
		for (int i = 0; i < m_company_number; i++) {
			m_NameComboBox.InsertString(i, (CString)(m_company + i)->get_name());
		}
		m_NameComboBox.SetCurSel(0);
		display_company();
	}
	// TODO: Add your command handler code here
}
// readfile Function
void CAccountingInfoSystem_withMFCDlg::readFile(char* filename) {
	FILE *ifp;
	char* readline = new char[READLINE_LENGTH]{0};
	fopen_s(&ifp, filename, "r");
	if (ifp == nullptr) {
		TRACE("File Not Found");
		return;
	}
	else {
		m_company_number = 0;
		m_company = new Company[MAX_COMPANY_NUMBER]();
		while (!feof(ifp)) {
			fscanf_s(ifp, "%s", readline, READLINE_LENGTH);
			if (!strcmp(readline, "Company:")) {
				(m_company + m_company_number++)->readFile(ifp, readline);
			}
		}
	}
	fclose(ifp);
}




void CAccountingInfoSystem_withMFCDlg::OnCbnSelendokCombo1()
{
	selected = m_NameComboBox.GetCurSel();
	display_company();
	// TODO: Add your control notification handler code here
}

// display the selected comapny
void CAccountingInfoSystem_withMFCDlg::display_company() {
	// The INFO of the selected company
	m_name = (m_company + selected)->get_name();
	m_assets = *(m_company + selected)->get_assets();
	m_liabilities = *(m_company + selected)->get_liabilities();
	m_revenue = 0;
	m_expenses = 0;
	m_EmployeeList.DeleteAllItems();
	m_MaterialList.DeleteAllItems();
	m_ProductList.DeleteAllItems();
	UpdateData(false);
	Employee* employee;
	Product* product;
	Material* material;


	// setting the employee list control
	for (int i = 0; i < (m_company + selected)->get_employee_number(); i++) {
		employee = (m_company + selected)->get_employee(i);
		CString salary;
		salary.Format(_T("%u"), *employee->get_salary());
		int nindex = m_EmployeeList.InsertItem(0, (CString)employee->get_name());
		m_EmployeeList.SetItemText(nindex, 1, salary);
		m_EmployeeList.SetItemText(nindex, 2, (CString)employee->get_date());
		m_expenses += *employee->get_salary();
		//delete employee;
	}
	// setting the material list control
	for (int i = 0; i < (m_company + selected)->get_material_type_number(); i++) {
		material = (m_company + selected)->get_material(i);
		CString number;
		number.Format(_T("%u"), *material->get_number());
		CString price;
		price.Format(_T("%u"), *material->get_price());

		int nindex = m_MaterialList.InsertItem(0, (CString)material->get_name());
		m_MaterialList.SetItemText(nindex, 1, number);
		m_MaterialList.SetItemText(nindex, 2, price);
		m_MaterialList.SetItemText(nindex, 3, (CString)material->get_date());
		m_expenses += *material->get_number() * *material->get_price();
		//delete material;
	}
	for (int i = 0; i < (m_company + selected)->get_product_type_number(); i++) {
		product = (m_company + selected)->get_product(i);
		CString number;
		number.Format(_T("%u"), *product->get_number());
		CString price;
		price.Format(_T("%u"), *product->get_price());

		int nindex = m_ProductList.InsertItem(0, (CString)product->get_name());
		m_ProductList.SetItemText(nindex, 1, number);
		m_ProductList.SetItemText(nindex, 2, price);
		m_ProductList.SetItemText(nindex, 3, (CString)product->get_date());
		m_revenue += *product->get_number() * *product->get_price();
		//delete product;
	}
	UpdateData(false);
}

void CAccountingInfoSystem_withMFCDlg::OnHelpAbout()
{
	m_About = new CAbout();
	m_About->DoModal();
	// TODO: Add your command handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton7()
{	
	m_GeneralLedger_Function = new CGeneralLedger();
	m_GeneralLedger_Function->SetCompany(m_company, m_company_number);
	m_GeneralLedger_Function->DoModal();

	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton8()
{
	m_Bill_Function = new CBill();
	m_Bill_Function->SetCompany(m_company, m_company_number);
	m_Bill_Function->DoModal();
	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton9()
{
	m_Inventory_Function = new CProduct_F();
	m_Inventory_Function->SetProduct(m_company, m_company_number);
	m_Inventory_Function->DoModal();
	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton10()
{
	m_Order_Function = new COrder_F();
	m_Order_Function->SetOrder(m_company, m_company_number);
	m_Order_Function->DoModal();
	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton11()
{
	m_Customer_Function = new CCustomer();
	m_Customer_Function->SetCompany(m_company, m_company_number);
	m_Customer_Function->DoModal();
	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton12()
{
	m_Employee_Function = new CEmployeeF();
	m_Employee_Function->SetCompany(m_company, m_company_number);
	m_Employee_Function->DoModal();
	// TODO: Add your control notification handler code here
}


// Apply Button
void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton16()
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnFileSave()
{
	CString szFilter = _T("text|*.txt|All|*.*||");
	CFileDialog FileDialog(FALSE, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY, szFilter, this);
	if (FileDialog.DoModal() == IDOK) {
		CString szFileName = FileDialog.GetPathName();
		char* filename = new char[szFileName.GetLength() + 1];
		sprintf_s(filename, szFileName.GetLength() + 1, "%S", szFileName);
		FILE* m_ofp;
		fopen_s(&m_ofp, filename, "w");
		for (int i = 0; i < m_company_number; i++) {
			(m_company + i)->printFile(m_ofp);
		}
		fclose(m_ofp);
		//delete m_ofp;
		//delete[] filename;
	}
	// TODO: Add your command handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton13()
{
	int index = m_EmployeeList.GetSelectionMark();
	int employee_number = (m_company + selected)->get_employee_number();
	Employee* employee = (m_company + selected)->get_employee(employee_number - 1 - index);
	m_EmployeeDlg = new CEmployee();
	m_EmployeeDlg->SetEmployee(employee);
	m_EmployeeDlg->DoModal();
	if (!m_EmployeeDlg->isEmpty) {
		m_expenses -= *employee->get_salary();
		char* tmpname = new char[m_EmployeeDlg->m_name.GetLength() + 1];
		sprintf_s(tmpname, m_EmployeeDlg->m_name.GetLength() + 1, "%S", m_EmployeeDlg->m_name);
		CString salary;
		salary.Format(_T("%u"), m_EmployeeDlg->m_salary);
		employee->set_name(tmpname);
		employee->set_salary(m_EmployeeDlg->m_salary);

		m_EmployeeList.SetItemText(index, 0, m_EmployeeDlg->m_name);
		m_EmployeeList.SetItemText(index, 1, salary);
		m_EmployeeList.SetItemText(index, 2, (CString)(m_company + selected)->get_Date("Emloyee"));
		m_expenses += *employee->get_salary();

		//delete[] tmpname;
	}
	//delete employee;
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton14()
{
	int index = m_MaterialList.GetSelectionMark();
	int material_number = (m_company + selected)->get_material_type_number();
	Material* material = (m_company + selected)->get_material(material_number - 1 - index);
	m_Material = new CMaterial();
	m_Material->SetMaterial(material);
	m_Material->DoModal();
	if (!m_Material->isEmpty) {
		m_expenses -= *material->get_number() * *material->get_price();
		char* tmpname = new char[m_Material->m_name.GetLength() + 1];
		sprintf_s(tmpname, m_Material->m_name.GetLength() + 1, "%S", m_Material->m_name);
		CString number;
		number.Format(_T("%u"), m_Material->m_number);
		CString price;
		price.Format(_T("%u"), m_Material->m_price);
		//set
		material->set_material(tmpname, m_Material->m_number, m_Material->m_price);


		m_MaterialList.SetItemText(index ,0, m_Material->m_name);
		m_MaterialList.SetItemText(index, 1, number);
		m_MaterialList.SetItemText(index, 2, price);
		m_MaterialList.SetItemText(index, 3, (CString)(m_company + selected)->get_Date("Material"));
		m_expenses += *material->get_number() * *material->get_price();
		UpdateData(false);
	}
	// TODO: Add your control notification handler code here
}


void CAccountingInfoSystem_withMFCDlg::OnBnClickedButton15()
{
	int index = m_ProductList.GetSelectionMark();
	int product_number = (m_company + selected)->get_product_type_number();
	Product* product = (m_company + selected)->get_product(product_number - 1 - index);
	m_Product = new CProduct();
	m_Product->SetCompany(m_company + selected);
	m_Product->SetProduct(product);
	m_Product->DoModal();
	m_revenue -= *product->get_number() * *product->get_price();
	if (!m_Product->isEmpty) {
		CString number;
		number.Format(_T("%u"), m_Product->m_number);
		CString price;
		price.Format(_T("%u"), m_Product->m_price);
		m_ProductList.SetItemText(index, 0, m_Product->m_name);
		m_ProductList.SetItemText(index, 1, number);
		m_ProductList.SetItemText(index, 2, price);
		m_ProductList.SetItemText(index, 3, (CString)(m_company + selected)->get_Date("Product"));
	}
	m_revenue -= *product->get_number() * *product->get_price();
	UpdateData(false);
}