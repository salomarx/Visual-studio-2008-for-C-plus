#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CLRSketcher {

	/// <summary>
	/// Summary for PenDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PenDialog : public System::Windows::Forms::Form
	{
	public:
		PenDialog(void)
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
		~PenDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::GroupBox^  penWidthGroupBox;
  private: System::Windows::Forms::RadioButton^  penWidthButton6;

  private: System::Windows::Forms::RadioButton^  penWidthButton5;

  private: System::Windows::Forms::RadioButton^  penWidthButton4;

  private: System::Windows::Forms::RadioButton^  penWidthButton3;

  private: System::Windows::Forms::RadioButton^  penWidthButton2;

  private: System::Windows::Forms::RadioButton^  penWidthButton1;
  private: System::Windows::Forms::Button^  penWidthOK;
  private: System::Windows::Forms::Button^  penWidthCancel;

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
      this->penWidthGroupBox = (gcnew System::Windows::Forms::GroupBox());
      this->penWidthButton6 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton5 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton4 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton3 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton2 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton1 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthOK = (gcnew System::Windows::Forms::Button());
      this->penWidthCancel = (gcnew System::Windows::Forms::Button());
      this->penWidthGroupBox->SuspendLayout();
      this->SuspendLayout();
      // 
      // penWidthGroupBox
      // 
      this->penWidthGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->penWidthGroupBox->Controls->Add(this->penWidthButton6);
      this->penWidthGroupBox->Controls->Add(this->penWidthButton5);
      this->penWidthGroupBox->Controls->Add(this->penWidthButton4);
      this->penWidthGroupBox->Controls->Add(this->penWidthButton3);
      this->penWidthGroupBox->Controls->Add(this->penWidthButton2);
      this->penWidthGroupBox->Controls->Add(this->penWidthButton1);
      this->penWidthGroupBox->Location = System::Drawing::Point(19, 19);
      this->penWidthGroupBox->Margin = System::Windows::Forms::Padding(10, 10, 10, 20);
      this->penWidthGroupBox->Name = L"penWidthGroupBox";
      this->penWidthGroupBox->Size = System::Drawing::Size(254, 143);
      this->penWidthGroupBox->TabIndex = 0;
      this->penWidthGroupBox->TabStop = false;
      this->penWidthGroupBox->Text = L"Select Pen Width";
      // 
      // penWidthButton6
      // 
      this->penWidthButton6->AutoSize = true;
      this->penWidthButton6->Location = System::Drawing::Point(132, 109);
      this->penWidthButton6->Name = L"penWidthButton6";
      this->penWidthButton6->Size = System::Drawing::Size(84, 17);
      this->penWidthButton6->TabIndex = 5;
      this->penWidthButton6->Text = L"Pen Width 6";
      this->penWidthButton6->UseVisualStyleBackColor = true;
      // 
      // penWidthButton5
      // 
      this->penWidthButton5->AutoSize = true;
      this->penWidthButton5->Location = System::Drawing::Point(132, 70);
      this->penWidthButton5->Name = L"penWidthButton5";
      this->penWidthButton5->Size = System::Drawing::Size(84, 17);
      this->penWidthButton5->TabIndex = 4;
      this->penWidthButton5->Text = L"Pen Width 5";
      this->penWidthButton5->UseVisualStyleBackColor = true;
      // 
      // penWidthButton4
      // 
      this->penWidthButton4->AutoSize = true;
      this->penWidthButton4->Location = System::Drawing::Point(132, 31);
      this->penWidthButton4->Name = L"penWidthButton4";
      this->penWidthButton4->Size = System::Drawing::Size(84, 17);
      this->penWidthButton4->TabIndex = 3;
      this->penWidthButton4->Text = L"Pen Width 4";
      this->penWidthButton4->UseVisualStyleBackColor = true;
      // 
      // penWidthButton3
      // 
      this->penWidthButton3->AutoSize = true;
      this->penWidthButton3->Location = System::Drawing::Point(22, 109);
      this->penWidthButton3->Name = L"penWidthButton3";
      this->penWidthButton3->Size = System::Drawing::Size(84, 17);
      this->penWidthButton3->TabIndex = 2;
      this->penWidthButton3->Text = L"Pen Width 3";
      this->penWidthButton3->UseVisualStyleBackColor = true;
      // 
      // penWidthButton2
      // 
      this->penWidthButton2->AutoSize = true;
      this->penWidthButton2->Location = System::Drawing::Point(22, 70);
      this->penWidthButton2->Name = L"penWidthButton2";
      this->penWidthButton2->Size = System::Drawing::Size(84, 17);
      this->penWidthButton2->TabIndex = 1;
      this->penWidthButton2->Text = L"Pen Width 2";
      this->penWidthButton2->UseVisualStyleBackColor = true;
      // 
      // penWidthButton1
      // 
      this->penWidthButton1->AutoSize = true;
      this->penWidthButton1->Location = System::Drawing::Point(22, 31);
      this->penWidthButton1->Name = L"penWidthButton1";
      this->penWidthButton1->Size = System::Drawing::Size(84, 17);
      this->penWidthButton1->TabIndex = 0;
      this->penWidthButton1->Text = L"Pen Width 1";
      this->penWidthButton1->UseVisualStyleBackColor = true;
      // 
      // penWidthOK
      // 
      this->penWidthOK->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->penWidthOK->Location = System::Drawing::Point(50, 176);
      this->penWidthOK->Name = L"penWidthOK";
      this->penWidthOK->Size = System::Drawing::Size(75, 23);
      this->penWidthOK->TabIndex = 1;
      this->penWidthOK->Text = L"OK";
      this->penWidthOK->UseVisualStyleBackColor = true;
      // 
      // penWidthCancel
      // 
      this->penWidthCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->penWidthCancel->Location = System::Drawing::Point(160, 175);
      this->penWidthCancel->Name = L"penWidthCancel";
      this->penWidthCancel->Size = System::Drawing::Size(75, 23);
      this->penWidthCancel->TabIndex = 2;
      this->penWidthCancel->Text = L"Cancel";
      this->penWidthCancel->UseVisualStyleBackColor = true;
      // 
      // PenDialog
      // 
      this->AcceptButton = this->penWidthOK;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->CancelButton = this->penWidthCancel;
      this->ClientSize = System::Drawing::Size(292, 223);
      this->ControlBox = false;
      this->Controls->Add(this->penWidthCancel);
      this->Controls->Add(this->penWidthOK);
      this->Controls->Add(this->penWidthGroupBox);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"PenDialog";
      this->Text = L"Set Pen Width";
      this->penWidthGroupBox->ResumeLayout(false);
      this->penWidthGroupBox->PerformLayout();
      this->ResumeLayout(false);

    }
#pragma endregion

public: property float PenWidth
{
  float get()
  {
    if(penWidthButton1->Checked)
      return 1.0f;
    if(penWidthButton2->Checked)
      return 2.0f;
    if(penWidthButton3->Checked)
      return 3.0f;
    if(penWidthButton4->Checked)
      return 4.0f;
    if(penWidthButton5->Checked)
      return 5.0f;
    return 6.0f;
  }

  void set(float penWidth)
  {
    if(penWidth == 1.0f)
      penWidthButton1->Checked = true;
    else if(penWidth == 2.0f)
      penWidthButton2->Checked = true;
    else if(penWidth == 3.0f)
      penWidthButton3->Checked = true;
    else if(penWidth == 4.0f)
      penWidthButton4->Checked = true;
    else if(penWidth == 5.0f)
      penWidthButton5->Checked = true;
    else if(penWidth == 6.0f)
      penWidthButton6->Checked = true;
  }
}


	};
}
