#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

//#include "Header1.h"
//#include "Header2.h"
#include "SettingsClass.h"
#include "MeasClass.h"
#include "CSVSaver.h"
#include "SerialManager.h"



namespace CppCLRWinFormsProject {

  //using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::IO;
  using namespace System::IO::Ports;


  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  
  private:
      //A class to handle saving to CSV
      CSVSaver^ csvSaver;
      //A class to hold the settings for scanning different wavelengths
      ScanSettings^ scanSettings;
      //A class to hold the settings the instrument is currently set to
      InstrumentSettings^ instrumentSettings;
      //A class to deal with measurements
      MeasClass^ meas;
      //A class to deal with serial communication
      SerialManager^ serialManager1;

      //Scan settings part of the form
      System::Windows::Forms::Label^ labScanSettings;
      System::Windows::Forms::Label^ labScanLED;
      System::Windows::Forms::NumericUpDown^ nudScanLEDR;
      System::Windows::Forms::NumericUpDown^ nudScanLEDG;
      System::Windows::Forms::NumericUpDown^ nudScanLEDB;
      System::Windows::Forms::Label^ labGainExt;
      System::Windows::Forms::ComboBox^ cboxScanGainExtR;
      System::Windows::Forms::ComboBox^ cboxScanGainExtG;
      System::Windows::Forms::ComboBox^ cboxScanGainExtB;
      System::Windows::Forms::Label^ labGainSca;      
      System::Windows::Forms::ComboBox^ cboxScanGainScaR;
      System::Windows::Forms::ComboBox^ cboxScanGainScaG;
      System::Windows::Forms::ComboBox^ cboxScanGainScaB;      
      System::Windows::Forms::Label^ labIntTimeExt;
      System::Windows::Forms::ComboBox^ cboxScanIntTimeExtR;
      System::Windows::Forms::ComboBox^ cboxScanIntTimeExtG;
      System::Windows::Forms::ComboBox^ cboxScanIntTimeExtB;
      System::Windows::Forms::Label^ labIntTimeSca;
      System::Windows::Forms::ComboBox^ cboxScanIntTimeScaR;
      System::Windows::Forms::ComboBox^ cboxScanIntTimeScaG;
      System::Windows::Forms::ComboBox^ cboxScanIntTimeScaB;
      System::Windows::Forms::Label^ labNumSamples;
      System::Windows::Forms::NumericUpDown^ nudNumSamples;

      //Manual settings part of the form
      System::Windows::Forms::Label^ labManualSettings;
      System::Windows::Forms::Label^ labManualLED;
      System::Windows::Forms::NumericUpDown^ nudManualLEDB;
      System::Windows::Forms::NumericUpDown^ nudManualLEDG;
      System::Windows::Forms::NumericUpDown^ nudManualLEDR;
      System::Windows::Forms::Label^ labManualGainExt;
      System::Windows::Forms::ComboBox^ cboxManualGainExt;
      System::Windows::Forms::Label^ labManualGainSca;
      System::Windows::Forms::ComboBox^ cboxManualGainSca;
      System::Windows::Forms::Label^ labManualIntTimeExt;
      System::Windows::Forms::ComboBox^ cboxManualIntTimeExt;
      System::Windows::Forms::Label^ labManualIntTimeSca;
      System::Windows::Forms::ComboBox^ cboxManualIntTimeSca;
      System::Windows::Forms::Button^ btnSet;
      

      //Serial part of the form
      System::Windows::Forms::Label^ labSerial;
      System::Windows::Forms::Label^ labCOMPort;
      System::Windows::Forms::Label^ labSerialSent;
      System::Windows::Forms::Label^ labSerialReceived;
      System::Windows::Forms::ComboBox^ cboxCOMPort;
      System::Windows::Forms::RichTextBox^ rtbSerialReceived;
      System::Windows::Forms::RichTextBox^ rtbSerialSent;


      //Measurements part of the form
      System::Windows::Forms::Label^ labMeasurements;
      System::Windows::Forms::Label^ labMeasTime;
      System::Windows::Forms::TextBox^ tbMeasTime;
      System::Windows::Forms::Label^ LabMeasExt;
      System::Windows::Forms::TextBox^ tbMeasExtR;
      System::Windows::Forms::TextBox^ tbMeasExtG;
      System::Windows::Forms::TextBox^ tbMeasExtB;
      System::Windows::Forms::Label^ labMeasSca;
      System::Windows::Forms::TextBox^ tbMeasScaB;
      System::Windows::Forms::TextBox^ tbMeasScaG;
      System::Windows::Forms::TextBox^ tbMeasScaR;
      System::Windows::Forms::Label^ labNotes;
      System::Windows::Forms::TextBox^ tbNotes;
      System::Windows::Forms::Label^ labFolderPath;
      System::Windows::Forms::TextBox^ tbFolderPath;
      System::Windows::Forms::Button^ btnManualMsmt;
      System::Windows::Forms::Button^ btnScan;  

      System::Windows::Forms::Button^ btnSave;
  private: System::Windows::Forms::CheckBox^ checkboxAutoSave;
  private: System::Windows::Forms::Button^ btnGainCal;
  private: System::Windows::Forms::Button^ btnIntTimeCal;
  private: System::Windows::Forms::Button^ btnLEDCal;







  private: System::ComponentModel::IContainer^ components;
  



         /// <summary>
         /// Required designer variable.
         /// </summary>



