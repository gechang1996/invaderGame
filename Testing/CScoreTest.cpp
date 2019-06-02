#include "stdafx.h"
#include "CppUnitTest.h"
#include "Score.h"
#include "Game.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCScoreConstruct)
		{
			CGame game;
			CScore score(&game);

		}

		TEST_METHOD(TestCScoreIsZero)
		{
			CGame game;
			CScore score(&game);
			

			int msuScore = score.GetMSUScore();
			int invaderScore = score.GetInvaderScore();

			Assert::AreEqual(msuScore, 0);
			Assert::AreEqual(invaderScore, 0);
		}

		TEST_METHOD(TestCScoreUpdate)
		{
			CGame game;
			CScore score(&game);

			int msuScore = score.GetMSUScore();
			int invaderScore = score.GetInvaderScore();

			Assert::AreEqual(0, msuScore);
			Assert::AreEqual(0, invaderScore);

			score.UpdateMSUScore();
			score.UpdateInvaderScore();

			Assert::AreEqual(1, score.GetMSUScore());
			Assert::AreEqual(1, score.GetInvaderScore());
		}

	};
}