#pragma once
#include <string>

#using <System.dll>

using namespace System;



ref class CSVSaver
{
private:
    System::String^ m_FilePath;
    EventHandler^ _FilePathChanged;

public:
    event EventHandler^ FilePathChanged
    {
        void add(EventHandler^ handler)
        {
            _FilePathChanged += handler;
        }
        void remove(EventHandler^ handler)
        {
            _FilePathChanged -= handler;
        }
    }

    property String^ FilePath
    {
        String^ get()
        {
            return m_FilePath;
        }
        void set(String^ value)
        {
            if (m_FilePath != value)
            {
                m_FilePath = value;
                OnFilePathChanged();
            }
        }
    }

protected:
    void OnFilePathChanged()
    {
        _FilePathChanged(this, EventArgs::Empty);
    }


public:
    //Default initialisation
    CSVSaver() {
        m_FilePath = "";
    }


    ////Functions to get and set the variables
    //property System::String^ FilePath {
    //	System::String^ get() { return m_FilePath; }
    //	void set(System::String^ value) { m_FilePath = value; }
    //}

};