  public:
    Form1(void)
    {
      InitializeComponent();

      //Find COM ports
      findPorts();

      //Open the serial port manager as a dummy
      serialManager1 = gcnew SerialManager();
      
      //ScanSettings object to store instrument scan settings
      scanSettings = gcnew ScanSettings;

      //InstrumentSettings object to store current instrument settings
      instrumentSettings = gcnew InstrumentSettings;

      //Measurements object to store measurements
      meas = gcnew MeasClass;   

      //CSVSaver object
      //CSVSaver^ csvSaver = gcnew CSVSaver;
      csvSaver = gcnew CSVSaver();

     


      //Bind the TextBox control to the scanSettings properties
      nudScanLEDR->DataBindings->Add("Value", scanSettings, "LEDR");
      nudScanLEDG->DataBindings->Add("Value", scanSettings, "LEDG");
      nudScanLEDB->DataBindings->Add("Value", scanSettings, "LEDB");   
      nudNumSamples->DataBindings->Add("Value", scanSettings, "NumSamples");


      tbMeasTime->DataBindings->Add("Text", meas, "MeasTime");
      tbNotes->DataBindings->Add("Text", meas, "Notes");

      //Bind the file path to the csvSaver object
      tbFolderPath->DataBindings->Add("Text", csvSaver, "FolderPath");
      csvSaver->FolderPathChanged += gcnew EventHandler(this, &Form1::Update_tbFolderPath);

      

      //Set options for Gain boxes
      cboxScanGainExtR->Items->Add(1);
      cboxScanGainExtR->Items->Add(4);
      cboxScanGainExtR->Items->Add(16);
      cboxScanGainExtR->Items->Add(60);
      cboxScanGainExtR->SelectedItem = 60;
      cboxScanGainExtG->Items->Add(1);
      cboxScanGainExtG->Items->Add(4);
      cboxScanGainExtG->Items->Add(16);
      cboxScanGainExtG->Items->Add(60);
      cboxScanGainExtG->SelectedItem = 60;
      cboxScanGainExtB->Items->Add(1);
      cboxScanGainExtB->Items->Add(4);
      cboxScanGainExtB->Items->Add(16);
      cboxScanGainExtB->Items->Add(60);
      cboxScanGainExtB->SelectedItem = 60;
      cboxScanGainScaR->Items->Add(1);
      cboxScanGainScaR->Items->Add(4);
      cboxScanGainScaR->Items->Add(16);
      cboxScanGainScaR->Items->Add(60);
      cboxScanGainScaR->SelectedItem = 60;
      cboxScanGainScaG->Items->Add(1);
      cboxScanGainScaG->Items->Add(4);
      cboxScanGainScaG->Items->Add(16);
      cboxScanGainScaG->Items->Add(60);
      cboxScanGainScaG->SelectedItem = 60;
      cboxScanGainScaB->Items->Add(1);
      cboxScanGainScaB->Items->Add(4);
      cboxScanGainScaB->Items->Add(16);
      cboxScanGainScaB->Items->Add(60);
      cboxScanGainScaB->SelectedItem = 60;
      cboxManualGainExt->Items->Add(1);
      cboxManualGainExt->Items->Add(4);
      cboxManualGainExt->Items->Add(16);
      cboxManualGainExt->Items->Add(60);
      cboxManualGainExt->SelectedItem = 60;
      cboxManualGainSca->Items->Add(1);
      cboxManualGainSca->Items->Add(4);
      cboxManualGainSca->Items->Add(16);
      cboxManualGainSca->Items->Add(60);
      cboxManualGainSca->SelectedItem = 60;


      //Set options for integration time boxes
      cboxScanIntTimeExtR->Items->Add(24);
      cboxScanIntTimeExtR->Items->Add(60);
      cboxScanIntTimeExtR->Items->Add(120);
      cboxScanIntTimeExtR->Items->Add(240);
      cboxScanIntTimeExtR->Items->Add(480);
      cboxScanIntTimeExtR->SelectedItem = 120;
      cboxScanIntTimeExtG->Items->Add(24);
      cboxScanIntTimeExtG->Items->Add(60);
      cboxScanIntTimeExtG->Items->Add(120);
      cboxScanIntTimeExtG->Items->Add(240);
      cboxScanIntTimeExtG->Items->Add(480);
      cboxScanIntTimeExtG->SelectedItem = 120;
      cboxScanIntTimeExtB->Items->Add(24);
      cboxScanIntTimeExtB->Items->Add(60);
      cboxScanIntTimeExtB->Items->Add(120);
      cboxScanIntTimeExtB->Items->Add(240);
      cboxScanIntTimeExtB->Items->Add(480);
      cboxScanIntTimeExtB->SelectedItem = 120;
      cboxScanIntTimeScaR->Items->Add(24);
      cboxScanIntTimeScaR->Items->Add(60);
      cboxScanIntTimeScaR->Items->Add(120);
      cboxScanIntTimeScaR->Items->Add(240);
      cboxScanIntTimeScaR->Items->Add(480);
      cboxScanIntTimeScaR->SelectedItem = 120;
      cboxScanIntTimeScaG->Items->Add(24);
      cboxScanIntTimeScaG->Items->Add(60);
      cboxScanIntTimeScaG->Items->Add(120);
      cboxScanIntTimeScaG->Items->Add(240);
      cboxScanIntTimeScaG->Items->Add(480);
      cboxScanIntTimeScaG->SelectedItem = 120;
      cboxScanIntTimeScaB->Items->Add(24);
      cboxScanIntTimeScaB->Items->Add(60);
      cboxScanIntTimeScaB->Items->Add(120);
      cboxScanIntTimeScaB->Items->Add(240);
      cboxScanIntTimeScaB->Items->Add(480);
      cboxScanIntTimeScaB->SelectedItem = 120;
      cboxManualIntTimeExt->Items->Add(24);
      cboxManualIntTimeExt->Items->Add(60);
      cboxManualIntTimeExt->Items->Add(120);
      cboxManualIntTimeExt->Items->Add(240);
      cboxManualIntTimeExt->Items->Add(480);
      cboxManualIntTimeExt->SelectedItem = 120;
      cboxManualIntTimeSca->Items->Add(24);
      cboxManualIntTimeSca->Items->Add(60);
      cboxManualIntTimeSca->Items->Add(120);
      cboxManualIntTimeSca->Items->Add(240);
      cboxManualIntTimeSca->Items->Add(480);
      cboxManualIntTimeSca->SelectedItem = 120;

      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }



 








#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->labScanSettings = (gcnew System::Windows::Forms::Label());
        this->labScanLED = (gcnew System::Windows::Forms::Label());
        this->labGainExt = (gcnew System::Windows::Forms::Label());
        this->labGainSca = (gcnew System::Windows::Forms::Label());
        this->labNumSamples = (gcnew System::Windows::Forms::Label());
        this->labMeasurements = (gcnew System::Windows::Forms::Label());
        this->btnScan = (gcnew System::Windows::Forms::Button());
        this->LabMeasExt = (gcnew System::Windows::Forms::Label());
        this->labMeasSca = (gcnew System::Windows::Forms::Label());
        this->tbMeasTime = (gcnew System::Windows::Forms::TextBox());
        this->labMeasTime = (gcnew System::Windows::Forms::Label());
        this->tbNotes = (gcnew System::Windows::Forms::TextBox());
        this->labNotes = (gcnew System::Windows::Forms::Label());
        this->nudScanLEDR = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanLEDG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanLEDB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudNumSamples = (gcnew System::Windows::Forms::NumericUpDown());
        this->tbFolderPath = (gcnew System::Windows::Forms::TextBox());
        this->btnSave = (gcnew System::Windows::Forms::Button());
        this->labFolderPath = (gcnew System::Windows::Forms::Label());
        this->cboxCOMPort = (gcnew System::Windows::Forms::ComboBox());
        this->labCOMPort = (gcnew System::Windows::Forms::Label());
        this->labIntTimeExt = (gcnew System::Windows::Forms::Label());
        this->cboxScanIntTimeExtR = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeExtG = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeExtB = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeScaB = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeScaG = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeScaR = (gcnew System::Windows::Forms::ComboBox());
        this->labIntTimeSca = (gcnew System::Windows::Forms::Label());
        this->rtbSerialReceived = (gcnew System::Windows::Forms::RichTextBox());
        this->labSerial = (gcnew System::Windows::Forms::Label());
        this->rtbSerialSent = (gcnew System::Windows::Forms::RichTextBox());
        this->labSerialSent = (gcnew System::Windows::Forms::Label());
        this->labSerialReceived = (gcnew System::Windows::Forms::Label());
        this->labManualIntTimeSca = (gcnew System::Windows::Forms::Label());
        this->cboxManualIntTimeSca = (gcnew System::Windows::Forms::ComboBox());
        this->cboxManualIntTimeExt = (gcnew System::Windows::Forms::ComboBox());
        this->labManualIntTimeExt = (gcnew System::Windows::Forms::Label());
        this->nudManualLEDB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudManualLEDG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudManualLEDR = (gcnew System::Windows::Forms::NumericUpDown());
        this->labManualGainSca = (gcnew System::Windows::Forms::Label());
        this->labManualGainExt = (gcnew System::Windows::Forms::Label());
        this->labManualLED = (gcnew System::Windows::Forms::Label());
        this->labManualSettings = (gcnew System::Windows::Forms::Label());
        this->cboxManualGainSca = (gcnew System::Windows::Forms::ComboBox());
        this->cboxManualGainExt = (gcnew System::Windows::Forms::ComboBox());
        this->btnSet = (gcnew System::Windows::Forms::Button());
        this->btnManualMsmt = (gcnew System::Windows::Forms::Button());
        this->cboxScanGainScaB = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanGainScaG = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanGainScaR = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanGainExtB = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanGainExtG = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanGainExtR = (gcnew System::Windows::Forms::ComboBox());
        this->tbMeasExtR = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasExtG = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasExtB = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasScaB = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasScaG = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasScaR = (gcnew System::Windows::Forms::TextBox());
        this->checkboxAutoSave = (gcnew System::Windows::Forms::CheckBox());
        this->btnGainCal = (gcnew System::Windows::Forms::Button());
        this->btnIntTimeCal = (gcnew System::Windows::Forms::Button());
        this->btnLEDCal = (gcnew System::Windows::Forms::Button());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNumSamples))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudManualLEDB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudManualLEDG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudManualLEDR))->BeginInit();
        this->SuspendLayout();
        // 
        // labScanSettings
        // 
        this->labScanSettings->AutoSize = true;
        this->labScanSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labScanSettings->Location = System::Drawing::Point(12, 9);
        this->labScanSettings->Name = L"labScanSettings";
        this->labScanSettings->Size = System::Drawing::Size(221, 24);
        this->labScanSettings->TabIndex = 5;
        this->labScanSettings->Text = L"RGB SCAN SETTINGS";
        this->labScanSettings->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
        // 
        // labScanLED
        // 
        this->labScanLED->AutoSize = true;
        this->labScanLED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labScanLED->Location = System::Drawing::Point(12, 41);
        this->labScanLED->Name = L"labScanLED";
        this->labScanLED->Size = System::Drawing::Size(44, 20);
        this->labScanLED->TabIndex = 12;
        this->labScanLED->Text = L"LED";
        // 
        // labGainExt
        // 
        this->labGainExt->AutoSize = true;
        this->labGainExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labGainExt->Location = System::Drawing::Point(12, 71);
        this->labGainExt->Name = L"labGainExt";
        this->labGainExt->Size = System::Drawing::Size(78, 20);
        this->labGainExt->TabIndex = 19;
        this->labGainExt->Text = L"Gain Ext";
        // 
        // labGainSca
        // 
        this->labGainSca->AutoSize = true;
        this->labGainSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labGainSca->Location = System::Drawing::Point(12, 100);
        this->labGainSca->Name = L"labGainSca";
        this->labGainSca->Size = System::Drawing::Size(83, 20);
        this->labGainSca->TabIndex = 23;
        this->labGainSca->Text = L"Gain Sca";
        // 
        // labNumSamples
        // 
        this->labNumSamples->AutoSize = true;
        this->labNumSamples->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labNumSamples->Location = System::Drawing::Point(12, 185);
        this->labNumSamples->Name = L"labNumSamples";
        this->labNumSamples->Size = System::Drawing::Size(90, 20);
        this->labNumSamples->TabIndex = 24;
        this->labNumSamples->Text = L"n samples";
        this->labNumSamples->Click += gcnew System::EventHandler(this, &Form1::labNumSamples_Click);
        // 
        // labMeasurements
        // 
        this->labMeasurements->AutoSize = true;
        this->labMeasurements->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labMeasurements->Location = System::Drawing::Point(12, 399);
        this->labMeasurements->Name = L"labMeasurements";
        this->labMeasurements->Size = System::Drawing::Size(182, 24);
        this->labMeasurements->TabIndex = 27;
        this->labMeasurements->Text = L"MEASUREMENTS";
        // 
        // btnScan
        // 
        this->btnScan->BackColor = System::Drawing::Color::Khaki;
        this->btnScan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnScan->Location = System::Drawing::Point(411, 397);
        this->btnScan->Name = L"btnScan";
        this->btnScan->Size = System::Drawing::Size(91, 59);
        this->btnScan->TabIndex = 31;
        this->btnScan->Text = L"RGB\r\nSCAN";
        this->btnScan->UseVisualStyleBackColor = false;
        this->btnScan->Click += gcnew System::EventHandler(this, &Form1::btnScan_Click);
        // 
        // LabMeasExt
        // 
        this->LabMeasExt->AutoSize = true;
        this->LabMeasExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->LabMeasExt->Location = System::Drawing::Point(12, 456);
        this->LabMeasExt->Name = L"LabMeasExt";
        this->LabMeasExt->Size = System::Drawing::Size(35, 20);
        this->LabMeasExt->TabIndex = 36;
        this->LabMeasExt->Text = L"Ext";
        // 
        // labMeasSca
        // 
        this->labMeasSca->AutoSize = true;
        this->labMeasSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labMeasSca->Location = System::Drawing::Point(12, 484);
        this->labMeasSca->Name = L"labMeasSca";
        this->labMeasSca->Size = System::Drawing::Size(40, 20);
        this->labMeasSca->TabIndex = 40;
        this->labMeasSca->Text = L"Sca";
        // 
        // tbMeasTime
        // 
        this->tbMeasTime->BackColor = System::Drawing::SystemColors::Window;
        this->tbMeasTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasTime->Location = System::Drawing::Point(85, 426);
        this->tbMeasTime->Name = L"tbMeasTime";
        this->tbMeasTime->ReadOnly = true;
        this->tbMeasTime->Size = System::Drawing::Size(142, 22);
        this->tbMeasTime->TabIndex = 42;
        // 
        // labMeasTime
        // 
        this->labMeasTime->AutoSize = true;
        this->labMeasTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labMeasTime->Location = System::Drawing::Point(12, 425);
        this->labMeasTime->Name = L"labMeasTime";
        this->labMeasTime->Size = System::Drawing::Size(47, 20);
        this->labMeasTime->TabIndex = 41;
        this->labMeasTime->Text = L"Time";
        // 
        // tbNotes
        // 
        this->tbNotes->Location = System::Drawing::Point(84, 512);
        this->tbNotes->Name = L"tbNotes";
        this->tbNotes->Size = System::Drawing::Size(310, 20);
        this->tbNotes->TabIndex = 43;
        this->tbNotes->TextChanged += gcnew System::EventHandler(this, &Form1::tbNotes_TextChanged);
        // 
        // labNotes
        // 
        this->labNotes->AutoSize = true;
        this->labNotes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labNotes->Location = System::Drawing::Point(12, 510);
        this->labNotes->Name = L"labNotes";
        this->labNotes->Size = System::Drawing::Size(61, 20);
        this->labNotes->TabIndex = 44;
        this->labNotes->Text = L"Notes:";
        // 
        // nudScanLEDR
        // 
        this->nudScanLEDR->BackColor = System::Drawing::Color::LightCoral;
        this->nudScanLEDR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanLEDR->Location = System::Drawing::Point(111, 39);
        this->nudScanLEDR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudScanLEDR->Name = L"nudScanLEDR";
        this->nudScanLEDR->Size = System::Drawing::Size(57, 22);
        this->nudScanLEDR->TabIndex = 45;
        this->nudScanLEDR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        this->nudScanLEDR->ValueChanged += gcnew System::EventHandler(this, &Form1::nudScanLEDR_ValueChanged);
        // 
        // nudScanLEDG
        // 
        this->nudScanLEDG->BackColor = System::Drawing::Color::LightGreen;
        this->nudScanLEDG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanLEDG->Location = System::Drawing::Point(196, 39);
        this->nudScanLEDG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudScanLEDG->Name = L"nudScanLEDG";
        this->nudScanLEDG->Size = System::Drawing::Size(57, 22);
        this->nudScanLEDG->TabIndex = 46;
        this->nudScanLEDG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudScanLEDB
        // 
        this->nudScanLEDB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudScanLEDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanLEDB->Location = System::Drawing::Point(276, 39);
        this->nudScanLEDB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudScanLEDB->Name = L"nudScanLEDB";
        this->nudScanLEDB->Size = System::Drawing::Size(57, 22);
        this->nudScanLEDB->TabIndex = 47;
        this->nudScanLEDB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudNumSamples
        // 
        this->nudNumSamples->BackColor = System::Drawing::Color::White;
        this->nudNumSamples->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudNumSamples->Location = System::Drawing::Point(111, 185);
        this->nudNumSamples->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        this->nudNumSamples->Name = L"nudNumSamples";
        this->nudNumSamples->Size = System::Drawing::Size(57, 22);
        this->nudNumSamples->TabIndex = 54;
        this->nudNumSamples->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        // 
        // tbFolderPath
        // 
        this->tbFolderPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbFolderPath->Location = System::Drawing::Point(128, 541);
        this->tbFolderPath->Name = L"tbFolderPath";
        this->tbFolderPath->Size = System::Drawing::Size(266, 22);
        this->tbFolderPath->TabIndex = 62;
        // 
        // btnSave
        // 
        this->btnSave->BackColor = System::Drawing::Color::Khaki;
        this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSave->Location = System::Drawing::Point(411, 537);
        this->btnSave->Name = L"btnSave";
        this->btnSave->Size = System::Drawing::Size(148, 26);
        this->btnSave->TabIndex = 63;
        this->btnSave->Text = L"SAVE";
        this->btnSave->UseVisualStyleBackColor = false;
        this->btnSave->Click += gcnew System::EventHandler(this, &Form1::btnSave_Click);
        // 
        // labFolderPath
        // 
        this->labFolderPath->AutoSize = true;
        this->labFolderPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labFolderPath->Location = System::Drawing::Point(12, 541);
        this->labFolderPath->Name = L"labFolderPath";
        this->labFolderPath->Size = System::Drawing::Size(110, 20);
        this->labFolderPath->TabIndex = 64;
        this->labFolderPath->Text = L"Save Folder:";
        // 
        // cboxCOMPort
        // 
        this->cboxCOMPort->BackColor = System::Drawing::Color::Khaki;
        this->cboxCOMPort->FormattingEnabled = true;
        this->cboxCOMPort->Location = System::Drawing::Point(145, 223);
        this->cboxCOMPort->Name = L"cboxCOMPort";
        this->cboxCOMPort->Size = System::Drawing::Size(121, 21);
        this->cboxCOMPort->TabIndex = 65;
        this->cboxCOMPort->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxCOMPort_SelectedIndexChanged);
        // 
        // labCOMPort
        // 
        this->labCOMPort->AutoSize = true;
        this->labCOMPort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labCOMPort->Location = System::Drawing::Point(99, 224);
        this->labCOMPort->Name = L"labCOMPort";
        this->labCOMPort->Size = System::Drawing::Size(40, 16);
        this->labCOMPort->TabIndex = 66;
        this->labCOMPort->Text = L"COM";
        // 
        // labIntTimeExt
        // 
        this->labIntTimeExt->AutoSize = true;
        this->labIntTimeExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labIntTimeExt->Location = System::Drawing::Point(12, 132);
        this->labIntTimeExt->Name = L"labIntTimeExt";
        this->labIntTimeExt->Size = System::Drawing::Size(81, 16);
        this->labIntTimeExt->TabIndex = 67;
        this->labIntTimeExt->Text = L"Int time Ext";
        // 
        // cboxScanIntTimeExtR
        // 
        this->cboxScanIntTimeExtR->BackColor = System::Drawing::Color::LightCoral;
        this->cboxScanIntTimeExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxScanIntTimeExtR->FormattingEnabled = true;
        this->cboxScanIntTimeExtR->Location = System::Drawing::Point(111, 131);
        this->cboxScanIntTimeExtR->Name = L"cboxScanIntTimeExtR";
        this->cboxScanIntTimeExtR->Size = System::Drawing::Size(57, 21);
        this->cboxScanIntTimeExtR->TabIndex = 68;
        this->cboxScanIntTimeExtR->Text = L"120";
        this->cboxScanIntTimeExtR->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeExtR_SelectedIndexChanged);
        // 
        // cboxScanIntTimeExtG
        // 
        this->cboxScanIntTimeExtG->BackColor = System::Drawing::Color::LightGreen;
        this->cboxScanIntTimeExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxScanIntTimeExtG->FormattingEnabled = true;
        this->cboxScanIntTimeExtG->Location = System::Drawing::Point(196, 131);
        this->cboxScanIntTimeExtG->Name = L"cboxScanIntTimeExtG";
        this->cboxScanIntTimeExtG->Size = System::Drawing::Size(57, 21);
        this->cboxScanIntTimeExtG->TabIndex = 69;
        this->cboxScanIntTimeExtG->Text = L"120";
        this->cboxScanIntTimeExtG->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeExtG_SelectedIndexChanged);
        // 
        // cboxScanIntTimeExtB
        // 
        this->cboxScanIntTimeExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->cboxScanIntTimeExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxScanIntTimeExtB->FormattingEnabled = true;
        this->cboxScanIntTimeExtB->Location = System::Drawing::Point(276, 131);
        this->cboxScanIntTimeExtB->Name = L"cboxScanIntTimeExtB";
        this->cboxScanIntTimeExtB->Size = System::Drawing::Size(57, 21);
        this->cboxScanIntTimeExtB->TabIndex = 70;
        this->cboxScanIntTimeExtB->Text = L"120";
        this->cboxScanIntTimeExtB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeExtB_SelectedIndexChanged);
        // 
        // cboxScanIntTimeScaB
        // 
        this->cboxScanIntTimeScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->cboxScanIntTimeScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxScanIntTimeScaB->FormattingEnabled = true;
        this->cboxScanIntTimeScaB->Location = System::Drawing::Point(276, 158);
        this->cboxScanIntTimeScaB->Name = L"cboxScanIntTimeScaB";
        this->cboxScanIntTimeScaB->Size = System::Drawing::Size(57, 21);
        this->cboxScanIntTimeScaB->TabIndex = 73;
        this->cboxScanIntTimeScaB->Text = L"120";
        this->cboxScanIntTimeScaB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeScaB_SelectedIndexChanged);
        // 
        // cboxScanIntTimeScaG
        // 
        this->cboxScanIntTimeScaG->BackColor = System::Drawing::Color::LightGreen;
        this->cboxScanIntTimeScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxScanIntTimeScaG->FormattingEnabled = true;
        this->cboxScanIntTimeScaG->Location = System::Drawing::Point(196, 158);
        this->cboxScanIntTimeScaG->Name = L"cboxScanIntTimeScaG";
        this->cboxScanIntTimeScaG->Size = System::Drawing::Size(57, 21);
        this->cboxScanIntTimeScaG->TabIndex = 72;
        this->cboxScanIntTimeScaG->Text = L"120";
        this->cboxScanIntTimeScaG->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeScaG_SelectedIndexChanged);
        // 
        // cboxScanIntTimeScaR
        // 
        this->cboxScanIntTimeScaR->BackColor = System::Drawing::Color::LightCoral;
        this->cboxScanIntTimeScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxScanIntTimeScaR->FormattingEnabled = true;
        this->cboxScanIntTimeScaR->Location = System::Drawing::Point(111, 158);
        this->cboxScanIntTimeScaR->Name = L"cboxScanIntTimeScaR";
        this->cboxScanIntTimeScaR->Size = System::Drawing::Size(57, 21);
        this->cboxScanIntTimeScaR->TabIndex = 71;
        this->cboxScanIntTimeScaR->Text = L"120";
        this->cboxScanIntTimeScaR->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeScaR_SelectedIndexChanged);
        // 
        // labIntTimeSca
        // 
        this->labIntTimeSca->AutoSize = true;
        this->labIntTimeSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labIntTimeSca->Location = System::Drawing::Point(13, 159);
        this->labIntTimeSca->Name = L"labIntTimeSca";
        this->labIntTimeSca->Size = System::Drawing::Size(87, 16);
        this->labIntTimeSca->TabIndex = 74;
        this->labIntTimeSca->Text = L"Int time Sca";
        // 
        // rtbSerialReceived
        // 
        this->rtbSerialReceived->Location = System::Drawing::Point(408, 272);
        this->rtbSerialReceived->Name = L"rtbSerialReceived";
        this->rtbSerialReceived->Size = System::Drawing::Size(386, 119);
        this->rtbSerialReceived->TabIndex = 76;
        this->rtbSerialReceived->Text = L"";
        // 
        // labSerial
        // 
        this->labSerial->AutoSize = true;
        this->labSerial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labSerial->Location = System::Drawing::Point(10, 220);
        this->labSerial->Name = L"labSerial";
        this->labSerial->Size = System::Drawing::Size(81, 24);
        this->labSerial->TabIndex = 77;
        this->labSerial->Text = L"SERIAL";
        // 
        // rtbSerialSent
        // 
        this->rtbSerialSent->Location = System::Drawing::Point(16, 272);
        this->rtbSerialSent->Name = L"rtbSerialSent";
        this->rtbSerialSent->Size = System::Drawing::Size(386, 119);
        this->rtbSerialSent->TabIndex = 78;
        this->rtbSerialSent->Text = L"";
        // 
        // labSerialSent
        // 
        this->labSerialSent->AutoSize = true;
        this->labSerialSent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labSerialSent->Location = System::Drawing::Point(13, 253);
        this->labSerialSent->Name = L"labSerialSent";
        this->labSerialSent->Size = System::Drawing::Size(48, 16);
        this->labSerialSent->TabIndex = 79;
        this->labSerialSent->Text = L"SENT";
        // 
        // labSerialReceived
        // 
        this->labSerialReceived->AutoSize = true;
        this->labSerialReceived->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labSerialReceived->Location = System::Drawing::Point(405, 253);
        this->labSerialReceived->Name = L"labSerialReceived";
        this->labSerialReceived->Size = System::Drawing::Size(83, 16);
        this->labSerialReceived->TabIndex = 80;
        this->labSerialReceived->Text = L"RECEIVED";
        // 
        // labManualIntTimeSca
        // 
        this->labManualIntTimeSca->AutoSize = true;
        this->labManualIntTimeSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->labManualIntTimeSca->Location = System::Drawing::Point(415, 159);
        this->labManualIntTimeSca->Name = L"labManualIntTimeSca";
        this->labManualIntTimeSca->Size = System::Drawing::Size(87, 16);
        this->labManualIntTimeSca->TabIndex = 93;
        this->labManualIntTimeSca->Text = L"Int time Sca";
        // 
        // cboxManualIntTimeSca
        // 
        this->cboxManualIntTimeSca->BackColor = System::Drawing::Color::White;
        this->cboxManualIntTimeSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxManualIntTimeSca->FormattingEnabled = true;
        this->cboxManualIntTimeSca->Location = System::Drawing::Point(514, 158);
        this->cboxManualIntTimeSca->Name = L"cboxManualIntTimeSca";
        this->cboxManualIntTimeSca->Size = System::Drawing::Size(57, 21);
        this->cboxManualIntTimeSca->TabIndex = 92;
        this->cboxManualIntTimeSca->Text = L"120";
        // 
        // cboxManualIntTimeExt
        // 
        this->cboxManualIntTimeExt->BackColor = System::Drawing::Color::White;
        this->cboxManualIntTimeExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->cboxManualIntTimeExt->FormattingEnabled = true;
        this->cboxManualIntTimeExt->Location = System::Drawing::Point(514, 131);
        this->cboxManualIntTimeExt->Name = L"cboxManualIntTimeExt";
        this->cboxManualIntTimeExt->Size = System::Drawing::Size(57, 21);
        this->cboxManualIntTimeExt->TabIndex = 91;
        this->cboxManualIntTimeExt->Text = L"120";
        // 
        // labManualIntTimeExt
        // 
        this->labManualIntTimeExt->AutoSize = true;
        this->labManualIntTimeExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->labManualIntTimeExt->Location = System::Drawing::Point(415, 132);
        this->labManualIntTimeExt->Name = L"labManualIntTimeExt";
        this->labManualIntTimeExt->Size = System::Drawing::Size(81, 16);
        this->labManualIntTimeExt->TabIndex = 90;
        this->labManualIntTimeExt->Text = L"Int time Ext";
        // 
        // nudManualLEDB
        // 
        this->nudManualLEDB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudManualLEDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudManualLEDB->Location = System::Drawing::Point(679, 39);
        this->nudManualLEDB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudManualLEDB->Name = L"nudManualLEDB";
        this->nudManualLEDB->Size = System::Drawing::Size(57, 22);
        this->nudManualLEDB->TabIndex = 87;
        this->nudManualLEDB->ValueChanged += gcnew System::EventHandler(this, &Form1::nudManualLEDB_ValueChanged);
        // 
        // nudManualLEDG
        // 
        this->nudManualLEDG->BackColor = System::Drawing::Color::LightGreen;
        this->nudManualLEDG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudManualLEDG->Location = System::Drawing::Point(599, 39);
        this->nudManualLEDG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudManualLEDG->Name = L"nudManualLEDG";
        this->nudManualLEDG->Size = System::Drawing::Size(57, 22);
        this->nudManualLEDG->TabIndex = 86;
        this->nudManualLEDG->ValueChanged += gcnew System::EventHandler(this, &Form1::nudManualLEDG_ValueChanged);
        // 
        // nudManualLEDR
        // 
        this->nudManualLEDR->BackColor = System::Drawing::Color::LightCoral;
        this->nudManualLEDR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudManualLEDR->Location = System::Drawing::Point(514, 39);
        this->nudManualLEDR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudManualLEDR->Name = L"nudManualLEDR";
        this->nudManualLEDR->Size = System::Drawing::Size(57, 22);
        this->nudManualLEDR->TabIndex = 85;
        this->nudManualLEDR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        this->nudManualLEDR->ValueChanged += gcnew System::EventHandler(this, &Form1::nudManualLEDR_ValueChanged);
        // 
        // labManualGainSca
        // 
        this->labManualGainSca->AutoSize = true;
        this->labManualGainSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labManualGainSca->Location = System::Drawing::Point(415, 100);
        this->labManualGainSca->Name = L"labManualGainSca";
        this->labManualGainSca->Size = System::Drawing::Size(83, 20);
        this->labManualGainSca->TabIndex = 84;
        this->labManualGainSca->Text = L"Gain Sca";
        // 
        // labManualGainExt
        // 
        this->labManualGainExt->AutoSize = true;
        this->labManualGainExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labManualGainExt->Location = System::Drawing::Point(415, 71);
        this->labManualGainExt->Name = L"labManualGainExt";
        this->labManualGainExt->Size = System::Drawing::Size(78, 20);
        this->labManualGainExt->TabIndex = 83;
        this->labManualGainExt->Text = L"Gain Ext";
        // 
        // labManualLED
        // 
        this->labManualLED->AutoSize = true;
        this->labManualLED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labManualLED->Location = System::Drawing::Point(415, 41);
        this->labManualLED->Name = L"labManualLED";
        this->labManualLED->Size = System::Drawing::Size(44, 20);
        this->labManualLED->TabIndex = 82;
        this->labManualLED->Text = L"LED";
        // 
        // labManualSettings
        // 
        this->labManualSettings->AutoSize = true;
        this->labManualSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labManualSettings->Location = System::Drawing::Point(415, 9);
        this->labManualSettings->Name = L"labManualSettings";
        this->labManualSettings->Size = System::Drawing::Size(202, 24);
        this->labManualSettings->TabIndex = 81;
        this->labManualSettings->Text = L"MANUAL SETTINGS";
        // 
        // cboxManualGainSca
        // 
        this->cboxManualGainSca->BackColor = System::Drawing::Color::White;
        this->cboxManualGainSca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxManualGainSca->FormattingEnabled = true;
        this->cboxManualGainSca->Location = System::Drawing::Point(514, 99);
        this->cboxManualGainSca->Name = L"cboxManualGainSca";
        this->cboxManualGainSca->Size = System::Drawing::Size(57, 21);
        this->cboxManualGainSca->TabIndex = 95;
        this->cboxManualGainSca->Text = L"60";
        // 
        // cboxManualGainExt
        // 
        this->cboxManualGainExt->BackColor = System::Drawing::Color::White;
        this->cboxManualGainExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxManualGainExt->FormattingEnabled = true;
        this->cboxManualGainExt->Location = System::Drawing::Point(514, 70);
        this->cboxManualGainExt->Name = L"cboxManualGainExt";
        this->cboxManualGainExt->Size = System::Drawing::Size(57, 21);
        this->cboxManualGainExt->TabIndex = 94;
        this->cboxManualGainExt->Text = L"60";
        this->cboxManualGainExt->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxManualGainExt_SelectedIndexChanged);
        // 
        // btnSet
        // 
        this->btnSet->BackColor = System::Drawing::Color::Khaki;
        this->btnSet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSet->Location = System::Drawing::Point(642, 115);
        this->btnSet->Name = L"btnSet";
        this->btnSet->Size = System::Drawing::Size(75, 33);
        this->btnSet->TabIndex = 96;
        this->btnSet->Text = L"SET";
        this->btnSet->UseVisualStyleBackColor = false;
        this->btnSet->Click += gcnew System::EventHandler(this, &Form1::btnSet_Click);
        // 
        // btnManualMsmt
        // 
        this->btnManualMsmt->BackColor = System::Drawing::Color::Khaki;
        this->btnManualMsmt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnManualMsmt->Location = System::Drawing::Point(411, 462);
        this->btnManualMsmt->Name = L"btnManualMsmt";
        this->btnManualMsmt->Size = System::Drawing::Size(185, 59);
        this->btnManualMsmt->TabIndex = 97;
        this->btnManualMsmt->Text = L"MANUAL\r\nMEASUREMENT";
        this->btnManualMsmt->UseVisualStyleBackColor = false;
        this->btnManualMsmt->Click += gcnew System::EventHandler(this, &Form1::btnManualMsmt_Click);
        // 
        // cboxScanGainScaB
        // 
        this->cboxScanGainScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->cboxScanGainScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxScanGainScaB->FormattingEnabled = true;
        this->cboxScanGainScaB->Location = System::Drawing::Point(276, 99);
        this->cboxScanGainScaB->Name = L"cboxScanGainScaB";
        this->cboxScanGainScaB->Size = System::Drawing::Size(57, 21);
        this->cboxScanGainScaB->TabIndex = 103;
        this->cboxScanGainScaB->Text = L"60";
        this->cboxScanGainScaB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanGainScaB_SelectedIndexChanged);
        // 
        // cboxScanGainScaG
        // 
        this->cboxScanGainScaG->BackColor = System::Drawing::Color::LightGreen;
        this->cboxScanGainScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxScanGainScaG->FormattingEnabled = true;
        this->cboxScanGainScaG->Location = System::Drawing::Point(196, 99);
        this->cboxScanGainScaG->Name = L"cboxScanGainScaG";
        this->cboxScanGainScaG->Size = System::Drawing::Size(57, 21);
        this->cboxScanGainScaG->TabIndex = 102;
        this->cboxScanGainScaG->Text = L"60";
        this->cboxScanGainScaG->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanGainScaG_SelectedIndexChanged);
        // 
        // cboxScanGainScaR
        // 
        this->cboxScanGainScaR->BackColor = System::Drawing::Color::LightCoral;
        this->cboxScanGainScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxScanGainScaR->FormattingEnabled = true;
        this->cboxScanGainScaR->Location = System::Drawing::Point(111, 99);
        this->cboxScanGainScaR->Name = L"cboxScanGainScaR";
        this->cboxScanGainScaR->Size = System::Drawing::Size(57, 21);
        this->cboxScanGainScaR->TabIndex = 101;
        this->cboxScanGainScaR->Text = L"60";
        this->cboxScanGainScaR->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanGainScaR_SelectedIndexChanged);
        // 
        // cboxScanGainExtB
        // 
        this->cboxScanGainExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->cboxScanGainExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxScanGainExtB->FormattingEnabled = true;
        this->cboxScanGainExtB->Location = System::Drawing::Point(276, 70);
        this->cboxScanGainExtB->Name = L"cboxScanGainExtB";
        this->cboxScanGainExtB->Size = System::Drawing::Size(57, 21);
        this->cboxScanGainExtB->TabIndex = 100;
        this->cboxScanGainExtB->Text = L"60";
        this->cboxScanGainExtB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanGainExtB_SelectedIndexChanged);
        // 
        // cboxScanGainExtG
        // 
        this->cboxScanGainExtG->BackColor = System::Drawing::Color::LightGreen;
        this->cboxScanGainExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxScanGainExtG->FormattingEnabled = true;
        this->cboxScanGainExtG->Location = System::Drawing::Point(196, 70);
        this->cboxScanGainExtG->Name = L"cboxScanGainExtG";
        this->cboxScanGainExtG->Size = System::Drawing::Size(57, 21);
        this->cboxScanGainExtG->TabIndex = 99;
        this->cboxScanGainExtG->Text = L"60";
        this->cboxScanGainExtG->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanGainExtG_SelectedIndexChanged);
        // 
        // cboxScanGainExtR
        // 
        this->cboxScanGainExtR->BackColor = System::Drawing::Color::LightCoral;
        this->cboxScanGainExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxScanGainExtR->FormattingEnabled = true;
        this->cboxScanGainExtR->Location = System::Drawing::Point(111, 70);
        this->cboxScanGainExtR->Name = L"cboxScanGainExtR";
        this->cboxScanGainExtR->Size = System::Drawing::Size(57, 21);
        this->cboxScanGainExtR->TabIndex = 98;
        this->cboxScanGainExtR->Text = L"60";
        this->cboxScanGainExtR->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanGainExtR_SelectedIndexChanged);
        // 
        // tbMeasExtR
        // 
        this->tbMeasExtR->BackColor = System::Drawing::Color::LightCoral;
        this->tbMeasExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasExtR->Location = System::Drawing::Point(84, 456);
        this->tbMeasExtR->Name = L"tbMeasExtR";
        this->tbMeasExtR->ReadOnly = true;
        this->tbMeasExtR->Size = System::Drawing::Size(84, 22);
        this->tbMeasExtR->TabIndex = 104;
        // 
        // tbMeasExtG
        // 
        this->tbMeasExtG->BackColor = System::Drawing::Color::LightGreen;
        this->tbMeasExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasExtG->Location = System::Drawing::Point(174, 456);
        this->tbMeasExtG->Name = L"tbMeasExtG";
        this->tbMeasExtG->ReadOnly = true;
        this->tbMeasExtG->Size = System::Drawing::Size(84, 22);
        this->tbMeasExtG->TabIndex = 105;
        // 
        // tbMeasExtB
        // 
        this->tbMeasExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbMeasExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasExtB->Location = System::Drawing::Point(264, 456);
        this->tbMeasExtB->Name = L"tbMeasExtB";
        this->tbMeasExtB->ReadOnly = true;
        this->tbMeasExtB->Size = System::Drawing::Size(84, 22);
        this->tbMeasExtB->TabIndex = 106;
        // 
        // tbMeasScaB
        // 
        this->tbMeasScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbMeasScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasScaB->Location = System::Drawing::Point(264, 484);
        this->tbMeasScaB->Name = L"tbMeasScaB";
        this->tbMeasScaB->ReadOnly = true;
        this->tbMeasScaB->Size = System::Drawing::Size(84, 22);
        this->tbMeasScaB->TabIndex = 109;
        // 
        // tbMeasScaG
        // 
        this->tbMeasScaG->BackColor = System::Drawing::Color::LightGreen;
        this->tbMeasScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasScaG->Location = System::Drawing::Point(174, 484);
        this->tbMeasScaG->Name = L"tbMeasScaG";
        this->tbMeasScaG->ReadOnly = true;
        this->tbMeasScaG->Size = System::Drawing::Size(84, 22);
        this->tbMeasScaG->TabIndex = 108;
        // 
        // tbMeasScaR
        // 
        this->tbMeasScaR->BackColor = System::Drawing::Color::LightCoral;
        this->tbMeasScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasScaR->Location = System::Drawing::Point(84, 484);
        this->tbMeasScaR->Name = L"tbMeasScaR";
        this->tbMeasScaR->ReadOnly = true;
        this->tbMeasScaR->Size = System::Drawing::Size(84, 22);
        this->tbMeasScaR->TabIndex = 107;
        // 
        // checkboxAutoSave
        // 
        this->checkboxAutoSave->AutoSize = true;
        this->checkboxAutoSave->Checked = true;
        this->checkboxAutoSave->CheckState = System::Windows::Forms::CheckState::Checked;
        this->checkboxAutoSave->Location = System::Drawing::Point(565, 543);
        this->checkboxAutoSave->Name = L"checkboxAutoSave";
        this->checkboxAutoSave->Size = System::Drawing::Size(73, 17);
        this->checkboxAutoSave->TabIndex = 110;
        this->checkboxAutoSave->Text = L"AutoSave";
        this->checkboxAutoSave->UseVisualStyleBackColor = true;
        this->checkboxAutoSave->CheckedChanged += gcnew System::EventHandler(this, &Form1::cbAutoSave_CheckedChanged);
        // 
        // btnGainCal
        // 
        this->btnGainCal->BackColor = System::Drawing::Color::Khaki;
        this->btnGainCal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnGainCal->Location = System::Drawing::Point(681, 397);
        this->btnGainCal->Name = L"btnGainCal";
        this->btnGainCal->Size = System::Drawing::Size(113, 59);
        this->btnGainCal->TabIndex = 111;
        this->btnGainCal->Text = L"GAIN\r\nCAL";
        this->btnGainCal->UseVisualStyleBackColor = false;
        this->btnGainCal->Click += gcnew System::EventHandler(this, &Form1::btnGainCal_Click);
        // 
        // btnIntTimeCal
        // 
        this->btnIntTimeCal->BackColor = System::Drawing::Color::Khaki;
        this->btnIntTimeCal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnIntTimeCal->Location = System::Drawing::Point(681, 462);
        this->btnIntTimeCal->Name = L"btnIntTimeCal";
        this->btnIntTimeCal->Size = System::Drawing::Size(113, 59);
        this->btnIntTimeCal->TabIndex = 112;
        this->btnIntTimeCal->Text = L"INT TIME\r\nCAL";
        this->btnIntTimeCal->UseVisualStyleBackColor = false;
        this->btnIntTimeCal->Click += gcnew System::EventHandler(this, &Form1::btnIntTimeCal_Click);
        // 
        // btnLEDCal
        // 
        this->btnLEDCal->BackColor = System::Drawing::Color::Khaki;
        this->btnLEDCal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnLEDCal->Location = System::Drawing::Point(681, 527);
        this->btnLEDCal->Name = L"btnLEDCal";
        this->btnLEDCal->Size = System::Drawing::Size(113, 40);
        this->btnLEDCal->TabIndex = 113;
        this->btnLEDCal->Text = L"LED CAL";
        this->btnLEDCal->UseVisualStyleBackColor = false;
        this->btnLEDCal->Click += gcnew System::EventHandler(this, &Form1::btnLEDCal_Click);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(802, 577);
        this->Controls->Add(this->btnLEDCal);
        this->Controls->Add(this->btnIntTimeCal);
        this->Controls->Add(this->btnGainCal);
        this->Controls->Add(this->checkboxAutoSave);
        this->Controls->Add(this->tbMeasScaB);
        this->Controls->Add(this->tbMeasScaG);
        this->Controls->Add(this->tbMeasScaR);
        this->Controls->Add(this->tbMeasExtB);
        this->Controls->Add(this->tbMeasExtG);
        this->Controls->Add(this->tbMeasExtR);
        this->Controls->Add(this->cboxScanGainScaB);
        this->Controls->Add(this->cboxScanGainScaG);
        this->Controls->Add(this->cboxScanGainScaR);
        this->Controls->Add(this->cboxScanGainExtB);
        this->Controls->Add(this->cboxScanGainExtG);
        this->Controls->Add(this->cboxScanGainExtR);
        this->Controls->Add(this->btnManualMsmt);
        this->Controls->Add(this->btnSet);
        this->Controls->Add(this->cboxManualGainSca);
        this->Controls->Add(this->cboxManualGainExt);
        this->Controls->Add(this->labManualIntTimeSca);
        this->Controls->Add(this->cboxManualIntTimeSca);
        this->Controls->Add(this->cboxManualIntTimeExt);
        this->Controls->Add(this->labManualIntTimeExt);
        this->Controls->Add(this->nudManualLEDB);
        this->Controls->Add(this->nudManualLEDG);
        this->Controls->Add(this->nudManualLEDR);
        this->Controls->Add(this->labManualGainSca);
        this->Controls->Add(this->labManualGainExt);
        this->Controls->Add(this->labManualLED);
        this->Controls->Add(this->labManualSettings);
        this->Controls->Add(this->labSerialReceived);
        this->Controls->Add(this->labSerialSent);
        this->Controls->Add(this->rtbSerialSent);
        this->Controls->Add(this->labSerial);
        this->Controls->Add(this->rtbSerialReceived);
        this->Controls->Add(this->labIntTimeSca);
        this->Controls->Add(this->cboxScanIntTimeScaB);
        this->Controls->Add(this->cboxScanIntTimeScaG);
        this->Controls->Add(this->cboxScanIntTimeScaR);
        this->Controls->Add(this->cboxScanIntTimeExtB);
        this->Controls->Add(this->cboxScanIntTimeExtG);
        this->Controls->Add(this->cboxScanIntTimeExtR);
        this->Controls->Add(this->labIntTimeExt);
        this->Controls->Add(this->labCOMPort);
        this->Controls->Add(this->cboxCOMPort);
        this->Controls->Add(this->labFolderPath);
        this->Controls->Add(this->btnSave);
        this->Controls->Add(this->tbFolderPath);
        this->Controls->Add(this->nudNumSamples);
        this->Controls->Add(this->nudScanLEDB);
        this->Controls->Add(this->nudScanLEDG);
        this->Controls->Add(this->nudScanLEDR);
        this->Controls->Add(this->labNotes);
        this->Controls->Add(this->tbNotes);
        this->Controls->Add(this->tbMeasTime);
        this->Controls->Add(this->labMeasTime);
        this->Controls->Add(this->labMeasSca);
        this->Controls->Add(this->LabMeasExt);
        this->Controls->Add(this->btnScan);
        this->Controls->Add(this->labMeasurements);
        this->Controls->Add(this->labNumSamples);
        this->Controls->Add(this->labGainSca);
        this->Controls->Add(this->labGainExt);
        this->Controls->Add(this->labScanLED);
        this->Controls->Add(this->labScanSettings);
        this->Name = L"Form1";
        this->Text = L"BeerSpec GUI";
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNumSamples))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudManualLEDB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudManualLEDG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudManualLEDR))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.



  private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
  }

