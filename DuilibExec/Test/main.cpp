#include "stdafx.h"

class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void Notify(TNotifyUI& msg) {
		if (msg.sType == _T("click") && msg.pSender->GetName() == _T("btnHello")) {
			::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE) {
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetName(_T("btnHello"));
			pWnd->SetText(_T("Hello World"));
			pWnd->SetBkColor(0xff00ff00);

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			m_PaintManager.AddNotifier(this);
			return lRes;
		} 
		else if (uMsg == WM_NCACTIVATE) {
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE) {
			return 0;
		}
		else if (uMsg == WM_NCPAINT) {
			return 0;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes)) {
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();
	return 0;
}