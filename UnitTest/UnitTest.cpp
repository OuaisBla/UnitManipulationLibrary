#include "stdafx.h"


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;



void TestLength();
void TestForce();
void TestAcceleration();
void TestMass();
void TestVelocity();
void TestAngular();
void TestRunTimePerformance();
void TestPV_equals_NRT();
void TestElectric();
void TestTemperature();
void TestFrequency();
void TestSquareMeter();
void TestCubicMeter();
void TestSimplifier();

void InitializeSuffixes();


namespace UnitTest
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		[ClassInitialize()]
		static void MyClassInitialize(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ ) 
    {
      InitializeSuffixes();

      TestSimplifier();
    }
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestLength()
		{
      
      ::TestLength();

		}

    [TestMethod]
    void TestForce()
    {

      ::TestForce();

    }

    [TestMethod]
    void TestAcceleration()
    {

      ::TestAcceleration();

    }

    [TestMethod]
    void TestMass()
    {

      ::TestMass();

    }

    [TestMethod]
    void TestVelocity()
    {

      ::TestVelocity();

    }

    [TestMethod]
    void TestAngular()
    {

      ::TestAngular();

    }

    [TestMethod]
    void TestRunTimePerformance()
    {

      ::TestRunTimePerformance();

    }

    [TestMethod]
    void TestPV_equals_NRT()
    {

      ::TestPV_equals_NRT();

    }

    [TestMethod]
    void TestElectric()
    {

      ::TestElectric();

    }

    [TestMethod]
    void TestTemperature()
    {

      ::TestTemperature();

    }

    [TestMethod]
    void TestFrequency()
    {

      ::TestFrequency();

    }

    [TestMethod]
    void TestSquareMeter()
    {

      ::TestSquareMeter();

    }


    [TestMethod]
    void TestCubicMeter()
    {

      ::TestCubicMeter();

    }
    
	};
}