private: System::Void labLEDR_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void labNumSamples_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnMakeGetMsmt_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbLEDR_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void in_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}




void Update_tbFolderPath(Object^ sender, EventArgs^ e)
{
    // Update the TextBox with the latest value from csvSaver.FilePath
    tbFolderPath->Text = csvSaver->FolderPath;
}
    


private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
    csvSaver->SaveDataToFile(instrumentSettings, meas);
}
private: System::Void tbNotes_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    meas->Notes = tbNotes->Text;
}
private: System::Void nudScanLEDR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->LEDR = Decimal::ToInt32(nudScanLEDR->Value);
}
private: System::Void nudScanLEDG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->LEDG = Decimal::ToInt32(nudScanLEDG->Value);
}
private: System::Void nudScanLEDB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->LEDB = Decimal::ToInt32(nudScanLEDB->Value);
}
private: System::Void cboxScanGainExtR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainExtR = System::Convert::ToInt32(cboxScanGainExtR->SelectedValue);
}
private: System::Void cboxScanGainExtG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainExtG = System::Convert::ToInt32(cboxScanGainExtG->SelectedValue);
}
private: System::Void cboxScanGainExtB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainExtB = System::Convert::ToInt32(cboxScanGainExtB->SelectedValue);
}
private: System::Void cboxScanGainScaR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainScaR = System::Convert::ToInt32(cboxScanGainScaR->SelectedValue);
}
private: System::Void cboxScanGainScaG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainScaG = System::Convert::ToInt32(cboxScanGainScaG->SelectedValue);
}
  private: System::Void cboxScanGainScaB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
      scanSettings->GainScaB = System::Convert::ToInt32(cboxScanGainScaB->SelectedValue);
}

