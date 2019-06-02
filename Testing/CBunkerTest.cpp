#include "stdafx.h"
#include "CppUnitTest.h"
#include "Bunker.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	class CBunkerMock : public CBunker
	{
	public:
		/**  Constructor
		 * \param city City this tile is a member of */
		CBunkerMock(CGame *game) : CBunker(game)
		{
		}

		///  Default constructor (disabled)
		CBunkerMock() = delete;

		///  Copy constructor (disabled)
		CBunkerMock(const CBunkerMock &) = delete;

		/** Accept a visitor
		 * \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor *visitor) override {}

		~CBunkerMock() {}
	};
	TEST_CLASS(CBunkerTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestBunkerConstruct)
		{
			CGame game;
			CBunker bunker(&game);
		}

		TEST_METHOD(TestBunkerState)
		{
			CGame game;
			CBunker bunker(&game);

			int state = bunker.GetBunkerState();

			Assert::AreEqual(0, state);
			
			bunker.SetBunkerState(3);

			Assert::AreEqual(3, bunker.GetBunkerState());

			bunker.SwitchState();

			Assert::AreEqual(4, bunker.GetBunkerState());
		}

		TEST_METHOD(TestBunkerHit)
		{
			CGame game;
			CBunker bunker(&game);

			int hits = bunker.GetBunkerState();

			Assert::AreEqual(0, hits);

			bunker.SetBunkerState(3);
			hits = bunker.GetBunkerState();

			Assert::AreEqual(3, hits);
		}

	};
}