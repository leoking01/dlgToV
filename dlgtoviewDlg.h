
// dlgtoviewDlg.h : ͷ�ļ�
//

#pragma once
#include"zydview.h"

// CdlgtoviewDlg �Ի���
class CdlgtoviewDlg : public CDialogEx
{
// ����
public:
	CdlgtoviewDlg(CWnd* pParent = NULL);	// ��׼���캯��
	zydview*pview;
// �Ի�������
	enum { IDD = IDD_DLGTOVIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
//	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
