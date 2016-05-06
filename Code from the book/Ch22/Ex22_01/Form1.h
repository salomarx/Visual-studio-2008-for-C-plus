#pragma once
#include "LottoLimitsDialog.h"
#include "EuroLimitsDialog.h"
#include "UserValueDialog.h"

namespace Ex22_01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
: lottoValuesCount(6),
euroValuesCount(5), euroStarsCount(2),
lottoLowerLimit(1),lottoUpperLimit(49),
lottoUserMinimum(lottoLowerLimit),lottoUserMaximum(lottoUpperLimit),
euroLowerLimit(1), euroUpperLimit(50),
euroStarsLowerLimit(1),euroStarsUpperLimit(9),
euroUserMinimum(euroLowerLimit),euroUserMaximum(euroUpperLimit),
euroStarsUserMinimum(euroStarsLowerLimit),euroStarsUserMaximum(euroStarsUpperLimit)
		{
			InitializeComponent();
			//
      random = gcnew Random;
  lottoLimitsDialog = gcnew LottoLimitsDialog;
  lottoLimitsDialog->SetLowerLimitsList(1, lottoUpperLimit-lottoValuesCount+1,
                                                                 lottoUserMinimum);
  lottoLimitsDialog->SetUpperLimitsList(lottoValuesCount, lottoUpperLimit,
                                                                 lottoUserMaximum);
  euroLimitsDialog = gcnew EuroLimitsDialog;
  euroLimitsDialog->LowerStarsLimit = euroStarsLowerLimit;
  euroLimitsDialog->UpperStarsLimit = euroStarsUpperLimit;
  userValueDialog = gcnew UserValueDialog;
  //
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
  private: System::Windows::Forms::MenuStrip^  menuStrip1;
  private: System::Windows::Forms::ToolStripMenuItem^  playMenuItem;
  protected: 

  private: System::Windows::Forms::ToolStripMenuItem^  limitsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  upperMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  lowerMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  resetMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  aboutMenuItem;
  private: System::Windows::Forms::TabControl^  tabControl1;
  private: System::Windows::Forms::TabPage^  lottoTab;
  private: System::Windows::Forms::TabPage^  euroTab;
  private: System::Windows::Forms::TabPage^  webTab;
  private: System::Windows::Forms::GroupBox^  lottoValues;
  private: System::Windows::Forms::SplitContainer^  euroEntry;
  private: System::Windows::Forms::GroupBox^  euroValues;
  private: System::Windows::Forms::GroupBox^  euroStars;
  private: System::Windows::Forms::Button^  euroValue4;

  private: System::Windows::Forms::Button^  euroValue1;
  private: System::Windows::Forms::Button^  euroValue3;
  private: System::Windows::Forms::Button^  euroValue5;



  private: System::Windows::Forms::Button^  euroValue2;
  private: System::Windows::Forms::Button^  euroStar2;


  private: System::Windows::Forms::Button^  euroStar1;
  private: System::Windows::Forms::Button^  lottoValue6;
  private: System::Windows::Forms::Button^  lottoValue5;
  private: System::Windows::Forms::Button^  lottoValue4;
  private: System::Windows::Forms::Button^  lottoValue3;
  private: System::Windows::Forms::Button^  lottoValue2;








  private: System::Windows::Forms::Button^  lottoValue1;
  private: System::Windows::Forms::WebBrowser^  webBrowser;
  private: System::Windows::Forms::ContextMenuStrip^  buttonContextMenu;
  private: System::Windows::Forms::ToolStripMenuItem^  chooseValue;
  private: System::ComponentModel::IContainer^  components;











	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->components = (gcnew System::ComponentModel::Container());
      this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
      this->playMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->limitsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->upperMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->lowerMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->resetMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->aboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
      this->lottoTab = (gcnew System::Windows::Forms::TabPage());
      this->lottoValues = (gcnew System::Windows::Forms::GroupBox());
      this->lottoValue6 = (gcnew System::Windows::Forms::Button());
      this->buttonContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
      this->chooseValue = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->lottoValue5 = (gcnew System::Windows::Forms::Button());
      this->lottoValue4 = (gcnew System::Windows::Forms::Button());
      this->lottoValue3 = (gcnew System::Windows::Forms::Button());
      this->lottoValue2 = (gcnew System::Windows::Forms::Button());
      this->lottoValue1 = (gcnew System::Windows::Forms::Button());
      this->euroTab = (gcnew System::Windows::Forms::TabPage());
      this->euroEntry = (gcnew System::Windows::Forms::SplitContainer());
      this->euroValues = (gcnew System::Windows::Forms::GroupBox());
      this->euroValue3 = (gcnew System::Windows::Forms::Button());
      this->euroValue5 = (gcnew System::Windows::Forms::Button());
      this->euroValue4 = (gcnew System::Windows::Forms::Button());
      this->euroValue2 = (gcnew System::Windows::Forms::Button());
      this->euroValue1 = (gcnew System::Windows::Forms::Button());
      this->euroStars = (gcnew System::Windows::Forms::GroupBox());
      this->euroStar2 = (gcnew System::Windows::Forms::Button());
      this->euroStar1 = (gcnew System::Windows::Forms::Button());
      this->webTab = (gcnew System::Windows::Forms::TabPage());
      this->webBrowser = (gcnew System::Windows::Forms::WebBrowser());
      this->menuStrip1->SuspendLayout();
      this->tabControl1->SuspendLayout();
      this->lottoTab->SuspendLayout();
      this->lottoValues->SuspendLayout();
      this->buttonContextMenu->SuspendLayout();
      this->euroTab->SuspendLayout();
      this->euroEntry->Panel1->SuspendLayout();
      this->euroEntry->Panel2->SuspendLayout();
      this->euroEntry->SuspendLayout();
      this->euroValues->SuspendLayout();
      this->euroStars->SuspendLayout();
      this->webTab->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->playMenuItem, this->limitsToolStripMenuItem, 
        this->helpToolStripMenuItem});
      this->menuStrip1->Location = System::Drawing::Point(0, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(474, 24);
      this->menuStrip1->TabIndex = 0;
      this->menuStrip1->Text = L"menuStrip1";
      // 
      // playMenuItem
      // 
      this->playMenuItem->Name = L"playMenuItem";
      this->playMenuItem->Size = System::Drawing::Size(39, 20);
      this->playMenuItem->Text = L"&Play";
      this->playMenuItem->ToolTipText = L"Create new set of values";
      this->playMenuItem->Click += gcnew System::EventHandler(this, &Form1::playMenuItem_Click);
      // 
      // limitsToolStripMenuItem
      // 
      this->limitsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->upperMenuItem, 
        this->lowerMenuItem, this->resetMenuItem});
      this->limitsToolStripMenuItem->Name = L"limitsToolStripMenuItem";
      this->limitsToolStripMenuItem->Size = System::Drawing::Size(45, 20);
      this->limitsToolStripMenuItem->Text = L"&Limits";
      // 
      // upperMenuItem
      // 
      this->upperMenuItem->Name = L"upperMenuItem";
      this->upperMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
        | System::Windows::Forms::Keys::U));
      this->upperMenuItem->Size = System::Drawing::Size(174, 22);
      this->upperMenuItem->Text = L"Upper";
      this->upperMenuItem->ToolTipText = L"Set upper limit for values";
      this->upperMenuItem->Click += gcnew System::EventHandler(this, &Form1::upperMenuItem_Click);
      // 
      // lowerMenuItem
      // 
      this->lowerMenuItem->Name = L"lowerMenuItem";
      this->lowerMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
        | System::Windows::Forms::Keys::L));
      this->lowerMenuItem->Size = System::Drawing::Size(174, 22);
      this->lowerMenuItem->Text = L"Lower";
      this->lowerMenuItem->ToolTipText = L"Set lower limits for values";
      this->lowerMenuItem->Click += gcnew System::EventHandler(this, &Form1::lowerMenuItem_Click);
      // 
      // resetMenuItem
      // 
      this->resetMenuItem->Name = L"resetMenuItem";
      this->resetMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
        | System::Windows::Forms::Keys::R));
      this->resetMenuItem->Size = System::Drawing::Size(174, 22);
      this->resetMenuItem->Text = L"Reset";
      this->resetMenuItem->ToolTipText = L"Reset limits to original values";
      this->resetMenuItem->Click += gcnew System::EventHandler(this, &Form1::resetMenuItem_Click);
      // 
      // helpToolStripMenuItem
      // 
      this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutMenuItem});
      this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
      this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
      this->helpToolStripMenuItem->Text = L"&Help";
      // 
      // aboutMenuItem
      // 
      this->aboutMenuItem->Name = L"aboutMenuItem";
      this->aboutMenuItem->Size = System::Drawing::Size(114, 22);
      this->aboutMenuItem->Text = L"About";
      this->aboutMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutMenuItem_Click);
      // 
      // tabControl1
      // 
      this->tabControl1->Controls->Add(this->lottoTab);
      this->tabControl1->Controls->Add(this->euroTab);
      this->tabControl1->Controls->Add(this->webTab);
      this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
      this->tabControl1->Location = System::Drawing::Point(0, 24);
      this->tabControl1->Name = L"tabControl1";
      this->tabControl1->SelectedIndex = 0;
      this->tabControl1->Size = System::Drawing::Size(474, 268);
      this->tabControl1->TabIndex = 1;
      // 
      // lottoTab
      // 
      this->lottoTab->Controls->Add(this->lottoValues);
      this->lottoTab->Location = System::Drawing::Point(4, 22);
      this->lottoTab->Name = L"lottoTab";
      this->lottoTab->Padding = System::Windows::Forms::Padding(3);
      this->lottoTab->Size = System::Drawing::Size(466, 242);
      this->lottoTab->TabIndex = 0;
      this->lottoTab->Text = L"Lotto";
      this->lottoTab->UseVisualStyleBackColor = true;
      // 
      // lottoValues
      // 
      this->lottoValues->Controls->Add(this->lottoValue6);
      this->lottoValues->Controls->Add(this->lottoValue5);
      this->lottoValues->Controls->Add(this->lottoValue4);
      this->lottoValues->Controls->Add(this->lottoValue3);
      this->lottoValues->Controls->Add(this->lottoValue2);
      this->lottoValues->Controls->Add(this->lottoValue1);
      this->lottoValues->Dock = System::Windows::Forms::DockStyle::Fill;
      this->lottoValues->Location = System::Drawing::Point(3, 3);
      this->lottoValues->Name = L"lottoValues";
      this->lottoValues->Size = System::Drawing::Size(460, 236);
      this->lottoValues->TabIndex = 0;
      this->lottoValues->TabStop = false;
      this->lottoValues->Text = L"Values 1 to 49";
      // 
      // lottoValue6
      // 
      this->lottoValue6->BackColor = System::Drawing::Color::SkyBlue;
      this->lottoValue6->ContextMenuStrip = this->buttonContextMenu;
      this->lottoValue6->Location = System::Drawing::Point(313, 127);
      this->lottoValue6->Name = L"lottoValue6";
      this->lottoValue6->Size = System::Drawing::Size(56, 23);
      this->lottoValue6->TabIndex = 0;
      this->lottoValue6->Text = L"6";
      this->lottoValue6->UseVisualStyleBackColor = false;
      this->lottoValue6->Click += gcnew System::EventHandler(this, &Form1::lottoValue_Click);
      // 
      // buttonContextMenu
      // 
      this->buttonContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->chooseValue});
      this->buttonContextMenu->Name = L"buttonContextMenu";
      this->buttonContextMenu->Size = System::Drawing::Size(153, 48);
      this->buttonContextMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::buttonContextMenu_Opening);
      // 
      // chooseValue
      // 
      this->chooseValue->Name = L"chooseValue";
      this->chooseValue->Size = System::Drawing::Size(152, 22);
      this->chooseValue->Text = L"&Choose";
      this->chooseValue->Click += gcnew System::EventHandler(this, &Form1::chooseValue_Click);
      // 
      // lottoValue5
      // 
      this->lottoValue5->BackColor = System::Drawing::Color::SkyBlue;
      this->lottoValue5->ContextMenuStrip = this->buttonContextMenu;
      this->lottoValue5->Location = System::Drawing::Point(175, 127);
      this->lottoValue5->Name = L"lottoValue5";
      this->lottoValue5->Size = System::Drawing::Size(56, 23);
      this->lottoValue5->TabIndex = 0;
      this->lottoValue5->Text = L"5";
      this->lottoValue5->UseVisualStyleBackColor = false;
      this->lottoValue5->Click += gcnew System::EventHandler(this, &Form1::lottoValue_Click);
      // 
      // lottoValue4
      // 
      this->lottoValue4->BackColor = System::Drawing::Color::SkyBlue;
      this->lottoValue4->ContextMenuStrip = this->buttonContextMenu;
      this->lottoValue4->Location = System::Drawing::Point(37, 127);
      this->lottoValue4->Name = L"lottoValue4";
      this->lottoValue4->Size = System::Drawing::Size(56, 23);
      this->lottoValue4->TabIndex = 0;
      this->lottoValue4->Text = L"4";
      this->lottoValue4->UseVisualStyleBackColor = false;
      this->lottoValue4->Click += gcnew System::EventHandler(this, &Form1::lottoValue_Click);
      // 
      // lottoValue3
      // 
      this->lottoValue3->BackColor = System::Drawing::Color::SkyBlue;
      this->lottoValue3->ContextMenuStrip = this->buttonContextMenu;
      this->lottoValue3->Location = System::Drawing::Point(313, 66);
      this->lottoValue3->Name = L"lottoValue3";
      this->lottoValue3->Size = System::Drawing::Size(56, 23);
      this->lottoValue3->TabIndex = 0;
      this->lottoValue3->Text = L"3";
      this->lottoValue3->UseVisualStyleBackColor = false;
      this->lottoValue3->Click += gcnew System::EventHandler(this, &Form1::lottoValue_Click);
      // 
      // lottoValue2
      // 
      this->lottoValue2->BackColor = System::Drawing::Color::SkyBlue;
      this->lottoValue2->ContextMenuStrip = this->buttonContextMenu;
      this->lottoValue2->Location = System::Drawing::Point(175, 66);
      this->lottoValue2->Name = L"lottoValue2";
      this->lottoValue2->Size = System::Drawing::Size(56, 23);
      this->lottoValue2->TabIndex = 0;
      this->lottoValue2->Text = L"2";
      this->lottoValue2->UseVisualStyleBackColor = false;
      this->lottoValue2->Click += gcnew System::EventHandler(this, &Form1::lottoValue_Click);
      // 
      // lottoValue1
      // 
      this->lottoValue1->BackColor = System::Drawing::Color::SkyBlue;
      this->lottoValue1->ContextMenuStrip = this->buttonContextMenu;
      this->lottoValue1->Location = System::Drawing::Point(37, 66);
      this->lottoValue1->Name = L"lottoValue1";
      this->lottoValue1->Size = System::Drawing::Size(56, 23);
      this->lottoValue1->TabIndex = 0;
      this->lottoValue1->Text = L"1";
      this->lottoValue1->UseVisualStyleBackColor = false;
      this->lottoValue1->Click += gcnew System::EventHandler(this, &Form1::lottoValue_Click);
      // 
      // euroTab
      // 
      this->euroTab->Controls->Add(this->euroEntry);
      this->euroTab->Location = System::Drawing::Point(4, 22);
      this->euroTab->Name = L"euroTab";
      this->euroTab->Padding = System::Windows::Forms::Padding(3);
      this->euroTab->Size = System::Drawing::Size(466, 242);
      this->euroTab->TabIndex = 1;
      this->euroTab->Text = L"Euromillions";
      this->euroTab->UseVisualStyleBackColor = true;
      // 
      // euroEntry
      // 
      this->euroEntry->Dock = System::Windows::Forms::DockStyle::Fill;
      this->euroEntry->IsSplitterFixed = true;
      this->euroEntry->Location = System::Drawing::Point(3, 3);
      this->euroEntry->Name = L"euroEntry";
      this->euroEntry->Orientation = System::Windows::Forms::Orientation::Horizontal;
      // 
      // euroEntry.Panel1
      // 
      this->euroEntry->Panel1->Controls->Add(this->euroValues);
      // 
      // euroEntry.Panel2
      // 
      this->euroEntry->Panel2->Controls->Add(this->euroStars);
      this->euroEntry->Size = System::Drawing::Size(460, 236);
      this->euroEntry->SplitterDistance = 110;
      this->euroEntry->TabIndex = 0;
      // 
      // euroValues
      // 
      this->euroValues->Controls->Add(this->euroValue3);
      this->euroValues->Controls->Add(this->euroValue5);
      this->euroValues->Controls->Add(this->euroValue4);
      this->euroValues->Controls->Add(this->euroValue2);
      this->euroValues->Controls->Add(this->euroValue1);
      this->euroValues->Dock = System::Windows::Forms::DockStyle::Fill;
      this->euroValues->Location = System::Drawing::Point(0, 0);
      this->euroValues->Name = L"euroValues";
      this->euroValues->Size = System::Drawing::Size(460, 110);
      this->euroValues->TabIndex = 0;
      this->euroValues->TabStop = false;
      this->euroValues->Text = L"Values 1 to 50";
      // 
      // euroValue3
      // 
      this->euroValue3->BackColor = System::Drawing::Color::Silver;
      this->euroValue3->ContextMenuStrip = this->buttonContextMenu;
      this->euroValue3->Location = System::Drawing::Point(311, 19);
      this->euroValue3->Name = L"euroValue3";
      this->euroValue3->Size = System::Drawing::Size(56, 23);
      this->euroValue3->TabIndex = 0;
      this->euroValue3->Text = L"3";
      this->euroValue3->UseVisualStyleBackColor = false;
      this->euroValue3->Click += gcnew System::EventHandler(this, &Form1::euroValue_Click);
      // 
      // euroValue5
      // 
      this->euroValue5->BackColor = System::Drawing::Color::Silver;
      this->euroValue5->ContextMenuStrip = this->buttonContextMenu;
      this->euroValue5->Location = System::Drawing::Point(312, 65);
      this->euroValue5->Name = L"euroValue5";
      this->euroValue5->Size = System::Drawing::Size(56, 23);
      this->euroValue5->TabIndex = 0;
      this->euroValue5->Text = L"5";
      this->euroValue5->UseVisualStyleBackColor = false;
      this->euroValue5->Click += gcnew System::EventHandler(this, &Form1::euroValue_Click);
      // 
      // euroValue4
      // 
      this->euroValue4->BackColor = System::Drawing::Color::Silver;
      this->euroValue4->ContextMenuStrip = this->buttonContextMenu;
      this->euroValue4->Location = System::Drawing::Point(35, 65);
      this->euroValue4->Name = L"euroValue4";
      this->euroValue4->Size = System::Drawing::Size(56, 23);
      this->euroValue4->TabIndex = 0;
      this->euroValue4->Text = L"4";
      this->euroValue4->UseVisualStyleBackColor = false;
      this->euroValue4->Click += gcnew System::EventHandler(this, &Form1::euroValue_Click);
      // 
      // euroValue2
      // 
      this->euroValue2->BackColor = System::Drawing::Color::Silver;
      this->euroValue2->ContextMenuStrip = this->buttonContextMenu;
      this->euroValue2->Location = System::Drawing::Point(173, 42);
      this->euroValue2->Name = L"euroValue2";
      this->euroValue2->Size = System::Drawing::Size(56, 23);
      this->euroValue2->TabIndex = 0;
      this->euroValue2->Text = L"2";
      this->euroValue2->UseVisualStyleBackColor = false;
      this->euroValue2->Click += gcnew System::EventHandler(this, &Form1::euroValue_Click);
      // 
      // euroValue1
      // 
      this->euroValue1->BackColor = System::Drawing::Color::Silver;
      this->euroValue1->ContextMenuStrip = this->buttonContextMenu;
      this->euroValue1->Location = System::Drawing::Point(35, 19);
      this->euroValue1->Name = L"euroValue1";
      this->euroValue1->Size = System::Drawing::Size(56, 23);
      this->euroValue1->TabIndex = 0;
      this->euroValue1->Text = L"1";
      this->euroValue1->UseVisualStyleBackColor = false;
      this->euroValue1->Click += gcnew System::EventHandler(this, &Form1::euroValue_Click);
      // 
      // euroStars
      // 
      this->euroStars->Controls->Add(this->euroStar2);
      this->euroStars->Controls->Add(this->euroStar1);
      this->euroStars->Dock = System::Windows::Forms::DockStyle::Fill;
      this->euroStars->Location = System::Drawing::Point(0, 0);
      this->euroStars->Name = L"euroStars";
      this->euroStars->Size = System::Drawing::Size(460, 122);
      this->euroStars->TabIndex = 0;
      this->euroStars->TabStop = false;
      this->euroStars->Text = L"Values 1 to 9";
      // 
      // euroStar2
      // 
      this->euroStar2->BackColor = System::Drawing::Color::Gold;
      this->euroStar2->ContextMenuStrip = this->buttonContextMenu;
      this->euroStar2->Location = System::Drawing::Point(296, 46);
      this->euroStar2->Name = L"euroStar2";
      this->euroStar2->Size = System::Drawing::Size(56, 23);
      this->euroStar2->TabIndex = 0;
      this->euroStar2->Text = L"2";
      this->euroStar2->UseVisualStyleBackColor = false;
      this->euroStar2->Click += gcnew System::EventHandler(this, &Form1::euroStar_Click);
      // 
      // euroStar1
      // 
      this->euroStar1->BackColor = System::Drawing::Color::Gold;
      this->euroStar1->ContextMenuStrip = this->buttonContextMenu;
      this->euroStar1->Location = System::Drawing::Point(108, 46);
      this->euroStar1->Name = L"euroStar1";
      this->euroStar1->Size = System::Drawing::Size(56, 23);
      this->euroStar1->TabIndex = 0;
      this->euroStar1->Text = L"1";
      this->euroStar1->UseVisualStyleBackColor = false;
      this->euroStar1->Click += gcnew System::EventHandler(this, &Form1::euroStar_Click);
      // 
      // webTab
      // 
      this->webTab->Controls->Add(this->webBrowser);
      this->webTab->Location = System::Drawing::Point(4, 22);
      this->webTab->Name = L"webTab";
      this->webTab->Padding = System::Windows::Forms::Padding(3);
      this->webTab->Size = System::Drawing::Size(466, 242);
      this->webTab->TabIndex = 2;
      this->webTab->Text = L"Web Page";
      this->webTab->UseVisualStyleBackColor = true;
      // 
      // webBrowser
      // 
      this->webBrowser->Dock = System::Windows::Forms::DockStyle::Fill;
      this->webBrowser->Location = System::Drawing::Point(3, 3);
      this->webBrowser->MinimumSize = System::Drawing::Size(20, 20);
      this->webBrowser->Name = L"webBrowser";
      this->webBrowser->Size = System::Drawing::Size(460, 236);
      this->webBrowser->TabIndex = 0;
      this->webBrowser->Url = (gcnew System::Uri(L"http://www.national-lottery.co.uk", System::UriKind::Absolute));
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(474, 292);
      this->Controls->Add(this->tabControl1);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->Name = L"Form1";
      this->Text = L"A Winning Application";
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->tabControl1->ResumeLayout(false);
      this->lottoTab->ResumeLayout(false);
      this->lottoValues->ResumeLayout(false);
      this->buttonContextMenu->ResumeLayout(false);
      this->euroTab->ResumeLayout(false);
      this->euroEntry->Panel1->ResumeLayout(false);
      this->euroEntry->Panel2->ResumeLayout(false);
      this->euroEntry->ResumeLayout(false);
      this->euroValues->ResumeLayout(false);
      this->euroStars->ResumeLayout(false);
      this->webTab->ResumeLayout(false);
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void upperMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  ::DialogResult result;
  if(lottoTab->Visible)
  {
    lottoLimitsDialog->SetUpperEnabled();
    result = lottoLimitsDialog->ShowDialog(this);
    if(result == ::DialogResult::OK)
    {
      lottoUserMaximum = lottoLimitsDialog->UpperLimit;
      lottoUserMinimum = lottoLimitsDialog->LowerLimit;
    }
  }
  else if(euroTab->Visible)
  {
    euroLimitsDialog->SetUpperEnabled();
    result = euroLimitsDialog->ShowDialog(this); 
    if(result == ::DialogResult::OK)
    {
      euroUserMaximum = euroLimitsDialog->UpperValuesLimit;
      euroUserMinimum = euroLimitsDialog->LowerValuesLimit;
      euroStarsUserMaximum = euroLimitsDialog->UpperStarsLimit;
      euroStarsUserMinimum = euroLimitsDialog->LowerStarsLimit;
    }
  }
          }
