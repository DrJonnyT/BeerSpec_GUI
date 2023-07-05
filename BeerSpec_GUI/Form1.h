#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include "SettingsClass.h"
#include "MeasClass.h"
#include "CSVSaver.h"
//#include "SerialComms.h"




namespace CppCLRWinFormsProject {

  using namespace System;
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
      SettingsClass^ settings;
      System::IO::Ports::SerialPort^ serialPort1;
  private: System::Windows::Forms::Label^ labFolderPath;
  
  private: System::Windows::Forms::ComboBox^ cboxCOMPort;
  private: System::Windows::Forms::Label^ labCOMPort;

         MeasClass^ meas;


  public:
    Form1(void)
    {
      InitializeComponent();

      //Find COM ports
      findPorts();

      //serialPort1 = gcnew System::IO::Ports::SerialPort;
      
      //Settings object to store instrument settings
      settings = gcnew SettingsClass;

      //Measurements object to store measurements
      meas = gcnew MeasClass;   

      //CSVSaver object
      //CSVSaver^ csvSaver = gcnew CSVSaver;
      csvSaver = gcnew CSVSaver();


      //Bind the TextBox control to the settings properties
      nudLEDR->DataBindings->Add("Value", settings, "LEDR");
      nudLEDG->DataBindings->Add("Value", settings, "LEDG");
      nudLEDB->DataBindings->Add("Value", settings, "LEDB");
      nudGainExtR->DataBindings->Add("Value", settings, "GainExtR");
      nudGainExtG->DataBindings->Add("Value", settings, "GainExtG");
      nudGainExtB->DataBindings->Add("Value", settings, "GainExtB");
      nudGainScaR->DataBindings->Add("Value", settings, "GainScaR");
      nudGainScaG->DataBindings->Add("Value", settings, "GainScaG");
      nudGainScaB->DataBindings->Add("Value", settings, "GainScaB");
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
  private: System::Windows::Forms::TextBox^ out_textBox;
  private: System::Windows::Forms::TextBox^ in_textBox;
  private: System::Windows::Forms::Button^ button_plus_1;
  private: System::Windows::Forms::Button^ button_plus_2;
  private: System::ComponentModel::IContainer^ components;






  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>

  
    //Define settings part of form
    System::Windows::Forms::Label^ labSettings;
    System::Windows::Forms::Label^ labLED;
    System::Windows::Forms::NumericUpDown^ nudLEDR;
    System::Windows::Forms::NumericUpDown^ nudLEDG;
    System::Windows::Forms::NumericUpDown^ nudLEDB;

    System::Windows::Forms::Label^ labGainExt;
    System::Windows::Forms::NumericUpDown^ nudGainExtB;
    System::Windows::Forms::NumericUpDown^ nudGainExtG;
    System::Windows::Forms::NumericUpDown^ nudGainExtR;

    System::Windows::Forms::Label^ labGainSca;
    System::Windows::Forms::NumericUpDown^ nudGainScaB;
    System::Windows::Forms::NumericUpDown^ nudGainScaG;
    System::Windows::Forms::NumericUpDown^ nudGainScaR;

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
    System::Windows::Forms::CheckBox^ cboxAutoSave;
    System::Windows::Forms::Button^ btnSet;
private: System::Windows::Forms::NumericUpDown^ nudMeasExtR;
private: System::Windows::Forms::NumericUpDown^ nudMeasExtG;
private: System::Windows::Forms::NumericUpDown^ nudMeasExtB;
private: System::Windows::Forms::NumericUpDown^ nudMeasScaB;
private: System::Windows::Forms::NumericUpDown^ nudMeasScaG;
private: System::Windows::Forms::NumericUpDown^ nudMeasScaR;


private: System::Windows::Forms::TextBox^ tbFolderPath;

private: System::Windows::Forms::Button^ btnSave;






    System::Windows::Forms::Button^ btnMakeGetMsmt;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->components = (gcnew System::ComponentModel::Container());
        this->out_textBox = (gcnew System::Windows::Forms::TextBox());
        this->in_textBox = (gcnew System::Windows::Forms::TextBox());
        this->button_plus_1 = (gcnew System::Windows::Forms::Button());
        this->button_plus_2 = (gcnew System::Windows::Forms::Button());
        this->labSettings = (gcnew System::Windows::Forms::Label());
        this->labLED = (gcnew System::Windows::Forms::Label());
        this->labGainExt = (gcnew System::Windows::Forms::Label());
        this->labGainSca = (gcnew System::Windows::Forms::Label());
        this->labNumSamples = (gcnew System::Windows::Forms::Label());
        this->labMeasurements = (gcnew System::Windows::Forms::Label());
        this->cboxAutoSave = (gcnew System::Windows::Forms::CheckBox());
        this->btnSet = (gcnew System::Windows::Forms::Button());
        this->btnMakeGetMsmt = (gcnew System::Windows::Forms::Button());
        this->LabMeasExt = (gcnew System::Windows::Forms::Label());
        this->labMeasSca = (gcnew System::Windows::Forms::Label());
        this->tbMeasTime = (gcnew System::Windows::Forms::TextBox());
        this->labMeasTime = (gcnew System::Windows::Forms::Label());
        this->tbNotes = (gcnew System::Windows::Forms::TextBox());
        this->labNotes = (gcnew System::Windows::Forms::Label());
        this->nudLEDR = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudLEDG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudLEDB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudGainExtB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudGainExtG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudGainExtR = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudGainScaB = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudGainScaG = (gcnew System::Windows::Forms::NumericUpDown());
        this->nudGainScaR = (gcnew System::Windows::Forms::NumericUpDown());
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
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLEDR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLEDG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLEDB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainExtB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainExtG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainExtR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainScaB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainScaG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainScaR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNumSamples))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtR))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaB))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaG))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaR))->BeginInit();
        this->SuspendLayout();
        // 
        // out_textBox
        // 
        this->out_textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->out_textBox->Location = System::Drawing::Point(12, 286);
        this->out_textBox->Multiline = true;
        this->out_textBox->Name = L"out_textBox";
        this->out_textBox->Size = System::Drawing::Size(156, 74);
        this->out_textBox->TabIndex = 0;
        // 
        // in_textBox
        // 
        this->in_textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->in_textBox->Location = System::Drawing::Point(570, 38);
        this->in_textBox->Name = L"in_textBox";
        this->in_textBox->Size = System::Drawing::Size(100, 20);
        this->in_textBox->TabIndex = 1;
        this->in_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::in_textBox_TextChanged);
        // 
        // button_plus_1
        // 
        this->button_plus_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->button_plus_1->Location = System::Drawing::Point(570, 68);
        this->button_plus_1->Name = L"button_plus_1";
        this->button_plus_1->Size = System::Drawing::Size(75, 23);
        this->button_plus_1->TabIndex = 2;
        this->button_plus_1->Text = L"plus 1";
        this->button_plus_1->UseVisualStyleBackColor = true;
        this->button_plus_1->Click += gcnew System::EventHandler(this, &Form1::button_plus_1_Click);
        // 
        // button_plus_2
        // 
        this->button_plus_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->button_plus_2->Location = System::Drawing::Point(570, 97);
        this->button_plus_2->Name = L"button_plus_2";
        this->button_plus_2->Size = System::Drawing::Size(75, 23);
        this->button_plus_2->TabIndex = 3;
        this->button_plus_2->Text = L"plus 2";
        this->button_plus_2->UseVisualStyleBackColor = true;
        this->button_plus_2->Click += gcnew System::EventHandler(this, &Form1::button_plus_2_Click);
        // 
        // labSettings
        // 
        this->labSettings->AutoSize = true;
        this->labSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labSettings->Location = System::Drawing::Point(12, 9);
        this->labSettings->Name = L"labSettings";
        this->labSettings->Size = System::Drawing::Size(111, 24);
        this->labSettings->TabIndex = 5;
        this->labSettings->Text = L"SETTINGS";
        this->labSettings->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
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
        this->labNumSamples->Location = System::Drawing::Point(12, 132);
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
        this->labMeasurements->Location = System::Drawing::Point(12, 167);
        this->labMeasurements->Name = L"labMeasurements";
        this->labMeasurements->Size = System::Drawing::Size(182, 24);
        this->labMeasurements->TabIndex = 27;
        this->labMeasurements->Text = L"MEASUREMENTS";
        // 
        // cboxAutoSave
        // 
        this->cboxAutoSave->AutoSize = true;
        this->cboxAutoSave->Checked = true;
        this->cboxAutoSave->CheckState = System::Windows::Forms::CheckState::Checked;
        this->cboxAutoSave->Location = System::Drawing::Point(570, 240);
        this->cboxAutoSave->Name = L"cboxAutoSave";
        this->cboxAutoSave->Size = System::Drawing::Size(71, 17);
        this->cboxAutoSave->TabIndex = 30;
        this->cboxAutoSave->Text = L"Autosave";
        this->cboxAutoSave->UseVisualStyleBackColor = true;
        // 
        // btnSet
        // 
        this->btnSet->BackColor = System::Drawing::Color::Khaki;
        this->btnSet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSet->Location = System::Drawing::Point(387, 63);
        this->btnSet->Name = L"btnSet";
        this->btnSet->Size = System::Drawing::Size(75, 33);
        this->btnSet->TabIndex = 31;
        this->btnSet->Text = L"SET";
        this->btnSet->UseVisualStyleBackColor = false;
        this->btnSet->Click += gcnew System::EventHandler(this, &Form1::btnSet_Click);
        // 
        // btnMakeGetMsmt
        // 
        this->btnMakeGetMsmt->BackColor = System::Drawing::Color::Khaki;
        this->btnMakeGetMsmt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnMakeGetMsmt->Location = System::Drawing::Point(387, 222);
        this->btnMakeGetMsmt->Name = L"btnMakeGetMsmt";
        this->btnMakeGetMsmt->Size = System::Drawing::Size(168, 48);
        this->btnMakeGetMsmt->TabIndex = 32;
        this->btnMakeGetMsmt->Text = L"MAKE && GET\r\nMEASUREMENTS";
        this->btnMakeGetMsmt->UseVisualStyleBackColor = false;
        this->btnMakeGetMsmt->Click += gcnew System::EventHandler(this, &Form1::btnMakeGetMsmt_Click);
        // 
        // LabMeasExt
        // 
        this->LabMeasExt->AutoSize = true;
        this->LabMeasExt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->LabMeasExt->Location = System::Drawing::Point(12, 224);
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
        this->labMeasSca->Location = System::Drawing::Point(12, 252);
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
        this->tbMeasTime->Location = System::Drawing::Point(111, 194);
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
        this->labMeasTime->Location = System::Drawing::Point(12, 193);
        this->labMeasTime->Name = L"labMeasTime";
        this->labMeasTime->Size = System::Drawing::Size(47, 20);
        this->labMeasTime->TabIndex = 41;
        this->labMeasTime->Text = L"Time";
        // 
        // tbNotes
        // 
        this->tbNotes->Location = System::Drawing::Point(320, 286);
        this->tbNotes->Name = L"tbNotes";
        this->tbNotes->Size = System::Drawing::Size(321, 20);
        this->tbNotes->TabIndex = 43;
        this->tbNotes->TextChanged += gcnew System::EventHandler(this, &Form1::tbNotes_TextChanged);
        // 
        // labNotes
        // 
        this->labNotes->AutoSize = true;
        this->labNotes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labNotes->Location = System::Drawing::Point(253, 284);
        this->labNotes->Name = L"labNotes";
        this->labNotes->Size = System::Drawing::Size(61, 20);
        this->labNotes->TabIndex = 44;
        this->labNotes->Text = L"Notes:";
        // 
        // nudLEDR
        // 
        this->nudLEDR->BackColor = System::Drawing::Color::LightCoral;
        this->nudLEDR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudLEDR->Location = System::Drawing::Point(111, 36);
        this->nudLEDR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudLEDR->Name = L"nudLEDR";
        this->nudLEDR->Size = System::Drawing::Size(57, 22);
        this->nudLEDR->TabIndex = 45;
        this->nudLEDR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        this->nudLEDR->ValueChanged += gcnew System::EventHandler(this, &Form1::nudLEDR_ValueChanged);
        // 
        // nudLEDG
        // 
        this->nudLEDG->BackColor = System::Drawing::Color::LightGreen;
        this->nudLEDG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudLEDG->Location = System::Drawing::Point(196, 36);
        this->nudLEDG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudLEDG->Name = L"nudLEDG";
        this->nudLEDG->Size = System::Drawing::Size(57, 22);
        this->nudLEDG->TabIndex = 46;
        this->nudLEDG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudLEDB
        // 
        this->nudLEDB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudLEDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudLEDB->Location = System::Drawing::Point(276, 36);
        this->nudLEDB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
        this->nudLEDB->Name = L"nudLEDB";
        this->nudLEDB->Size = System::Drawing::Size(57, 22);
        this->nudLEDB->TabIndex = 47;
        this->nudLEDB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudGainExtB
        // 
        this->nudGainExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudGainExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudGainExtB->Location = System::Drawing::Point(276, 68);
        this->nudGainExtB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudGainExtB->Name = L"nudGainExtB";
        this->nudGainExtB->Size = System::Drawing::Size(57, 22);
        this->nudGainExtB->TabIndex = 50;
        this->nudGainExtB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudGainExtG
        // 
        this->nudGainExtG->BackColor = System::Drawing::Color::LightGreen;
        this->nudGainExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudGainExtG->Location = System::Drawing::Point(196, 68);
        this->nudGainExtG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudGainExtG->Name = L"nudGainExtG";
        this->nudGainExtG->Size = System::Drawing::Size(57, 22);
        this->nudGainExtG->TabIndex = 49;
        this->nudGainExtG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudGainExtR
        // 
        this->nudGainExtR->BackColor = System::Drawing::Color::LightCoral;
        this->nudGainExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudGainExtR->Location = System::Drawing::Point(111, 68);
        this->nudGainExtR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudGainExtR->Name = L"nudGainExtR";
        this->nudGainExtR->Size = System::Drawing::Size(57, 22);
        this->nudGainExtR->TabIndex = 48;
        this->nudGainExtR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        this->nudGainExtR->ValueChanged += gcnew System::EventHandler(this, &Form1::nudGainExtR_ValueChanged);
        // 
        // nudGainScaB
        // 
        this->nudGainScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->nudGainScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudGainScaB->Location = System::Drawing::Point(276, 100);
        this->nudGainScaB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudGainScaB->Name = L"nudGainScaB";
        this->nudGainScaB->Size = System::Drawing::Size(57, 22);
        this->nudGainScaB->TabIndex = 53;
        this->nudGainScaB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudGainScaG
        // 
        this->nudGainScaG->BackColor = System::Drawing::Color::LightGreen;
        this->nudGainScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudGainScaG->Location = System::Drawing::Point(196, 100);
        this->nudGainScaG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudGainScaG->Name = L"nudGainScaG";
        this->nudGainScaG->Size = System::Drawing::Size(57, 22);
        this->nudGainScaG->TabIndex = 52;
        this->nudGainScaG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudGainScaR
        // 
        this->nudGainScaR->BackColor = System::Drawing::Color::LightCoral;
        this->nudGainScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudGainScaR->Location = System::Drawing::Point(111, 100);
        this->nudGainScaR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
        this->nudGainScaR->Name = L"nudGainScaR";
        this->nudGainScaR->Size = System::Drawing::Size(57, 22);
        this->nudGainScaR->TabIndex = 51;
        this->nudGainScaR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
        // 
        // nudNumSamples
        // 
        this->nudNumSamples->BackColor = System::Drawing::Color::White;
        this->nudNumSamples->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudNumSamples->Location = System::Drawing::Point(111, 132);
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
        this->nudMeasExtR->Location = System::Drawing::Point(111, 222);
        this->nudMeasExtR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
        this->nudMeasExtR->Name = L"nudMeasExtR";
        this->nudMeasExtR->ReadOnly = true;
        this->nudMeasExtR->Size = System::Drawing::Size(83, 22);
        this->nudMeasExtR->TabIndex = 55;
        this->nudMeasExtR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 18, 0, 0, 65536 });
        // 
        // nudMeasExtG
        // 
        this->nudMeasExtG->BackColor = System::Drawing::Color::LightGreen;
        this->nudMeasExtG->DecimalPlaces = 2;
        this->nudMeasExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->nudMeasExtG->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
        this->nudMeasExtG->Location = System::Drawing::Point(180, 222);
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
        this->nudMeasExtB->Location = System::Drawing::Point(250, 222);
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
        this->nudMeasScaB->Location = System::Drawing::Point(250, 253);
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
        this->nudMeasScaG->Location = System::Drawing::Point(180, 253);
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
        this->nudMeasScaR->Location = System::Drawing::Point(111, 253);
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
        this->tbFolderPath->Location = System::Drawing::Point(364, 313);
        this->tbFolderPath->Name = L"tbFolderPath";
        this->tbFolderPath->Size = System::Drawing::Size(266, 22);
        this->tbFolderPath->TabIndex = 62;
        this->tbFolderPath->TextChanged += gcnew System::EventHandler(this, &Form1::tbFolderPath_TextChanged);
        // 
        // btnSave
        // 
        this->btnSave->BackColor = System::Drawing::Color::Khaki;
        this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSave->Location = System::Drawing::Point(250, 341);
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
        this->labFolderPath->Location = System::Drawing::Point(248, 313);
        this->labFolderPath->Name = L"labFolderPath";
        this->labFolderPath->Size = System::Drawing::Size(110, 20);
        this->labFolderPath->TabIndex = 64;
        this->labFolderPath->Text = L"Save Folder:";
        // 
        // cboxCOMPort
        // 
        this->cboxCOMPort->FormattingEnabled = true;
        this->cboxCOMPort->Location = System::Drawing::Point(505, 167);
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
        this->labCOMPort->Location = System::Drawing::Point(459, 168);
        this->labCOMPort->Name = L"labCOMPort";
        this->labCOMPort->Size = System::Drawing::Size(40, 16);
        this->labCOMPort->TabIndex = 66;
        this->labCOMPort->Text = L"COM";
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(682, 372);
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
        this->Controls->Add(this->nudGainScaB);
        this->Controls->Add(this->nudGainScaG);
        this->Controls->Add(this->nudGainScaR);
        this->Controls->Add(this->nudGainExtB);
        this->Controls->Add(this->nudGainExtG);
        this->Controls->Add(this->nudGainExtR);
        this->Controls->Add(this->nudLEDB);
        this->Controls->Add(this->nudLEDG);
        this->Controls->Add(this->nudLEDR);
        this->Controls->Add(this->labNotes);
        this->Controls->Add(this->tbNotes);
        this->Controls->Add(this->tbMeasTime);
        this->Controls->Add(this->labMeasTime);
        this->Controls->Add(this->labMeasSca);
        this->Controls->Add(this->LabMeasExt);
        this->Controls->Add(this->btnMakeGetMsmt);
        this->Controls->Add(this->btnSet);
        this->Controls->Add(this->cboxAutoSave);
        this->Controls->Add(this->labMeasurements);
        this->Controls->Add(this->labNumSamples);
        this->Controls->Add(this->labGainSca);
        this->Controls->Add(this->labGainExt);
        this->Controls->Add(this->labLED);
        this->Controls->Add(this->labSettings);
        this->Controls->Add(this->button_plus_2);
        this->Controls->Add(this->button_plus_1);
        this->Controls->Add(this->in_textBox);
        this->Controls->Add(this->out_textBox);
        this->Name = L"Form1";
        this->Text = L"Form1";
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLEDR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLEDG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLEDB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainExtB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainExtG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainExtR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainScaB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainScaG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudGainScaR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNumSamples))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtR))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasExtB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaB))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaG))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudMeasScaR))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.

  private: System::Void button_plus_1_Click(System::Object^ sender, System::EventArgs^ e)
  {
    int n = Convert::ToInt32(in_textBox->Text);
    int result = N_header_1::plus_1(n);
    out_textBox->AppendText(String::Format("plus_1({0})={1}\r\n", n, result));
  }

  private: System::Void button_plus_2_Click(System::Object^ sender, System::EventArgs^ e)
  {
    N_header_2::plus_2_Click(in_textBox, out_textBox);
  }


  private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
  }

