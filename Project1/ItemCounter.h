/**
 * \file ItemCounter.h
 *
 * \author Chang Ge
 *
 * Class that uses CItemVisitor base class to create concrete visitors to count Items
 */

#pragma once

#include "ItemVisitor.h"


/**
 * visitor class used to count the number of items/bunkers
 */
class CItemCounter :
	public CItemVisitor
{
public:
	CItemCounter();
	virtual ~CItemCounter();

	/**
	 * Visits bunker
	 * \param bunker Bunker we are visiting
	 * \return mNumBunkers is incremented by one */
	void VisitBunker(CBunker *bunker) { mNumBunkers++; }

	/**
	* Visits bunker
	* \return mNumBunkers is set */
	int GetNumBunkers() const { return mNumBunkers; }

private:
	int mNumBunkers = 0; ///< bunker count
};