private: System::Void lowerMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  ::DialogResult result;
  if(lottoTab->Visible)
  {
    lottoLimitsDialog->SetLowerEnabled();
    result = lottoLimitsDialog->ShowDialog(this);
    if(result == ::DialogResult::OK)
    {
      lottoUserMaximum = lottoLimitsDialog->UpperLimit;
      lottoUserMinimum = lottoLimitsDialog->LowerLimit;
    }
  }
  else if(euroTab->Visible)
  {
    euroLimitsDialog->SetLowerEnabled();
    result = euroLimitsDialog->ShowDialog(this); 
    if(result == ::DialogResult::OK)
    {
      euroUserMaximum = euroLimitsDialog->UpperValuesLimit;
      euroUserMinimum = euroLimitsDialog->LowerValuesLimit;
      euroStarsUserMaximum = euroLimitsDialog->UpperStarsLimit;
      euroStarsUserMinimum = euroLimitsDialog->LowerStarsLimit;
    }
  }

         }
private: System::Void aboutMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  MessageBox::Show(L"© Copyright Ivor Horton", L"About A Winning Application",
                   MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
         }

private:
  int lottoValuesCount;           // Number of values in Lotto entry         
  int euroValuesCount;            // Number of values in Euromillions entry         
  int euroStarsCount;             // Number of stars in Euromillions entry         
  int lottoLowerLimit;            // Minimum value allowed in Lotto 
  int lottoUpperLimit;            // Maximum value allowed in Lotto 
  int lottoUserMinimum;           // Lower lotto range limit from user
  int lottoUserMaximum;           // Upper lotto range limit from user

  int euroLowerLimit;             // Minimum value allowed in Euromillions 
  int euroUpperLimit;             // Maximum value allowed in Euromillions
  int euroStarsLowerLimit;        // Minimum stars value allowed in Euromillions 
  int euroStarsUpperLimit;        // Maximum stars value allowed in Euromillions 
  int euroUserMinimum;            // Lower euro range limit from user
  int euroUserMaximum;            // Upper euro range limit from user
  int euroStarsUserMinimum;       // Lower euro stars range limit from user
  int euroStarsUserMaximum;       // Upper euro stars range limit from user
  Random^ random;                 // Generates pseudo-random numbers};
