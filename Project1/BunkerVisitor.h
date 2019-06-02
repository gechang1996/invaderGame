/**
 * \file BunkerVisitor.h
 *
 * \Chang Ge
 *
 * Implement visitor class for bunker
 */

#pragma once

#include "ItemVisitor.h"

/**
 * Class to keep track of state of bunker
 */
class CBunkerVisitor : public CItemVisitor
{
public:
	CBunkerVisitor();
	virtual ~CBunkerVisitor();

	/** Visit a CBunker object
	 * \param bunker Bunker we are visiting */
	virtual void VisitBunker(CBunker *bunker) override;
};

