/**
 * \file GameOver.h
 *
 * \author Chang Ge
 *
 * Class for presenting Game Over
 */

#pragma once

#include <memory>
#include <string>

class CGame;


/**
 * class to indictate the game has ended
 */
class CGameOver 
{
public:
	CGameOver() = delete;
	/// Copy constructor (disabled)
	CGameOver(const CGameOver &) = delete;
	virtual ~CGameOver();
	/**  Draw this item
	* \param graphics The graphics context to draw on */
	void Draw(Gdiplus::Graphics *graphics);
	/** Set the image of the game over
	 * \param file The file the image is in */
	void SetImage(const std::wstring &file);
	CGameOver(CGame *game);
	bool HitTest(double x, double y);

private:
	/// Gameover image
	std::unique_ptr<Gdiplus::Bitmap> mGameover;
};

