#pragma once
#include <chrono>

ref class MeasClass
{
private:
	//Sample time
	System::DateTime m_MeasTime;

	//Extinction mean and stdev
	System::Single m_MeasExtR;
	System::Single m_MeasExtG;
	System::Single m_MeasExtB;
	System::Single m_MeasExtR_std;
	System::Single m_MeasExtG_std;
	System::Single m_MeasExtB_std;

	//Scattering mean and stdev
	System::Single m_MeasScaR;
	System::Single m_MeasScaG;
	System::Single m_MeasScaB;
	System::Single m_MeasScaR_std;
	System::Single m_MeasScaG_std;
	System::Single m_MeasScaB_std;

public:
	//Default initialisation
	MeasClass() {
		m_MeasTime = System::DateTime::Now;
		m_MeasExtR = 0;
		m_MeasExtG = 0;
		m_MeasExtB = 0;
		m_MeasExtR_std = 0;
		m_MeasExtG_std = 0;
		m_MeasExtB_std = 0;
		m_MeasScaR = 0;
		m_MeasScaG = 0;
		m_MeasScaB = 0;
		m_MeasScaR_std = 0;
		m_MeasScaG_std = 0;
		m_MeasScaB_std = 0;
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

	property System::Single MeasExtR_std {
		System::Single get() { return m_MeasExtR_std; }
		void set(System::Single value) { m_MeasExtR_std = value; }
	}
	property System::Single MeasExtG_std {
		System::Single get() { return m_MeasExtG_std; }
		void set(System::Single value) { m_MeasExtG_std = value; }
	}
	property System::Single MeasExtB_std {
		System::Single get() { return m_MeasExtB_std; }
		void set(System::Single value) { m_MeasExtB_std = value; }
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

	property System::Single MeasScaR_std {
		System::Single get() { return m_MeasScaR_std; }
		void set(System::Single value) { m_MeasScaR_std = value; }
	}
	property System::Single MeasScaG_std {
		System::Single get() { return m_MeasScaG_std; }
		void set(System::Single value) { m_MeasScaG_std = value; }
	}
	property System::Single MeasScaB_std {
		System::Single get() { return m_MeasScaB_std; }
		void set(System::Single value) { m_MeasScaB_std = value; }
	}


	

};
