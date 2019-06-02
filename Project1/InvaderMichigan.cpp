/**
 * \file InvaderMichigan.cpp
 *
 * \author Chang Ge
 */
#include "stdafx.h"
#include <string>
#include "InvaderMichigan.h"

using namespace Gdiplus;
using namespace std;

/// Michigan invader filename 1
const wstring CInvaderMichiganImageName1 = L"images/invaderUMa.png";
/// Michigan invader filename 2
const wstring CInvaderMichiganImageName2 = L"images/invaderUMb.png";
/// Michigan invader filename 3
const wstring CInvaderMichiganImageName3 = L"images/invaderUMw1.png";
/// Michigan invader filename 4
const wstring CInvaderMichiganImageName4 = L"images/invaderUMw2.png";

/**
* destructor
*/
CInvaderMichigan::~CInvaderMichigan()
{
	
}

/** Constructor
 * \param game The game this is a member of
 */
CInvaderMichigan::CInvaderMichigan(CGame *game) :
	CInvader(game)
{
	SetImage(CInvaderMichiganImageName1);
	LoadImage(mImage1, CInvaderMichiganImageName1);
	LoadImage(mImage2, CInvaderMichiganImageName2);
	LoadImage(mImage15, CInvaderMichiganImageName3);
	LoadImage(mImage16, CInvaderMichiganImageName4);
}

/**
 * Update the Michigan invader
 * \param elapsed The amount of elapsed time
 */
void CInvaderMichigan::Update(double elapsed)
{
	if (GetShoot() == 0) 
	{
		CInvader::Update(elapsed);
	}
	else
	{
		if (mTimer == 0 && mTimer2 == 0)
		{
			MSUPlusOne();
		}
		if (mTimer < 0.5)
		{

			mTimer += elapsed;
		}
		else
		{
			if (mTimer2 < 1.5)
			{
				mTimer2 += elapsed;
			}
			else
			{
				DeleteInvader(GetX(), GetY());
			}
		}
	}
	
}


/**
 * Draw the michigan invader
 * \param graphics The graphics to draw on
 */
void CInvaderMichigan::Draw(Graphics *graphics)
{
	if (mTimer2 > 0)
	{
		int wid = mImage16->GetWidth();
		int hit = mImage16->GetHeight();

		graphics->DrawImage(mImage16.get(),
			(int)(GetX() - mOffsetLeft), (int)(GetY() + mOffsetDown - hit),
			wid, hit);
	}
	else if (GetShoot() == 1)
	{
		int wid = mImage15->GetWidth();
		int hit = mImage15->GetHeight();

		graphics->DrawImage(mImage15.get(),
			(int)(GetX() - mOffsetLeft), (int)(GetY() + mOffsetDown - hit),
			wid, hit);
	}
	else
	{
		CInvader::Draw(graphics);
	}
}
