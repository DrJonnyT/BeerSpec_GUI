#pragma once
#include <string>

#using <System.dll>
#include <fstream>
#include "SettingsClass.h"
#include "MeasClass.h"

using namespace System;
using namespace System::IO;




ref class CSVSaver
{
private:
    System::String^ m_FilePath;
    System::String^ m_FileName;
    System::String^ m_FolderPath;
    EventHandler^ _FolderPathChanged;

public:
    event EventHandler^ FolderPathChanged
    {
        void add(EventHandler^ handler)
        {
            _FolderPathChanged += handler;
        }
        void remove(EventHandler^ handler)
        {
            _FolderPathChanged -= handler;
        }
    }

    property String^ FolderPath
    {
        String^ get()
        {
            return m_FolderPath;
        }
        void set(String^ value)
        {
            if (m_FolderPath != value)
            {
                m_FolderPath = value;
                OnFolderPathChanged();
            }
        }
    }

protected:
    void OnFolderPathChanged()
    {
        _FolderPathChanged(this, EventArgs::Empty);
    }


public:
    //Default initialisation
    CSVSaver() {
        m_FilePath = "";
        m_FolderPath = "C:\\BeerSpec";
        //Make the filename the date/time
        String^ dateTimeString = DateTime::Now.ToString("yyyyMMdd-HHmmss");
        m_FileName = dateTimeString + "-BeerSpec.csv";
    }

    //Make a virtual member variable for the full file path
    property System::String^ FilePath
    {
        System::String^ get()
        {
            return m_FolderPath + "\\" + m_FileName;
        }
    }

    //Create a folder if it doesn't exist
    void CreateFolderIfNotExists(String^ folderPath)
    {
        if (!Directory::Exists(folderPath))
        {
            Directory::CreateDirectory(folderPath);
            Console::WriteLine("Folder created: " + folderPath);
        }
        else
        {
            Console::WriteLine("Folder already exists: " + folderPath);
        }
    }


    ////Functions to get and set the variables
    //property System::String^ FilePath {
    //	System::String^ get() { return m_FilePath; }
    //	void set(System::String^ value) { m_FilePath = value; }
    //}

    //Function to actually save the data
    void SaveDataToFile(SettingsClass^ settings, MeasClass^ meas)
    {
        //Check if the folder exists, and create it if not
        CreateFolderIfNotExists(m_FolderPath);

        // Check if the file exists
        bool fileExists = File::Exists(FilePath);

        // Open the file for appending or create a new file
        StreamWriter^ writer = gcnew StreamWriter(FilePath, fileExists);

        // Write the header row if the file is new
        if (!fileExists)
        {
            //Header for time and settings
            writer->Write("Time,LED_R,LED_G,LED_B,GainExtR,GainExtG,GainExtB,GainScaR,GainScaG,GainScaB");
            writer->Write("MeasExtR,MeasExtG,MeasExtB,MeasExtR_std,MeasExtG_std,MeasExtB_std,MeasScaR,MeasScaG,MeasScaB,MeasScaR_std,MeasScaG_std,MeasScaB_std,Notes");
            
            writer->WriteLine();
        }

        // Write the time and settings
        writer->Write(meas->MeasTime + ",");
        writer->Write(settings->LEDR.ToString() + ",");
        writer->Write(settings->LEDG.ToString() + ",");
        writer->Write(settings->LEDB.ToString() + ",");
        writer->Write(settings->GainExtR.ToString() + ",");
        writer->Write(settings->GainExtG.ToString() + ",");
        writer->Write(settings->GainExtB.ToString() + ",");
        writer->Write(settings->GainScaR.ToString() + ",");
        writer->Write(settings->GainScaG.ToString() + ",");
        writer->Write(settings->GainScaB.ToString() + ",");
        //Write the measured data
        writer->Write(meas->MeasExtR.ToString() + ",");
        writer->Write(meas->MeasExtG.ToString() + ",");
        writer->Write(meas->MeasExtB.ToString() + ",");
        writer->Write(meas->MeasExtR_std.ToString() + ",");
        writer->Write(meas->MeasExtG_std.ToString() + ",");
        writer->Write(meas->MeasExtB_std.ToString() + ",");
        writer->Write(meas->MeasScaR.ToString() + ",");
        writer->Write(meas->MeasScaG.ToString() + ",");
        writer->Write(meas->MeasScaB.ToString() + ",");
        writer->Write(meas->MeasScaR_std.ToString() + ",");
        writer->Write(meas->MeasScaG_std.ToString() + ",");
        writer->Write(meas->MeasScaB_std.ToString() + ",");
        writer->Write("\"" + meas->Notes + "\"");

        writer->WriteLine();

        // Close the file
        writer->Close();
    }

};

