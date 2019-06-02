/**
 * \file Football.cpp
 *
 * \Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "Football.h"
#include "InvaderVisitor.h"
#include "BunkerVisitor.h"
#include "Game.h"
#include "Item.h"

using namespace Gdiplus;
using namespace std;

const wstring Football = L"images/football.png"; ///< file location of football image
const double MoveY = -600; ///< Football start location
/// Football img for hit test
const int Footballimg = 33; 
/// Bunker img for hit test
const int Bunkerimg = 90;
/// Sparty img for hit test
const int Sparty = 50;

/**
 * Constructor
 * \param game The game we are in
 */
CFootball::CFootball(CGame *game) : CItem(game)
{
	SetImage(Football);
	SetSpeed(0, MoveY);
}

/**
* Destructor
*/
CFootball::~CFootball()
{
}


/**
 * Shoot something with football
 */
void CFootball :: Shootsth()
{
	///when a football hits a invader,put the football into a temporary list and it will be removed later
	///also, call invadervisitor to make invader disappear
	if (GetSpeedY() < 0)
	{
	std::shared_ptr<CItem> item1 = Getter()->HitTest(int(GetX()- Footballimg), int(GetY() - Footballimg));
	if (item1 != NULL &&item1->GetSpeedX()!=0)
		{
			std::shared_ptr<CItem> item2 = Getter()->HitTest(int(GetX()), int(GetY()));
			CInvaderVisitor visitor;
			item1->Accept(&visitor);
			Getter()->AddToRemove(item2);
		}
	}
	
	else
	{
		std::shared_ptr<CItem> item3 = Getter()->HitTest2(int(GetX() -Bunkerimg), int(GetY() + Footballimg));
		///when a football hit a bunker, call bunker visitor and move the football to a temporary list and remove it later 
		if (item3 != NULL && item3->GetSpeedX() == 0 &&item3->GetSpeedY()==0)
		{
			CBunkerVisitor visitor;
			item3->Accept(&visitor);
			std::shared_ptr<CItem> item4 = Getter()->HitTest(int(GetX()), int(GetY()));
			Getter()->AddToRemove(item4);
		}
		///when a football hit sparty, invader score+1, and move the football to a temporary list and remove it later
		else if (item3 != NULL && item3->GetSpeedX() == Sparty)
		{

			Getter()->GetScore()->UpdateInvaderScore();
			std::shared_ptr<CItem> item4 = Getter()->HitTest(int(GetX()), int(GetY()));
			Getter()->AddToRemove(item4);
		}
	}
}

/**
* Update the location of the football
* \param elapsed the time elapsed since last call
*/
void CFootball::Update(double elapsed)
{
	SetLocation(GetX() + GetSpeedX() * elapsed,
		GetY() + GetSpeedY() * elapsed);
}
