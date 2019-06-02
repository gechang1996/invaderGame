#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "InvaderIowa.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CInvaderIowaTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCInvaderIowaConstruct)
		{
			CGame game;
			CInvaderIowa item(&game);
		}

		TEST_METHOD(TestCInvaderIowaHitTest)
		{
			// Create an invader to test
			CGame game;
			CInvaderIowa invader(&game);

			// Give it a location
			invader.SetLocation(200, 100);

			// Center of the invader should be a true
			Assert::IsTrue(invader.HitTest(200, 100));

			// Left of the invader
			Assert::IsFalse(invader.HitTest(100, 100));

			// Right of the invader
			Assert::IsFalse(invader.HitTest(400, 100));

			// Above the invader
			Assert::IsFalse(invader.HitTest(200, 200));

			// Below the invader
			Assert::IsFalse(invader.HitTest(200, 0));
		}

		TEST_METHOD(TestCInvaderSetLocation)
		{
			CGame game;
			CInvaderIowa invader(&game);

			Assert::AreEqual(0, (int)invader.GetX());
			Assert::AreEqual(0, (int)invader.GetY());

			invader.SetLocation(53, 132);
			Assert::AreEqual(53, (int)invader.GetX());
			Assert::AreEqual(132, (int)invader.GetY());

		}
	};
}