#pragma once
ref class SettingsClass
{
private:
	int m_LEDR;
	int m_LEDG;
	int m_LEDB;
	float m_GainExtR;
	float m_GainExtG;
	float m_GainExtB;
	float m_GainScaR;
	float m_GainScaG;
	float m_GainScaB;
	int m_NumSamples;

public:
	//Functions to get and set the variables
	int GetLEDR() const { return m_LEDR; }
	void SetLEDR(int value) { m_LEDR = value; }
	int GetLEDG() const { return m_LEDG; }
	void SetLEDG(int value) { m_LEDG = value; }
	int GetLEDB() const { return m_LEDB; }
	void SetLEDB(int value) { m_LEDB = value; }

	int GetGainExtR() const { return m_GainExtR; }
	void SetGainExtR(int value) { m_GainExtR = value; }
	int GetGainExtG() const { return m_GainExtG; }
	void SetGainExtG(int value) { m_GainExtG = value; }
	int GetGainExtB() const { return m_GainExtB; }
	void SetGainExtB(int value) { m_GainExtB = value; }

	int GetGainScaR() const { return m_GainScaR; }
	void SetGainScaR(int value) { m_GainScaR = value; }
	int GetGainScaG() const { return m_GainScaG; }
	void SetGainScaG(int value) { m_GainScaG = value; }
	int GetGainScaB() const { return m_GainScaB; }
	void SetGainScaB(int value) { m_GainScaB = value; }
	
	int GetNumSamples() const { return m_NumSamples; }
	void SetNumSamples(int value) { m_NumSamples = value; }

};

