#pragma once



// u_homepage �Ի���

class u_homepage : public CDialogEx
{
	DECLARE_DYNAMIC(u_homepage)

public:
	u_homepage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~u_homepage();



// �Ի�������
	enum { IDD = userhomepage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32779();
	afx_msg void On32778();

	afx_msg void On32776();
	afx_msg void On32777();
	void jx();
};
