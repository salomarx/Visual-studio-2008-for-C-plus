#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Ex21_01 {

	/// <summary>
	/// Summary for EuroLimitsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class EuroLimitsDialog : public System::Windows::Forms::Form
	{
	public:
		EuroLimitsDialog(void)
      :lowerValuesLimit(1)
      ,upperValuesLimit(50)
      ,lowerStarsLimit(1)
      ,upperStarsLimit(9)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

public:
  // Disables controls for selecting upper limits
  void SetLowerEnabled(void)
  {
    upperValuesLimits->Enabled = false;
    upperStarsLimits->Enabled = false;
    lowerValuesLimits->Enabled = true;
    lowerStarsLimits->Enabled = true;
  }

  // Disables controls for selecting lower limits
  void SetUpperEnabled(void)
  {
    upperValuesLimits->Enabled = true;
    upperStarsLimits->Enabled = true;
    lowerValuesLimits->Enabled = false;
    lowerStarsLimits->Enabled = false;
  }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EuroLimitsDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  euroOK;
  protected: 
  private: System::Windows::Forms::Button^  euroCancel;
  private: System::Windows::Forms::GroupBox^  groupBox1;
  private: System::Windows::Forms::Label^  label2;
  private: System::Windows::Forms::Label^  label1;
  private: System::Windows::Forms::NumericUpDown^  upperValuesLimits;

  private: System::Windows::Forms::NumericUpDown^  lowerValuesLimits;

  private: System::Windows::Forms::GroupBox^  groupBox2;
  private: System::Windows::Forms::ComboBox^  upperStarsLimits;

  private: System::Windows::Forms::ComboBox^  lowerStarsLimits;

  private: System::Windows::Forms::Label^  label3;
  private: System::Windows::Forms::Label^  label4;

  private:
  int lowerValuesLimit;
  int upperValuesLimit;
  int lowerStarsLimit;
  int upperStarsLimit;

public:
  property int LowerValuesLimit
  {
    int get() {  return lowerValuesLimit;  }

    void set(int limit)
    {
      lowerValuesLimit = limit;
      lowerValuesLimits->Value = limit;        // Set as selected in NumericUpDown 
    }
  }
  property int UpperValuesLimit
  {
    int get() {  return upperValuesLimit;  }

    void set(int limit)
    {
      upperValuesLimit = limit;
      upperValuesLimits->Value = limit;        // Set as selected in NumericUpDown 
    }
  }
  property int LowerStarsLimit
  {
    int get() {  return lowerStarsLimit;  }

    void set(int limit)
    {
      lowerStarsLimit = limit;
      lowerStarsLimits->SelectedItem = limit;  // Set as selected in ComboBox 
      lowerStarsLimits->SelectedIndex =        // Set index for selected item
                                  lowerStarsLimits->FindString(limit.ToString());
    }
  }

  property int UpperStarsLimit
  {
    int get() {  return upperStarsLimit;  }

    void set(int limit)
    {
      upperStarsLimit = limit;
      upperStarsLimits->SelectedItem = limit;  // Set as selected in ComboBox 
      upperStarsLimits->SelectedIndex =        // Set index for selected item
                                  upperStarsLimits->FindString(limit.ToString());
    }
  }

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->euroOK = (gcnew System::Windows::Forms::Button());
      this->euroCancel = (gcnew System::Windows::Forms::Button());
      this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
      this->upperValuesLimits = (gcnew System::Windows::Forms::NumericUpDown());
      this->lowerValuesLimits = (gcnew System::Windows::Forms::NumericUpDown());
      this->label2 = (gcnew System::Windows::Forms::Label());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
      this->upperStarsLimits = (gcnew System::Windows::Forms::ComboBox());
      this->lowerStarsLimits = (gcnew System::Windows::Forms::ComboBox());
      this->label3 = (gcnew System::Windows::Forms::Label());
      this->label4 = (gcnew System::Windows::Forms::Label());
      this->groupBox1->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->upperValuesLimits))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lowerValuesLimits))->BeginInit();
      this->groupBox2->SuspendLayout();
      this->SuspendLayout();
      // 
      // euroOK
      // 
      this->euroOK->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->euroOK->Location = System::Drawing::Point(44, 188);
      this->euroOK->Name = L"euroOK";
      this->euroOK->Size = System::Drawing::Size(75, 23);
      this->euroOK->TabIndex = 0;
      this->euroOK->Text = L"OK";
      this->euroOK->UseVisualStyleBackColor = true;
      this->euroOK->Click += gcnew System::EventHandler(this, &EuroLimitsDialog::euroOK_Click);
      // 
      // euroCancel
      // 
      this->euroCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->euroCancel->Location = System::Drawing::Point(174, 188);
      this->euroCancel->Name = L"euroCancel";
      this->euroCancel->Size = System::Drawing::Size(75, 23);
      this->euroCancel->TabIndex = 0;
      this->euroCancel->Text = L"Cancel";
      this->euroCancel->UseVisualStyleBackColor = true;
      // 
      // groupBox1
      // 
      this->groupBox1->Controls->Add(this->upperValuesLimits);
      this->groupBox1->Controls->Add(this->lowerValuesLimits);
      this->groupBox1->Controls->Add(this->label2);
      this->groupBox1->Controls->Add(this->label1);
      this->groupBox1->Location = System::Drawing::Point(12, 12);
      this->groupBox1->Name = L"groupBox1";
      this->groupBox1->Size = System::Drawing::Size(268, 55);
      this->groupBox1->TabIndex = 1;
      this->groupBox1->TabStop = false;
      this->groupBox1->Text = L"Set Values Limits";
      // 
      // upperValuesLimits
      // 
      this->upperValuesLimits->Location = System::Drawing::Point(215, 21);
      this->upperValuesLimits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {49, 0, 0, 0});
      this->upperValuesLimits->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, 0});
      this->upperValuesLimits->Name = L"upperValuesLimits";
      this->upperValuesLimits->ReadOnly = true;
      this->upperValuesLimits->Size = System::Drawing::Size(36, 20);
      this->upperValuesLimits->TabIndex = 1;
      this->upperValuesLimits->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {49, 0, 0, 0});
      // 
      // lowerValuesLimits
      // 
      this->lowerValuesLimits->ImeMode = System::Windows::Forms::ImeMode::NoControl;
      this->lowerValuesLimits->Location = System::Drawing::Point(84, 21);
      this->lowerValuesLimits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {44, 0, 0, 0});
      this->lowerValuesLimits->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
      this->lowerValuesLimits->Name = L"lowerValuesLimits";
      this->lowerValuesLimits->ReadOnly = true;
      this->lowerValuesLimits->Size = System::Drawing::Size(36, 20);
      this->lowerValuesLimits->TabIndex = 1;
      this->lowerValuesLimits->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
      // 
      // label2
      // 
      this->label2->AutoSize = true;
      this->label2->Location = System::Drawing::Point(146, 25);
      this->label2->Name = L"label2";
      this->label2->Size = System::Drawing::Size(63, 13);
      this->label2->TabIndex = 0;
      this->label2->Text = L"Upper Limit:";
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Location = System::Drawing::Point(17, 25);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(63, 13);
      this->label1->TabIndex = 0;
      this->label1->Text = L"Lower Limit:";
      // 
      // groupBox2
      // 
      this->groupBox2->Controls->Add(this->upperStarsLimits);
      this->groupBox2->Controls->Add(this->lowerStarsLimits);
      this->groupBox2->Controls->Add(this->label3);
      this->groupBox2->Controls->Add(this->label4);
      this->groupBox2->Location = System::Drawing::Point(11, 92);
      this->groupBox2->Name = L"groupBox2";
      this->groupBox2->Size = System::Drawing::Size(268, 55);
      this->groupBox2->TabIndex = 2;
      this->groupBox2->TabStop = false;
      this->groupBox2->Text = L"Set Stars Limits";
      // 
      // upperStarsLimits
      // 
      this->upperStarsLimits->FormattingEnabled = true;
      this->upperStarsLimits->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
        L"9"});
      this->upperStarsLimits->Location = System::Drawing::Point(216, 24);
      this->upperStarsLimits->Name = L"upperStarsLimits";
      this->upperStarsLimits->Size = System::Drawing::Size(36, 21);
      this->upperStarsLimits->TabIndex = 1;
      // 
      // lowerStarsLimits
      // 
      this->lowerStarsLimits->FormattingEnabled = true;
      this->lowerStarsLimits->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
        L"8"});
      this->lowerStarsLimits->Location = System::Drawing::Point(85, 24);
      this->lowerStarsLimits->Name = L"lowerStarsLimits";
      this->lowerStarsLimits->Size = System::Drawing::Size(36, 21);
      this->lowerStarsLimits->TabIndex = 1;
      // 
      // label3
      // 
      this->label3->AutoSize = true;
      this->label3->Location = System::Drawing::Point(18, 28);
      this->label3->Name = L"label3";
      this->label3->Size = System::Drawing::Size(63, 13);
      this->label3->TabIndex = 0;
      this->label3->Text = L"Lower Limit:";
      // 
      // label4
      // 
      this->label4->AutoSize = true;
      this->label4->Location = System::Drawing::Point(147, 28);
      this->label4->Name = L"label4";
      this->label4->Size = System::Drawing::Size(63, 13);
      this->label4->TabIndex = 0;
      this->label4->Text = L"Upper Limit:";
      // 
      // EuroLimitsDialog
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(292, 231);
      this->ControlBox = false;
      this->Controls->Add(this->groupBox2);
      this->Controls->Add(this->groupBox1);
      this->Controls->Add(this->euroCancel);
      this->Controls->Add(this->euroOK);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"EuroLimitsDialog";
      this->Text = L"Set Euromillions Limits";
      this->groupBox1->ResumeLayout(false);
      this->groupBox1->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->upperValuesLimits))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lowerValuesLimits))->EndInit();
      this->groupBox2->ResumeLayout(false);
      this->groupBox2->PerformLayout();
      this->ResumeLayout(false);

    }
