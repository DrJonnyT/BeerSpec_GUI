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
      SettingsClass settings;

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
    System::Windows::Forms::TextBox^ tbLEDR;
    System::Windows::Forms::TextBox^ tbLEDG;
    System::Windows::Forms::TextBox^ tbLEDB;
    System::Windows::Forms::Label^ labGainExt;
    System::Windows::Forms::TextBox^ tbGainExtR;
    System::Windows::Forms::TextBox^ tbGainExtG;
    System::Windows::Forms::TextBox^ tbGainExtB;
    System::Windows::Forms::Label^ labGainSca;
    System::Windows::Forms::TextBox^ tbGainScaR;
    System::Windows::Forms::TextBox^ tbGainScaG;
    System::Windows::Forms::TextBox^ tbGainScaB;
    System::Windows::Forms::Label^ labNumSamples;
    System::Windows::Forms::TextBox^ tbNumSamples;


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
        this->tbLEDR = (gcnew System::Windows::Forms::TextBox());
        this->tbLEDG = (gcnew System::Windows::Forms::TextBox());
        this->tbLEDB = (gcnew System::Windows::Forms::TextBox());
        this->labLED = (gcnew System::Windows::Forms::Label());
        this->labGainExt = (gcnew System::Windows::Forms::Label());
        this->tbGainExtB = (gcnew System::Windows::Forms::TextBox());
        this->tbGainExtG = (gcnew System::Windows::Forms::TextBox());
        this->tbGainExtR = (gcnew System::Windows::Forms::TextBox());
        this->labGainSca = (gcnew System::Windows::Forms::Label());
        this->tbGainScaB = (gcnew System::Windows::Forms::TextBox());
        this->tbGainScaG = (gcnew System::Windows::Forms::TextBox());
        this->tbGainScaR = (gcnew System::Windows::Forms::TextBox());
        this->labNumSamples = (gcnew System::Windows::Forms::Label());
        this->tbNumSamples = (gcnew System::Windows::Forms::TextBox());
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
        // tbLEDR
        // 
        this->tbLEDR->BackColor = System::Drawing::Color::LightCoral;
        this->tbLEDR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbLEDR->Location = System::Drawing::Point(111, 36);
        this->tbLEDR->Name = L"tbLEDR";
        this->tbLEDR->Size = System::Drawing::Size(57, 22);
        this->tbLEDR->TabIndex = 6;
        this->tbLEDR->Text = L"128";
        this->tbLEDR->TextChanged += gcnew System::EventHandler(this, &Form1::tbLEDR_TextChanged);
        // 
        // tbLEDG
        // 
        this->tbLEDG->BackColor = System::Drawing::Color::LightGreen;
        this->tbLEDG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbLEDG->Location = System::Drawing::Point(196, 36);
        this->tbLEDG->Name = L"tbLEDG";
        this->tbLEDG->Size = System::Drawing::Size(57, 22);
        this->tbLEDG->TabIndex = 7;
        this->tbLEDG->Text = L"128";
        // 
        // tbLEDB
        // 
        this->tbLEDB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbLEDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbLEDB->Location = System::Drawing::Point(276, 36);
        this->tbLEDB->Name = L"tbLEDB";
        this->tbLEDB->Size = System::Drawing::Size(57, 22);
        this->tbLEDB->TabIndex = 8;
        this->tbLEDB->Text = L"128";
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
        // tbGainExtB
        // 
        this->tbGainExtB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbGainExtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbGainExtB->Location = System::Drawing::Point(276, 69);
        this->tbGainExtB->Name = L"tbGainExtB";
        this->tbGainExtB->Size = System::Drawing::Size(57, 22);
        this->tbGainExtB->TabIndex = 15;
        this->tbGainExtB->Text = L"128";
        // 
        // tbGainExtG
        // 
        this->tbGainExtG->BackColor = System::Drawing::Color::LightGreen;
        this->tbGainExtG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbGainExtG->Location = System::Drawing::Point(196, 69);
        this->tbGainExtG->Name = L"tbGainExtG";
        this->tbGainExtG->Size = System::Drawing::Size(57, 22);
        this->tbGainExtG->TabIndex = 14;
        this->tbGainExtG->Text = L"128";
        // 
        // tbGainExtR
        // 
        this->tbGainExtR->BackColor = System::Drawing::Color::LightCoral;
        this->tbGainExtR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbGainExtR->Location = System::Drawing::Point(111, 69);
        this->tbGainExtR->Name = L"tbGainExtR";
        this->tbGainExtR->Size = System::Drawing::Size(57, 22);
        this->tbGainExtR->TabIndex = 13;
        this->tbGainExtR->Text = L"128";
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
        // tbGainScaB
        // 
        this->tbGainScaB->BackColor = System::Drawing::Color::DeepSkyBlue;
        this->tbGainScaB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbGainScaB->Location = System::Drawing::Point(276, 98);
        this->tbGainScaB->Name = L"tbGainScaB";
        this->tbGainScaB->Size = System::Drawing::Size(57, 22);
        this->tbGainScaB->TabIndex = 22;
        this->tbGainScaB->Text = L"128";
        // 
        // tbGainScaG
        // 
        this->tbGainScaG->BackColor = System::Drawing::Color::LightGreen;
        this->tbGainScaG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbGainScaG->Location = System::Drawing::Point(196, 98);
        this->tbGainScaG->Name = L"tbGainScaG";
        this->tbGainScaG->Size = System::Drawing::Size(57, 22);
        this->tbGainScaG->TabIndex = 21;
        this->tbGainScaG->Text = L"128";
        // 
        // tbGainScaR
        // 
        this->tbGainScaR->BackColor = System::Drawing::Color::LightCoral;
        this->tbGainScaR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbGainScaR->Location = System::Drawing::Point(111, 98);
        this->tbGainScaR->Name = L"tbGainScaR";
        this->tbGainScaR->Size = System::Drawing::Size(57, 22);
        this->tbGainScaR->TabIndex = 20;
        this->tbGainScaR->Text = L"128";
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
        // tbNumSamples
        // 
        this->tbNumSamples->BackColor = System::Drawing::SystemColors::Window;
        this->tbNumSamples->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tbNumSamples->Location = System::Drawing::Point(111, 132);
        this->tbNumSamples->Name = L"tbNumSamples";
        this->tbNumSamples->Size = System::Drawing::Size(57, 22);
        this->tbNumSamples->TabIndex = 25;
        this->tbNumSamples->Text = L"1";
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
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(682, 372);
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
        this->Controls->Add(this->tbNumSamples);
        this->Controls->Add(this->labNumSamples);
        this->Controls->Add(this->labGainSca);
        this->Controls->Add(this->tbGainScaB);
        this->Controls->Add(this->tbGainScaG);
        this->Controls->Add(this->tbGainScaR);
        this->Controls->Add(this->labGainExt);
        this->Controls->Add(this->tbGainExtB);
        this->Controls->Add(this->tbGainExtG);
        this->Controls->Add(this->tbGainExtR);
        this->Controls->Add(this->labLED);
        this->Controls->Add(this->tbLEDB);
        this->Controls->Add(this->tbLEDG);
        this->Controls->Add(this->tbLEDR);
        this->Controls->Add(this->labSettings);
        this->Controls->Add(this->button_plus_2);
        this->Controls->Add(this->button_plus_1);
        this->Controls->Add(this->in_textBox);
        this->Controls->Add(this->out_textBox);
        this->Name = L"Form1";
        this->Text = L"Form1";
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

