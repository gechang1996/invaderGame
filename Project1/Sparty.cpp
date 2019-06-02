/**
 * \file Sparty.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "Sparty.h"

using namespace Gdiplus;
using namespace std;

/// Image file name
const wstring Sparty = L"images/sparty.png";
/// Initial speed
const double InitialSpeed=50;

/**
 * Constructor
 * \param game The game this is a part of
 */
CSparty::CSparty(CGame *game) : CItem(game)
{
	SetImage(Sparty);
	SetSpeed(InitialSpeed, InitialSpeed);

}

/*
* Destructor
*/
CSparty::~CSparty()
{
}


