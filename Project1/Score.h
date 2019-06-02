/**
 * \file Score.h
 *
 * \author Chang Ge
 *
 * Declares the Score class
 */

#pragma once
#include <memory>

// Forward reference for game
class CGame;
 
/**
 * Declares the Score class
 */
class CScore
{
public:
	CScore() = delete;
	/// Copy constructor (disabled)
	CScore(const CScore &) = delete;
	virtual ~CScore();

	CScore(CGame *game);

	void DisplayScore(Gdiplus::Graphics *graphics);

	/** Upate MSU's score by 1
	 */
	void UpdateMSUScore() { mMSUScore++; }

	/** Update Invader's score by 1 */
	void UpdateInvaderScore() { mInvaderScore++;  }

	/** Get the MSU score
	 * \returns the msu score */
	int GetMSUScore() { return mMSUScore; }

	void Reset();
	/** Get the invader score 
	 * \returns the invader score */
	int GetInvaderScore() { return mInvaderScore; }

private:
	/// The msu score
	int mMSUScore = 0;
	/// The invader score
	int mInvaderScore = 0;
};

