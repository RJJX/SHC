#pragma once
#include "afxcmn.h"


// _tourist �Ի���

class _tourist : public CDialogEx
{
	DECLARE_DYNAMIC(_tourist)

public:
	_tourist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~_tourist();

// �Ի�������
	enum { IDD = tourist };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CDatabase m_db;
	CRecordset rs;
	CListCtrl _list;
};