// find available COM ports
private: void findPorts(void)
{
    // get port names
    array<Object^>^ objectArray = SerialPort::GetPortNames();
    // add string array to combobox
    this->cboxCOMPort->Items->AddRange(objectArray);
}

private: System::Void cboxCOMPort_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

    if (serialManager1->IsOpen()) {
        this->serialManager1->Close();
    }
    
    //Open the new port
    String^ portName = this->cboxCOMPort->Text;
    serialManager1 = gcnew SerialManager(portName, 9600,rtbSerialSent,rtbSerialReceived);
    serialManager1->Open();  


    // Check if the serial port is open
    if (serialManager1->IsOpen())
    {
        Console::WriteLine("Serial port is open. Ready to send/receive data.");
        // Perform operations when the serial port is open
    }
    else
    {
        Console::WriteLine("Failed to open the serial port.");
        UpdatertbSerialReceived("not open");
    }



    //}
}
private: System::Void nudMeasExtR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cboxScanIntTimeExtR_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->IntTimeExtR = System::Convert::ToInt32(cboxScanIntTimeExtR->SelectedValue);
}
private: System::Void cboxScanIntTimeExtG_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->IntTimeExtG = System::Convert::ToInt32(cboxScanIntTimeExtG->SelectedValue);
}
private: System::Void cboxScanIntTimeExtB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->IntTimeExtB = System::Convert::ToInt32(cboxScanIntTimeExtB->SelectedValue);
}
private: System::Void cboxScanIntTimeScaR_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->IntTimeScaR = System::Convert::ToInt32(cboxScanIntTimeScaR->SelectedValue);
}
private: System::Void cboxScanIntTimeScaG_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->IntTimeScaG = System::Convert::ToInt32(cboxScanIntTimeScaG->SelectedValue);
}
private: System::Void cboxScanIntTimeScaB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->IntTimeScaB = System::Convert::ToInt32(cboxScanIntTimeScaB->SelectedValue);
}


