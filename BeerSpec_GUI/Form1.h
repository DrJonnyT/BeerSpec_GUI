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
      CSVSaver^ csvSaver;
      ScanSettings^ settings;
      System::IO::Ports::SerialPort^ serialPort1;
      SerialManager^ serialManager1;
  private: System::Windows::Forms::Label^ labFolderPath;
  
  private: System::Windows::Forms::ComboBox^ cboxCOMPort;
  private: System::Windows::Forms::Label^ labCOMPort;
  private: System::Windows::Forms::Label^ labIntTime;
  private: System::Windows::Forms::ComboBox^ cboxScanIntTimeExtR;
  private: System::Windows::Forms::ComboBox^ cboxScanIntTimeExtG;
  private: System::Windows::Forms::ComboBox^ cboxScanIntTimeExtB;
  private: System::Windows::Forms::ComboBox^ cboxScanIntTimeScaB;




  private: System::Windows::Forms::ComboBox^ cboxScanIntTimeScaG;




  private: System::Windows::Forms::ComboBox^ cboxScanIntTimeScaR;



  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::RichTextBox^ rtbSerialReceived;


  private: System::Windows::Forms::Label^ labSerial;
  private: System::Windows::Forms::RichTextBox^ rtbSerialSent;


  private: System::Windows::Forms::Label^ labSerialSent;
  private: System::Windows::Forms::Label^ labSerialReceived;
  private: System::Windows::Forms::Label^ labManualIntTimeSca;
  private: System::Windows::Forms::ComboBox^ cboxManualIntTimeSca;

  private: System::Windows::Forms::ComboBox^ cboxManualIntTimeExt;




  private: System::Windows::Forms::Label^ labManualIntTimeExt;






  private: System::Windows::Forms::NumericUpDown^ nudManualLEDB;

  private: System::Windows::Forms::NumericUpDown^ nudManualLEDG;

  private: System::Windows::Forms::NumericUpDown^ nudManualLEDR;

  private: System::Windows::Forms::Label^ labManualGainSca;

  private: System::Windows::Forms::Label^ labManualGainExt;

  private: System::Windows::Forms::Label^ labManualLED;

  private: System::Windows::Forms::Label^ labManualSettings;
  private: System::Windows::Forms::ComboBox^ cboxManualGainSca;

  private: System::Windows::Forms::ComboBox^ cboxManualGainExt;
  private: System::Windows::Forms::Button^ btnSet;
  private: System::Windows::Forms::Button^ btnManualMsmt;









         MeasClass^ meas;


  public:
    Form1(void)
    {
      InitializeComponent();

      //Find COM ports
      findPorts();

      //Open the serial port manager as a dummy
      serialManager1 = gcnew SerialManager();
      
      //Settings object to store instrument settings
      settings = gcnew ScanSettings;

      //Measurements object to store measurements
      meas = gcnew MeasClass;   

      //CSVSaver object
      //CSVSaver^ csvSaver = gcnew CSVSaver;
      csvSaver = gcnew CSVSaver();

     


      //Bind the TextBox control to the settings properties
      nudScanLEDR->DataBindings->Add("Value", settings, "LEDR");
      nudScanLEDG->DataBindings->Add("Value", settings, "LEDG");
      nudScanLEDB->DataBindings->Add("Value", settings, "LEDB");
      nudScanGainExtR->DataBindings->Add("Value", settings, "GainExtR");
      nudScanGainExtG->DataBindings->Add("Value", settings, "GainExtG");
      nudScanGainExtB->DataBindings->Add("Value", settings, "GainExtB");
      nudScanGainScaR->DataBindings->Add("Value", settings, "GainScaR");
      nudScanGainScaG->DataBindings->Add("Value", settings, "GainScaG");
      nudScanGainScaB->DataBindings->Add("Value", settings, "GainScaB");
      nudNumSamples->DataBindings->Add("Value", settings, "NumSamples");

      //Bind the TextBoxes to the measurement properties
      nudMeasExtR->DataBindings->Add("Value", meas, "MeasExtR");
      nudMeasExtG->DataBindings->Add("Value", meas, "MeasExtG");
      nudMeasExtB->DataBindings->Add("Value", meas, "MeasExtB");
      nudMeasScaR->DataBindings->Add("Value", meas, "MeasScaR");
      nudMeasScaG->DataBindings->Add("Value", meas, "MeasScaG");
      nudMeasScaB->DataBindings->Add("Value", meas, "MeasScaB");

      tbMeasTime->DataBindings->Add("Text", meas, "MeasTime");
      tbNotes->DataBindings->Add("Text", meas, "Notes");

      //Bind the file path to the csvSaver object
      tbFolderPath->DataBindings->Add("Text", csvSaver, "FolderPath");
      csvSaver->FolderPathChanged += gcnew EventHandler(this, &Form1::Update_tbFolderPath);

      


      //Remove arrows from measurements
      nudMeasExtR->Controls->RemoveAt(0);
      nudMeasExtG->Controls->RemoveAt(0);
      nudMeasExtB->Controls->RemoveAt(0);
      nudMeasScaR->Controls->RemoveAt(0);
      nudMeasScaG->Controls->RemoveAt(0);
      nudMeasScaB->Controls->RemoveAt(0);


      //Set options for integration time boxes
      cboxScanIntTimeExtR->Items->Add(24.);
      cboxScanIntTimeExtR->Items->Add(60.);
      cboxScanIntTimeExtR->Items->Add(120.);
      cboxScanIntTimeExtR->Items->Add(240.);
      cboxScanIntTimeExtR->Items->Add(480.);
      cboxScanIntTimeExtG->Items->Add(24.);
      cboxScanIntTimeExtG->Items->Add(60.);
      cboxScanIntTimeExtG->Items->Add(120.);
      cboxScanIntTimeExtG->Items->Add(240.);
      cboxScanIntTimeExtG->Items->Add(480.);
      cboxScanIntTimeExtB->Items->Add(24.);
      cboxScanIntTimeExtB->Items->Add(60.);
      cboxScanIntTimeExtB->Items->Add(120.);
      cboxScanIntTimeExtB->Items->Add(240.);
      cboxScanIntTimeExtB->Items->Add(480.);
      cboxScanIntTimeScaR->Items->Add(24.);
      cboxScanIntTimeScaR->Items->Add(60.);
      cboxScanIntTimeScaR->Items->Add(120.);
      cboxScanIntTimeScaR->Items->Add(240.);
      cboxScanIntTimeScaR->Items->Add(480.);
      cboxScanIntTimeScaG->Items->Add(24.);
      cboxScanIntTimeScaG->Items->Add(60.);
      cboxScanIntTimeScaG->Items->Add(120.);
      cboxScanIntTimeScaG->Items->Add(240.);
      cboxScanIntTimeScaG->Items->Add(480.);
      cboxScanIntTimeScaB->Items->Add(24.);
      cboxScanIntTimeScaB->Items->Add(60.);
      cboxScanIntTimeScaB->Items->Add(120.);
      cboxScanIntTimeScaB->Items->Add(240.);
      cboxScanIntTimeScaB->Items->Add(480.);

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

  //Default buttons etc from the example




  private: System::ComponentModel::IContainer^ components;
private: System::Windows::Forms::Label^ labScanSettings;






  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>

  
    //Define settings part of form

    System::Windows::Forms::Label^ labLED;
    System::Windows::Forms::NumericUpDown^ nudScanLEDR;
    System::Windows::Forms::NumericUpDown^ nudScanLEDG;
    System::Windows::Forms::NumericUpDown^ nudScanLEDB;

    System::Windows::Forms::Label^ labGainExt;
    System::Windows::Forms::NumericUpDown^ nudScanGainExtB;
    System::Windows::Forms::NumericUpDown^ nudScanGainExtG;
    System::Windows::Forms::NumericUpDown^ nudScanGainExtR;

    System::Windows::Forms::Label^ labGainSca;
    System::Windows::Forms::NumericUpDown^ nudScanGainScaB;
    System::Windows::Forms::NumericUpDown^ nudScanGainScaG;
    System::Windows::Forms::NumericUpDown^ nudScanGainScaR;

    System::Windows::Forms::Label^ labNumSamples;
    System::Windows::Forms::NumericUpDown^ nudNumSamples;


    //Define measurements part of form
    System::Windows::Forms::Label^ labMeasurements;
    System::Windows::Forms::Label^ labMeasTime;
    System::Windows::Forms::TextBox^ tbMeasTime;
    System::Windows::Forms::Label^ LabMeasExt;



    System::Windows::Forms::Label^ labMeasSca;



    System::Windows::Forms::Label^ labNotes;
    System::Windows::Forms::TextBox^ tbNotes;

    System::Windows::Forms::Button^ btnScan;
private: System::Windows::Forms::NumericUpDown^ nudMeasExtR;
private: System::Windows::Forms::NumericUpDown^ nudMeasExtG;
private: System::Windows::Forms::NumericUpDown^ nudMeasExtB;
private: System::Windows::Forms::NumericUpDown^ nudMeasScaB;
private: System::Windows::Forms::NumericUpDown^ nudMeasScaG;
private: System::Windows::Forms::NumericUpDown^ nudMeasScaR;


private: System::Windows::Forms::TextBox^ tbFolderPath;

private: System::Windows::Forms::Button^ btnSave;








#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->components = (gcnew System::ComponentModel::Container());
        this->labScanSettings = (gcnew System::Windows::Forms::Label());
        this->labLED = (gcnew System::Windows::Forms::Label());
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
        this->nudScanGainExtB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanGainExtG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanGainExtR = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanGainScaB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanGainScaG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudScanGainScaR = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudNumSamples = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudMeasExtR = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudMeasExtG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudMeasExtB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudMeasScaB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudMeasScaG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudMeasScaR = (gcnew System::Windows::Forms::NumericUpDown());
        this->tbFolderPath = (gcnew System::Windows::Forms::TextBox());
        this->btnSave = (gcnew System::Windows::Forms::Button());
        this->labFolderPath = (gcnew System::Windows::Forms::Label());
        this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
        this->cboxCOMPort = (gcnew System::Windows::Forms::ComboBox());
        this->labCOMPort = (gcnew System::Windows::Forms::Label());
        this->labIntTime = (gcnew System::Windows::Forms::Label());
        this->cboxScanIntTimeExtR = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeExtG = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeExtB = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeScaB = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeScaG = (gcnew System::Windows::Forms::ComboBox());
        this->cboxScanIntTimeScaR = (gcnew System::Windows::Forms::ComboBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
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
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainExtB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainExtG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainExtR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainScaB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainScaG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainScaR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNumSamples))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaR))->BeginInit();
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
        this->labScanSettings->Size = System::Drawing::Size(173, 24);
        this->labScanSettings->TabIndex = 5;
        this->labScanSettings->Text = L"SCAN SETTINGS";
        this->labScanSettings->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
        // 
        // labLED
        // 
        this->labLED->AutoSize = true;
        this->labLED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labLED->Location = System::Drawing::Point(12, 38);
        this->labLED->Name = L"labLED";
        this->labLED->Size = System::Drawing::Size(44, 20);
        this->labLED->TabIndex = 12;
        this->labLED->Text = L"LED";
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
        this->btnScan->Location = System::Drawing::Point(372, 439);
        this->btnScan->Name = L"btnScan";
        this->btnScan->Size = System::Drawing::Size(75, 33);
        this->btnScan->TabIndex = 31;
        this->btnScan->Text = L"SCAN";
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
        this->tbNotes->Location = System::Drawing::Point(84, 518);
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
        this->labNotes->Location = System::Drawing::Point(12, 516);
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
        this->nudScanLEDR->Location = System::Drawing::Point(111, 36);
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
        this->nudScanLEDG->Location = System::Drawing::Point(196, 36);
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
        this->nudScanLEDB->Location = System::Drawing::Point(276, 36);
        this->nudScanLEDB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudScanLEDB->Name = L"nudScanLEDB";
        this->nudScanLEDB->Size = System::Drawing::Size(57, 22);
        this->nudScanLEDB->TabIndex = 47;
        this->nudScanLEDB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudScanGainExtB
        // 
        this->nudScanGainExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudScanGainExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanGainExtB->Location = System::Drawing::Point(276, 68);
        this->nudScanGainExtB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudScanGainExtB->Name = L"nudScanGainExtB";
        this->nudScanGainExtB->Size = System::Drawing::Size(57, 22);
        this->nudScanGainExtB->TabIndex = 50;
        this->nudScanGainExtB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        // 
        // nudScanGainExtG
        // 
        this->nudScanGainExtG->BackColor = System::Drawing::Color::LightGreen;
        this->nudScanGainExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanGainExtG->Location = System::Drawing::Point(196, 68);
        this->nudScanGainExtG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudScanGainExtG->Name = L"nudScanGainExtG";
        this->nudScanGainExtG->Size = System::Drawing::Size(57, 22);
        this->nudScanGainExtG->TabIndex = 49;
        this->nudScanGainExtG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        // 
        // nudScanGainExtR
        // 
        this->nudScanGainExtR->BackColor = System::Drawing::Color::LightCoral;
        this->nudScanGainExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanGainExtR->Location = System::Drawing::Point(111, 68);
        this->nudScanGainExtR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudScanGainExtR->Name = L"nudScanGainExtR";
        this->nudScanGainExtR->Size = System::Drawing::Size(57, 22);
        this->nudScanGainExtR->TabIndex = 48;
        this->nudScanGainExtR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        this->nudScanGainExtR->ValueChanged += gcnew System::EventHandler(this, &Form1::nudScanGainExtR_ValueChanged);
        // 
        // nudScanGainScaB
        // 
        this->nudScanGainScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudScanGainScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanGainScaB->Location = System::Drawing::Point(276, 100);
        this->nudScanGainScaB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudScanGainScaB->Name = L"nudScanGainScaB";
        this->nudScanGainScaB->Size = System::Drawing::Size(57, 22);
        this->nudScanGainScaB->TabIndex = 53;
        this->nudScanGainScaB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        // 
        // nudScanGainScaG
        // 
        this->nudScanGainScaG->BackColor = System::Drawing::Color::LightGreen;
        this->nudScanGainScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanGainScaG->Location = System::Drawing::Point(196, 100);
        this->nudScanGainScaG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudScanGainScaG->Name = L"nudScanGainScaG";
        this->nudScanGainScaG->Size = System::Drawing::Size(57, 22);
        this->nudScanGainScaG->TabIndex = 52;
        this->nudScanGainScaG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        // 
        // nudScanGainScaR
        // 
        this->nudScanGainScaR->BackColor = System::Drawing::Color::LightCoral;
        this->nudScanGainScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudScanGainScaR->Location = System::Drawing::Point(111, 100);
        this->nudScanGainScaR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudScanGainScaR->Name = L"nudScanGainScaR";
        this->nudScanGainScaR->Size = System::Drawing::Size(57, 22);
        this->nudScanGainScaR->TabIndex = 51;
        this->nudScanGainScaR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
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
        // nudMeasExtR
        // 
        this->nudMeasExtR->BackColor = System::Drawing::Color::LightCoral;
        this->nudMeasExtR->DecimalPlaces = 2;
        this->nudMeasExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasExtR->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasExtR->Location = System::Drawing::Point(85, 454);
        this->nudMeasExtR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasExtR->Name = L"nudMeasExtR";
        this->nudMeasExtR->ReadOnly = true;
        this->nudMeasExtR->Size = System::Drawing::Size(83, 22);
        this->nudMeasExtR->TabIndex = 55;
        this->nudMeasExtR->ValueChanged += gcnew System::EventHandler(this, &Form1::nudMeasExtR_ValueChanged);
        // 
        // nudMeasExtG
        // 
        this->nudMeasExtG->BackColor = System::Drawing::Color::LightGreen;
        this->nudMeasExtG->DecimalPlaces = 2;
        this->nudMeasExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasExtG->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasExtG->Location = System::Drawing::Point(154, 454);
        this->nudMeasExtG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasExtG->Name = L"nudMeasExtG";
        this->nudMeasExtG->ReadOnly = true;
        this->nudMeasExtG->Size = System::Drawing::Size(83, 22);
        this->nudMeasExtG->TabIndex = 56;
        // 
        // nudMeasExtB
        // 
        this->nudMeasExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudMeasExtB->DecimalPlaces = 2;
        this->nudMeasExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasExtB->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasExtB->Location = System::Drawing::Point(224, 454);
        this->nudMeasExtB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasExtB->Name = L"nudMeasExtB";
        this->nudMeasExtB->ReadOnly = true;
        this->nudMeasExtB->Size = System::Drawing::Size(83, 22);
        this->nudMeasExtB->TabIndex = 57;
        // 
        // nudMeasScaB
        // 
        this->nudMeasScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudMeasScaB->DecimalPlaces = 2;
        this->nudMeasScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasScaB->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasScaB->Location = System::Drawing::Point(224, 485);
        this->nudMeasScaB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasScaB->Name = L"nudMeasScaB";
        this->nudMeasScaB->ReadOnly = true;
        this->nudMeasScaB->Size = System::Drawing::Size(83, 22);
        this->nudMeasScaB->TabIndex = 60;
        // 
        // nudMeasScaG
        // 
        this->nudMeasScaG->BackColor = System::Drawing::Color::LightGreen;
        this->nudMeasScaG->DecimalPlaces = 2;
        this->nudMeasScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasScaG->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasScaG->Location = System::Drawing::Point(154, 485);
        this->nudMeasScaG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasScaG->Name = L"nudMeasScaG";
        this->nudMeasScaG->ReadOnly = true;
        this->nudMeasScaG->Size = System::Drawing::Size(83, 22);
        this->nudMeasScaG->TabIndex = 59;
        // 
        // nudMeasScaR
        // 
        this->nudMeasScaR->BackColor = System::Drawing::Color::LightCoral;
        this->nudMeasScaR->DecimalPlaces = 2;
        this->nudMeasScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasScaR->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasScaR->Location = System::Drawing::Point(85, 485);
        this->nudMeasScaR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasScaR->Name = L"nudMeasScaR";
        this->nudMeasScaR->ReadOnly = true;
        this->nudMeasScaR->Size = System::Drawing::Size(83, 22);
        this->nudMeasScaR->TabIndex = 58;
        // 
        // tbFolderPath
        // 
        this->tbFolderPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbFolderPath->Location = System::Drawing::Point(128, 545);
        this->tbFolderPath->Name = L"tbFolderPath";
        this->tbFolderPath->Size = System::Drawing::Size(266, 22);
        this->tbFolderPath->TabIndex = 62;
        // 
        // btnSave
        // 
        this->btnSave->BackColor = System::Drawing::Color::Khaki;
        this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSave->Location = System::Drawing::Point(473, 539);
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
        this->labFolderPath->Location = System::Drawing::Point(12, 545);
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
        // labIntTime
        // 
        this->labIntTime->AutoSize = true;
        this->labIntTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labIntTime->Location = System::Drawing::Point(12, 132);
        this->labIntTime->Name = L"labIntTime";
        this->labIntTime->Size = System::Drawing::Size(81, 16);
        this->labIntTime->TabIndex = 67;
        this->labIntTime->Text = L"Int time Ext";
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
        this->cboxScanIntTimeExtR->Text = L"24";
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
        this->cboxScanIntTimeExtG->Text = L"24";
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
        this->cboxScanIntTimeExtB->Text = L"24";
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
        this->cboxScanIntTimeScaB->Text = L"24";
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
        this->cboxScanIntTimeScaG->Text = L"24";
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
        this->cboxScanIntTimeScaR->Text = L"24";
        this->cboxScanIntTimeScaR->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cboxScanIntTimeScaR_SelectedIndexChanged);
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(13, 159);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(87, 16);
        this->label1->TabIndex = 74;
        this->label1->Text = L"Int time Sca";
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
        this->cboxManualIntTimeSca->Text = L"24";
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
        this->cboxManualIntTimeExt->Text = L"24";
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
        this->nudManualLEDB->Location = System::Drawing::Point(679, 36);
        this->nudManualLEDB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudManualLEDB->Name = L"nudManualLEDB";
        this->nudManualLEDB->Size = System::Drawing::Size(57, 22);
        this->nudManualLEDB->TabIndex = 87;
        this->nudManualLEDB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudManualLEDG
        // 
        this->nudManualLEDG->BackColor = System::Drawing::Color::LightGreen;
        this->nudManualLEDG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudManualLEDG->Location = System::Drawing::Point(599, 36);
        this->nudManualLEDG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudManualLEDG->Name = L"nudManualLEDG";
        this->nudManualLEDG->Size = System::Drawing::Size(57, 22);
        this->nudManualLEDG->TabIndex = 86;
        this->nudManualLEDG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudManualLEDR
        // 
        this->nudManualLEDR->BackColor = System::Drawing::Color::LightCoral;
        this->nudManualLEDR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudManualLEDR->Location = System::Drawing::Point(514, 36);
        this->nudManualLEDR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudManualLEDR->Name = L"nudManualLEDR";
        this->nudManualLEDR->Size = System::Drawing::Size(57, 22);
        this->nudManualLEDR->TabIndex = 85;
        this->nudManualLEDR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
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
        this->labManualLED->Location = System::Drawing::Point(415, 38);
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
        this->cboxManualGainSca->Location = System::Drawing::Point(514, 100);
        this->cboxManualGainSca->Name = L"cboxManualGainSca";
        this->cboxManualGainSca->Size = System::Drawing::Size(57, 21);
        this->cboxManualGainSca->TabIndex = 95;
        this->cboxManualGainSca->Text = L"1";
        // 
        // cboxManualGainExt
        // 
        this->cboxManualGainExt->BackColor = System::Drawing::Color::White;
        this->cboxManualGainExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->cboxManualGainExt->FormattingEnabled = true;
        this->cboxManualGainExt->Location = System::Drawing::Point(514, 73);
        this->cboxManualGainExt->Name = L"cboxManualGainExt";
        this->cboxManualGainExt->Size = System::Drawing::Size(57, 21);
        this->cboxManualGainExt->TabIndex = 94;
        this->cboxManualGainExt->Text = L"1";
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
        // 
        // btnManualMsmt
        // 
        this->btnManualMsmt->BackColor = System::Drawing::Color::Khaki;
        this->btnManualMsmt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnManualMsmt->Location = System::Drawing::Point(565, 426);
        this->btnManualMsmt->Name = L"btnManualMsmt";
        this->btnManualMsmt->Size = System::Drawing::Size(185, 59);
        this->btnManualMsmt->TabIndex = 97;
        this->btnManualMsmt->Text = L"MAKE MANUAL\r\nMEASUREMENT";
        this->btnManualMsmt->UseVisualStyleBackColor = false;
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(834, 577);
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
        this->Controls->Add(this->label1);
        this->Controls->Add(this->cboxScanIntTimeScaB);
        this->Controls->Add(this->cboxScanIntTimeScaG);
        this->Controls->Add(this->cboxScanIntTimeScaR);
        this->Controls->Add(this->cboxScanIntTimeExtB);
        this->Controls->Add(this->cboxScanIntTimeExtG);
        this->Controls->Add(this->cboxScanIntTimeExtR);
        this->Controls->Add(this->labIntTime);
        this->Controls->Add(this->labCOMPort);
        this->Controls->Add(this->cboxCOMPort);
        this->Controls->Add(this->labFolderPath);
        this->Controls->Add(this->btnSave);
        this->Controls->Add(this->tbFolderPath);
        this->Controls->Add(this->nudMeasScaB);
        this->Controls->Add(this->nudMeasScaG);
        this->Controls->Add(this->nudMeasScaR);
        this->Controls->Add(this->nudMeasExtB);
        this->Controls->Add(this->nudMeasExtG);
        this->Controls->Add(this->nudMeasExtR);
        this->Controls->Add(this->nudNumSamples);
        this->Controls->Add(this->nudScanGainScaB);
        this->Controls->Add(this->nudScanGainScaG);
        this->Controls->Add(this->nudScanGainScaR);
        this->Controls->Add(this->nudScanGainExtB);
        this->Controls->Add(this->nudScanGainExtG);
        this->Controls->Add(this->nudScanGainExtR);
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
        this->Controls->Add(this->labLED);
        this->Controls->Add(this->labScanSettings);
        this->Name = L"Form1";
        this->Text = L"BeerSpec GUI";
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanLEDB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainExtB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainExtG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainExtR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainScaB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainScaG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudScanGainScaR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNumSamples))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaR))->EndInit();
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
private: System::Void btnScan_Click(System::Object^ sender, System::EventArgs^ e) {
    if (serialManager1->IsOpen())
    {   
        //Set LED RGB
        String^ serialOut = "#SETTINGSLEDRGB " + System::Convert::ToString(settings->LEDR) + " " + System::Convert::ToString(settings->LEDG) + " " + System::Convert::ToString(settings->LEDB);
        serialManager1->EnqueueSendCommand(serialOut);        
        
        //Set Gains
        serialOut = "#SETTINGSGAINS " + System::Convert::ToString(settings->GainExtR) + " " + System::Convert::ToString(settings->GainExtG) + " " + System::Convert::ToString(settings->GainExtB);
        serialOut = serialOut + " " + System::Convert::ToString(settings->GainScaR) + " " + System::Convert::ToString(settings->GainScaG) + " " + System::Convert::ToString(settings->GainScaB);
        serialManager1->EnqueueSendCommand(serialOut);

        //Set IntTimes
        serialOut = "#SETTINGSINTTIMESS " + System::Convert::ToString(settings->IntTimeExtR) + " " + System::Convert::ToString(settings->IntTimeExtG) + " " + System::Convert::ToString(settings->IntTimeExtB);
        serialOut = serialOut + " " + System::Convert::ToString(settings->IntTimeScaR) + " " + System::Convert::ToString(settings->IntTimeScaG) + " " + System::Convert::ToString(settings->IntTimeScaB);
        serialManager1->EnqueueSendCommand(serialOut);

        //Send the queued commands and process the received ones
        serialManager1->SendQueuedCommands();
        System::Threading::Thread::Sleep(1000);
        serialManager1->ProcessReceivedCommands();    

    }
    else
    {
        UpdatertbSerialReceived("Serial port not open");
    }
    
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
    csvSaver->SaveDataToFile(settings, meas);
}
private: System::Void tbNotes_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    meas->Notes = tbNotes->Text;
}
private: System::Void nudScanLEDR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->LEDR = Decimal::ToInt32(nudScanLEDR->Value);
}
private: System::Void nudScanLEDG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->LEDG = Decimal::ToInt32(nudScanLEDG->Value);
}
private: System::Void nudScanLEDB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->LEDB = Decimal::ToInt32(nudScanLEDB->Value);
}
private: System::Void nudScanGainExtR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainExtR = Decimal::ToInt32(nudScanGainExtR->Value);
}
private: System::Void nudScanGainExtG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainExtG = Decimal::ToInt32(nudScanGainExtG->Value);
}
private: System::Void nudScanGainExtB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainExtB = Decimal::ToInt32(nudScanGainExtB->Value);
}
private: System::Void nudScanGainScaR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainScaR = Decimal::ToInt32(nudScanGainScaR->Value);
}
private: System::Void nudScanGainScaG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainScaG = Decimal::ToInt32(nudScanGainScaG->Value);
}
  private: System::Void nudScanGainScaB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
      settings->GainScaB = Decimal::ToInt32(nudScanGainScaB->Value);
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
    settings->IntTimeExtR = System::Convert::ToInt32(cboxScanIntTimeExtR->SelectedValue);
}
private: System::Void cboxScanIntTimeExtG_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->IntTimeExtG = System::Convert::ToInt32(cboxScanIntTimeExtG->SelectedValue);
}
private: System::Void cboxScanIntTimeExtB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->IntTimeExtB = System::Convert::ToInt32(cboxScanIntTimeExtB->SelectedValue);
}
private: System::Void cboxScanIntTimeScaR_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->IntTimeScaR = System::Convert::ToInt32(cboxScanIntTimeScaR->SelectedValue);
}
private: System::Void cboxScanIntTimeScaG_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->IntTimeScaG = System::Convert::ToInt32(cboxScanIntTimeScaG->SelectedValue);
}
private: System::Void cboxScanIntTimeScaB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->IntTimeScaB = System::Convert::ToInt32(cboxScanIntTimeScaB->SelectedValue);
}


private:
    bool isWaitingForNewLine = false;
    System::Text::StringBuilder^ receivedDataBuilder = gcnew System::Text::StringBuilder();

void serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
    System::String^ receivedData = serialPort1->ReadExisting();
    receivedDataBuilder->Append(receivedData);

    // Check if the received data contains a new line character
    if (receivedData->Contains("\n")) {
        //Make the complete command of everything up intil the \n
        int newLineIndex = receivedDataBuilder->ToString()->LastIndexOf("\n");
        System::String^ completeData = receivedDataBuilder->ToString()->Substring(0, newLineIndex + 1);

        // Check if the received data came from the Arduino command
        if (completeData->StartsWith("@")) {
            // Update the received commands RichTextBox
            Invoke(gcnew Action<System::String^>(this, &Form1::UpdatertbSerialReceived), completeData);
        }

        // Clear the StringBuilder and stop waiting for a new line
        receivedDataBuilder->Clear();
        isWaitingForNewLine = false;
    }
    else {
        isWaitingForNewLine = true;
    }
}



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
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject


