#pragma once
#include "CppCLR_Utils.h"
#include "MeasClass.h"
#include "SettingsClass.h"

#ifdef _DEBUG // to make Unittests only available in debug mode 
#include "SimpleUnitTests.h" // comment out to turn off Unittests
#endif


namespace N_rk1_Utils_demo
{ // These two functions are only short demos how to use
  // CppCLR_Utils.h and SimpleUnitTests.h. They are 
  // never called, you can remove them.

  void CppCLRUtils_demo()
  {
    // A short demo, how CppCLRUtils can be used. 

    // test string conversions 
    // from std::string to String::String and vice versa

    std::string s = "std::string";
    System::String^ S = rk1::to_String(s);
    s = rk1::to_string(S);

    // If you call in Form1(void), after InitializeComponent();
    //   rk1::StaticTextBox::Init(out_textBox);
    // you can write to out_textBox without have to pass the out_textBox
    //   rk1::StaticTextBox::WriteLine("Write to out_textBox");
  }

  int plus_1(int x) // a very simple function to illustrate unittests
  {
    return x + 1;
  }

  void SimpleUnitTests_demo()
  {
#ifdef SIMPLEUNITTESTS_H__ // this macro is defined by #include "SimpleUnitTests.h"
      // If you call all unittest functions after 
      //    #ifdef SIMPLEUNITTESTS_H__
      // removing 
      //    #include "SimpleUnitTests.h"
      // disables all unittests without having to remove or comment them out.
      rk1::OpenConsole(); // to display the unittest results in a 
      //                     separate console window
      rk1::Assert::Init("SimpleUnitTests_demo");

      //MeasClass unit tests
      //Currently can't test MeasClass.MeasTime as it's a System::String and the test framework can only do std::string
      MeasClass meas;
      meas.MeasExtR = 100;
      meas.MeasExtG = 101;
      meas.MeasExtB = 102;
      meas.MeasScaR = 200;
      meas.MeasScaG = 201;
      meas.MeasScaB = 202;
      rk1::Assert::AreEqual(meas.MeasExtR, 100, "test case: meas.MeasExtR, 100");
      rk1::Assert::AreEqual(meas.MeasExtG, 101, "test case: meas.MeasExtG, 101");
      rk1::Assert::AreEqual(meas.MeasExtB, 102, "test case: meas.MeasExtB, 102");
      rk1::Assert::AreEqual(meas.MeasScaR, 200, "test case: meas.MeasScaR, 200");
      rk1::Assert::AreEqual(meas.MeasScaG, 201, "test case: meas.MeasScaG, 201");
      rk1::Assert::AreEqual(meas.MeasScaB, 202, "test case: meas.MeasScaB, 202");
      
      //InstrumentSettings unit tests
      InstrumentSettings instrumentSettings;
      instrumentSettings.LEDR = 10;
      instrumentSettings.LEDG = 20;
      instrumentSettings.LEDB = 30;
      instrumentSettings.GainExt = 4;
      instrumentSettings.GainSca = 16;
      instrumentSettings.IntTimeExt = 240;
      instrumentSettings.IntTimeSca = 480;
      rk1::Assert::AreEqual(instrumentSettings.LEDR, 10, "test case: instrumentSettings.LEDR, 10");
      rk1::Assert::AreEqual(instrumentSettings.LEDG, 20, "test case: instrumentSettings.LEDG, 20");
      rk1::Assert::AreEqual(instrumentSettings.LEDB, 30, "test case: instrumentSettings.LEDB, 30");
      rk1::Assert::AreEqual(instrumentSettings.GainExt, 4, "test case: instrumentSettings.GainExt, 4");
      rk1::Assert::AreEqual(instrumentSettings.GainSca, 16, "test case: instrumentSettings.GainSca, 16");
      rk1::Assert::AreEqual(instrumentSettings.IntTimeExt, 240, "test case: instrumentSettings.IntTimeExt, 240");
      rk1::Assert::AreEqual(instrumentSettings.IntTimeSca, 480, "test case: instrumentSettings.IntTimeSca, 480");

      //ScanSettings unit tests
      ScanSettings scanSettings;
      scanSettings.LEDR = 10;
      scanSettings.LEDG = 20;
      scanSettings.LEDB = 30;
      scanSettings.GainExtR = 1;
      scanSettings.GainExtG = 4;
      scanSettings.GainExtB = 16;
      scanSettings.GainScaR = 60;
      scanSettings.GainScaG = 16;
      scanSettings.GainScaB = 1;
      scanSettings.IntTimeExtR = 1;
      scanSettings.IntTimeExtG = 4;
      scanSettings.IntTimeExtB = 16;
      scanSettings.IntTimeScaR = 60;
      scanSettings.IntTimeScaG = 16;
      scanSettings.IntTimeScaB = 1;
      rk1::Assert::AreEqual(scanSettings.LEDR, 10, "test case: scanSettings.LEDR, 10");
      rk1::Assert::AreEqual(scanSettings.LEDG, 20, "test case: scanSettings.LEDG, 20");
      rk1::Assert::AreEqual(scanSettings.LEDB, 30, "test case: scanSettings.LEDB, 30");
      rk1::Assert::AreEqual(scanSettings.GainExtR, 1, "test case: scanSettings.GainExtR, 1");
      rk1::Assert::AreEqual(scanSettings.GainExtG, 4, "test case: scanSettings.GainExtG, 4");
      rk1::Assert::AreEqual(scanSettings.GainExtB, 16, "test case: scanSettings.GainExtB, 16");
      rk1::Assert::AreEqual(scanSettings.GainScaR, 60, "test case: scanSettings.GainScaR, 60");
      rk1::Assert::AreEqual(scanSettings.GainScaG, 16, "test case: scanSettings.GainScaG, 16");
      rk1::Assert::AreEqual(scanSettings.GainScaB, 1, "test case: scanSettings.GainScaB, 1");
      rk1::Assert::AreEqual(scanSettings.IntTimeExtR, 1, "test case: scanSettings.IntTimeExtR, 1");
      rk1::Assert::AreEqual(scanSettings.IntTimeExtG, 4, "test case: scanSettings.IntTimeExtG, 4");
      rk1::Assert::AreEqual(scanSettings.IntTimeExtB, 16, "test case: scanSettings.IntTimeExtB, 16");
      rk1::Assert::AreEqual(scanSettings.IntTimeScaR, 60, "test case: scanSettings.IntTimeScaR, 60");
      rk1::Assert::AreEqual(scanSettings.IntTimeScaG, 16, "test case: scanSettings.IntTimeScaG, 16");
      rk1::Assert::AreEqual(scanSettings.IntTimeScaB, 1, "test case: scanSettings.IntTimeScaB, 1");

      // reports how many tests failed
      rk1::Assert::Summary();

#endif // SIMPLEUNITTESTS_H__ 
  }

  void execute()
  {
    N_rk1_Utils_demo::CppCLRUtils_demo();
    N_rk1_Utils_demo::SimpleUnitTests_demo();
  }
}
