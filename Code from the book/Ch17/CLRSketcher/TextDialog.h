#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CLRSketcher {

	/// <summary>
	/// Summary for TextDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class TextDialog : public System::Windows::Forms::Form
	{
	public:
		TextDialog(void)
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
		~TextDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  textOKButton;
  protected: 

  protected: 
  private: System::Windows::Forms::Button^  textCancelButton;
  private: System::Windows::Forms::TextBox^  textBox1;
  private: System::Windows::Forms::Label^  label1;

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
      this->textOKButton = (gcnew System::Windows::Forms::Button());
      this->textCancelButton = (gcnew System::Windows::Forms::Button());
      this->textBox1 = (gcnew System::Windows::Forms::TextBox());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->SuspendLayout();
      // 
      // textOKButton
      // 
      this->textOKButton->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->textOKButton->Location = System::Drawing::Point(42, 149);
      this->textOKButton->Name = L"textOKButton";
      this->textOKButton->Size = System::Drawing::Size(75, 23);
      this->textOKButton->TabIndex = 1;
      this->textOKButton->Text = L"OK";
      this->textOKButton->UseVisualStyleBackColor = true;
      // 
      // textCancelButton
      // 
      this->textCancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->textCancelButton->Location = System::Drawing::Point(176, 148);
      this->textCancelButton->Name = L"textCancelButton";
      this->textCancelButton->Size = System::Drawing::Size(75, 23);
      this->textCancelButton->TabIndex = 2;
      this->textCancelButton->Text = L"Cancel";
      this->textCancelButton->UseVisualStyleBackColor = true;
      // 
      // textBox1
      // 
      this->textBox1->Location = System::Drawing::Point(42, 43);
      this->textBox1->Name = L"textBox1";
      this->textBox1->Size = System::Drawing::Size(209, 20);
      this->textBox1->TabIndex = 0;
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->label1->Location = System::Drawing::Point(39, 23);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(171, 17);
      this->label1->TabIndex = 3;
      this->label1->Text = L"Enter text for the element:";
      // 
      // TextDialog
      // 
      this->AcceptButton = this->textOKButton;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->CancelButton = this->textCancelButton;
      this->ClientSize = System::Drawing::Size(292, 193);
      this->ControlBox = false;
      this->Controls->Add(this->label1);
      this->Controls->Add(this->textBox1);
      this->Controls->Add(this->textCancelButton);
      this->Controls->Add(this->textOKButton);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"TextDialog";
      this->Text = L"Create Text Element";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
    public: property String^ TextString
    {
      String^ get() {return textBox1->Text; }
      void set(String^ text) { textBox1->Text = text; }
    }
	};
}
