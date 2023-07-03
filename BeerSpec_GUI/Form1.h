#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include "SettingsClass.h"
#include "MeasClass.h"

namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
    Form1(void)
    {
      InitializeComponent();
      
      //Settings object to store instrument settings
      //settings = gcnew SettingsClass();
      //SettingsClass^ settings(127,128,129);
      SettingsClass^ settings = gcnew SettingsClass;

      //Measurements object to store measurements
      //meas = gcnew MeasClass();
      MeasClass^ meas;
      


      //Bind the TextBox control to the IntValue property
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
  





  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;
  
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
    System::Windows::Forms::TextBox^ tbMeasExtR;
    System::Windows::Forms::TextBox^ tbMeasExtG;
    System::Windows::Forms::TextBox^ tbMeasExtB;
    System::Windows::Forms::Label^ labMeasSca;
    System::Windows::Forms::TextBox^ tbMeasScaR;
    System::Windows::Forms::TextBox^ tbMeasScaG;
    System::Windows::Forms::TextBox^ tbMeasScaB;
    System::Windows::Forms::Label^ labNotes;
    System::Windows::Forms::TextBox^ tbNotes;
    System::Windows::Forms::CheckBox^ cboxAutoSave;
    System::Windows::Forms::Button^ btnSet;
 



    System::Windows::Forms::Button^ btnMakeGetMsmt;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
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
        this->tbMeasExtB = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasExtG = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasExtR = (gcnew System::Windows::Forms::TextBox());
        this->LabMeasExt = (gcnew System::Windows::Forms::Label());
        this->labMeasSca = (gcnew System::Windows::Forms::Label());
        this->tbMeasScaB = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasScaG = (gcnew System::Windows::Forms::TextBox());
        this->tbMeasScaR = (gcnew System::Windows::Forms::TextBox());
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
        this->cboxAutoSave->Location = System::Drawing::Point(538, 240);
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
        this->btnMakeGetMsmt->Location = System::Drawing::Point(355, 222);
        this->btnMakeGetMsmt->Name = L"btnMakeGetMsmt";
        this->btnMakeGetMsmt->Size = System::Drawing::Size(168, 48);
        this->btnMakeGetMsmt->TabIndex = 32;
        this->btnMakeGetMsmt->Text = L"MAKE && GET\r\nMEASUREMENTS";
        this->btnMakeGetMsmt->UseVisualStyleBackColor = false;
        this->btnMakeGetMsmt->Click += gcnew System::EventHandler(this, &Form1::btnMakeGetMsmt_Click);
        // 
        // tbMeasExtB
        // 
        this->tbMeasExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbMeasExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasExtB->Location = System::Drawing::Point(276, 222);
        this->tbMeasExtB->Name = L"tbMeasExtB";
        this->tbMeasExtB->Size = System::Drawing::Size(57, 22);
        this->tbMeasExtB->TabIndex = 35;
        this->tbMeasExtB->Text = L"128";
        // 
        // tbMeasExtG
        // 
        this->tbMeasExtG->BackColor = System::Drawing::Color::LightGreen;
        this->tbMeasExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasExtG->Location = System::Drawing::Point(196, 222);
        this->tbMeasExtG->Name = L"tbMeasExtG";
        this->tbMeasExtG->Size = System::Drawing::Size(57, 22);
        this->tbMeasExtG->TabIndex = 34;
        this->tbMeasExtG->Text = L"128";
        // 
        // tbMeasExtR
        // 
        this->tbMeasExtR->BackColor = System::Drawing::Color::LightCoral;
        this->tbMeasExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasExtR->Location = System::Drawing::Point(111, 222);
        this->tbMeasExtR->Name = L"tbMeasExtR";
        this->tbMeasExtR->Size = System::Drawing::Size(57, 22);
        this->tbMeasExtR->TabIndex = 33;
        this->tbMeasExtR->Text = L"128";
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
        // tbMeasScaB
        // 
        this->tbMeasScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbMeasScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasScaB->Location = System::Drawing::Point(276, 250);
        this->tbMeasScaB->Name = L"tbMeasScaB";
        this->tbMeasScaB->Size = System::Drawing::Size(57, 22);
        this->tbMeasScaB->TabIndex = 39;
        this->tbMeasScaB->Text = L"128";
        // 
        // tbMeasScaG
        // 
        this->tbMeasScaG->BackColor = System::Drawing::Color::LightGreen;
        this->tbMeasScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasScaG->Location = System::Drawing::Point(196, 250);
        this->tbMeasScaG->Name = L"tbMeasScaG";
        this->tbMeasScaG->Size = System::Drawing::Size(57, 22);
        this->tbMeasScaG->TabIndex = 38;
        this->tbMeasScaG->Text = L"128";
        // 
        // tbMeasScaR
        // 
        this->tbMeasScaR->BackColor = System::Drawing::Color::LightCoral;
        this->tbMeasScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasScaR->Location = System::Drawing::Point(111, 250);
        this->tbMeasScaR->Name = L"tbMeasScaR";
        this->tbMeasScaR->Size = System::Drawing::Size(57, 22);
        this->tbMeasScaR->TabIndex = 37;
        this->tbMeasScaR->Text = L"128";
        // 
        // tbMeasTime
        // 
        this->tbMeasTime->BackColor = System::Drawing::SystemColors::Window;
        this->tbMeasTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbMeasTime->Location = System::Drawing::Point(111, 194);
        this->tbMeasTime->Name = L"tbMeasTime";
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
        this->tbNotes->Location = System::Drawing::Point(323, 299);
        this->tbNotes->Name = L"tbNotes";
        this->tbNotes->Size = System::Drawing::Size(321, 20);
        this->tbNotes->TabIndex = 43;
        // 
        // labNotes
        // 
        this->labNotes->AutoSize = true;
        this->labNotes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labNotes->Location = System::Drawing::Point(256, 299);
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
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(682, 372);
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
        this->Controls->Add(this->tbMeasScaB);
        this->Controls->Add(this->tbMeasScaG);
        this->Controls->Add(this->tbMeasScaR);
        this->Controls->Add(this->LabMeasExt);
        this->Controls->Add(this->tbMeasExtB);
        this->Controls->Add(this->tbMeasExtG);
        this->Controls->Add(this->tbMeasExtR);
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
}
private: System::Void labNumSamples_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnMakeGetMsmt_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbLEDR_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void in_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

