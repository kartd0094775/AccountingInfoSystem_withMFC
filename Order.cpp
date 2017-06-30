// Order.cpp : implementation file
//

#include "stdafx.h"
#include "AccountingInfoSystem_withMFC.h"
#include "Order.h"
#include "afxdialogex.h"


// COrder dialog

IMPLEMENT_DYNAMIC(COrder, CDialogEx)

COrder::COrder(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrder::IDD, pParent)
	, m_customer(_T(""))
	, m_address(_T(""))
	, m_number(0)
{
	isEmpty = true;
}

COrder::~COrder()
{
}
BOOL COrder::OnInitDialog() {
	BOOL ret = __super::OnInitDialog();
	m_ProductList.InsertColumn(0, _T("Product"), LVCFMT_FILL, 60);
	m_ProductList.InsertColumn(1, _T("Price"), LVCFMT_LEFT, 60);
	m_OrderList.InsertColumn(0, _T("Product"), LVCFMT_LEFT, 45);
	m_OrderList.InsertColumn(1, _T("Number"), LVCFMT_LEFT, 45);
	m_OrderList.InsertColumn(2, _T("Price"), LVCFMT_LEFT, 45);
	DWORD dwStyle;
	dwStyle = m_ProductList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_ProductList.SetExtendedStyle(dwStyle);
	m_OrderList.SetExtendedStyle(dwStyle);

	Product* product;
	CString number;
	for (int i = 0; i < m_company->get_product_type_number(); i++) {
		product = m_company->get_product(i);
		number.Format(_T("%u"), *product->get_number());
		int nindex = m_ProductList.InsertItem(0, (CString)product->get_name());
		m_ProductList.SetItemText(nindex, 1, number);
	}
	return ret;
}

void COrder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_customer);
	DDX_Text(pDX, IDC_EDIT2, m_address);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_DateCtrl);
	DDX_Text(pDX, IDC_EDIT4, m_number);
	DDX_Control(pDX, IDC_LIST1, m_OrderList);
	DDX_Control(pDX, IDC_LIST4, m_ProductList);
}


BEGIN_MESSAGE_MAP(COrder, CDialogEx)
	ON_BN_CLICKED(IDOK, &COrder::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &COrder::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK2, &COrder::OnBnClickedOk2)
END_MESSAGE_MAP()


// COrder message handlers


void COrder::OnBnClickedOk()
{
	UpdateData(true);
	if (m_customer != _T("")) { 
		CTime time;
		m_DateCtrl.GetTime(time);
		m_date = time.Format(("%Y/%m/%d"));
		char* customer = new char[NAME_SIZE];
		sprintf_s(customer, m_customer.GetLength() + 1, "%S", m_customer);
		char* address = new char[NAME_SIZE];
		sprintf_s(address, m_address.GetLength() + 1, "%S", m_address);
		char* expectedDate = new char[NAME_SIZE];
		sprintf_s(expectedDate, m_date.GetLength() + 1, "%S", m_date);

		int ret_product_number = m_OrderList.GetItemCount();
		char** ret_product = new char*[MAX_MATERIAL_SIZE];
		int* ret_product_amount = new int[MAX_MATERIAL_SIZE];
		for (int i = 0; i < MAX_MATERIAL_SIZE; i++) {
			*(ret_product + i) = new char[NAME_SIZE]{0};
		}
		for (int i = 0; i < ret_product_number; i++) {
			CString tmp_product = m_OrderList.GetItemText(i, 0);
			CString number = m_OrderList.GetItemText(i, 1);
			sprintf_s(ret_product[i], tmp_product.GetLength() + 1, "%S", tmp_product);
			ret_product_amount[i] = _ttoi(number);
		}
		m_company->set_orders(
			customer,
			address,
			expectedDate,
			ret_product,
			ret_product_amount,
			ret_product_number
			);
		isEmpty = false; }
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
void COrder::SetCompany(Company* company) {
	m_company = company;
}
void COrder::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int index = m_ProductList.GetSelectionMark();
	CString product = m_ProductList.GetItemText(index, 0);
	CString number;
	number.Format(_T("%u"), m_number);
	CString price = m_ProductList.GetItemText(index, 1);
	int nindex = m_OrderList.InsertItem(0, product);
	m_OrderList.SetItemText(nindex, 1, number);
	m_OrderList.SetItemText(nindex, 2, price);
}


void COrder::OnBnClickedOk2()
{
	int index = m_OrderList.GetSelectionMark();
	m_OrderList.DeleteItem(index);
	// TODO: Add your control notification handler code here
	
}
