// GameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LOLDLL.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "Solider.h"
#include "ObjectExtend.h"
#include "GameInit.h"
#include "Equment.h"
#include "Skill.h"
#include "HeroBuff.h"
#include "ScanBase.h"
#include "FieldFight.h"
#include "GameCALL.h"
#include "Turret.h"
#include "Person.h"
#include "SkillServices.h"
#include "EqumentServices.h"
#define _SELF L"GameDlg.cpp"
// CGameDlg dialog

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameDlg::IDD, pParent)
{

}

CGameDlg::~CGameDlg()
{
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGameDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CGameDlg::OnNMClickList1)
END_MESSAGE_MAP()

BOOL CGameDlg::OnInitDialog()
{
	CListCtrl * m_List = ((CListCtrl *)GetDlgItem(IDC_LIST1));
	if (m_List != nullptr)
		m_List->SetExtendedStyle(m_List->GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	CComboBox * CCB = (CComboBox *)GetDlgItem(IDC_CCB_CMD);
	if (CCB != nullptr)
	{
		CCB->InsertString(0, L"AllySolider");
		CCB->InsertString(1, L"遍历背包");
		CCB->InsertString(2, L"遍历技能");
		CCB->InsertString(3, L"人物BUFF");
		CCB->InsertString(4, L"ScanBase");
		CCB->InsertString(5, L"PartyStart!");
		CCB->InsertString(6, L"Test!");
	}
	
	CGameInit::GetInstance().InitTimer();
	return TRUE;
}


// CGameDlg message handlers
LPCWSTR ConvertNumber(__in LPCWSTR pwszFormat, ...)
{
	va_list		args;
	static wchar_t		szBuff[1024] = { 0 };

	va_start(args, pwszFormat);
	_vsnwprintf_s(szBuff, _countof(szBuff) - 1, _TRUNCATE, pwszFormat, args);
	va_end(args);

	return szBuff;
}

DWORD WINAPI _TestThread(LPVOID lpParm)
{
	CFieldFight::GetInstance().StartShowTime();
	return 0;
}

void CGameDlg::OnBnClickedButton1()
{
	CComboBox * CCB = (CComboBox*)GetDlgItem(IDC_CCB_CMD);
	CEdit * pEdit = (CEdit *)GetDlgItem(IDC_EDIT_COPY);
	CListCtrl * m_List = (CListCtrl *)GetDlgItem(IDC_LIST1);
	if (CCB == NULL || m_List == NULL || pEdit == NULL)
		return;

	auto fnDeleteListData = [&m_List]
	{
		m_List->DeleteAllItems();
		int nColumnCount = m_List->GetHeaderCtrl()->GetItemCount();
		for (int i = 0; i < nColumnCount; i++)
		{
			m_List->DeleteColumn(0);
		}
	};

	// Delete All Item
	fnDeleteListData();

	int nIndex = CCB->GetCurSel();
	if (nIndex == 0)
	{
		m_List->InsertColumn(0, L"Base", LVCFMT_LEFT, 80);
		m_List->InsertColumn(1, L"ID", LVCFMT_LEFT, 80);
		m_List->InsertColumn(2, L"ID2", LVCFMT_LEFT, 80);
		m_List->InsertColumn(3, L"Name", LVCFMT_LEFT, 150);
		m_List->InsertColumn(4, L"IsShow", LVCFMT_LEFT, 30);
		m_List->InsertColumn(5, L"TarId", LVCFMT_LEFT, 80);
		m_List->InsertColumn(6, L"Point", LVCFMT_LEFT, 100);
		m_List->InsertColumn(7, L"HP/MAXHP", LVCFMT_LEFT, 80);
		m_List->InsertColumn(8, L"Dis", LVCFMT_LEFT, 50);
		m_List->InsertColumn(9, L"Type", LVCFMT_LEFT, 50);
		m_List->InsertColumn(10, L"Camp", LVCFMT_LEFT, 50);

		vector<CSolider> vlst;
		CObjectExtend::GetInstance().GetHumanTypeListByType<CSolider>(em_Human_Type::em_Human_Type_Unknow, em_Camp::em_Camp_Blue, vlst);

		for (CONST auto& itm : vlst)
		{
			int nRow = m_List->InsertItem(m_List->GetItemCount(), ConvertNumber(L"%X", itm.GetNodeBase()));

			m_List->SetItemText(nRow, 1, ConvertNumber(L"%X", itm.GetId()));

			m_List->SetItemText(nRow, 2, ConvertNumber(L"%X", itm.GetSkillParameter()));

			m_List->SetItemText(nRow, 3, itm.GetName().c_str());

			m_List->SetItemText(nRow, 4, itm.IsShowInFog() ? L"YES" : L"NO");

			m_List->SetItemText(nRow, 5, ConvertNumber(L"%X", itm.GetTargetId()));

			Point Pt = itm.GetPoint();
			m_List->SetItemText(nRow, 6, ConvertNumber(L"%d,%d,%d", Pt.GetX(), Pt.GetY(), Pt.GetZ()));

			m_List->SetItemText(nRow, 7, ConvertNumber(L"%d-%d",itm.GetHp(), itm.GetMaxHp()));

			m_List->SetItemText(nRow, 8, ConvertNumber(L"%.2f", itm.GetDis()));

			m_List->SetItemText(nRow, 9, ConvertNumber(L"%X", itm.GetHumanType()));

			m_List->SetItemText(nRow, 10, ConvertNumber(L"%X", itm.GetCurrentCamp()));
		}

	}
	else if (nIndex == 1)
	{
		m_List->InsertColumn(0, L"Base", LVCFMT_LEFT, 80);
		m_List->InsertColumn(1, L"ID", LVCFMT_LEFT, 50);
		m_List->InsertColumn(2, L"Count", LVCFMT_LEFT, 50);

		vector<CEqument> vlst;
		CObjectExtend::GetInstance().GetCurrentHeroEqumentList(vlst);
		for (CONST auto& itm : vlst)
		{
			int nRow = m_List->InsertItem(m_List->GetItemCount(), ConvertNumber(L"%X", itm.GetNodeBase()));

			m_List->SetItemText(nRow, 1, ConvertNumber(L"%X", itm.GetId()));

			m_List->SetItemText(nRow, 2, ConvertNumber(L"%d", itm.GetCount()));
		}
	}
	else if (nIndex == 2)
	{
		m_List->InsertColumn(0, L"Base", LVCFMT_LEFT, 80);
		m_List->InsertColumn(1, L"Index", LVCFMT_LEFT, 50);
		m_List->InsertColumn(2, L"Level", LVCFMT_LEFT, 50);
		m_List->InsertColumn(3, L"Name", LVCFMT_LEFT, 100);
		m_List->InsertColumn(4, L"ExpendMp", LVCFMT_LEFT, 80);
		m_List->InsertColumn(5, L"CD", LVCFMT_LEFT, 50);
		m_List->InsertColumn(6, L"IsUse", LVCFMT_LEFT, 80);

		vector<CSkill> vlst;
		CObjectExtend::GetInstance().GetSkillList(vlst);
		for (CONST auto& itm : vlst)
		{
			int nRow = m_List->InsertItem(m_List->GetItemCount(), ConvertNumber(L"%X", itm.GetNodeBase()));

			m_List->SetItemText(nRow, 1, ConvertNumber(L"%d", itm.GetSkillIndex()));

			m_List->SetItemText(nRow, 2, ConvertNumber(L"%d", itm.GetLevel()));

			m_List->SetItemText(nRow, 3, itm.GetName().c_str());

			m_List->SetItemText(nRow, 4, ConvertNumber(L"%d", itm.GetExpendMp()));

			m_List->SetItemText(nRow, 5, itm.IsCooldown() ? L"Yes" : L"No");

			m_List->SetItemText(nRow, 6, itm.IsCooldown() ? L"Yes" : L"No");
		}
	}
	else if (nIndex == 3)
	{
		m_List->InsertColumn(0, L"Base", LVCFMT_LEFT, 80);
		m_List->InsertColumn(1, L"ID", LVCFMT_LEFT, 50);
		m_List->InsertColumn(2, L"Count", LVCFMT_LEFT, 50);
		m_List->InsertColumn(3, L"Name", LVCFMT_LEFT, 100);

		vector<CHeroBuff> vlst;
		CObjectExtend::GetInstance().GetCurrentHeroBuffList(vlst);
		for (CONST auto& itm : vlst)
		{
			int nRow = m_List->InsertItem(m_List->GetItemCount(), ConvertNumber(L"%X", itm.GetNodeBase()));

			m_List->SetItemText(nRow, 1, ConvertNumber(L"%X", itm.GetId()));

			m_List->SetItemText(nRow, 2, ConvertNumber(L"%d", itm.GetCount()));

			m_List->SetItemText(nRow, 3, itm.GetName().c_str());
		}
	}
	else if (nIndex == 4)
	{
		CScanBase::GetInstance().Begin();
	}
	else if (nIndex == 5)
	{
		static HANDLE hThread = NULL;
		if (hThread == NULL)
		{
			GameStart;
			hThread = cbBEGINTHREADEX(NULL, NULL, _TestThread, NULL, NULL, NULL);
		}
		else
		{
			StopGame;
			WaitForSingleObject(hThread, INFINITE);
			hThread = NULL;
		}
	}
	else if (nIndex == 6)
	{
		GameStart;
		CEqumentServices::GetInstance().CheckMedicine();
	}
}


void CGameDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


void CGameDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if (pNMListView->iItem != -1 && pNMListView->iSubItem != -1)
	{
		CListCtrl * m_list = (CListCtrl *)GetDlgItem(IDC_LIST1);
		CString str = m_list->GetItemText(pNMListView->iItem, pNMListView->iSubItem);
		((CEdit*)GetDlgItem(IDC_EDIT_COPY))->SetWindowTextW(str);
	}
	*pResult = 0;
}
