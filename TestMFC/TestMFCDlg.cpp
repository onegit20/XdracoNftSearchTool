
// TestMFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"
#include "afxdialogex.h"

#include <iostream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCDlg 对话框



CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH, m_search);
	DDX_Control(pDX, IDC_RESET, m_reset);
	DDX_Control(pDX, IDC_CANCEL, m_cancel);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_CHARACTERCLASS, m_characterclass);
	DDX_Control(pDX, IDC_CONSITUTION, m_consitution);
	DDX_Control(pDX, IDC_GOPTIONS, m_goptions);
	DDX_Control(pDX, IDC_LEGENDARY, m_legendary);
	DDX_Control(pDX, IDC_LEVEL1, m_level1);
	DDX_Control(pDX, IDC_LEVEL2, m_level2);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_POWER1, m_power1);
	DDX_Control(pDX, IDC_POWER2, m_power2);
	DDX_Control(pDX, IDC_PRICE1, m_price1);
	DDX_Control(pDX, IDC_PRICE2, m_price2);
	DDX_Control(pDX, IDC_SCAT, m_scat);
	DDX_Control(pDX, IDC_SCHARACTERCLASS, m_scharacterclass);
	DDX_Control(pDX, IDC_SCONSITUTION, m_sconsitution);
	DDX_Control(pDX, IDC_SLEGENDARY, m_slegendary);
	DDX_Control(pDX, IDC_SLEVEL, m_slevel);
	DDX_Control(pDX, IDC_SLEVELTO, m_slevelto);
	DDX_Control(pDX, IDC_SPOWER, m_spower);
	DDX_Control(pDX, IDC_SPOWERTO, m_spowerto);
	DDX_Control(pDX, IDC_SPRICE, m_sprice);
	DDX_Control(pDX, IDC_SPRICETO, m_spriceto);
	DDX_Control(pDX, IDC_CATNO, m_catno);
	DDX_Control(pDX, IDC_CATYES, m_catyes);
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CATNO, &CTestMFCDlg::OnClickedCatno)
	ON_BN_CLICKED(IDC_CATYES, &CTestMFCDlg::OnClickedCatyes)
	ON_BN_CLICKED(IDC_SEARCH, &CTestMFCDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_RESET, &CTestMFCDlg::OnBnClickedReset)
END_MESSAGE_MAP()


// CTestMFCDlg 消息处理程序

