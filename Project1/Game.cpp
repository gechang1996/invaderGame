/**
 * \file Game.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include <sstream>
#include "Game.h"
#include "Score.h"
#include "Item.h"
#include "Bunker.h"
#include "Sparty.h"
#include "Football.h"
#include "InvaderIowa.h"
#include "InvaderMichigan.h"
#include "InvaderNebraska.h"
#include "InvaderOhioState.h"
#include "InvaderWisconsin.h"
#include "FootballVisitor.h"
#include "InvaderCounter.h"

using namespace Gdiplus;
using namespace std;

/// Constant used for generating random nums.
const int Hundred = 100;

/// The tolerance
const double Tolerance = 60;

/// The x offset 
const double XOffset = 10;

/// They y offset
const double YOffset = 20;

/// Game area width in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;

/// Positive Y Movement for speed
const double PosMoveY = 500;

/** 
* Constructor
*/
CGame::CGame()
{
	PopulateGame();
}

/**
* Destructor
*/
CGame::~CGame()
{
}

/** Draw the game playing field
* \param graphics The GDI+ graphics context to draw on
* \param width The width of the screen
* \param height The height of the screen
*/
void CGame::OnDraw(Graphics *graphics, int width, int height)
{

	// Fill the background with black
	SolidBrush brush(Color::Black);
	
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = 0;
	if (height > Height * mScale) {
		mYOffset = (float)((height - Height * mScale) / 2);
	}

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// Display the score on the screen
	mScore->DisplayScore(graphics);
	
	
	for (auto item : mItems)
	{
		item->Draw(graphics);
	}

}
/** Draw the game playing field
* \param graphics The GDI+ graphics context to draw on
* \param width The width of the screen
* \param height The height of the screen
*/
void CGame::OnDraw2(Graphics *graphics, int width, int height)
{

	OnDraw (graphics, width, height);
	GameOver(graphics);
	
	mGameOver->Draw(graphics);
}

/**  Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{

	for (auto pItem = mItems.begin(); pItem != mItems.end(); pItem++)
	{
		auto item = *pItem;

		
		if (HasBeenDestroyed(item))
		{
			AddToRemove(item);
		}
		else 
		{
			CFootballVisitor visitor;
			item->Accept(&visitor);
			item->Update(elapsed);
		}
			

	}
	
	for (auto item : mToRemove)
	{
		DeleteItem(item);
	}
	mToRemove.clear();
	for (auto item : mShootFootballs)
	{
		mItems.push_back(item);
	}
	mShootFootballs.clear();


}


/**
 * Assure items empty and display text/button
 * \param graphics The graphics object to draw on
 */
void CGame::GameOver(Graphics *graphics)
{

	// Check if all invaders are removed
		// Display game over text
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 130);
		SolidBrush yellow(Color::Yellow);
		// TODO: figure out coordinate for where text goes

		graphics->DrawString(L"Game Over!", -1, &font, PointF(-600, 200), &yellow);
	
}

/**  Add an item to the game
* \param item New tile to add
*/
void CGame::Add(shared_ptr<CItem> item)
{
	mItems.push_back(item);
}


/**
 * Set the sparty location
 * \param p The point of location
 */
void CGame::SetSpartyLoc(CPoint p)
{
	const double YPos = 910;
	const double XMax = 550;
	const int imghead = 50;
	const int imgfoot = 40;
	double oX = (p.x - mXOffset) / mScale;
	
	if (oX > Width / 2 - imghead)
	{
		oX = Width / 2 - imghead;
	}
	else if (oX < -Width / 2 + imgfoot)
	{
		oX = -Width / 2 + imgfoot;
	}

	mItems[0]->SetLocation(oX, YPos);

}


/**
 * Populates the game with all the invaders
 * 
 * This function should be used to construct the game
 */