private: System::Void labLEDR_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnSet_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->serialPort1->IsOpen)
    {
        this->serialPort1->WriteLine("#SETLED 128 0 0");
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



private: System::Void tbFolderPath_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    csvSaver->FolderPath = tbFolderPath->Text;
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
private: System::Void nudLEDR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->LEDR = Decimal::ToInt32(nudLEDR->Value);
}
private: System::Void nudLEDG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->LEDG = Decimal::ToInt32(nudLEDG->Value);
}
private: System::Void nudLEDB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->LEDB = Decimal::ToInt32(nudLEDB->Value);
}
private: System::Void nudGainExtR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainExtR = Decimal::ToInt32(nudGainExtR->Value);
}
private: System::Void nudGainExtG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainExtG = Decimal::ToInt32(nudGainExtG->Value);
}
private: System::Void nudGainExtB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainExtB = Decimal::ToInt32(nudGainExtB->Value);
}
private: System::Void nudGainScaR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainScaR = Decimal::ToInt32(nudGainScaR->Value);
}
private: System::Void nudGainScaG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    settings->GainScaG = Decimal::ToInt32(nudGainScaG->Value);
}
  private: System::Void nudGainScaB_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
      settings->GainScaB = Decimal::ToInt32(nudGainScaB->Value);
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
    //close existing serialPort
    this->serialPort1->Close();

    // make sure port isn't open	
    if (!this->serialPort1->IsOpen) {
        this->serialPort1->PortName = this->cboxCOMPort->Text;
        //open serial port 
        this->serialPort1->Open();
    }
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject


