/**
 * \file BunkerVisitor.cpp
 *
 * \Chang Ge
 */

#include "stdafx.h"
#include "BunkerVisitor.h"
#include "Bunker.h"

/*
* Constructor
*/
CBunkerVisitor::CBunkerVisitor()
{
}

/*
* Destructor
*/
CBunkerVisitor::~CBunkerVisitor()
{
}

void CBunkerVisitor::VisitBunker(CBunker *bunker)
{
	bunker->SwitchState();
}