private:
    bool isWaitingForNewLine = false;
    System::Text::StringBuilder^ receivedDataBuilder = gcnew System::Text::StringBuilder();

//LEGACY FOR OLD WAY OF HANDING SERIAL COMMS BEFORE USING SerialManager class
//void serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
//    System::String^ receivedData = serialPort1->ReadExisting();
//    receivedDataBuilder->Append(receivedData);
//
//    // Check if the received data contains a new line character
//    if (receivedData->Contains("\n")) {
//        //Make the complete command of everything up intil the \n
//        int newLineIndex = receivedDataBuilder->ToString()->LastIndexOf("\n");
//        System::String^ completeData = receivedDataBuilder->ToString()->Substring(0, newLineIndex + 1);
//
//        // Check if the received data came from the Arduino command
//        if (completeData->StartsWith("@")) {
//            // Update the received commands RichTextBox
//            Invoke(gcnew Action<System::String^>(this, &Form1::UpdatertbSerialReceived), completeData);
//        }
//
//        // Clear the StringBuilder and stop waiting for a new line
//        receivedDataBuilder->Clear();
//        isWaitingForNewLine = false;
//    }
//    else {
//        isWaitingForNewLine = true;
//    }
//}



void UpdatertbSerialSent(System::String^ data) {
    //First add datetime
    String^ dateTimeNowStr = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
    //Remove whitespace from the ends
    data = data->Trim();

    // Check if the formatted data is empty
    if (!System::String::IsNullOrEmpty(data)) {
        // Add the formatted data to the RichTextBox with the desired formatting
        rtbSerialSent->AppendText(dateTimeNowStr + ": " + data + "\n");

        //Scroll to the end of the richtextbox
        rtbSerialSent->SelectionStart = rtbSerialSent->Text->Length;
        rtbSerialSent->ScrollToCaret();
    }

}


