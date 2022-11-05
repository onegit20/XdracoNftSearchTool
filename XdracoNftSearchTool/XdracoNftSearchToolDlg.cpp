
// XdracoNftSearchToolDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "XdracoNftSearchTool.h"
#include "XdracoNftSearchToolDlg.h"
#include "afxdialogex.h"

#include "LibcurlHttp.h"
#include "Url.h"
#include "Character.h"
#include "vector"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CXdracoNftSearchToolDlg 对话框



CXdracoNftSearchToolDlg::CXdracoNftSearchToolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_XDRACONFTSEARCHTOOL_DIALOG, pParent)
	, m_bSearching(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXdracoNftSearchToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH, m_search);
	DDX_Control(pDX, IDC_CANCEL, m_cancel);
	DDX_Control(pDX, IDC_CATNO, m_catno);
	DDX_Control(pDX, IDC_CATYES, m_catyes);
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
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_RESET, m_reset);
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
}

BEGIN_MESSAGE_MAP(CXdracoNftSearchToolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH, &CXdracoNftSearchToolDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_RESET, &CXdracoNftSearchToolDlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_CANCEL, &CXdracoNftSearchToolDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CATYES, &CXdracoNftSearchToolDlg::OnClickedCatyes)
	ON_BN_CLICKED(IDC_CATNO, &CXdracoNftSearchToolDlg::OnBnClickedCatno)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CXdracoNftSearchToolDlg::OnDblclkList)
END_MESSAGE_MAP()


// CXdracoNftSearchToolDlg 消息处理程序

BOOL CXdracoNftSearchToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowTextW(L"xdraco.com NFT角色查找工具 v0.4.1");
	CRect myrect(0, 0, 800, 600);
	CWnd::SetWindowPos(NULL, 0, 0, myrect.Width(), myrect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	GetClientRect(&myrect);
	int width = myrect.right - myrect.left;
	int height = myrect.bottom - myrect.top;

	m_goptions.MoveWindow(10, 10, width - 10 - 30 - 90 - 10, 180);
	m_search.MoveWindow(width - 100, 25, 90, 30);
	m_reset.MoveWindow(width - 100, 80, 90, 30);
	m_cancel.MoveWindow(width - 100, 135, 90, 30);

	m_scharacterclass.MoveWindow(40, 40, 30, 24);
	m_characterclass.MoveWindow(90, 36, 80, 120);
	m_characterclass.AddString(L"不限");
	m_characterclass.AddString(L"战士");
	m_characterclass.AddString(L"法师");
	m_characterclass.AddString(L"道士");
	m_characterclass.AddString(L"弩手");
	m_characterclass.AddString(L"武士");
	m_characterclass.SetCurSel(0);

	m_slevel.MoveWindow(40, 80, 30, 24);
	m_level1.MoveWindow(90, 76, 80, 24);
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

	m_sconsitution.MoveWindow(370, 40, 90, 24);
	m_consitution.MoveWindow(485, 36, 80, 24);

	m_slegendary.MoveWindow(370, 80, 105, 24);
	m_legendary.MoveWindow(485, 76, 80, 24);

	m_scat.MoveWindow(370, 120, 90, 24);
	m_catyes.MoveWindow(485, 116, 40, 24);
	m_catno.MoveWindow(545, 116, 40, 24);
	m_catno.SetCheck(TRUE);

	m_list.MoveWindow(10, 195, width - 20, height - 210);
	m_progress.MoveWindow(0, height - 15, width, 15);

	m_list.ModifyStyle(LVS_ICON | LVS_LIST | LVS_SMALLICON, LVS_REPORT);
	m_list.InsertColumn(0, L"序号", LVCFMT_LEFT, 40);
	m_list.InsertColumn(1, L"职业", LVCFMT_LEFT, 40);
	m_list.InsertColumn(2, L"等级", LVCFMT_LEFT, 40);
	m_list.InsertColumn(3, L"战力", LVCFMT_LEFT, 60);
	m_list.InsertColumn(4, L"价格(w币)", LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, L"红宠数", LVCFMT_LEFT, 60);
	m_list.InsertColumn(6, L"金宠数", LVCFMT_LEFT, 60);
	m_list.InsertColumn(7, L"复活猫", LVCFMT_LEFT, 60);
	m_list.InsertColumn(8, L"体质", LVCFMT_LEFT, 40);
	m_list.InsertColumn(9, L"购买链接", LVCFMT_LEFT, width - 20 - 500);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);  //经纬线|选中高亮

	m_cancel.EnableWindow(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CXdracoNftSearchToolDlg::OnPaint()
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
HCURSOR CXdracoNftSearchToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CXdracoNftSearchToolDlg::OnBnClickedSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CWinThread* pThread1 = AfxBeginThread(SearchNft, this);
}


void CXdracoNftSearchToolDlg::OnBnClickedReset()
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


void CXdracoNftSearchToolDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bSearching = FALSE;
}


void CXdracoNftSearchToolDlg::OnClickedCatyes()
{
	// TODO: 在此添加控件通知处理程序代码
	m_catyes.SetCheck(TRUE);
	m_catno.SetCheck(FALSE);
}


void CXdracoNftSearchToolDlg::OnBnClickedCatno()
{
	// TODO: 在此添加控件通知处理程序代码
	m_catno.SetCheck(TRUE);
	m_catyes.SetCheck(FALSE);
}


void CXdracoNftSearchToolDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//以下两种方式都行
	//ShellExecute(NULL, _T("open"), m_list.GetItemText(m_list.GetNextItem(-1, LVNI_SELECTED), 9), NULL, NULL, SW_SHOW);
	ShellExecute(NULL, _T("open"), m_list.GetItemText(pNMItemActivate->iItem, 9), NULL, NULL, SW_SHOW);
	*pResult = 0;
}


UINT __cdecl CXdracoNftSearchToolDlg::SearchNft(LPVOID pParam) {
	CXdracoNftSearchToolDlg* pDlg = (CXdracoNftSearchToolDlg*)pParam;

	pDlg->m_bSearching = TRUE;

	pDlg->m_cancel.EnableWindow(1);
	pDlg->m_reset.EnableWindow(0);
	pDlg->m_list.DeleteAllItems();
	pDlg->m_list.UpdateWindow();
	pDlg->m_search.SetWindowTextW(L"搜索中...");
	pDlg->m_search.EnableWindow(0);

	pDlg->m_characterclass.EnableWindow(0);
	pDlg->m_level1.EnableWindow(0);
	pDlg->m_level2.EnableWindow(0);
	pDlg->m_power1.EnableWindow(0);
	pDlg->m_power2.EnableWindow(0);
	pDlg->m_price1.EnableWindow(0);
	pDlg->m_price2.EnableWindow(0);
	pDlg->m_consitution.EnableWindow(0);
	pDlg->m_legendary.EnableWindow(0);
	pDlg->m_catyes.EnableWindow(0);
	pDlg->m_catno.EnableWindow(0);

	CString str_level1, str_level2;
	CString str_power1, str_power2;
	CString str_price1, str_price2;
	CString str_consitution;
	CString str_legendary;

	pDlg->m_level1.GetWindowTextW(str_level1);
	pDlg->m_level2.GetWindowTextW(str_level2);
	pDlg->m_power1.GetWindowTextW(str_power1);
	pDlg->m_power2.GetWindowTextW(str_power2);
	pDlg->m_price1.GetWindowTextW(str_price1);
	pDlg->m_price2.GetWindowTextW(str_price2);
	pDlg->m_consitution.GetWindowTextW(str_consitution);
	pDlg->m_legendary.GetWindowTextW(str_legendary);

	int characterClass = pDlg->m_characterclass.GetCurSel();
	int minLevel = _ttoi(str_level1);
	int maxLevel = _ttoi(str_level2);
	int minPower = _ttoi(str_power1);
	int maxPower = _ttoi(str_power2);
	int minPrice = _ttoi(str_price1);
	int maxPrice = _ttoi(str_price2);
	int consitutionLevel = _ttoi(str_consitution);
	int legendaryCount = _ttoi(str_legendary);
	int haveCat = pDlg->m_catyes.GetCheck();


	LibcurlHttp http;
	Url url;
	vector<Character> character;

	url.set_classFuck(characterClass);
	url.set_levMin(minLevel);
	url.set_levMax(maxLevel);
	url.set_powerMin(minPower);
	url.set_powerMax(maxPower);
	url.set_priceMin(minPrice);
	url.set_priceMax(maxPrice);

	string response;
	int page = 1;
	int total_count = 0;
	int final_count = 0;
	while (TRUE  && pDlg->m_bSearching) {
		url.set_page(page);
		url.url_update();
		bool res = http.HttpRequest(url.url(), response);
		if (res) {
			json j = json::parse(response);
			if (j["code"] == 200) {
				int first_id = j["data"]["firstID"];
				int next_total_count = j["data"]["totalCount"];
				if (total_count != next_total_count) {
					total_count = next_total_count;
					character.resize(total_count);
					pDlg->m_progress.SetRange(0, total_count);
				}
				int lists_size = j["data"]["lists"].size();

				if (lists_size == 0)
					break;

				int begin_i = (page - 1) * 20;
				int end_i = begin_i + lists_size;
				for (int i = begin_i; i < end_i && pDlg->m_bSearching; ++i) {
					Character mycharacter = character[i];
					int j_index = i % 20;
					mycharacter.set_row_id(j["data"]["lists"][j_index]["rowID"]);
					mycharacter.set_sequence(j["data"]["lists"][j_index]["seq"]);

					mycharacter.set_transport_id(j["data"]["lists"][j_index]["transportID"]);
					string response_training;
					http.HttpRequest(
						url.baseurl_training() + "?transportID=" + to_string(mycharacter.transport_id()) + "&languageCode=" + url.languageCode(),
						response_training);
					json j_training = json::parse(response_training);
					mycharacter.set_consitution_level(j_training["data"]["consitutionLevel"]);

					string response_spirit;
					http.HttpRequest(
						url.baseurl_spirit() + "?transportID=" + to_string(mycharacter.transport_id()) + "&languageCode=" + url.languageCode(),
						response_spirit);
					json j_spirit = json::parse(response_spirit);
					mycharacter.set_pets_count(j_spirit["data"]["inven"].size());
					int epic_count = 0, legendary_count = 0;
					for (int ii = 0; ii < mycharacter.pets_count() && pDlg->m_bSearching; ++ii) {
						switch (j_spirit["data"]["inven"][ii].value("grade", 0)) {
						case 4:
							++epic_count;
							break;
						case 5:
							++legendary_count;
							break;
						default:
							break;
						}
						if (j_spirit["data"]["inven"][ii]["iconPath"] == mycharacter.draknyan_icon_path()) {
							mycharacter.set_have_resurrector_darknyan(true);
						}
					}
					mycharacter.set_epic_pets_count(epic_count);
					mycharacter.set_legendary_pets_count(legendary_count);

					mycharacter.set_token_id(j["data"]["lists"][j_index]["nftID"]);
					mycharacter.set_character_name(j["data"]["lists"][j_index]["characterName"]);
					mycharacter.set_character_class(j["data"]["lists"][j_index]["class"]);
					mycharacter.set_level(j["data"]["lists"][j_index]["lv"]);
					mycharacter.set_power(j["data"]["lists"][j_index]["powerScore"]);
					mycharacter.set_price(j["data"]["lists"][j_index]["price"]);

					if (mycharacter.consitution_level() >= consitutionLevel
						&& mycharacter.legendary_pets_count() >= legendaryCount
						&& mycharacter.have_resurrector_darknyan() == haveCat) {
						CString sn, cc, lv, po, pr, ep, lp, cat, con, turl;
						sn.Format(_T("%d"), final_count + 1);
						switch (mycharacter.character_class()) {
						case 1:
							cc = _T("战士");
							break;
						case 2:
							cc = _T("法师");
							break;
						case 3:
							cc = _T("道士");
							break;
						case 4:
							cc = _T("弩手");
							break;
						case 5:
							cc = _T("武士");
							break;
						}
						lv.Format(_T("%d"), mycharacter.level());
						po.Format(_T("%d"), mycharacter.power());
						pr.Format(_T("%d"), mycharacter.price());
						ep.Format(_T("%d"), mycharacter.epic_pets_count());
						lp.Format(_T("%d"), mycharacter.legendary_pets_count());
						if (mycharacter.have_resurrector_darknyan())
							cat = _T("有");
						con.Format(_T("%d"), mycharacter.consitution_level());
						string str = url.baseurl_nft_trade() + to_string(mycharacter.sequence());
						turl = str.c_str();
						pDlg->m_list.InsertItem(final_count, sn, 0);
						pDlg->m_list.SetItemText(final_count, 1, cc);
						pDlg->m_list.SetItemText(final_count, 2, lv);
						pDlg->m_list.SetItemText(final_count, 3, po);
						pDlg->m_list.SetItemText(final_count, 4, pr);
						pDlg->m_list.SetItemText(final_count, 5, ep);
						pDlg->m_list.SetItemText(final_count, 6, lp);
						pDlg->m_list.SetItemText(final_count, 7, cat);
						pDlg->m_list.SetItemText(final_count, 8, con);
						pDlg->m_list.SetItemText(final_count, 9, turl);
						pDlg->m_list.UpdateWindow();

						final_count++;
					}
					pDlg->m_progress.SetPos(i + 1);
				}
			}
		}
		page++;
	}
	pDlg->m_cancel.EnableWindow(0);
	pDlg->m_reset.EnableWindow(1);
	pDlg->m_search.SetWindowTextW(L"开始搜索");
	pDlg->m_search.EnableWindow(1);
	
	pDlg->m_characterclass.EnableWindow(1);
	pDlg->m_level1.EnableWindow(1);
	pDlg->m_level2.EnableWindow(1);
	pDlg->m_power1.EnableWindow(1);
	pDlg->m_power2.EnableWindow(1);
	pDlg->m_price1.EnableWindow(1);
	pDlg->m_price2.EnableWindow(1);
	pDlg->m_consitution.EnableWindow(1);
	pDlg->m_legendary.EnableWindow(1);
	pDlg->m_catyes.EnableWindow(1);
	pDlg->m_catno.EnableWindow(1);

	return 0;
}
