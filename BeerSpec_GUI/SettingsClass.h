#pragma once

ref class SettingsClass
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
	//Initialisation
	SettingsClass(int LEDR,int LEDG,int LEDB,int GainExtR,int GainExtG,int GainExtB,int GainScaR,int GainScaG,int GainScaB,int NumSamples) {
		m_LEDR = LEDR;
		m_LEDG = LEDG;
		m_LEDB = LEDB;
		m_GainExtR = GainExtR;
		m_GainExtG = GainExtG;
		m_GainExtB = GainExtB;
		m_GainScaR = GainScaR;
		m_GainScaG = GainScaG;
		m_GainScaB = GainScaB;
		m_NumSamples = NumSamples;
	}
	//Default initialisation
	SettingsClass() {
		m_LEDR = 128;
		m_LEDG = 128;
		m_LEDB = 128;
		m_GainExtR = 1;
		m_GainExtG = 1;
		m_GainExtB = 1;
		m_GainScaR = 1;
		m_GainScaG = 1;
		m_GainScaB = 1;
		m_IntTimeExtR = 24;
		m_IntTimeExtG = 24;
		m_IntTimeExtB = 24;
		m_IntTimeScaR = 24;
		m_IntTimeScaG = 24;
		m_IntTimeScaB = 24;
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

