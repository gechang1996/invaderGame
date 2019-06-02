#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "InvaderNebraska.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CInvaderNebraskaTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCInvaderMichiganConstruct)
		{
			CGame game;
			CInvaderNebraska item(&game);
		}

		TEST_METHOD(TestCInvaderHitTest)
		{
			// Create an invader to test
			CGame game;
			CInvaderNebraska invader(&game);

			// Give it a location
			invader.SetLocation(400, 100);

			// Center of the invader should be a true
			Assert::IsFalse(invader.HitTest(200, 100));

			// Left of the invader
			Assert::IsFalse(invader.HitTest(100, 100));

			// Right of the invader
			Assert::IsTrue(invader.HitTest(400, 100));

			// Above the invader
			Assert::IsFalse(invader.HitTest(200, 200));

			// Below the invader
			Assert::IsFalse(invader.HitTest(200, 0));
		}

	};
}