private: System::Void playMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  array<int>^ values;        // Variable to store a handle to array of integers
  if(lottoTab->Visible)
  {
    // Generate and set values for Lotto entry
    values = gcnew array<int>(lottoValuesCount);           // Create the array
    GetValues(values, lottoUserMinimum, lottoUserMaximum); // Generate values
    SetValues(values, lottoValues);   
  }
  else if(euroTab->Visible)
  {
    // Generate and set values for Euromillions entry
    values = gcnew array<int>(euroValuesCount);
    GetValues(values, euroUserMinimum, euroUserMaximum);
    SetValues(values, euroValues);
    values = gcnew array<int>(euroStarsCount);
    GetValues(values, euroStarsUserMinimum, euroStarsUserMaximum);
    SetValues(values, euroStars);
  }
        }

         void GetValues(array<int>^ values, int min, int max)
         {
  values[0] = random->Next(min, max+1);     // Generate first random value
           
  // Generate remaining random values
  for(int i = 1 ; i<values->Length ; i++)
  {
    for(;;)                                 // Loop until a valid value is found
    {
      // Generate random integer from min to max
      values[i] = random->Next(min, max+1);

      // Check that its different from previous values
      if(IsValid(values[i], values, i))     // Check against previous values...
        break;                              // ...it is different so end loop
    }
  }
         }

         // Check whether number is different from array elements
         bool IsValid(int number, array<int>^ values, int indexLimit)
         {
    for(int i = 0 ; i< indexLimit ; i++)
    {
      if(number == values[i])
        return false;
    }
    return true;
         }

         // Set values as text on buttons in a GroupBox control
         void SetValues(array<int>^ values, GroupBox^ groupBox)
         {
    Array::Sort(values);               // Sort values in ascending sequence
    int count = values->Length - 1;
    for(int i = 0 ; i<groupBox->Controls->Count ; i++)
      safe_cast<Button^>(groupBox->Controls[i])->Text = values[count-i].ToString();
         }