#pragma endregion
private: 
  System::Void euroOK_Click(System::Object^  sender, System::EventArgs^  e)
  {
  ::DialogResult result;               

  // get the limits for values 
  int valuesLower = Decimal::ToInt32(lowerValuesLimits->Value);
  int valuesUpper = Decimal::ToInt32(upperValuesLimits->Value);
  if(valuesUpper - valuesLower < 4)              // Check for an adequate range
  {
    result = MessageBox::Show(this,              // Range insufficient so
           "Upper values limit: "+valuesUpper +  // display message box
           "  Lower values limit: "+ valuesLower+
           "\nUpper values limit must be at least 4 greater that the lower limit."+
           "\nTry Again.",
           "Limits Invalid",
           MessageBoxButtons::OKCancel,
           MessageBoxIcon::Error);
    
    if(result == ::DialogResult::OK)             // If message box OK clicked
      DialogResult = ::DialogResult::None;       // prevent dialog from closing
    else                                         // Messag box Cancel clicked
      DialogResult = ::DialogResult::Cancel;     // so close the dialog
    return;
  }
 
  // Get stars limits
  int starsLower = lowerStarsLimits->SelectedItem == nullptr ?
                   lowerStarsLimit :
                   Int32::Parse(lowerStarsLimits->SelectedItem->ToString());

  int starsUpper = upperStarsLimits->SelectedItem == nullptr ?
                   upperStarsLimit :
                   Int32::Parse(upperStarsLimits->SelectedItem->ToString());

  if(starsUpper - starsLower < 1)                // Check for an adequate range
  {
    result = MessageBox::Show(this,              // Range insufficient so
           "Upper stars limit: "+starsUpper +    // so display message box
           "  Lower stars limit: "+ starsLower+
           "\nUpper stars limit must be at least 1 greater that the lower limit."+
           "\nTry Again.",
           "Limits Invalid",
           MessageBoxButtons::OKCancel,
           MessageBoxIcon::Error);
    if(result == ::DialogResult::OK)             // If message box OK clicked
      DialogResult = ::DialogResult::None;       // prevent dialog from closing
    else                                         // Message box Cancel clicked
      DialogResult = ::DialogResult::Cancel;     // so close the dialog
  }
  // Store the new limits
  lowerValuesLimit = valuesLower;
  upperValuesLimit = valuesUpper;
  lowerStarsLimit = starsLower;
  upperStarsLimit = starsUpper;
  }
};
}
