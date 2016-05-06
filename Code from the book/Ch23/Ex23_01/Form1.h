#pragma once


namespace Ex23_01 {

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
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
      // Create book data, one book per array
      array<String^>^ book1 = {L"0-09-174271-4", L"Wonderful Life",
                               L"Stephen Jay Gould", L"Hutchinson Radius"};
      array<String^>^ book2 = {L"0-09-977170-5", L"The Emperor's New Mind",
                               L"Roger Penrose", L"Vintage"};
      array<String^>^ book3 = {L"0-14-017996-8",L"Metamagical Themas",
                               L"Douglas R. Hofstadter", L"Penguin"};
      array<String^>^ book4 = {L"0-201-36080-2", L"The Meaning Of It All",
                               L"Richard P. Feynman", L"Addison-Wesley"};
      array<String^>^ book5 = {L"0-593-03449-X", L"The Walpole Orange",
                               L"Frank Muir", L"Bantam Press"};
      array<String^>^ book6 = {L"0-439-99358-X", L"The Amber Spyglass",
                             L"Philip Pullman", L"Scholastic Children's Books"};
      array<String^>^ book7 = {L"0-552-13461-9", L"Pyramids",
                               L"Terry Pratchett", L"Corgi Books"};
      array<String^>^ book8 = {L"0-7493-9739-X", L"Made In America",
                               L"Bill Bryson", L"Minerva"};

      // Create Array of books
      array<array<String^>^>^ books ={book1, book2, book3, book4,
                                      book5, book6, book7, book8};

      // Add all the books to the control
      for each(array<String^>^ book in books )
        dataGridView1->Rows->Add(book);
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
  private: System::Windows::Forms::DataGridView^  dataGridView1;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  ISBN;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Title;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Author;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Publisher;
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
      this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
      this->ISBN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->Author = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->Publisher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
      this->SuspendLayout();
      // 
      // dataGridView1
      // 
      this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
      this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
      this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->ISBN, this->Title, 
        this->Author, this->Publisher});
      this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
      this->dataGridView1->Location = System::Drawing::Point(0, 0);
      this->dataGridView1->Name = L"dataGridView1";
      this->dataGridView1->Size = System::Drawing::Size(442, 273);
      this->dataGridView1->TabIndex = 0;
      // 
      // ISBN
      // 
      this->ISBN->HeaderText = L"ISBN";
      this->ISBN->Name = L"ISBN";
      this->ISBN->Width = 57;
      // 
      // Title
      // 
      this->Title->HeaderText = L"Title";
      this->Title->Name = L"Title";
      this->Title->Width = 52;
      // 
      // Author
      // 
      this->Author->HeaderText = L"Author";
      this->Author->Name = L"Author";
      this->Author->Width = 63;
      // 
      // Publisher
      // 
      this->Publisher->HeaderText = L"Publisher";
      this->Publisher->Name = L"Publisher";
      this->Publisher->Width = 75;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(442, 273);
      this->Controls->Add(this->dataGridView1);
      this->Name = L"Form1";
      this->Text = L"My Book List";
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
      this->ResumeLayout(false);

    }
#pragma endregion
	};
}