void UpdatertbSerialReceived(System::String^ data) {
    //First add datetime
    String^ dateTimeNowStr = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
    //Remove whitespace from the ends
    data = data->Trim();

    // Check if the formatted data is empty
    if (!System::String::IsNullOrEmpty(data)) {
        // Add the formatted data to the RichTextBox with the desired formatting
        rtbSerialReceived->AppendText(dateTimeNowStr + ": " + data + "\n");

        //Scroll to the end of the richtextbox
        rtbSerialReceived->SelectionStart = rtbSerialReceived->Text->Length;
        rtbSerialReceived->ScrollToCaret();
    }

}
private: System::Void cboxScanGainExtR_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainExtR = System::Convert::ToInt32(cboxScanGainExtR->SelectedValue);
}
private: System::Void cboxManualGainExt_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cboxScanGainExtG_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainExtG = System::Convert::ToInt32(cboxScanGainExtG->SelectedValue);
}
private: System::Void cboxScanGainExtB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainExtB = System::Convert::ToInt32(cboxScanGainExtB->SelectedValue);
}
private: System::Void cboxScanGainScaR_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainScaR = System::Convert::ToInt32(cboxScanGainScaR->SelectedValue);
}
private: System::Void cboxScanGainScaG_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainScaG = System::Convert::ToInt32(cboxScanGainScaG->SelectedValue);
}
private: System::Void cboxScanGainScaB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    scanSettings->GainScaB = System::Convert::ToInt32(cboxScanGainScaB->SelectedValue);
}
private: System::Void btnSet_Click(System::Object^ sender, System::EventArgs^ e) {
    if (serialManager1->IsOpen())
    {
        //Update the instrumentSettings object
        instrumentSettings->LEDR = static_cast<int>(nudManualLEDR->Value);

        instrumentSettings->LEDG = static_cast<int>(nudManualLEDG->Value);
        instrumentSettings->LEDB = static_cast<int>(nudManualLEDB->Value);
        instrumentSettings->GainExt = static_cast<int>(cboxManualGainExt->SelectedItem);
        instrumentSettings->GainSca = static_cast<int>(cboxManualGainSca->SelectedItem);
        instrumentSettings->IntTimeExt = static_cast<int>(cboxManualIntTimeExt->SelectedItem);
        instrumentSettings->IntTimeSca = static_cast<int>(cboxManualIntTimeSca->SelectedItem);


        //Set LED RGB
        //String^ serialOut = instrumentSettings->SerialCommand();
        serialManager1->EnqueueSendCommand(instrumentSettings->SerialSet());

        //String^ serialOut = "#SETTINGSLEDRGB " + System::Convert::ToString(scanSettings->LEDR) + " " + System::Convert::ToString(scanSettings->LEDG) + " " + System::Convert::ToString(scanSettings->LEDB);
        //serialManager1->EnqueueSendCommand(serialOut);

        ////Set Gains
        //serialOut = "#SETTINGSGAINS " + System::Convert::ToString(scanSettings->GainExtR) + " " + System::Convert::ToString(scanSettings->GainExtG) + " " + System::Convert::ToString(scanSettings->GainExtB);
        //serialOut = serialOut + " " + System::Convert::ToString(scanSettings->GainScaR) + " " + System::Convert::ToString(scanSettings->GainScaG) + " " + System::Convert::ToString(scanSettings->GainScaB);
        //serialManager1->EnqueueSendCommand(serialOut);

        ////Set IntTimes
        //serialOut = "#SETTINGSINTTIMESS " + System::Convert::ToString(scanSettings->IntTimeExtR) + " " + System::Convert::ToString(scanSettings->IntTimeExtG) + " " + System::Convert::ToString(scanSettings->IntTimeExtB);
        //serialOut = serialOut + " " + System::Convert::ToString(scanSettings->IntTimeScaR) + " " + System::Convert::ToString(scanSettings->IntTimeScaG) + " " + System::Convert::ToString(scanSettings->IntTimeScaB);
        //serialManager1->EnqueueSendCommand(serialOut);

        //Send the queued commands and process the received ones
        serialManager1->SendQueuedCommands();
        System::Threading::Thread::Sleep(1000);
        serialManager1->ProcessReceivedCommands(meas);

    }
    else
    {
        UpdatertbSerialReceived("Serial port not open");
    }
}
private: System::Void btnManualMsmt_Click(System::Object^ sender, System::EventArgs^ e) {
    //Read Extinction data
    serialManager1->EnqueueSendCommand("#READEXT");
    serialManager1->SendQueuedCommands();
    //Time to sleep for, in ms. This should be longer than it takes to make a measurement
    int sleepTime = 2000 + instrumentSettings->IntTimeExt;
    System::Threading::Thread::Sleep(sleepTime);
    serialManager1->ProcessReceivedCommands(meas);
    //Update the measurement boxes on the panel
    tbMeasTime->Text = meas->MeasTime;
    tbMeasExtR->Text = System::Convert::ToString(meas->MeasExtR);
    tbMeasExtG->Text = System::Convert::ToString(meas->MeasExtG);
    tbMeasExtB->Text = System::Convert::ToString(meas->MeasExtB);

    //Read Scattering data
    serialManager1->EnqueueSendCommand("#READSCA");
    serialManager1->SendQueuedCommands();
    System::Threading::Thread::Sleep(sleepTime);
    serialManager1->ProcessReceivedCommands(meas);
    //Update the measurement boxes on the panel
    tbMeasTime->Text = meas->MeasTime;
    tbMeasScaR->Text = System::Convert::ToString(meas->MeasScaR);
    tbMeasScaG->Text = System::Convert::ToString(meas->MeasScaG);
    tbMeasScaB->Text = System::Convert::ToString(meas->MeasScaB);

    //Save if autosave is ticked
    if (checkboxAutoSave->Checked)
    {
        csvSaver->SaveDataToFile(instrumentSettings, meas);
    }
}
private: System::Void btnScan_Click(System::Object^ sender, System::EventArgs^ e) {
    //First update settings in scanSettings object from front panel
    updateScanSettings();

    if (serialManager1->IsOpen())
    {   
        //Loop through the number of samples to take
        for(int i=0; i<nudNumSamples->Value;i++)
        {
            //Update instrumentSettings from scanSettings RED
            instrumentSettings->LEDR = scanSettings->LEDR;
            instrumentSettings->LEDG = 0;
            instrumentSettings->LEDB = 0;
            instrumentSettings->GainExt = scanSettings->GainExtR;
            instrumentSettings->GainSca = scanSettings->GainScaR;
            instrumentSettings->IntTimeExt = scanSettings->IntTimeExtR;
            instrumentSettings->IntTimeSca = scanSettings->IntTimeScaR;
            setRead();

            //Update instrumentSettings from scanSettings GREEN
            instrumentSettings->LEDR = 0;
            instrumentSettings->LEDG = scanSettings->LEDG;
            instrumentSettings->LEDB = 0;
            instrumentSettings->GainExt = scanSettings->GainExtG;
            instrumentSettings->GainSca = scanSettings->GainScaG;
            instrumentSettings->IntTimeExt = scanSettings->IntTimeExtG;
            instrumentSettings->IntTimeSca = scanSettings->IntTimeScaG;
            setRead();

            //Update instrumentSettings from scanSettings BLUE
            instrumentSettings->LEDR = 0;
            instrumentSettings->LEDG = 0;
            instrumentSettings->LEDB = scanSettings->LEDB;
            instrumentSettings->GainExt = scanSettings->GainExtB;
            instrumentSettings->GainSca = scanSettings->GainScaB;
            instrumentSettings->IntTimeExt = scanSettings->IntTimeExtB;
            instrumentSettings->IntTimeSca = scanSettings->IntTimeScaB;
            setRead();
        }
        


    }
    else
    {
        UpdatertbSerialReceived("Serial port not open");
    }
    
}