void CGame::PopulateGame()
{
	// Draw sparty
	const int XSpartyStart = 0;
	const int YSpartyLim = 910;

	shared_ptr<CItem> Sparty = make_shared<CSparty>(this);
	Sparty->SetLocation(XSpartyStart, YSpartyLim);

	mItems.push_back(Sparty);


	// We center the columns on the screen

	// Loop over the rows of items we will create
	// We use the constant here to indicate how 
	// many rows we want to create

	const int Bunkerspace = 400;
	const int Times1 = 3;
	const int Times2 = 10;
	const int Invaderspace = 120;
	
	const int XBunkerStart = -450;
	const int YBunkerStart = 800;
	const int XInvaderStart= -500;
	const int Y1 = 200;
	const int Y2 = 315;
	const int Y3 = 430;
	const int Y4 = 545;
	const int Y5 = 660;
	
	/// Draws Bunker
	for (int c = 0; c < Times1; c++)
	{
		// Each column is 128 pixels to the right.
		int x = c * Bunkerspace + XBunkerStart;

		// Create a new Bunker.
		// This creates a shared pointer pointing at this bunker
		shared_ptr<CItem> Bunker = make_shared<CBunker>(this);

		// Set the location
		Bunker->SetLocation(x, YBunkerStart);

		// Add to the list of bunker.
		mItems.push_back(Bunker);
	}
	// We center the columns on the screen

	for (int c1 = 0; c1 < Times2; c1++)
	{
		///Draw Invader Iowa
		// Each column is 128 pixels to the right.
		int x1 = c1 * Invaderspace + XInvaderStart;

		// Create a new invader.
		// This creates a shared pointer pointing at this invader
		shared_ptr<CItem> invader1 = make_shared<CInvaderIowa>(this);

		// Set the location
		invader1->SetLocation(x1, Y1);

		// Add to the list of invader.
		mItems.push_back(invader1);
		
		/// Draw invader Wisconsin
		// Each column is 128 pixels to the right.
		int x2 = c1 * Invaderspace + XInvaderStart;

		// Create a new invader.
		// This creates a shared pointer pointing at this invader
		shared_ptr<CItem> invader2 = make_shared<CInvaderWisconsin>(this);

		// Set the location
		invader2->SetLocation(x2, Y2);

		// Add to the list of invader.
		mItems.push_back(invader2);

		/// Draw Invader Michigan
		// Each column is 128 pixels to the right.
		int x3 = c1 * Invaderspace + XInvaderStart;

		// Create a new invader.
		// This creates a shared pointer pointing at this invader
		shared_ptr<CItem> invader3 = make_shared<CInvaderMichigan>(this);

		// Set the location
		invader3->SetLocation(x3, Y3);

		// Add to the list of invader.
		mItems.push_back(invader3);

		/// Draw Invader Nebraska 
		// Each column is 128 pixels to the right.
		int x4 = c1 * Invaderspace + XInvaderStart;

		// Create a new invader.
		// This creates a shared pointer pointing at this invader
		shared_ptr<CItem> invader4 = make_shared<CInvaderNebraska>(this);

		// Set the location
		invader4->SetLocation(x4, Y4);

		// Add to the list of invader.
		mItems.push_back(invader4);

		/// Draw Invader Ohio State
		// Each column is 128 pixels to the right.
		int x5 = c1 * Invaderspace + XInvaderStart;

		// Create a new invader.
		// This creates a shared pointer pointing at this invader
		shared_ptr<CItem> invader5 = make_shared<CInvaderOhioState>(this);

		// Set the location
		invader5->SetLocation(x5, Y5);

		// Add to the list of Invader.
		mItems.push_back(invader5);
	}
}


/** Test an x,y click location to see if it clicked
* on some item in the game.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CGame::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}
/** Test an x,y click location to see if it clicked
* on some item in the game.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
shared_ptr<CItem> CGame::HitTest2(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest2(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


/**
 * Test if 
 * \param item to test destruction
 * \returns true if item is destroyed
 */
bool CGame::HasBeenDestroyed(shared_ptr<CItem> item)
{
	double ypos = item->GetY();
	double xpos = item->GetX();
	if (ypos < 0 || ypos > Height || xpos < -Width / 2 || xpos > Width / 2 + Tolerance)
	{
		return true;
	}
	else
	{
		return false;
	}
}




/**  Delete an item from the game
*
* \param item The item to delete.
*/
void CGame::DeleteItem(shared_ptr<CItem> item)
{
	auto loc = find(::begin(mItems), ::end(mItems), item);
	if (loc != ::end(mItems))
	{
		mItems.erase(loc);
	}
}

/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor *visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}

/**
 * Shoot a random ball upwards
 * \param x - initial x location
 * \param y - initial y location
 */
void CGame::RandomShootBall(double x, double y)
{
	double rand_num = rand() % Hundred;
	if (rand_num <= 1)
	{
		
		shared_ptr<CItem> football = make_shared<CFootball>(this);

		football->SetLocation(x + XOffset, y + YOffset);
		football->SetSpeed(0, PosMoveY);
		mShootFootballs.push_back(football);
	}
}

/**
 * Reset the game
 */
void CGame::Reset()
{
	mItems.clear();
	mToRemove.clear();
	mShootFootballs.clear();
	mScore->Reset();
	PopulateGame();
}