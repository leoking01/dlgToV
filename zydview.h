#pragma once



// zydview ��ͼ

class zydview : public CScrollView
{
	DECLARE_DYNCREATE(zydview)

protected:
public:
	zydview();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~zydview();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��

	DECLARE_MESSAGE_MAP()
};