//Update scanSettings object from front panel
private: System::Void updateScanSettings() {
    scanSettings->LEDR = static_cast<int>(nudScanLEDR->Value);
    scanSettings->LEDG = static_cast<int>(nudScanLEDG->Value);
    scanSettings->LEDB = static_cast<int>(nudScanLEDB->Value);
    scanSettings->GainExtR = static_cast<int>(cboxScanGainExtR->SelectedItem);
    scanSettings->GainExtG = static_cast<int>(cboxScanGainExtG->SelectedItem);
    scanSettings->GainExtB = static_cast<int>(cboxScanGainExtB->SelectedItem);
    scanSettings->GainScaR = static_cast<int>(cboxScanGainScaR->SelectedItem);
    scanSettings->GainScaG = static_cast<int>(cboxScanGainScaG->SelectedItem);
    scanSettings->GainScaB = static_cast<int>(cboxScanGainScaB->SelectedItem);
    scanSettings->IntTimeExtR = static_cast<int>(cboxScanIntTimeExtR->SelectedItem);
    scanSettings->IntTimeExtG = static_cast<int>(cboxScanIntTimeExtG->SelectedItem);
    scanSettings->IntTimeExtB = static_cast<int>(cboxScanIntTimeExtB->SelectedItem);
    scanSettings->IntTimeScaR = static_cast<int>(cboxScanIntTimeScaR->SelectedItem);
    scanSettings->IntTimeScaG = static_cast<int>(cboxScanIntTimeScaG->SelectedItem);
    scanSettings->IntTimeScaB = static_cast<int>(cboxScanIntTimeScaB->SelectedItem);
}
//#SETALL, #READEXT, and #READSCA commands, one after the other
private: System::Void setRead() {
    //Serial command to update instrument settings
    serialManager1->EnqueueSendCommand(instrumentSettings->SerialSet());
    serialManager1->SendQueuedCommands();
    System::Threading::Thread::Sleep(500);
    serialManager1->ProcessReceivedCommands(meas);

    //Read Extinction data
    serialManager1->EnqueueSendCommand("#READEXT \n");
    serialManager1->SendQueuedCommands();
    int sleepTime = 2000 + instrumentSettings->IntTimeExt;
    System::Threading::Thread::Sleep(sleepTime);
    serialManager1->ProcessReceivedCommands(meas);

    //Update the measurement boxes on the panel
    tbMeasTime->Text = meas->MeasTime;
    tbMeasExtR->Text = System::Convert::ToString(meas->MeasExtR);
    tbMeasExtG->Text = System::Convert::ToString(meas->MeasExtG);
    tbMeasExtB->Text = System::Convert::ToString(meas->MeasExtB);

    //Read Scattering data
    serialManager1->EnqueueSendCommand("#READSCA \n");
    serialManager1->SendQueuedCommands();
    sleepTime = 2000 + instrumentSettings->IntTimeSca;
    System::Threading::Thread::Sleep(sleepTime);
    serialManager1->ProcessReceivedCommands(meas);

    //Update the measurement boxes on the panel
    tbMeasTime->Text = meas->MeasTime;
    tbMeasScaR->Text = System::Convert::ToString(meas->MeasScaR);
    tbMeasScaG->Text = System::Convert::ToString(meas->MeasScaG);
    tbMeasScaB->Text = System::Convert::ToString(meas->MeasScaB);

    //Save if autosave is ticked
    if (checkboxAutoSave->Checked)
    {
        csvSaver->SaveDataToFile(instrumentSettings, meas);
    }
}




