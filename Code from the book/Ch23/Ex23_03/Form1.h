#pragma once


namespace Ex23_03 {

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
      dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
      dataGridView->AutoResizeColumnHeadersHeight();
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
  private: Ex22_03::Customers^  Customers;
  private: System::Windows::Forms::BindingSource^  customersBindingSource;
  private: Ex22_03::CustomersTableAdapters::CustomersTableAdapter^  CustomersTableAdapter;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  customerIDDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  companyNameDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  contactNameDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  contactTitleDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  addressDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  cityDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  regionDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  postalCodeDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  countryDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  phoneDataGridViewTextBoxColumn;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  faxDataGridViewTextBoxColumn;
  private: System::Windows::Forms::BindingNavigator^  bindingNavigator1;
  private: System::Windows::Forms::ToolStripButton^  bindingNavigatorAddNewItem;
  private: System::Windows::Forms::ToolStripLabel^  bindingNavigatorCountItem;
  private: System::Windows::Forms::ToolStripButton^  bindingNavigatorDeleteItem;
  private: System::Windows::Forms::ToolStripButton^  bindingNavigatorMoveFirstItem;
  private: System::Windows::Forms::ToolStripButton^  bindingNavigatorMovePreviousItem;
  private: System::Windows::Forms::ToolStripSeparator^  bindingNavigatorSeparator;
  private: System::Windows::Forms::ToolStripTextBox^  bindingNavigatorPositionItem;
  private: System::Windows::Forms::ToolStripSeparator^  bindingNavigatorSeparator1;
  private: System::Windows::Forms::ToolStripButton^  bindingNavigatorMoveNextItem;
  private: System::Windows::Forms::ToolStripButton^  bindingNavigatorMoveLastItem;
  private: System::Windows::Forms::ToolStripSeparator^  bindingNavigatorSeparator2;
  private: System::ComponentModel::IContainer^  components;
  protected: 

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
      System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
      this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
      this->customerIDDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->companyNameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->contactNameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->contactTitleDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->addressDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->cityDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->regionDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->postalCodeDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->countryDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->phoneDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->faxDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->customersBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
      this->Customers = (gcnew Ex22_03::Customers());
      this->CustomersTableAdapter = (gcnew Ex22_03::CustomersTableAdapters::CustomersTableAdapter());
      this->bindingNavigator1 = (gcnew System::Windows::Forms::BindingNavigator(this->components));
      this->bindingNavigatorMoveFirstItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->bindingNavigatorMovePreviousItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->bindingNavigatorSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->bindingNavigatorPositionItem = (gcnew System::Windows::Forms::ToolStripTextBox());
      this->bindingNavigatorCountItem = (gcnew System::Windows::Forms::ToolStripLabel());
      this->bindingNavigatorSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->bindingNavigatorMoveNextItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->bindingNavigatorMoveLastItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->bindingNavigatorSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->bindingNavigatorAddNewItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->bindingNavigatorDeleteItem = (gcnew System::Windows::Forms::ToolStripButton());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->customersBindingSource))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Customers))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingNavigator1))->BeginInit();
      this->bindingNavigator1->SuspendLayout();
      this->SuspendLayout();
      // 
      // dataGridView
      // 
      this->dataGridView->AutoGenerateColumns = false;
      this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
      this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {this->customerIDDataGridViewTextBoxColumn, 
        this->companyNameDataGridViewTextBoxColumn, this->contactNameDataGridViewTextBoxColumn, this->contactTitleDataGridViewTextBoxColumn, 
        this->addressDataGridViewTextBoxColumn, this->cityDataGridViewTextBoxColumn, this->regionDataGridViewTextBoxColumn, this->postalCodeDataGridViewTextBoxColumn, 
        this->countryDataGridViewTextBoxColumn, this->phoneDataGridViewTextBoxColumn, this->faxDataGridViewTextBoxColumn});
      this->dataGridView->DataSource = this->customersBindingSource;
      this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
      this->dataGridView->Location = System::Drawing::Point(0, 0);
      this->dataGridView->Name = L"dataGridView";
      this->dataGridView->Size = System::Drawing::Size(442, 262);
      this->dataGridView->TabIndex = 0;
      // 
      // customerIDDataGridViewTextBoxColumn
      // 
      this->customerIDDataGridViewTextBoxColumn->DataPropertyName = L"CustomerID";
      this->customerIDDataGridViewTextBoxColumn->HeaderText = L"CustomerID";
      this->customerIDDataGridViewTextBoxColumn->Name = L"customerIDDataGridViewTextBoxColumn";
      // 
      // companyNameDataGridViewTextBoxColumn
      // 
      this->companyNameDataGridViewTextBoxColumn->DataPropertyName = L"CompanyName";
      this->companyNameDataGridViewTextBoxColumn->HeaderText = L"CompanyName";
      this->companyNameDataGridViewTextBoxColumn->Name = L"companyNameDataGridViewTextBoxColumn";
      // 
      // contactNameDataGridViewTextBoxColumn
      // 
      this->contactNameDataGridViewTextBoxColumn->DataPropertyName = L"ContactName";
      this->contactNameDataGridViewTextBoxColumn->HeaderText = L"ContactName";
      this->contactNameDataGridViewTextBoxColumn->Name = L"contactNameDataGridViewTextBoxColumn";
      // 
      // contactTitleDataGridViewTextBoxColumn
      // 
      this->contactTitleDataGridViewTextBoxColumn->DataPropertyName = L"ContactTitle";
      this->contactTitleDataGridViewTextBoxColumn->HeaderText = L"ContactTitle";
      this->contactTitleDataGridViewTextBoxColumn->Name = L"contactTitleDataGridViewTextBoxColumn";
      // 
      // addressDataGridViewTextBoxColumn
      // 
      this->addressDataGridViewTextBoxColumn->DataPropertyName = L"Address";
      this->addressDataGridViewTextBoxColumn->HeaderText = L"Address";
      this->addressDataGridViewTextBoxColumn->Name = L"addressDataGridViewTextBoxColumn";
      // 
      // cityDataGridViewTextBoxColumn
      // 
      this->cityDataGridViewTextBoxColumn->DataPropertyName = L"City";
      this->cityDataGridViewTextBoxColumn->HeaderText = L"City";
      this->cityDataGridViewTextBoxColumn->Name = L"cityDataGridViewTextBoxColumn";
      // 
      // regionDataGridViewTextBoxColumn
      // 
      this->regionDataGridViewTextBoxColumn->DataPropertyName = L"Region";
      this->regionDataGridViewTextBoxColumn->HeaderText = L"Region";
      this->regionDataGridViewTextBoxColumn->Name = L"regionDataGridViewTextBoxColumn";
      // 
      // postalCodeDataGridViewTextBoxColumn
      // 
      this->postalCodeDataGridViewTextBoxColumn->DataPropertyName = L"PostalCode";
      this->postalCodeDataGridViewTextBoxColumn->HeaderText = L"PostalCode";
      this->postalCodeDataGridViewTextBoxColumn->Name = L"postalCodeDataGridViewTextBoxColumn";
      // 
      // countryDataGridViewTextBoxColumn
      // 
      this->countryDataGridViewTextBoxColumn->DataPropertyName = L"Country";
      this->countryDataGridViewTextBoxColumn->HeaderText = L"Country";
      this->countryDataGridViewTextBoxColumn->Name = L"countryDataGridViewTextBoxColumn";
      // 
      // phoneDataGridViewTextBoxColumn
      // 
      this->phoneDataGridViewTextBoxColumn->DataPropertyName = L"Phone";
      this->phoneDataGridViewTextBoxColumn->HeaderText = L"Phone";
      this->phoneDataGridViewTextBoxColumn->Name = L"phoneDataGridViewTextBoxColumn";
      // 
      // faxDataGridViewTextBoxColumn
      // 
      this->faxDataGridViewTextBoxColumn->DataPropertyName = L"Fax";
      this->faxDataGridViewTextBoxColumn->HeaderText = L"Fax";
      this->faxDataGridViewTextBoxColumn->Name = L"faxDataGridViewTextBoxColumn";
      // 
      // customersBindingSource
      // 
      this->customersBindingSource->DataMember = L"Customers";
      this->customersBindingSource->DataSource = this->Customers;
      // 
      // Customers
      // 
      this->Customers->DataSetName = L"Customers";
      this->Customers->SchemaSerializationMode = System::Data::SchemaSerializationMode::IncludeSchema;
      // 
      // CustomersTableAdapter
      // 
      this->CustomersTableAdapter->ClearBeforeFill = true;
      // 
      // bindingNavigator1
      // 
      this->bindingNavigator1->AddNewItem = this->bindingNavigatorAddNewItem;
      this->bindingNavigator1->BindingSource = this->customersBindingSource;
      this->bindingNavigator1->CountItem = this->bindingNavigatorCountItem;
      this->bindingNavigator1->DeleteItem = this->bindingNavigatorDeleteItem;
      this->bindingNavigator1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->bindingNavigatorMoveFirstItem, 
        this->bindingNavigatorMovePreviousItem, this->bindingNavigatorSeparator, this->bindingNavigatorPositionItem, this->bindingNavigatorCountItem, 
        this->bindingNavigatorSeparator1, this->bindingNavigatorMoveNextItem, this->bindingNavigatorMoveLastItem, this->bindingNavigatorSeparator2, 
        this->bindingNavigatorAddNewItem, this->bindingNavigatorDeleteItem});
      this->bindingNavigator1->Location = System::Drawing::Point(0, 0);
      this->bindingNavigator1->MoveFirstItem = this->bindingNavigatorMoveFirstItem;
      this->bindingNavigator1->MoveLastItem = this->bindingNavigatorMoveLastItem;
      this->bindingNavigator1->MoveNextItem = this->bindingNavigatorMoveNextItem;
      this->bindingNavigator1->MovePreviousItem = this->bindingNavigatorMovePreviousItem;
      this->bindingNavigator1->Name = L"bindingNavigator1";
      this->bindingNavigator1->PositionItem = this->bindingNavigatorPositionItem;
      this->bindingNavigator1->Size = System::Drawing::Size(442, 25);
      this->bindingNavigator1->TabIndex = 1;
      this->bindingNavigator1->Text = L"bindingNavigator1";
      // 
      // bindingNavigatorMoveFirstItem
      // 
      this->bindingNavigatorMoveFirstItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorMoveFirstItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorMoveFirstItem.Image")));
      this->bindingNavigatorMoveFirstItem->Name = L"bindingNavigatorMoveFirstItem";
      this->bindingNavigatorMoveFirstItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorMoveFirstItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorMoveFirstItem->Text = L"Move first";
      // 
      // bindingNavigatorMovePreviousItem
      // 
      this->bindingNavigatorMovePreviousItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorMovePreviousItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorMovePreviousItem.Image")));
      this->bindingNavigatorMovePreviousItem->Name = L"bindingNavigatorMovePreviousItem";
      this->bindingNavigatorMovePreviousItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorMovePreviousItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorMovePreviousItem->Text = L"Move previous";
      // 
      // bindingNavigatorSeparator
      // 
      this->bindingNavigatorSeparator->Name = L"bindingNavigatorSeparator";
      this->bindingNavigatorSeparator->Size = System::Drawing::Size(6, 25);
      // 
      // bindingNavigatorPositionItem
      // 
      this->bindingNavigatorPositionItem->AccessibleName = L"Position";
      this->bindingNavigatorPositionItem->AutoSize = false;
      this->bindingNavigatorPositionItem->Name = L"bindingNavigatorPositionItem";
      this->bindingNavigatorPositionItem->Size = System::Drawing::Size(50, 23);
      this->bindingNavigatorPositionItem->Text = L"0";
      this->bindingNavigatorPositionItem->ToolTipText = L"Current position";
      // 
      // bindingNavigatorCountItem
      // 
      this->bindingNavigatorCountItem->Name = L"bindingNavigatorCountItem";
      this->bindingNavigatorCountItem->Size = System::Drawing::Size(42, 22);
      this->bindingNavigatorCountItem->Text = L"of {0}";
      this->bindingNavigatorCountItem->ToolTipText = L"Total number of items";
      // 
      // bindingNavigatorSeparator1
      // 
      this->bindingNavigatorSeparator1->Name = L"bindingNavigatorSeparator";
      this->bindingNavigatorSeparator1->Size = System::Drawing::Size(6, 25);
      // 
      // bindingNavigatorMoveNextItem
      // 
      this->bindingNavigatorMoveNextItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorMoveNextItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorMoveNextItem.Image")));
      this->bindingNavigatorMoveNextItem->Name = L"bindingNavigatorMoveNextItem";
      this->bindingNavigatorMoveNextItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorMoveNextItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorMoveNextItem->Text = L"Move next";
      // 
      // bindingNavigatorMoveLastItem
      // 
      this->bindingNavigatorMoveLastItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorMoveLastItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorMoveLastItem.Image")));
      this->bindingNavigatorMoveLastItem->Name = L"bindingNavigatorMoveLastItem";
      this->bindingNavigatorMoveLastItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorMoveLastItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorMoveLastItem->Text = L"Move last";
      // 
      // bindingNavigatorSeparator2
      // 
      this->bindingNavigatorSeparator2->Name = L"bindingNavigatorSeparator";
      this->bindingNavigatorSeparator2->Size = System::Drawing::Size(6, 25);
      // 
      // bindingNavigatorAddNewItem
      // 
      this->bindingNavigatorAddNewItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorAddNewItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorAddNewItem.Image")));
      this->bindingNavigatorAddNewItem->Name = L"bindingNavigatorAddNewItem";
      this->bindingNavigatorAddNewItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorAddNewItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorAddNewItem->Text = L"Add new";
      this->bindingNavigatorAddNewItem->Click += gcnew System::EventHandler(this, &Form1::bindingNavigatorAddNewItem_Click);
      // 
      // bindingNavigatorDeleteItem
      // 
      this->bindingNavigatorDeleteItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorDeleteItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorDeleteItem.Image")));
      this->bindingNavigatorDeleteItem->Name = L"bindingNavigatorDeleteItem";
      this->bindingNavigatorDeleteItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorDeleteItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorDeleteItem->Text = L"Delete";
      this->bindingNavigatorDeleteItem->Click += gcnew System::EventHandler(this, &Form1::bindingNavigatorDeleteItem_Click);
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(442, 262);
      this->Controls->Add(this->bindingNavigator1);
      this->Controls->Add(this->dataGridView);
      this->Name = L"Form1";
      this->Text = L"Using a Binding Source Component";
      this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->customersBindingSource))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Customers))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingNavigator1))->EndInit();
      this->bindingNavigator1->ResumeLayout(false);
      this->bindingNavigator1->PerformLayout();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
             // TODO: This line of code loads data into the 'Customers._Customers' table. You can move, or remove it, as needed.
             this->CustomersTableAdapter->Fill(this->Customers->_Customers);
           }
  private:
    System::Void bindingNavigatorAddNewItem_Click(System::Object^  sender, System::EventArgs^  e) 
    {
      try
      {
        CustomersTableAdapter->Update(Customers->_Customers);
//        CustomersTableAdapter->Update(NorthwindDataSet->Customers);
      }
      catch (Exception^ ex)
      {
        MessageBox::Show(L"Update Failed!\n"+ex,
                         L"Database Record Update Error",
                         MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
      }
    }
  private: 
    System::Void bindingNavigatorDeleteItem_Click(System::Object^  sender, System::EventArgs^  e) 
    {
      try
      {
        CustomersTableAdapter->Update(Customers->_Customers);
      }
      catch (Exception^ ex)
      {
        MessageBox::Show(L"Delete Failed!\n"+ex,
                         L"Database Record Delete Error",
                         MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
      }
    }
};
}