private: System::Void resetMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    if(lottoTab->Visible)
    {
      // Reset user limits for Lotto
      lottoUserMaximum = lottoUpperLimit; 
      lottoUserMinimum = lottoLowerLimit; 
      lottoLimitsDialog->UpperLimit = lottoUpperLimit;
      lottoLimitsDialog->LowerLimit = lottoLowerLimit;
    }
    else if(euroTab->Visible)
    {
      // Reset user limits for Euromillions
      euroUserMaximum = euroUpperLimit; 
      euroUserMinimum = euroLowerLimit; 
      euroStarsUserMaximum = euroStarsUpperLimit; 
      euroStarsUserMinimum = euroStarsLowerLimit; 

      // Code to update Euromillions limits dialog...
    }
         }

    private:  LottoLimitsDialog^ lottoLimitsDialog;
private:
  EuroLimitsDialog^ euroLimitsDialog;    // Dialog to set Euromillions limits


  // Generates a new value for button different from current buttons
  void SetNewValue(Button^ button, array<Button^>^ buttons, int lowerLimit, int upperLimit)
  {
  int index = 0;                       // Index of button in buttons

  // Array to store button values
  array<int>^ values = gcnew array<int>(buttons->Length);

  // Get values from buttons and find index for button
  for(int i = 0 ; i < values->Length ; i++)
  {
    values[i] = Int32::Parse(buttons[i]->Text);  // Get current button value

    // If current handle is same as button, save the index value
    if(button == buttons[i])                     
      index = i;
  }

  int newValue = 0;                    // Store the new button value
  // Check if it is different from the other button values
  for(;;)                              // Loop until we get a good one
  {
    newValue = random->Next(lowerLimit, upperLimit);  // Generate a value
    if(IsValid(newValue, values, values->Length))     // If it's OK...
      break;                                          // ...end the loop
    }
    values[index] = newValue;          // Store the new value at index

    Array::Sort(values);                         // Sort the value
    for(int i = 0 ; i < values->Length ; i++)    // and set the values
      buttons[i]->Text = values[i].ToString();   // as text on the buttons
  }
