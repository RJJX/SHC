#pragma once


// update �Ի���

class update : public CDialogEx
{
	DECLARE_DYNAMIC(update)

public:
	update(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~update();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CDatabase m_db;
	CRecordset rs;
	afx_msg void OnBnClickedOk();

	_variant_t result;
};
