#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Ex21_01 {

	/// <summary>
	/// Summary for HelpAboutDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class HelpAboutDialog : public System::Windows::Forms::Form
	{
	public:
		HelpAboutDialog(void)
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
		~HelpAboutDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  OKbutton;
  private: System::Windows::Forms::Label^  label1;
  protected: 

  protected: 

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
      this->OKbutton = (gcnew System::Windows::Forms::Button());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->SuspendLayout();
      // 
      // OKbutton
      // 
      this->OKbutton->Location = System::Drawing::Point(299, 107);
      this->OKbutton->Name = L"OKbutton";
      this->OKbutton->Size = System::Drawing::Size(75, 23);
      this->OKbutton->TabIndex = 0;
      this->OKbutton->Text = L"OK";
      this->OKbutton->UseVisualStyleBackColor = true;
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Font = (gcnew System::Drawing::Font(L"Papyrus", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->label1->Location = System::Drawing::Point(84, 53);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(238, 25);
      this->label1->TabIndex = 1;
      this->label1->Text = L"Copyright Ivor Horton 2005";
      // 
      // HelpAboutDialog
      // 
      this->AcceptButton = this->OKbutton;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(402, 176);
      this->ControlBox = false;
      this->Controls->Add(this->label1);
      this->Controls->Add(this->OKbutton);
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"HelpAboutDialog";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
      this->Text = L"About a Winning Application";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
	};
}
