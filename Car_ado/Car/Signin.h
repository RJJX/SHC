#pragma once


// Signin �Ի���

class Signin : public CDialogEx
{
	DECLARE_DYNAMIC(Signin)

public:
	Signin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Signin();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };
	CDatabase m_db;
	CRecordset rs;
	CRecordset ra;

	CString uid;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	public:
	

};

