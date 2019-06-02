/**
 * \file FootballVisitor.cpp
 *
 * \author Chang Ge
 */
#include "stdafx.h"
#include "FootballVisitor.h"
#include "Football.h"

 /**
  * Constructor
  */
CFootballVisitor::CFootballVisitor()
{
}

/**
* Destructor
*/
CFootballVisitor::~CFootballVisitor()
{
}

void CFootballVisitor::VisitFootball(CFootball *Football)
{
	Football->Shootsth();
}
