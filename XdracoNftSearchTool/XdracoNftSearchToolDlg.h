
// XdracoNftSearchToolDlg.h: 头文件
//

#pragma once


// CXdracoNftSearchToolDlg 对话框
class CXdracoNftSearchToolDlg : public CDialogEx
{
// 构造
public:
	CXdracoNftSearchToolDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XDRACONFTSEARCHTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_search;
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClickedCatyes();
	afx_msg void OnBnClickedCatno();
	CButton m_cancel;
	CButton m_catno;
	CButton m_catyes;
	CComboBox m_characterclass;
	CEdit m_consitution;
	CStatic m_goptions;
	CEdit m_legendary;
	CEdit m_level1;
	CEdit m_level2;
	CListCtrl m_list;
	CEdit m_power1;
	CEdit m_power2;
	CEdit m_price1;
	CEdit m_price2;
	CProgressCtrl m_progress;
	CButton m_reset;
	CStatic m_scat;
	CStatic m_scharacterclass;
	CStatic m_sconsitution;
	CStatic m_slegendary;
	CStatic m_slevel;
	CStatic m_slevelto;
	CStatic m_spower;
	CStatic m_spowerto;
	CStatic m_sprice;
	CStatic m_spriceto;
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	static UINT __cdecl SearchNft(LPVOID pParam);
	BOOL m_bSearching;
};