BOOL CTestMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//SetWindowTextW(L"查找工具  0.1");

	//初始化对话框大小
	CRect myrect(0, 0, 800, 600);
	CWnd::SetWindowPos(NULL, 0, 0, myrect.Width(), myrect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	//初始化控件
	GetClientRect(&myrect);
	int width = myrect.right - myrect.left;
	int height = myrect.bottom - myrect.top;

	m_goptions.MoveWindow(10, 10, width-10-30-90-10, 180);
	m_search.MoveWindow(width-100, 25, 90, 30);
	m_reset.MoveWindow(width-100, 80, 90, 30);
	m_cancel.MoveWindow(width-100, 135,90, 30);

	m_scharacterclass.MoveWindow(40, 40, 30, 24);
	m_characterclass.MoveWindow(90, 36, 80, 120);
	m_characterclass.AddString(L"不限");
	m_characterclass.AddString(L"战士");
	m_characterclass.AddString(L"法师");
	m_characterclass.AddString(L"道士");
	m_characterclass.AddString(L"武士");
	m_characterclass.AddString(L"弩手");
	m_characterclass.SetCurSel(0);

	m_slevel.MoveWindow(40, 80, 30, 24);
	m_level1.MoveWindow(90, 76, 80,24);
	m_slevelto.MoveWindow(180, 80, 20, 24);
	m_level2.MoveWindow(200, 76, 80, 24);

	m_spower.MoveWindow(40, 120, 30, 24);
	m_power1.MoveWindow(90, 116, 80, 24);
	m_spowerto.MoveWindow(180, 120, 20, 24);
	m_power2.MoveWindow(200, 116, 80, 24);

	m_sprice.MoveWindow(40, 160, 30, 24);
	m_price1.MoveWindow(90, 156, 80, 24);
	m_spriceto.MoveWindow(180, 160, 20, 24);
	m_price2.MoveWindow(200, 156, 80, 24);

	m_sconsitution.MoveWindow(370,40,90,24);
	m_consitution.MoveWindow(470, 36, 80, 24);

	m_slegendary.MoveWindow(370, 80, 90, 24);
	m_legendary.MoveWindow(470, 76, 80, 24);

	m_scat.MoveWindow(370, 120, 90, 24);
	m_catyes.MoveWindow(470, 116, 30, 24);
	m_catno.MoveWindow(520, 116, 30, 24);
	m_catno.SetCheck(TRUE);
	
	m_list.MoveWindow(10, 195, width-20, height-210);
	m_progress.MoveWindow(0, height-15, width, 15);

	m_list.ModifyStyle(LVS_ICON | LVS_LIST | LVS_SMALLICON, LVS_REPORT);
	m_list.InsertColumn(0, L"序号", LVCFMT_LEFT, 60);
	m_list.InsertColumn(1, L"职业", LVCFMT_LEFT, 60);
	m_list.InsertColumn(2, L"等级", LVCFMT_LEFT, 60);
	m_list.InsertColumn(3, L"战力", LVCFMT_LEFT, 80);
	m_list.InsertColumn(4, L"价格(w币)", LVCFMT_LEFT, 80);
	m_list.InsertColumn(5, L"红宠数", LVCFMT_LEFT, 60);
	m_list.InsertColumn(6, L"金宠数", LVCFMT_LEFT, 60);
	m_list.InsertColumn(7, L"体质", LVCFMT_LEFT, 60);
	m_list.InsertColumn(8, L"购买链接", LVCFMT_LEFT, width - 20 - 520);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES);  //经纬线

	m_list.InsertItem(0,L"1", 0);
	m_list.SetItemText(0,1, L"战士");
	m_list.SetItemText(0,2, L"90");
	m_list.SetItemText(0,3, L"154876");

	std::string str = "法师";
	CString cstr;
	cstr = str.c_str();
	
	m_list.InsertItem(1, L"2", 0);
	m_list.SetItemText(1, 1, cstr);
	m_list.SetItemText(1, 2, L"105");
	m_list.SetItemText(1, 3, L"184659");

	//GetDlgItem(IDC_SEARCH)->SetFocus();  //用TAB顺序设置也行
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMFCDlg::OnClickedCatno()
{
	// TODO: 在此添加控件通知处理程序代码
	m_catno.SetCheck(TRUE);
	m_catyes.SetCheck(FALSE);
}


void CTestMFCDlg::OnClickedCatyes()
{
	// TODO: 在此添加控件通知处理程序代码
	m_catyes.SetCheck(TRUE);
	m_catno.SetCheck(FALSE);
}


void CTestMFCDlg::OnBnClickedSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str_level1, str_level2;
	CString str_power1, str_power2;
	CString str_price1, str_price2;
	CString str_consitution;
	CString str_legendary;

	m_level1.GetWindowTextW(str_level1);
	m_level2.GetWindowTextW(str_level2);
	m_power1.GetWindowTextW(str_power1);
	m_power2.GetWindowTextW(str_power2);
	m_price1.GetWindowTextW(str_price1);
	m_price2.GetWindowTextW(str_price2);
	m_consitution.GetWindowTextW(str_consitution);
	m_legendary.GetWindowTextW(str_legendary);

	int characterClass = m_characterclass.GetCurSel();
	int minLevel = _ttoi(str_level1);
	int maxLevel = _ttoi(str_level2);
	int minPower = _ttoi(str_power1);
	int maxPower = _ttoi(str_power2);
	int minPrice = _ttoi(str_price1);
	int maxPrice = _ttoi(str_price2);
	int consitutionLevel = _ttoi(str_consitution);
	int legendaryCount = _ttoi(str_legendary);
	int haveCat = m_catyes.GetCheck();
	
	m_progress.SetRange(0, 100);
	m_progress.SetPos(50);
}


void CTestMFCDlg::OnBnClickedReset()
{
	// TODO: 在此添加控件通知处理程序代码

	m_characterclass.SetCurSel(0);
	m_level1.SetSel(0, -1);
	m_level1.Clear();
	m_level2.SetSel(0, -1);
	m_level2.Clear();
	m_power1.SetSel(0, -1);
	m_power1.Clear();
	m_power2.SetSel(0, -1);
	m_power2.Clear();
	m_price1.SetSel(0, -1);
	m_price1.Clear();
	m_price2.SetSel(0, -1);
	m_price2.Clear();
	m_consitution.SetSel(0, -1);
	m_consitution.Clear();
	m_legendary.SetSel(0, -1);
	m_legendary.Clear();
	m_catno.SetCheck(TRUE);
	m_catyes.SetCheck(FALSE);
}
