/**
 * \file ChildView.cpp
 *
 * \Chang Ge
 */


// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Project1.h"
#include "ChildView.h"
#include "Football.h"
#include "DoubleBufferDC.h"
#include "Game.h"
#include "ItemVisitor.h"
#include "InvaderCounter.h"
#include "BunkerVisitor.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;

/// Game area width in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;
///Find the hand of sparty
const double SpartyHand = 36;

/// Frame duration in milliseconds
const int FrameDuration = 30;
///Football y position
const int FootballY = 900;
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/**
 * Paint the game
 */
void CChildView::OnPaint() 
{

	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);
	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);
		/*
		 * Initialize the elapsed time system
		 */
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}
	/*
	 * Compute the elapsed time since the last draw
	 */

	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	//CItemVisitor visitor;
	
	mGame.Update(elapsed);
	//mGame.Accept(&visitor);
	CInvaderCounter visitor;
	mGame.Accept(&visitor);
	int InvaderNum = visitor.GetNumInvaders();

	if (InvaderNum == 0) 
	{
		mGame.OnDraw2(&graphics, rect.Width(), rect.Height());
		
	}
	else
	{
		mGame.OnDraw(&graphics, rect.Width(), rect.Height());
	}
}


/**
*  Handle timer events
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}

/**
 * Erase the background
 * \param pDC - background object
 * \returns False
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return FALSE;
}


/**
 * Set sparty's x location
 * \param nFlags - flags of movement
 * \param point - point of movement
 */
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	mGame.SetSpartyLoc(point);

}


/**
 * Action of clicking for football or game over
 * \param nFlags - flags of click
 * \param point - point of click
 */
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	double scale = mGame.GetScale();
	double xOffset = mGame.GetXOffset();
	double yOffset = mGame.GetYOffset();

	const int imghead = 50;
	const int imgfoot = 40;
	double oX = (point.x - xOffset) / scale;
	double oY = (point.y - yOffset) / scale;
	CInvaderCounter visitor1;
	mGame.Accept(&visitor1);
	int InvaderNum = visitor1.GetNumInvaders();

	if (InvaderNum == 0)
	{
		if (mGame.GetGameOver()->HitTest(oX, oY))
		{
			mGame.Reset();
		}
	}


	if (oX < -Width / 2+ imgfoot)
	{
		oX = -Width / 2+ imgfoot;
	}
	else if (oX > Width / 2- imghead)
	{
		oX = Width / 2- imghead;
	}

	auto football = make_shared<CFootball>(&mGame);
	football->SetLocation(oX+ SpartyHand, FootballY);
	mGame.Add(football);
	

}
