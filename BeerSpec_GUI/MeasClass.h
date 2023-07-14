#pragma once
using namespace System;

ref class MeasClass
{
private:
	//Sample time
	//DateTime m_MeasTime;
	String^ m_MeasTime;

	//Extinction mean and stdev
	int m_MeasExtR;
	int m_MeasExtG;
	int m_MeasExtB;

	//Scattering mean and stdev
	int m_MeasScaR;
	int m_MeasScaG;
	int m_MeasScaB;

	String^ m_Notes;

public:
	//Default initialisation
	MeasClass() {
		//m_MeasTime = DateTime::Now;
		m_MeasTime = DateTime::Now.ToString();
		m_MeasExtR = 0;
		m_MeasExtG = 0;
		m_MeasExtB = 0;
		m_MeasScaR = 0;
		m_MeasScaG = 0;
		m_MeasScaB = 0;
		m_Notes = "";
	}


	//Functions to get and set the variables
	//Time
	//property DateTime MeasTime {
	//	DateTime get() { return m_MeasTime; }
	//	void set(DateTime value) { m_MeasTime = value; }
	//}
	property String^ MeasTime {
		String^ get() { return m_MeasTime; }
		void set(String^ value) { m_MeasTime = value; }
	}

	//Extinction measurements
	property int MeasExtR {
		int get() { return m_MeasExtR; }
		void set(int value) { m_MeasExtR = value; }
	}
	property int MeasExtG {
		int get() { return m_MeasExtG; }
		void set(int value) { m_MeasExtG = value; }
	}
	property int MeasExtB {
		int get() { return m_MeasExtB; }
		void set(int value) { m_MeasExtB = value; }
	}

	//Scattering measurements
	property int MeasScaR {
		int get() { return m_MeasScaR; }
		void set(int value) { m_MeasScaR = value; }
	}
	property int MeasScaG {
		int get() { return m_MeasScaG; }
		void set(int value) { m_MeasScaG = value; }
	}
	property int MeasScaB {
		int get() { return m_MeasScaB; }
		void set(int value) { m_MeasScaB = value; }
	}

	property String^ Notes {
		String^ get() { return m_Notes; }
		void set(String^ value) { m_Notes = value; }
	}

	//Read the "@EXT = R G B" command from serial
	void ReadExtFromString(String^ input)
	{
		String^ prefix = "@EXT = ";
		if (input->StartsWith(prefix))
		{
			String^ trimmedInput = input->Substring(prefix->Length);
			array<String^>^ substrings = trimmedInput->Split(' ');

			if (substrings->Length >= 3)
			{
				if (Int32::TryParse(substrings[0], m_MeasExtR))
				{
					if (Int32::TryParse(substrings[1], m_MeasExtG))
					{
						if (Int32::TryParse(substrings[2], m_MeasExtB))
						{
							// All three integers successfully parsed
							return;
						}
					}
				}
			}
		}

		// Handle parsing failure if needed, set all to zero
		m_MeasExtR = -1;
		m_MeasExtG = -1;
		m_MeasExtB = -1;
	}

	//Read the "@SCA = R G B" command from serial
	void ReadScaFromString(String^ input)
	{
		String^ prefix = "@SCA = ";
		if (input->StartsWith(prefix))
		{
			String^ trimmedInput = input->Substring(prefix->Length);
			array<String^>^ substrings = trimmedInput->Split(' ');

			if (substrings->Length >= 3)
			{
				if (Int32::TryParse(substrings[0], m_MeasScaR))
				{
					if (Int32::TryParse(substrings[1], m_MeasScaG))
					{
						if (Int32::TryParse(substrings[2], m_MeasScaB))
						{
							// All three integers successfully parsed
							return;
						}
					}
				}
			}
		}

		// Handle parsing failure if needed, set all to zero
		m_MeasScaR = -1;
		m_MeasScaG = -1;
		m_MeasScaB = -1;
	}
	

};
