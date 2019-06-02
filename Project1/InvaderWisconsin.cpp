/**
 * \file InvaderWisconsin.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "InvaderWisconsin.h"

using namespace Gdiplus;
using namespace std;

/// Wisconsin invader filename 1
const wstring CInvaderWisconsinImageName1 = L"images/invaderWa.png";
/// Wisconsin invader filename 2
const wstring CInvaderWisconsinImageName2 = L"images/invaderWb.png";
/// Wisconsin invader filename 3
const wstring CInvaderWisconsinImageName3 = L"images/invaderWo.png";


/**
* Destructor
*/
CInvaderWisconsin::~CInvaderWisconsin()
{
}

/** 
* Constructor
* \param game The game this is a member of
*/
CInvaderWisconsin::CInvaderWisconsin(CGame *game) :
	CInvader(game)
{
	SetImage(CInvaderWisconsinImageName1);
	LoadImage(mImage1, CInvaderWisconsinImageName1);
	LoadImage(mImage2, CInvaderWisconsinImageName2);
	LoadImage(mImage8, CInvaderWisconsinImageName3);
}

/**
 * Update the wisonsin invader
 * \param elapsed Amount of time elapsed
 */
void CInvaderWisconsin::Update(double elapsed)
{
	
	if(GetShoot() == 1)
	{
		if (mTimer == 0)
		{
			MSUPlusOne();
		}
		mTimer += elapsed;
		if (mTimer >= 1)
		{
			DeleteInvader(GetX(), GetY());
		}
	}
	else
	{
		CInvader::Update(elapsed);
	}
	
}

/**
 * Draw the wisonsin invader
 * \param graphics The graphics to draw on
 */
void CInvaderWisconsin::Draw(Graphics *graphics)
{
	if (GetShoot() == 1) 
	{
		int wid = mImage8->GetWidth();
		int hit = mImage8->GetHeight();

		graphics->DrawImage(mImage8.get(),
			(int)(GetX() - mOffsetLeft), (int)(GetY() + mOffsetDown - hit),
			wid, hit);
	}
	else
	{
		CInvader::Draw(graphics);
	}
}

