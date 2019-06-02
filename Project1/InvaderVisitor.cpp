/**
 * \file InvaderVisitor.cpp
 *
 * \author Chang Ge
 */
#include "stdafx.h"
#include "InvaderVisitor.h"
#include "Invader.h"
#include "InvaderWisconsin.h"

/**
* Constructor
*/
CInvaderVisitor::CInvaderVisitor()
{
}

/**
* Destructor
*/
CInvaderVisitor::~CInvaderVisitor()
{
}

void CInvaderVisitor::VisitInvader(CInvader *invader)
{
	invader->SetShoot();
}
