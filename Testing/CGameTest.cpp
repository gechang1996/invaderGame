#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Sparty.h"
#include "InvaderIowa.h"
#include "InvaderMichigan.h"
#include "InvaderNebraska.h"
#include "InvaderOhioState.h"
#include "InvaderWisconsin.h"
#include "Bunker.h"
#include "Sparty.h"
#include "Invader.h"
#include "Football.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	class CGameMock : public CGame
	{
		//CGameMock() {};
	};

	class CTestVisitor : public CItemVisitor
	{
	public:
		//virtual void VisitInvader(CInvader *invader) override { mNumInvaders++; }
		//int mNumInvaders = 0;

		virtual void VisitBunker(CBunker *bunker) override { mNumBunkers++; }
		int mNumBunkers = 0;

		virtual void VisitSparty(CSparty *sparty) override { mNumSpartys++; }
		int mNumSpartys = 0;

		virtual void VisitFootball(CFootball *football) override { mNumFootballs++; }
		int mNumFootballs = 0;
		
	};
	
	
	
	TEST_CLASS(CGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestCGameHitTest)
		{
			CGame game;

			//We initialize game non-empty
			//Assert::IsTrue(game.HitTest(100, 200) == nullptr, L"Testing empty game");

			shared_ptr<CInvaderMichigan> invader1 = make_shared<CInvaderMichigan>(&game);
			invader1->SetLocation(100, 200);
			game.Add(invader1);

			Assert::IsTrue(game.HitTest(100, 200) == invader1, L"Testing invader1 at 100, 200");

			shared_ptr<CInvaderMichigan> invader2 = make_shared<CInvaderMichigan>(&game);
			invader2->SetLocation(100, 200);
			game.Add(invader2);

			//test fish2 is on top of fish1
			Assert::IsTrue(game.HitTest(100, 200) == invader2, L"Testing invader2 is on top at 100, 200");

			//test no fish are at location where no fish should be
			Assert::IsTrue(game.HitTest(0, 0) == nullptr, L"Testing invader at 200, 300");
		}

		TEST_METHOD(TestCGameAdd)
		{
			CGame game;
			Assert::IsTrue(game.GetItemAmount() == 54); // testing initial amount

			shared_ptr<CInvaderMichigan> invader1 = make_shared<CInvaderMichigan>(&game);
			invader1->SetLocation(100, 200);
			game.Add(invader1);

			shared_ptr<CInvaderMichigan> invader2 = make_shared<CInvaderMichigan>(&game);
			invader2->SetLocation(200, 200);
			game.Add(invader2);

			shared_ptr<CInvaderMichigan> invader3 = make_shared<CInvaderMichigan>(&game);
			invader3->SetLocation(300, 200);
			game.Add(invader3);

			shared_ptr<CInvaderMichigan> invader4 = make_shared<CInvaderMichigan>(&game);
			invader4->SetLocation(400, 200);
			game.Add(invader4);

			Assert::IsTrue(game.GetItemAmount() == 58);

			shared_ptr<CInvaderMichigan> invader5 = make_shared<CInvaderMichigan>(&game);
			invader5->SetLocation(500, 200);
			game.Add(invader5);

			Assert::IsTrue(game.GetItemAmount() == 59);

		}

		TEST_METHOD(TestCGameDeleteItem)
		{
			CGame game;
			Assert::IsTrue(game.GetItemAmount() == 54); // testing initial amount

			shared_ptr<CInvaderMichigan> invader1 = make_shared<CInvaderMichigan>(&game);
			invader1->SetLocation(100, 200);
			game.Add(invader1);

			shared_ptr<CInvaderMichigan> invader2 = make_shared<CInvaderMichigan>(&game);
			invader2->SetLocation(200, 200);
			game.Add(invader2);

			shared_ptr<CInvaderMichigan> invader3 = make_shared<CInvaderMichigan>(&game);
			invader3->SetLocation(300, 200);
			game.Add(invader3);

			shared_ptr<CInvaderMichigan> invader4 = make_shared<CInvaderMichigan>(&game);
			invader4->SetLocation(400, 200);
			game.Add(invader4);

			Assert::IsTrue(game.GetItemAmount() == 58);

			game.DeleteItem(invader2);
			Assert::IsTrue(game.GetItemAmount() == 57);

			game.DeleteItem(invader1);
			game.DeleteItem(invader3);
			Assert::IsTrue(game.GetItemAmount() == 55);

		}
	
	};
}