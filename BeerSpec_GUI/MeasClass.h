#pragma once


ref class MeasClass
{
private:
	//Sample time
	System::DateTime m_MeasTime;

	//Extinction mean and stdev
	System::Single m_MeasExtR;
	System::Single m_MeasExtG;
	System::Single m_MeasExtB;

	//Scattering mean and stdev
	System::Single m_MeasScaR;
	System::Single m_MeasScaG;
	System::Single m_MeasScaB;

	System::String^ m_Notes;

public:
	//Default initialisation
	MeasClass() {
		m_MeasTime = System::DateTime::Now;
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
	property System::DateTime MeasTime {
		System::DateTime get() { return m_MeasTime; }
		void set(System::DateTime value) { m_MeasTime = value; }
	}

	//Extinction measurements
	property System::Single MeasExtR {
		System::Single get() { return m_MeasExtR; }
		void set(System::Single value) { m_MeasExtR = value; }
	}
	property System::Single MeasExtG {
		System::Single get() { return m_MeasExtG; }
		void set(System::Single value) { m_MeasExtG = value; }
	}
	property System::Single MeasExtB {
		System::Single get() { return m_MeasExtB; }
		void set(System::Single value) { m_MeasExtB = value; }
	}

	//Scattering measurements
	property System::Single MeasScaR {
		System::Single get() { return m_MeasScaR; }
		void set(System::Single value) { m_MeasScaR = value; }
	}
	property System::Single MeasScaG {
		System::Single get() { return m_MeasScaG; }
		void set(System::Single value) { m_MeasScaG = value; }
	}
	property System::Single MeasScaB {
		System::Single get() { return m_MeasScaB; }
		void set(System::Single value) { m_MeasScaB = value; }
	}

	property System::String^ Notes {
		System::String^ get() { return m_Notes; }
		void set(System::String^ value) { m_Notes = value; }
	}


	

};