private: System::Void cbAutoSave_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void nudManualLEDR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void nudManualLEDG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void nudManualLEDB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnGainCal_Click(System::Object^ sender, System::EventArgs^ e) {
    //Loop through the different gain settings 
    //Probably do it with the LED set to R, G, or B
    array<int>^ gainArray = gcnew array<int>(4) { 1, 4, 16, 60 };

    //Set int times
    instrumentSettings->IntTimeExt = 120;
    instrumentSettings->IntTimeSca = 120;

    //Set LED to red
    instrumentSettings->LEDR = 128;
    instrumentSettings->LEDG = 0;
    instrumentSettings->LEDB = 0;
    meas->Notes = "Gain Cal Red";
    tbNotes->Text = "Gain Cal Red";

    //Loop through the different gains
    for each (int gain in gainArray)
    {
        instrumentSettings->GainExt = gain;
        instrumentSettings->GainSca = gain;
        setRead();
    }

    //Set LED to green
    instrumentSettings->LEDR = 0;
    instrumentSettings->LEDG = 128;
    instrumentSettings->LEDB = 0;
    meas->Notes = "Gain Cal Green";
    tbNotes->Text = "Gain Cal Green";

    //Loop through the different gains
    for each (int gain in gainArray)
    {
        instrumentSettings->GainExt = gain;
        instrumentSettings->GainSca = gain;
        setRead();
    }

    //Set LED to blue
    instrumentSettings->LEDR = 0;
    instrumentSettings->LEDG = 0;
    instrumentSettings->LEDB = 128;
    meas->Notes = "Gain Cal Blue";
    tbNotes->Text = "Gain Cal Blue";

    //Loop through the different gains
    for each (int gain in gainArray)
    {
        instrumentSettings->GainExt = gain;
        instrumentSettings->GainSca = gain;
        setRead();
    }



}
private: System::Void btnIntTimeCal_Click(System::Object^ sender, System::EventArgs^ e) {
    //Loop through the different int times
    //Probably do it with the LED set to R, G, or B
}
private: System::Void btnLEDCal_Click(System::Object^ sender, System::EventArgs^ e) {
    //Loop through some different LED setting between 0 - 255
    //Separate R, G, B rather than all at once
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject


