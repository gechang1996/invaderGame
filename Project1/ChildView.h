
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"

// CChildView window

/**
 * The child view window of the game
 */
class CChildView : public CWnd
{
private:
	/// An object that describes our aquarium
	CGame  mGame;
	/// True until the first time we draw
	bool mFirstDraw = true;
	long long mLastTime;    ///< Last time we read the timer

	double mTimeFreq;       ///< Rate the timer updates
	

// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

