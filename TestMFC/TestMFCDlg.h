
// TestMFCDlg.h: 头文件
//

#pragma once


// CTestMFCDlg 对话框
class CTestMFCDlg : public CDialogEx
{
// 构造
public:
	CTestMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMFC_DIALOG };
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
	CButton m_reset;
	CButton m_cancel;
	CProgressCtrl m_progress;
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
	CButton m_catno;
	CButton m_catyes;
	afx_msg void OnClickedCatno();
	afx_msg void OnClickedCatyes();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedReset();
};
