/**
 * \file Game.h
 *
 * \author Chang Ge
 *
 * main game class
 */

#pragma once
#include<memory>
#include<vector>
#include "Item.h"
#include "Score.h"
#include"GameOver.h"

/**
 * The Game class.
 */
class CGame
{
public:
	CGame();
	virtual ~CGame();
	void OnDraw(Gdiplus::Graphics *graphics, int width, int height);
	void OnDraw2(Gdiplus::Graphics *graphics, int width, int height);
	/** Get the score of the game
	 *\returns the game score */
	std::shared_ptr<CScore> GetScore() { return mScore; }

	void DeleteItem(std::shared_ptr<CItem> item);
	void Update(double elapsed);

	/// decide if the fish be eaten
	/// \param x X location
	/// \param y Y location
	void RandomShootBall(double x,double y);

	void Reset();

	std::shared_ptr<CItem> HitTest2(int x, int y);
	void PopulateGame();
	void Accept(CItemVisitor *visitor);
	void Add(std::shared_ptr<CItem> item);
	/// check if we click on the fish
	/// \param x X location
	/// \param y Y location
	std::shared_ptr<CItem> HitTest(int x, int y);

	/** Get a this game's game over instance
	 * \returns this game over object */
	std::shared_ptr<CGameOver> GetGameOver() { return mGameOver; }

	bool HasBeenDestroyed(std::shared_ptr<CItem> item);
	void GameOver(Gdiplus::Graphics *graphics);

	/** Add an item to be removed
	 * \param item The item to be removed
	 */
	void AddToRemove(std::shared_ptr<CItem> item) { mToRemove.push_back(item); }

	/** Add to this games football population
	 * \param item The football to add 
	 */
	void AddToFootballs(std::shared_ptr<CItem> item) { mShootFootballs.push_back(item); }

	/** Get how many items there are 
	 * \returns the items size 
	 */
	int GetItemAmount() { return mItems.size(); }

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area heigh in virtual pixels
	const static int Height = 1000;

	//std::shared_ptr<CItem> getSparty();
	void SetSpartyLoc(CPoint p);

	/** Get the scale of the game
	 * \returns the game scale */
	float GetScale() { return mScale; }

	/** Get the X offset of the game 
	 * \returns the game x offset */
	float GetXOffset() { return mXOffset; }

	/** Get the Y offset of the game
	 * \returns the game y offset
	 */
	float GetYOffset() { return mYOffset; }


private:

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
	std::vector<std::shared_ptr<CItem> > mShootFootballs;  ///< temporary list to store football.

	/// The scale of the game
	float mScale;
	/// The x offset of the game
	float mXOffset;
	/// The y offset of the game
	float mYOffset;
	std::vector<std::shared_ptr<CItem>> mToRemove; ///< temporary list to store items which should be removed
	std::shared_ptr<CScore> mScore = std::make_shared<CScore>(this); ///< score of the game
	std::shared_ptr<CGameOver> mGameOver = std::make_shared<CGameOver>(this); ///< The game over object for completion
};

