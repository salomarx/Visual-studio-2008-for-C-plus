#pragma once


namespace Ex23_02 {

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
      : oldCellBackColor(Color::Empty), oldCellForeColor(Color::Empty)
      , highlightedCell(nullptr)
		{
			InitializeComponent();
			//
// Create book data, one book per array
array<Object^>^ book1 = {gcnew DateTime(1999,11,5), L"0-09-174271-4",
                 L"Wonderful Life", L"Stephen Jay Gould", L"Hutchinson Radius"};
array<Object^>^ book2 = {gcnew DateTime(2001,10,25), L"0-09-977170-5",
                       L"The Emperor's New Mind", L"Roger Penrose", L"Vintage"};
array<Object^>^ book3 = {gcnew DateTime(1993,1,15), L"0-14-017996-8",
                    L"Metamagical Themas", "Douglas R. Hofstadter", L"Penguin"};
array<Object^>^ book4 = {gcnew DateTime(1994,2,7), L"0-201-36080-2",
            L"The Meaning Of It All", L"Richard P. Feynman", L"Addison-Wesley"};
array<Object^>^ book5 = {gcnew DateTime(1995,11,6), L"0-593-03449-X",
                          L"The Walpole Orange", "Frank Muir", L"Bantam Press"};
array<Object^>^ book6 = {gcnew DateTime(2004,7,16), L"0-439-99358-X",
      L"The Amber Spyglass", L"Philip Pullman", L"Scholastic Children's Books"};
array<Object^>^ book7 = {gcnew DateTime(2002,9,18), L"0-552-13461-9",
                               L"Pyramids", L"Terry Pratchett", L"Corgi Books"};
array<Object^>^ book8 = {gcnew DateTime(1998,2,27), L"0-7493-9739-X",
                                L"Made In America", L"Bill Bryson", L"Minerva"};

// Create Array of books
array<array<Object^>^>^ books = {book1, book2, book3, book4,
                                 book5, book6, book7, book8};
array<String^>^ headers = {L"Date", L"ISBN", L"Title", L"Author", L"Publisher"};
dataGridView->ColumnCount = headers->Length;          // Set number of columns

for(int i = 0 ; i<headers->Length ; i++)
  dataGridView->Columns[i]->Name = headers[i];

for each(array<Object^>^ book in books)
  dataGridView->Rows->Add(book);

dataGridView->Dock = DockStyle::Fill;
dataGridView->AutoResizeColumns();
dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
dataGridView->DefaultCellStyle->BackColor = Color::Pink;
dataGridView->DefaultCellStyle->ForeColor = Color::DarkBlue;
dataGridView->DefaultCellStyle->SelectionBackColor = Color::Green;
dataGridView->EnableHeadersVisualStyles = false;
DataGridViewCellStyle^ headerStyle = gcnew DataGridViewCellStyle;
headerStyle->Font = gcnew System::Drawing::Font("Times New Roman", 12,
                                                               FontStyle::Bold);
headerStyle->BackColor = Color::AliceBlue;
headerStyle->ForeColor = Color::BurlyWood;
dataGridView->ColumnHeadersDefaultCellStyle = headerStyle;
dataGridView->AutoResizeColumnHeadersHeight();

dataGridView->Columns[0]->DefaultCellStyle->Format = L"y";
for each(DataGridViewColumn^ column in dataGridView->Columns)
  column->ToolTipText = L"Click to\nsort rows";
dataGridView->AlternatingRowsDefaultCellStyle->BackColor = Color::Blue;
dataGridView->AlternatingRowsDefaultCellStyle->ForeColor = Color::White;

dataGridView->CellFormatting += 
   gcnew DataGridViewCellFormattingEventHandler(this, &Form1::OnCellFormatting);
dataGridView->CellMouseEnter +=
             gcnew DataGridViewCellEventHandler(this, &Form1::OnCellMouseEnter);
dataGridView->CellMouseLeave +=
             gcnew DataGridViewCellEventHandler(this, &Form1::OnCellMouseLeave);
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
  private: System::Windows::Forms::DataGridView^  dataGridView;
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
      this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
      this->SuspendLayout();
      // 
      // dataGridView
      // 
      this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
      this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
      this->dataGridView->Location = System::Drawing::Point(0, 0);
      this->dataGridView->Name = L"dataGridView";
      this->dataGridView->Size = System::Drawing::Size(292, 273);
      this->dataGridView->TabIndex = 0;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(292, 273);
      this->Controls->Add(this->dataGridView);
      this->Name = L"Form1";
      this->Text = L"My Other Book List";
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
      this->ResumeLayout(false);

    }
#pragma endregion
private:
void OnCellFormatting(Object^ sender, DataGridViewCellFormattingEventArgs^ e)
{
  // Check whether the cell is highlighted
  if(dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex] == highlightedCell)
    return;

 // Check if it's the date column
  if(dataGridView->Columns[e->ColumnIndex]->Name == L"Date")
  {
    // If the cell content is not null and the year is less than 2000
    // Set the background to red
    if(e->Value != nullptr && safe_cast<DateTime^>(e->Value)->Year < 2000)
    {
      e->CellStyle->BackColor = Color::Red;
      e->FormattingApplied = false;         // We did not format the data
    }
  }
}

// Stores for old cell colors in mouse enter event handler
// for restoring later in mouse leave event handler
private: Color oldCellBackColor;             
private: Color oldCellForeColor;

         private:
void OnCellMouseEnter(Object^ sender, DataGridViewCellEventArgs^ e)
{
  if(e->ColumnIndex >= 0 && e->RowIndex >= 0)    // Verify indexes non-negative 
  {
    // Identify the cell we have entered
    highlightedCell = dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex];
    
    // Save any old colors that are set
    oldCellBackColor = highlightedCell->Style->BackColor;
    oldCellForeColor = highlightedCell->Style->ForeColor;

    // Set highlight colors
    highlightedCell->Style->BackColor = Color::White;
    highlightedCell->Style->ForeColor = Color::Black;
  }
}

private:
void OnCellMouseLeave(Object^ sender, DataGridViewCellEventArgs^ e)
{
  if(e->ColumnIndex >=0 && e->RowIndex >=0)
  {
    // Restore the saved color values
    highlightedCell->Style->BackColor = oldCellBackColor;
    highlightedCell->Style->ForeColor = oldCellForeColor;

    // Reset save stores to no color
    oldCellForeColor = oldCellBackColor = Color::Empty;

    highlightedCell = nullptr;         // Reset highlighted cell handle
  }
}

private: DataGridViewCell^ highlightedCell;     // The currently highlighted cell
  };
}

