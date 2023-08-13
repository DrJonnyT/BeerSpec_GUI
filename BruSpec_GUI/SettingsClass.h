#pragma once
using namespace System;

//Class to contain the settings that would be implemented when a scan is initiated
//During a scan the instrument will measure each colour in sequence with no mixed colours on the LED
ref class ScanSettings
{
private:
	int m_LEDR;
	int m_LEDG;
	int m_LEDB;
	int m_GainExtR;
	int m_GainExtG;
	int m_GainExtB;
	int m_GainScaR;
	int m_GainScaG;
	int m_GainScaB;
	int m_IntTimeExtR;
	int m_IntTimeExtG;
	int m_IntTimeExtB;
	int m_IntTimeScaR;
	int m_IntTimeScaG;
	int m_IntTimeScaB;
	int m_NumSamples;

public:

	//Default initialisation
	ScanSettings() {
		m_LEDR = 255;
		m_LEDG = 255;
		m_LEDB = 255;
		m_GainExtR = 60;
		m_GainExtG = 60;
		m_GainExtB = 60;
		m_GainScaR = 60;
		m_GainScaG = 60;
		m_GainScaB = 60;
		m_IntTimeExtR = 120;
		m_IntTimeExtG = 120;
		m_IntTimeExtB = 120;
		m_IntTimeScaR = 120;
		m_IntTimeScaG = 120;
		m_IntTimeScaB = 120;
		m_NumSamples = 1;
	}


	//Functions to get and set the variables
	//LED settings
	property int LEDR {
		int get() { return m_LEDR; }
		void set(int value) { m_LEDR = value; }
	}
	property int LEDG {
		int get() { return m_LEDG; }
		void set(int value) { m_LEDG = value; }
	}
	property int LEDB {
		int get() { return m_LEDB; }
		void set(int value) { m_LEDB = value; }
	}

	//Extinction gains
	property int GainExtR {
		int get() { return m_GainExtR; }
		void set(int value) { m_GainExtR = value; }
	}
	property int GainExtG {
		int get() { return m_GainExtG; }
		void set(int value) { m_GainExtG = value; }
	}
	property int GainExtB {
		int get() { return m_GainExtB; }
		void set(int value) { m_GainExtB = value; }
	}

	//Scattering gains
	property int GainScaR {
		int get() { return m_GainScaR; }
		void set(int value) { m_GainScaR = value; }
	}
	property int GainScaG {
		int get() { return m_GainScaG; }
		void set(int value) { m_GainScaG = value; }
	}
	property int GainScaB {
		int get() { return m_GainScaB; }
		void set(int value) { m_GainScaB = value; }
	}
	property int IntTimeExtR {
		int get() { return m_IntTimeExtR; }
		void set(int value) { m_IntTimeExtR = value; }
	}
	property int IntTimeExtG {
		int get() { return m_IntTimeExtG; }
		void set(int value) { m_IntTimeExtG = value; }
	}
	property int IntTimeExtB {
		int get() { return m_IntTimeExtB; }
		void set(int value) { m_IntTimeExtB = value; }
	}
	property int IntTimeScaR {
		int get() { return m_IntTimeScaR; }
		void set(int value) { m_IntTimeScaR = value; }
	}
	property int IntTimeScaG {
		int get() { return m_IntTimeScaG; }
		void set(int value) { m_IntTimeScaG = value; }
	}
	property int IntTimeScaB {
		int get() { return m_IntTimeScaB; }
		void set(int value) { m_IntTimeScaB = value; }
	}
	property int NumSamples {
		int get() { return m_NumSamples; }
		void set(int value) { m_NumSamples = value; }
	}

};


//Class to contain the settings that the instrument is currently set to
ref class InstrumentSettings
{
private:
	int m_LEDR;
	int m_LEDG;
	int m_LEDB;
	int m_GainExt;
	int m_GainSca;
	int m_IntTimeExt;
	int m_IntTimeSca;

public:

	//Default initialisation
	InstrumentSettings() {
		m_LEDR = 128;
		m_LEDG = 128;
		m_LEDB = 128;
		m_GainExt = 60;
		m_GainSca = 60;
		m_IntTimeExt = 120;
		m_IntTimeSca = 120;
	}


	//Functions to get and set the variables
	//LED settings
	property int LEDR {
		int get() { return m_LEDR; }
		void set(int value) { m_LEDR = value; }
	}
	property int LEDG {
		int get() { return m_LEDG; }
		void set(int value) { m_LEDG = value; }
	}
	property int LEDB {
		int get() { return m_LEDB; }
		void set(int value) { m_LEDB = value; }
	}
	property int GainExt {
		int get() { return m_GainExt; }
		void set(int value) { m_GainExt = value; }
	}
	property int GainSca {
		int get() { return m_GainSca; }
		void set(int value) { m_GainSca = value; }
	}
	property int IntTimeExt {
		int get() { return m_IntTimeExt; }
		void set(int value) { m_IntTimeExt = value; }
	}
	property int IntTimeSca {
		int get() { return m_IntTimeSca; }
		void set(int value) { m_IntTimeSca = value; }
	}

	//Make a serial command containing all the settings
	String^ SerialSet()
	{
		String^ serialOut = "#SETALL";
		serialOut = serialOut + " " + Convert::ToString(m_LEDR) + " " + Convert::ToString(m_LEDG) + " " + Convert::ToString(m_LEDB);
		serialOut = serialOut + " " + Convert::ToString(m_GainExt) + " " + Convert::ToString(m_GainSca);
		serialOut = serialOut + " " + Convert::ToString(m_IntTimeExt) + " " + Convert::ToString(m_IntTimeSca);
		serialOut = serialOut + "\n";
		return serialOut;
	}


};