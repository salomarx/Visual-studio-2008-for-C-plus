#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Ex21_01 {

	/// <summary>
	/// Summary for UserValueDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class UserValueDialog : public System::Windows::Forms::Form
	{
	public:
		UserValueDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserValueDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  OK;
  protected: 
  private: System::Windows::Forms::Button^  Cancel;
  private: System::Windows::Forms::Label^  label;
  private: System::Windows::Forms::TextBox^  textBox;

  public:
  property int Value;

  public:
  property int LowerLimit;
  property int UpperLimit;
  property array<int>^ Values;                   // Current button values

  public:
  void SetLabelText(int lower, int upper)
  {
    label->Text = L"Enter your value between " + lower +L" and " + upper;
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
      this->OK = (gcnew System::Windows::Forms::Button());
      this->Cancel = (gcnew System::Windows::Forms::Button());
      this->label = (gcnew System::Windows::Forms::Label());
      this->textBox = (gcnew System::Windows::Forms::TextBox());
      this->SuspendLayout();
      // 
      // OK
      // 
      this->OK->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->OK->Location = System::Drawing::Point(26, 142);
      this->OK->Name = L"OK";
      this->OK->Size = System::Drawing::Size(75, 23);
      this->OK->TabIndex = 0;
      this->OK->Text = L"OK";
      this->OK->UseVisualStyleBackColor = true;
      this->OK->Click += gcnew System::EventHandler(this, &UserValueDialog::OK_Click);
      // 
      // Cancel
      // 
      this->Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->Cancel->Location = System::Drawing::Point(181, 142);
      this->Cancel->Name = L"Cancel";
      this->Cancel->Size = System::Drawing::Size(75, 23);
      this->Cancel->TabIndex = 0;
      this->Cancel->Text = L"Cancel";
      this->Cancel->UseVisualStyleBackColor = true;
      // 
      // label
      // 
      this->label->AutoSize = true;
      this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->label->Location = System::Drawing::Point(23, 32);
      this->label->Name = L"label";
      this->label->Size = System::Drawing::Size(233, 17);
      this->label->TabIndex = 1;
      this->label->Text = L"Enter your value between 1 and 50:";
      // 
      // textBox
      // 
      this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->textBox->Location = System::Drawing::Point(89, 83);
      this->textBox->Name = L"textBox";
      this->textBox->Size = System::Drawing::Size(88, 23);
      this->textBox->TabIndex = 2;
      this->textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      // 
      // UserValueDialog
      // 
      this->AcceptButton = this->OK;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->CancelButton = this->Cancel;
      this->ClientSize = System::Drawing::Size(287, 209);
      this->ControlBox = false;
      this->Controls->Add(this->textBox);
      this->Controls->Add(this->label);
      this->Controls->Add(this->Cancel);
      this->Controls->Add(this->OK);
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"UserValueDialog";
      this->Text = L"User Value Input Dialog";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: 
    System::Void OK_Click(System::Object^  sender, System::EventArgs^  e) 
    {
  ::DialogResult result;                    // Stores return value from Show()
  if(String::IsNullOrEmpty(textBox->Text))  // Chheck for null or empty string
  {
    result = MessageBox::Show(this,
                              L"No input - enter a value.",
                              L"Input Error",
                              MessageBoxButtons::RetryCancel,
                              MessageBoxIcon::Error);
    if(result == ::DialogResult::Retry)     // If Retry button clicked 
      DialogResult = ::DialogResult::None;  // ...prevent dialog from closing...
    else                                    // ...otherwise...
      DialogResult = ::DialogResult::Cancel;// ...close the dialog.
    return;
  }

  int value = Int32::Parse(textBox->Text);  // Get text box value
  bool valid = true;                        // Indicator for valid entry

  for each(int n in Values)                 // Check input against current values
    if(value == n)                          // If it's the same...
    {
      valid = false;                        // ...it is invalid.
      break;                                // Exit the loop              
    }

  // Check limits and result of previous validity check
  if(!valid || value < LowerLimit || value > UpperLimit)
  {
    result = MessageBox::Show(this,
                              L"Input not valid." +
                              L"Value must  be from " + LowerLimit +
                              L" to " + UpperLimit +
                              L"\nand must be different from existing values.",
                              L"Input Error",
                              MessageBoxButtons::RetryCancel,
                              MessageBoxIcon::Error);
    if(result == ::DialogResult::Retry)
      DialogResult = ::DialogResult::None;
    else
      DialogResult = ::DialogResult::Cancel;
  }
  else
  Value = value;                            // Store the input in the property
    }
};
}