private: System::Void lottoValue_Click(System::Object^  sender, System::EventArgs^  e) {
  Button^ button = safe_cast<Button^>(sender);

  // Create the array of button handles
  array<Button^>^ buttons = {lottoValue1, lottoValue2, lottoValue3,
                             lottoValue4, lottoValue5, lottoValue6};

  // Replace the value on button
  SetNewValue(button, buttons, lottoUserMinimum, lottoUserMaximum);
         }

private: System::Void euroValue_Click(System::Object^  sender, System::EventArgs^  e) {
  Button^ button = safe_cast<Button^>(sender);
  array<Button^>^ buttons = {euroValue1, euroValue2, euroValue3,
                             euroValue4, euroValue5 };
  SetNewValue(button, buttons, euroUserMinimum, euroUserMaximum);
         }
private: System::Void euroStar_Click(System::Object^  sender, System::EventArgs^  e) {
  Button^ button = safe_cast<Button^>(sender);
  array<Button^>^ buttons = { euroStar1, euroStar2 };
  SetNewValue(button, buttons, euroStarsUserMinimum, euroStarsUserMaximum);
         }
private: System::Void chooseValue_Click(System::Object^  sender, System::EventArgs^  e) {
  array<int>^ values;                  // Array to store current button values
  array<Button^>^ theButtons;          // Handle to aray of buttons

  // Check if the button is in the lottoValues group box
  if(lottoValues->Controls->Contains(contextButton))
  {
    // the button is from the lotto group...
    array<Button^>^ buttons = {lottoValue1, lottoValue2, lottoValue3,
                               lottoValue4, lottoValue5, lottoValue6};
    theButtons = buttons;              // Store array handle at outer scope
    values = GetButtonValues(buttons); // Get array of button values

    // Set up the dialog ready to be shown
    userValueDialog->Values = values = GetButtonValues(buttons);
    userValueDialog->LowerLimit = lottoUserMinimum;
    userValueDialog->UpperLimit = lottoUserMaximum;
    userValueDialog->SetLabelText(lottoUserMinimum, lottoUserMaximum);
    userValueDialog->ClearTextBox();
  }
  // Check if the button is in the euroValues group box
  else if(euroValues->Controls->Contains(contextButton))
  {
    // The button is in the Values group...
    array<Button^>^ buttons = {euroValue1, euroValue2, euroValue3,
                               euroValue4, euroValue5};
    theButtons = buttons;              // Store array handle at outer scope
    values = GetButtonValues(buttons); // Get array of button values

    // Set up the dialog ready to be shown
    userValueDialog->Values = values;
    userValueDialog->LowerLimit = euroUserMinimum;
    userValueDialog->UpperLimit = euroUserMaximum;
    userValueDialog->SetLabelText(euroUserMinimum, euroUserMaximum);
    userValueDialog->ClearTextBox();
 }
  // Check if the button is in the euroStars group box
 else if(euroStars->Controls->Contains(contextButton))
 {
   // The button is in the Stars group...
   array<Button^>^ buttons = { euroStar1, euroStar2 };
   theButtons = buttons;               // Store array handle at outer scope
    values = GetButtonValues(buttons); // Get array of button values

   // Set up the dialog ready to be shown
   userValueDialog->Values = values;
   userValueDialog->LowerLimit = euroStarsUserMinimum;
   userValueDialog->UpperLimit = euroStarsUserMaximum;
   userValueDialog->SetLabelText(euroStarsUserMinimum, euroStarsUserMaximum);
   userValueDialog->ClearTextBox();
  }
  // Display the dialog
  if(userValueDialog->ShowDialog(this) == ::DialogResult::OK)
  {
    // Determine which button value should be replaced
    for(int i = 0 ; i<theButtons->Length ; i++)
      if(contextButton == theButtons[i])
      {
        values[i] = userValueDialog->Value;
        break;
      }
    Array::Sort(values);               // Sort the values

    // Set all the button values
    for(int i = 0 ; i<theButtons->Length ; i++)
      theButtons[i]->Text = values[i].ToString();
  }
         }
private: System::Void buttonContextMenu_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
   contextButton = safe_cast<Button^>(buttonContextMenu->SourceControl);
         }

private:
  Button^ contextButton;          // Button that was right-clicked for context menu
private: UserValueDialog^ userValueDialog;

// Creates an array of button values from an array of buttons
array<int>^ GetButtonValues(array<Button^>^ buttons)
{
  array<int>^ values = gcnew array<int>(buttons->Length);
  for(int i = 0 ; i<values->Length ; i++)
    values[i] = Int32::Parse(buttons[i]->Text);
  return values;
}

};

}

