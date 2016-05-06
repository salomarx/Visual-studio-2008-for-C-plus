#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Ex21_01 {

	/// <summary>
	/// Summary for LottoLimitsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class LottoLimitsDialog : public System::Windows::Forms::Form
	{
	public:
		LottoLimitsDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

  private:
    void SetList(ListBox^ listBox, int min, int max, int selected)
    {
      listBox->BeginUpdate();              // Suppress drawing the listbox

      for(int n = min ; n <= max ; n++)
        listBox->Items->Add(n);

      listBox->EndUpdate();                // Resume drawing the list box

      listBox->SelectedItem = Int32(selected);
    }

private: 
  int lowerLimit;                      // Lower limit from control
  int upperLimit;                      // upper limit from control
public:
  property int LowerLimit              // Property accessing lower limit
  {
    int get(){  return lowerLimit;  }

    void set(int limit)
    { 
      lowerLimit = limit;
      lottoLowerList->SelectedItem = Int32(limit);
    }
  }

  property int UpperLimit              // Property accessing upper limit
  {
    int get(){  return upperLimit;  }

    void set(int limit)
    { 
      upperLimit = limit;
      lottoUpperList->SelectedItem = Int32(limit);
    }
  }

    void SetLowerLimitsList(int min, int max, int selected)
    {
      SetList(lottoLowerList, min, max, selected);
      lowerLimit = selected;
    }

    void SetUpperLimitsList(int min, int max, int selected)
    {
      SetList(lottoUpperList, min, max, selected);
      upperLimit = selected;
    }

   void SetUpperEnabled()
   {
     lottoUpperList->Enabled = true;   // Enable upper list box
     lottoLowerList->Enabled = false;  // Disable lower list box
   }

    void SetLowerEnabled()
    {
      lottoUpperList->Enabled = false; // Disable upper list box
      lottoLowerList->Enabled = true;  // Enable lower list box

    }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LottoLimitsDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  lottoOK;
  protected: 
  private: System::Windows::Forms::Button^  lottoCancel;
  private: System::Windows::Forms::Label^  label1;
  private: System::Windows::Forms::Label^  label2;
  private: System::Windows::Forms::ListBox^  lottoLowerList;
  private: System::Windows::Forms::ListBox^  lottoUpperList;



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
      this->lottoOK = (gcnew System::Windows::Forms::Button());
      this->lottoCancel = (gcnew System::Windows::Forms::Button());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->label2 = (gcnew System::Windows::Forms::Label());
      this->lottoLowerList = (gcnew System::Windows::Forms::ListBox());
      this->lottoUpperList = (gcnew System::Windows::Forms::ListBox());
      this->SuspendLayout();
      // 
      // lottoOK
      // 
      this->lottoOK->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->lottoOK->Location = System::Drawing::Point(46, 166);
      this->lottoOK->Name = L"lottoOK";
      this->lottoOK->Size = System::Drawing::Size(75, 23);
      this->lottoOK->TabIndex = 0;
      this->lottoOK->Text = L"OK";
      this->lottoOK->UseVisualStyleBackColor = true;
      this->lottoOK->Click += gcnew System::EventHandler(this, &LottoLimitsDialog::lottoOK_Click);
      // 
      // lottoCancel
      // 
      this->lottoCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->lottoCancel->Location = System::Drawing::Point(262, 165);
      this->lottoCancel->Name = L"lottoCancel";
      this->lottoCancel->Size = System::Drawing::Size(75, 23);
      this->lottoCancel->TabIndex = 1;
      this->lottoCancel->Text = L"Cancel";
      this->lottoCancel->UseVisualStyleBackColor = true;
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Location = System::Drawing::Point(61, 34);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(117, 13);
      this->label1->TabIndex = 2;
      this->label1->Text = L"Select lower limit value:";
      // 
      // label2
      // 
      this->label2->AutoSize = true;
      this->label2->Location = System::Drawing::Point(61, 86);
      this->label2->Name = L"label2";
      this->label2->Size = System::Drawing::Size(119, 13);
      this->label2->TabIndex = 2;
      this->label2->Text = L"Select upper limit value:";
      // 
      // lottoLowerList
      // 
      this->lottoLowerList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->lottoLowerList->FormattingEnabled = true;
      this->lottoLowerList->ItemHeight = 16;
      this->lottoLowerList->Location = System::Drawing::Point(262, 30);
      this->lottoLowerList->Name = L"lottoLowerList";
      this->lottoLowerList->ScrollAlwaysVisible = true;
      this->lottoLowerList->Size = System::Drawing::Size(41, 20);
      this->lottoLowerList->TabIndex = 3;
      // 
      // lottoUpperList
      // 
      this->lottoUpperList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->lottoUpperList->FormattingEnabled = true;
      this->lottoUpperList->ItemHeight = 16;
      this->lottoUpperList->Location = System::Drawing::Point(262, 82);
      this->lottoUpperList->Name = L"lottoUpperList";
      this->lottoUpperList->ScrollAlwaysVisible = true;
      this->lottoUpperList->Size = System::Drawing::Size(41, 20);
      this->lottoUpperList->TabIndex = 3;
      // 
      // LottoLimitsDialog
      // 
      this->AcceptButton = this->lottoOK;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->CancelButton = this->lottoCancel;
      this->ClientSize = System::Drawing::Size(382, 223);
      this->ControlBox = false;
      this->Controls->Add(this->lottoUpperList);
      this->Controls->Add(this->lottoLowerList);
      this->Controls->Add(this->label2);
      this->Controls->Add(this->label1);
      this->Controls->Add(this->lottoCancel);
      this->Controls->Add(this->lottoOK);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"LottoLimitsDialog";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
      this->Text = L"Set Limits for Lotto Values";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: 
    System::Void lottoOK_Click(System::Object^  sender, System::EventArgs^  e)
    {
      int upper = 0;
      int lower = 0;
      // If there's a currently selected upper limit item, save it
      if(lottoUpperList->SelectedItem != nullptr)
        upper = safe_cast<Int32>(lottoUpperList->SelectedItem);

      // If there's a currently selected lower limit item, save it
      if(lottoLowerList->SelectedItem != nullptr)
        lower = safe_cast<Int32>(lottoLowerList->SelectedItem);

      if(upper - lower < 5)
      {
        ::DialogResult result =    
        MessageBox::Show(L"Upper limit: " + upper + L"  Lower limit: " + lower +
                L"\nUpper limit must be at least 5 greater that the lower limit." +
                L"\nTry Again.",
                L"Limits Invalid", 
                MessageBoxButtons::OKCancel,
                MessageBoxIcon::Error);
        if(result == ::DialogResult::OK)
          DialogResult = ::DialogResult::None;
        else
          DialogResult = ::DialogResult::Cancel;
      }
      else
      {
        upperLimit = upper;
        lowerLimit = lower;
      }
    }
};
}
