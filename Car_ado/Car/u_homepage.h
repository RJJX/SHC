#pragma once



// u_homepage 对话框

class u_homepage : public CDialogEx
{
	DECLARE_DYNAMIC(u_homepage)

public:
	u_homepage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~u_homepage();



// 对话框数据
	enum { IDD = userhomepage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32779();
	afx_msg void On32778();

	afx_msg void On32776();
	afx_msg void On32777();
	void jx();
};
