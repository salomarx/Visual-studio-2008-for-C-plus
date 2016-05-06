#pragma once


namespace Ex23_05 {

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
  private: System::Windows::Forms::TabControl^  tabControl1;
  protected: 
  private: System::Windows::Forms::TabPage^  tabPage1;
  private: System::Windows::Forms::Panel^  panel3;
  private: System::Windows::Forms::TabPage^  tabPage2;
  private: System::Windows::Forms::Panel^  panel2;
  private: System::Windows::Forms::TabPage^  tabPage3;
  private: System::Windows::Forms::Panel^  panel1;
  private: Ex23_05::DataSet1^  DataSet1;
  private: System::Windows::Forms::BindingSource^  EmployeesBindingSource;
  private: Ex23_05::DataSet1TableAdapters::EmployeesTableAdapter^  EmployeesTableAdapter;
  private: System::Windows::Forms::BindingNavigator^  EmployeesBindingNavigator;
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
  private: System::Windows::Forms::ToolStripButton^  EmployeesBindingNavigatorSaveItem;
  private: System::Windows::Forms::DataGridView^  EmployeesDataGridView;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn10;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn11;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn12;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn13;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn14;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn15;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn16;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn17;
  private: System::Windows::Forms::BindingSource^  CustomersBindingSource;
  private: Ex23_05::DataSet1TableAdapters::CustomersTableAdapter^  CustomersTableAdapter;
  private: System::Windows::Forms::BindingNavigator^  bindingNavigator1;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
  private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
  private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox1;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
  private: System::Windows::Forms::DataGridView^  CustomersDataGridView;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn18;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn19;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn20;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn21;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn22;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn23;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn24;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn25;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn26;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn27;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn28;
  private: System::Windows::Forms::BindingNavigator^  bindingNavigator2;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton8;
  private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton9;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton10;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton11;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
  private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox2;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton12;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton13;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
  private: System::Windows::Forms::ToolStripButton^  toolStripButton14;
  private: System::Windows::Forms::BindingSource^  ProductsBindingSource;
  private: Ex23_05::DataSet1TableAdapters::ProductsTableAdapter^  ProductsTableAdapter;
private: System::Windows::Forms::DataGridView^  ProductsDataGridView;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn29;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn30;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn31;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn32;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn33;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn34;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn35;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn36;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn37;
private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewCheckBoxColumn1;
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
      System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
      this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
      this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
      this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
      this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
      this->panel1 = (gcnew System::Windows::Forms::Panel());
      this->panel2 = (gcnew System::Windows::Forms::Panel());
      this->panel3 = (gcnew System::Windows::Forms::Panel());
      this->DataSet1 = (gcnew Ex23_05::DataSet1());
      this->EmployeesBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
      this->EmployeesTableAdapter = (gcnew Ex23_05::DataSet1TableAdapters::EmployeesTableAdapter());
      this->EmployeesBindingNavigator = (gcnew System::Windows::Forms::BindingNavigator(this->components));
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
      this->EmployeesBindingNavigatorSaveItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->EmployeesDataGridView = (gcnew System::Windows::Forms::DataGridView());
      this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->CustomersBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
      this->CustomersTableAdapter = (gcnew Ex23_05::DataSet1TableAdapters::CustomersTableAdapter());
      this->CustomersDataGridView = (gcnew System::Windows::Forms::DataGridView());
      this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn28 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->bindingNavigator1 = (gcnew System::Windows::Forms::BindingNavigator(this->components));
      this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
      this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
      this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
      this->bindingNavigator2 = (gcnew System::Windows::Forms::BindingNavigator(this->components));
      this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
      this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripButton10 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripButton11 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripTextBox2 = (gcnew System::Windows::Forms::ToolStripTextBox());
      this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripButton12 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripButton13 = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripButton14 = (gcnew System::Windows::Forms::ToolStripButton());
      this->ProductsBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
      this->ProductsTableAdapter = (gcnew Ex23_05::DataSet1TableAdapters::ProductsTableAdapter());
      this->ProductsDataGridView = (gcnew System::Windows::Forms::DataGridView());
      this->dataGridViewTextBoxColumn29 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn30 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn31 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn32 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn33 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn34 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn35 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn36 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewTextBoxColumn37 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->dataGridViewCheckBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
      this->tabControl1->SuspendLayout();
      this->tabPage1->SuspendLayout();
      this->tabPage2->SuspendLayout();
      this->tabPage3->SuspendLayout();
      this->panel1->SuspendLayout();
      this->panel2->SuspendLayout();
      this->panel3->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DataSet1))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EmployeesBindingSource))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EmployeesBindingNavigator))->BeginInit();
      this->EmployeesBindingNavigator->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EmployeesDataGridView))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CustomersBindingSource))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CustomersDataGridView))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingNavigator1))->BeginInit();
      this->bindingNavigator1->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingNavigator2))->BeginInit();
      this->bindingNavigator2->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ProductsBindingSource))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ProductsDataGridView))->BeginInit();
      this->SuspendLayout();
      // 
      // tabControl1
      // 
      this->tabControl1->Controls->Add(this->tabPage1);
      this->tabControl1->Controls->Add(this->tabPage2);
      this->tabControl1->Controls->Add(this->tabPage3);
      this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
      this->tabControl1->Location = System::Drawing::Point(0, 0);
      this->tabControl1->Name = L"tabControl1";
      this->tabControl1->SelectedIndex = 0;
      this->tabControl1->Size = System::Drawing::Size(389, 262);
      this->tabControl1->TabIndex = 0;
      // 
      // tabPage1
      // 
      this->tabPage1->AutoScroll = true;
      this->tabPage1->Controls->Add(this->panel3);
      this->tabPage1->Location = System::Drawing::Point(4, 22);
      this->tabPage1->Name = L"tabPage1";
      this->tabPage1->Padding = System::Windows::Forms::Padding(3);
      this->tabPage1->Size = System::Drawing::Size(381, 236);
      this->tabPage1->TabIndex = 0;
      this->tabPage1->Text = L"Employees";
      this->tabPage1->UseVisualStyleBackColor = true;
      // 
      // tabPage2
      // 
      this->tabPage2->AutoScroll = true;
      this->tabPage2->Controls->Add(this->panel2);
      this->tabPage2->Location = System::Drawing::Point(4, 22);
      this->tabPage2->Name = L"tabPage2";
      this->tabPage2->Padding = System::Windows::Forms::Padding(3);
      this->tabPage2->Size = System::Drawing::Size(381, 236);
      this->tabPage2->TabIndex = 1;
      this->tabPage2->Text = L"Customers";
      this->tabPage2->UseVisualStyleBackColor = true;
      // 
      // tabPage3
      // 
      this->tabPage3->AutoScroll = true;
      this->tabPage3->Controls->Add(this->panel1);
      this->tabPage3->Location = System::Drawing::Point(4, 22);
      this->tabPage3->Name = L"tabPage3";
      this->tabPage3->Padding = System::Windows::Forms::Padding(3);
      this->tabPage3->Size = System::Drawing::Size(381, 236);
      this->tabPage3->TabIndex = 2;
      this->tabPage3->Text = L"Products";
      this->tabPage3->UseVisualStyleBackColor = true;
      // 
      // panel1
      // 
      this->panel1->Controls->Add(this->ProductsDataGridView);
      this->panel1->Controls->Add(this->bindingNavigator2);
      this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
      this->panel1->Location = System::Drawing::Point(3, 3);
      this->panel1->Name = L"panel1";
      this->panel1->Size = System::Drawing::Size(375, 230);
      this->panel1->TabIndex = 0;
      // 
      // panel2
      // 
      this->panel2->Controls->Add(this->bindingNavigator1);
      this->panel2->Controls->Add(this->CustomersDataGridView);
      this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
      this->panel2->Location = System::Drawing::Point(3, 3);
      this->panel2->Name = L"panel2";
      this->panel2->Size = System::Drawing::Size(375, 230);
      this->panel2->TabIndex = 0;
      // 
      // panel3
      // 
      this->panel3->Controls->Add(this->EmployeesBindingNavigator);
      this->panel3->Controls->Add(this->EmployeesDataGridView);
      this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
      this->panel3->Location = System::Drawing::Point(3, 3);
      this->panel3->Name = L"panel3";
      this->panel3->Size = System::Drawing::Size(375, 230);
      this->panel3->TabIndex = 0;
      // 
      // DataSet1
      // 
      this->DataSet1->DataSetName = L"DataSet1";
      this->DataSet1->SchemaSerializationMode = System::Data::SchemaSerializationMode::IncludeSchema;
      // 
      // EmployeesBindingSource
      // 
      this->EmployeesBindingSource->DataMember = L"Employees";
      this->EmployeesBindingSource->DataSource = this->DataSet1;
      // 
      // EmployeesTableAdapter
      // 
      this->EmployeesTableAdapter->ClearBeforeFill = true;
      // 
      // EmployeesBindingNavigator
      // 
      this->EmployeesBindingNavigator->AddNewItem = this->bindingNavigatorAddNewItem;
      this->EmployeesBindingNavigator->BindingSource = this->EmployeesBindingSource;
      this->EmployeesBindingNavigator->CountItem = this->bindingNavigatorCountItem;
      this->EmployeesBindingNavigator->DeleteItem = this->bindingNavigatorDeleteItem;
      this->EmployeesBindingNavigator->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->bindingNavigatorMoveFirstItem, 
        this->bindingNavigatorMovePreviousItem, this->bindingNavigatorSeparator, this->bindingNavigatorPositionItem, this->bindingNavigatorCountItem, 
        this->bindingNavigatorSeparator1, this->bindingNavigatorMoveNextItem, this->bindingNavigatorMoveLastItem, this->bindingNavigatorSeparator2, 
        this->bindingNavigatorAddNewItem, this->bindingNavigatorDeleteItem, this->EmployeesBindingNavigatorSaveItem});
      this->EmployeesBindingNavigator->Location = System::Drawing::Point(0, 0);
      this->EmployeesBindingNavigator->MoveFirstItem = this->bindingNavigatorMoveFirstItem;
      this->EmployeesBindingNavigator->MoveLastItem = this->bindingNavigatorMoveLastItem;
      this->EmployeesBindingNavigator->MoveNextItem = this->bindingNavigatorMoveNextItem;
      this->EmployeesBindingNavigator->MovePreviousItem = this->bindingNavigatorMovePreviousItem;
      this->EmployeesBindingNavigator->Name = L"EmployeesBindingNavigator";
      this->EmployeesBindingNavigator->PositionItem = this->bindingNavigatorPositionItem;
      this->EmployeesBindingNavigator->Size = System::Drawing::Size(375, 25);
      this->EmployeesBindingNavigator->TabIndex = 1;
      this->EmployeesBindingNavigator->Text = L"bindingNavigator1";
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
      // 
      // bindingNavigatorDeleteItem
      // 
      this->bindingNavigatorDeleteItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorDeleteItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorDeleteItem.Image")));
      this->bindingNavigatorDeleteItem->Name = L"bindingNavigatorDeleteItem";
      this->bindingNavigatorDeleteItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorDeleteItem->Size = System::Drawing::Size(23, 22);
      this->bindingNavigatorDeleteItem->Text = L"Delete";
      // 
      // EmployeesBindingNavigatorSaveItem
      // 
      this->EmployeesBindingNavigatorSaveItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->EmployeesBindingNavigatorSaveItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"EmployeesBindingNavigatorSaveItem.Image")));
      this->EmployeesBindingNavigatorSaveItem->Name = L"EmployeesBindingNavigatorSaveItem";
      this->EmployeesBindingNavigatorSaveItem->Size = System::Drawing::Size(23, 22);
      this->EmployeesBindingNavigatorSaveItem->Text = L"Save Data";
      this->EmployeesBindingNavigatorSaveItem->Click += gcnew System::EventHandler(this, &Form1::EmployeesBindingNavigatorSaveItem_Click);
      // 
      // EmployeesDataGridView
      // 
      this->EmployeesDataGridView->AutoGenerateColumns = false;
      this->EmployeesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(17) {this->dataGridViewTextBoxColumn1, 
        this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5, 
        this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, 
        this->dataGridViewTextBoxColumn10, this->dataGridViewTextBoxColumn11, this->dataGridViewTextBoxColumn12, this->dataGridViewTextBoxColumn13, 
        this->dataGridViewTextBoxColumn14, this->dataGridViewTextBoxColumn15, this->dataGridViewTextBoxColumn16, this->dataGridViewTextBoxColumn17});
      this->EmployeesDataGridView->DataSource = this->EmployeesBindingSource;
      this->EmployeesDataGridView->Location = System::Drawing::Point(-3, 28);
      this->EmployeesDataGridView->Name = L"EmployeesDataGridView";
      this->EmployeesDataGridView->Size = System::Drawing::Size(380, 205);
      this->EmployeesDataGridView->TabIndex = 0;
      // 
      // dataGridViewTextBoxColumn1
      // 
      this->dataGridViewTextBoxColumn1->DataPropertyName = L"EmployeeID";
      this->dataGridViewTextBoxColumn1->HeaderText = L"EmployeeID";
      this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
      this->dataGridViewTextBoxColumn1->ReadOnly = true;
      // 
      // dataGridViewTextBoxColumn2
      // 
      this->dataGridViewTextBoxColumn2->DataPropertyName = L"LastName";
      this->dataGridViewTextBoxColumn2->HeaderText = L"LastName";
      this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
      // 
      // dataGridViewTextBoxColumn3
      // 
      this->dataGridViewTextBoxColumn3->DataPropertyName = L"FirstName";
      this->dataGridViewTextBoxColumn3->HeaderText = L"FirstName";
      this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
      // 
      // dataGridViewTextBoxColumn4
      // 
      this->dataGridViewTextBoxColumn4->DataPropertyName = L"Title";
      this->dataGridViewTextBoxColumn4->HeaderText = L"Title";
      this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
      // 
      // dataGridViewTextBoxColumn5
      // 
      this->dataGridViewTextBoxColumn5->DataPropertyName = L"TitleOfCourtesy";
      this->dataGridViewTextBoxColumn5->HeaderText = L"TitleOfCourtesy";
      this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
      // 
      // dataGridViewTextBoxColumn6
      // 
      this->dataGridViewTextBoxColumn6->DataPropertyName = L"BirthDate";
      this->dataGridViewTextBoxColumn6->HeaderText = L"BirthDate";
      this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
      // 
      // dataGridViewTextBoxColumn7
      // 
      this->dataGridViewTextBoxColumn7->DataPropertyName = L"HireDate";
      this->dataGridViewTextBoxColumn7->HeaderText = L"HireDate";
      this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
      // 
      // dataGridViewTextBoxColumn8
      // 
      this->dataGridViewTextBoxColumn8->DataPropertyName = L"Address";
      this->dataGridViewTextBoxColumn8->HeaderText = L"Address";
      this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
      // 
      // dataGridViewTextBoxColumn9
      // 
      this->dataGridViewTextBoxColumn9->DataPropertyName = L"City";
      this->dataGridViewTextBoxColumn9->HeaderText = L"City";
      this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
      // 
      // dataGridViewTextBoxColumn10
      // 
      this->dataGridViewTextBoxColumn10->DataPropertyName = L"Region";
      this->dataGridViewTextBoxColumn10->HeaderText = L"Region";
      this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
      // 
      // dataGridViewTextBoxColumn11
      // 
      this->dataGridViewTextBoxColumn11->DataPropertyName = L"PostalCode";
      this->dataGridViewTextBoxColumn11->HeaderText = L"PostalCode";
      this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
      // 
      // dataGridViewTextBoxColumn12
      // 
      this->dataGridViewTextBoxColumn12->DataPropertyName = L"Country";
      this->dataGridViewTextBoxColumn12->HeaderText = L"Country";
      this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
      // 
      // dataGridViewTextBoxColumn13
      // 
      this->dataGridViewTextBoxColumn13->DataPropertyName = L"HomePhone";
      this->dataGridViewTextBoxColumn13->HeaderText = L"HomePhone";
      this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
      // 
      // dataGridViewTextBoxColumn14
      // 
      this->dataGridViewTextBoxColumn14->DataPropertyName = L"Extension";
      this->dataGridViewTextBoxColumn14->HeaderText = L"Extension";
      this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
      // 
      // dataGridViewTextBoxColumn15
      // 
      this->dataGridViewTextBoxColumn15->DataPropertyName = L"Photo";
      this->dataGridViewTextBoxColumn15->HeaderText = L"Photo";
      this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
      // 
      // dataGridViewTextBoxColumn16
      // 
      this->dataGridViewTextBoxColumn16->DataPropertyName = L"Notes";
      this->dataGridViewTextBoxColumn16->HeaderText = L"Notes";
      this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
      // 
      // dataGridViewTextBoxColumn17
      // 
      this->dataGridViewTextBoxColumn17->DataPropertyName = L"ReportsTo";
      this->dataGridViewTextBoxColumn17->HeaderText = L"ReportsTo";
      this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
      // 
      // CustomersBindingSource
      // 
      this->CustomersBindingSource->DataMember = L"Customers";
      this->CustomersBindingSource->DataSource = this->DataSet1;
      // 
      // CustomersTableAdapter
      // 
      this->CustomersTableAdapter->ClearBeforeFill = true;
      // 
      // CustomersDataGridView
      // 
      this->CustomersDataGridView->AutoGenerateColumns = false;
      this->CustomersDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {this->dataGridViewTextBoxColumn18, 
        this->dataGridViewTextBoxColumn19, this->dataGridViewTextBoxColumn20, this->dataGridViewTextBoxColumn21, this->dataGridViewTextBoxColumn22, 
        this->dataGridViewTextBoxColumn23, this->dataGridViewTextBoxColumn24, this->dataGridViewTextBoxColumn25, this->dataGridViewTextBoxColumn26, 
        this->dataGridViewTextBoxColumn27, this->dataGridViewTextBoxColumn28});
      this->CustomersDataGridView->DataSource = this->CustomersBindingSource;
      this->CustomersDataGridView->Location = System::Drawing::Point(-3, 23);
      this->CustomersDataGridView->Name = L"CustomersDataGridView";
      this->CustomersDataGridView->Size = System::Drawing::Size(381, 214);
      this->CustomersDataGridView->TabIndex = 0;
      // 
      // dataGridViewTextBoxColumn18
      // 
      this->dataGridViewTextBoxColumn18->DataPropertyName = L"CustomerID";
      this->dataGridViewTextBoxColumn18->HeaderText = L"CustomerID";
      this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
      // 
      // dataGridViewTextBoxColumn19
      // 
      this->dataGridViewTextBoxColumn19->DataPropertyName = L"CompanyName";
      this->dataGridViewTextBoxColumn19->HeaderText = L"CompanyName";
      this->dataGridViewTextBoxColumn19->Name = L"dataGridViewTextBoxColumn19";
      // 
      // dataGridViewTextBoxColumn20
      // 
      this->dataGridViewTextBoxColumn20->DataPropertyName = L"ContactName";
      this->dataGridViewTextBoxColumn20->HeaderText = L"ContactName";
      this->dataGridViewTextBoxColumn20->Name = L"dataGridViewTextBoxColumn20";
      // 
      // dataGridViewTextBoxColumn21
      // 
      this->dataGridViewTextBoxColumn21->DataPropertyName = L"ContactTitle";
      this->dataGridViewTextBoxColumn21->HeaderText = L"ContactTitle";
      this->dataGridViewTextBoxColumn21->Name = L"dataGridViewTextBoxColumn21";
      // 
      // dataGridViewTextBoxColumn22
      // 
      this->dataGridViewTextBoxColumn22->DataPropertyName = L"Address";
      this->dataGridViewTextBoxColumn22->HeaderText = L"Address";
      this->dataGridViewTextBoxColumn22->Name = L"dataGridViewTextBoxColumn22";
      // 
      // dataGridViewTextBoxColumn23
      // 
      this->dataGridViewTextBoxColumn23->DataPropertyName = L"City";
      this->dataGridViewTextBoxColumn23->HeaderText = L"City";
      this->dataGridViewTextBoxColumn23->Name = L"dataGridViewTextBoxColumn23";
      // 
      // dataGridViewTextBoxColumn24
      // 
      this->dataGridViewTextBoxColumn24->DataPropertyName = L"Region";
      this->dataGridViewTextBoxColumn24->HeaderText = L"Region";
      this->dataGridViewTextBoxColumn24->Name = L"dataGridViewTextBoxColumn24";
      // 
      // dataGridViewTextBoxColumn25
      // 
      this->dataGridViewTextBoxColumn25->DataPropertyName = L"PostalCode";
      this->dataGridViewTextBoxColumn25->HeaderText = L"PostalCode";
      this->dataGridViewTextBoxColumn25->Name = L"dataGridViewTextBoxColumn25";
      // 
      // dataGridViewTextBoxColumn26
      // 
      this->dataGridViewTextBoxColumn26->DataPropertyName = L"Country";
      this->dataGridViewTextBoxColumn26->HeaderText = L"Country";
      this->dataGridViewTextBoxColumn26->Name = L"dataGridViewTextBoxColumn26";
      // 
      // dataGridViewTextBoxColumn27
      // 
      this->dataGridViewTextBoxColumn27->DataPropertyName = L"Phone";
      this->dataGridViewTextBoxColumn27->HeaderText = L"Phone";
      this->dataGridViewTextBoxColumn27->Name = L"dataGridViewTextBoxColumn27";
      // 
      // dataGridViewTextBoxColumn28
      // 
      this->dataGridViewTextBoxColumn28->DataPropertyName = L"Fax";
      this->dataGridViewTextBoxColumn28->HeaderText = L"Fax";
      this->dataGridViewTextBoxColumn28->Name = L"dataGridViewTextBoxColumn28";
      // 
      // bindingNavigator1
      // 
      this->bindingNavigator1->AddNewItem = this->toolStripButton1;
      this->bindingNavigator1->BindingSource = this->CustomersBindingSource;
      this->bindingNavigator1->CountItem = this->toolStripLabel1;
      this->bindingNavigator1->DeleteItem = this->toolStripButton2;
      this->bindingNavigator1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->toolStripButton3, 
        this->toolStripButton4, this->toolStripSeparator1, this->toolStripTextBox1, this->toolStripLabel1, this->toolStripSeparator2, 
        this->toolStripButton5, this->toolStripButton6, this->toolStripSeparator3, this->toolStripButton1, this->toolStripButton2, this->toolStripButton7});
      this->bindingNavigator1->Location = System::Drawing::Point(0, 0);
      this->bindingNavigator1->MoveFirstItem = this->toolStripButton3;
      this->bindingNavigator1->MoveLastItem = this->toolStripButton6;
      this->bindingNavigator1->MoveNextItem = this->toolStripButton5;
      this->bindingNavigator1->MovePreviousItem = this->toolStripButton4;
      this->bindingNavigator1->Name = L"bindingNavigator1";
      this->bindingNavigator1->PositionItem = this->toolStripTextBox1;
      this->bindingNavigator1->Size = System::Drawing::Size(375, 25);
      this->bindingNavigator1->TabIndex = 2;
      this->bindingNavigator1->Text = L"bindingNavigator1";
      // 
      // toolStripButton1
      // 
      this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
      this->toolStripButton1->Name = L"toolStripButton1";
      this->toolStripButton1->RightToLeftAutoMirrorImage = true;
      this->toolStripButton1->Size = System::Drawing::Size(23, 22);
      this->toolStripButton1->Text = L"Add new";
      // 
      // toolStripLabel1
      // 
      this->toolStripLabel1->Name = L"toolStripLabel1";
      this->toolStripLabel1->Size = System::Drawing::Size(42, 22);
      this->toolStripLabel1->Text = L"of {0}";
      this->toolStripLabel1->ToolTipText = L"Total number of items";
      // 
      // toolStripButton2
      // 
      this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
      this->toolStripButton2->Name = L"toolStripButton2";
      this->toolStripButton2->RightToLeftAutoMirrorImage = true;
      this->toolStripButton2->Size = System::Drawing::Size(23, 22);
      this->toolStripButton2->Text = L"Delete";
      // 
      // toolStripButton3
      // 
      this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
      this->toolStripButton3->Name = L"toolStripButton3";
      this->toolStripButton3->RightToLeftAutoMirrorImage = true;
      this->toolStripButton3->Size = System::Drawing::Size(23, 22);
      this->toolStripButton3->Text = L"Move first";
      // 
      // toolStripButton4
      // 
      this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
      this->toolStripButton4->Name = L"toolStripButton4";
      this->toolStripButton4->RightToLeftAutoMirrorImage = true;
      this->toolStripButton4->Size = System::Drawing::Size(23, 22);
      this->toolStripButton4->Text = L"Move previous";
      // 
      // toolStripSeparator1
      // 
      this->toolStripSeparator1->Name = L"toolStripSeparator1";
      this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripTextBox1
      // 
      this->toolStripTextBox1->AccessibleName = L"Position";
      this->toolStripTextBox1->AutoSize = false;
      this->toolStripTextBox1->Name = L"toolStripTextBox1";
      this->toolStripTextBox1->Size = System::Drawing::Size(50, 23);
      this->toolStripTextBox1->Text = L"0";
      this->toolStripTextBox1->ToolTipText = L"Current position";
      // 
      // toolStripSeparator2
      // 
      this->toolStripSeparator2->Name = L"toolStripSeparator2";
      this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripButton5
      // 
      this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton5.Image")));
      this->toolStripButton5->Name = L"toolStripButton5";
      this->toolStripButton5->RightToLeftAutoMirrorImage = true;
      this->toolStripButton5->Size = System::Drawing::Size(23, 22);
      this->toolStripButton5->Text = L"Move next";
      // 
      // toolStripButton6
      // 
      this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton6.Image")));
      this->toolStripButton6->Name = L"toolStripButton6";
      this->toolStripButton6->RightToLeftAutoMirrorImage = true;
      this->toolStripButton6->Size = System::Drawing::Size(23, 22);
      this->toolStripButton6->Text = L"Move last";
      // 
      // toolStripSeparator3
      // 
      this->toolStripSeparator3->Name = L"toolStripSeparator3";
      this->toolStripSeparator3->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripButton7
      // 
      this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton7.Image")));
      this->toolStripButton7->Name = L"toolStripButton7";
      this->toolStripButton7->Size = System::Drawing::Size(23, 22);
      this->toolStripButton7->Text = L"Save Data";
      // 
      // bindingNavigator2
      // 
      this->bindingNavigator2->AddNewItem = this->toolStripButton8;
      this->bindingNavigator2->BindingSource = this->ProductsBindingSource;
      this->bindingNavigator2->CountItem = this->toolStripLabel2;
      this->bindingNavigator2->DeleteItem = this->toolStripButton9;
      this->bindingNavigator2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->toolStripButton10, 
        this->toolStripButton11, this->toolStripSeparator4, this->toolStripTextBox2, this->toolStripLabel2, this->toolStripSeparator5, 
        this->toolStripButton12, this->toolStripButton13, this->toolStripSeparator6, this->toolStripButton8, this->toolStripButton9, 
        this->toolStripButton14});
      this->bindingNavigator2->Location = System::Drawing::Point(0, 0);
      this->bindingNavigator2->MoveFirstItem = this->toolStripButton10;
      this->bindingNavigator2->MoveLastItem = this->toolStripButton13;
      this->bindingNavigator2->MoveNextItem = this->toolStripButton12;
      this->bindingNavigator2->MovePreviousItem = this->toolStripButton11;
      this->bindingNavigator2->Name = L"bindingNavigator2";
      this->bindingNavigator2->PositionItem = this->toolStripTextBox2;
      this->bindingNavigator2->Size = System::Drawing::Size(375, 25);
      this->bindingNavigator2->TabIndex = 2;
      this->bindingNavigator2->Text = L"bindingNavigator1";
      // 
      // toolStripButton8
      // 
      this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton8.Image")));
      this->toolStripButton8->Name = L"toolStripButton8";
      this->toolStripButton8->RightToLeftAutoMirrorImage = true;
      this->toolStripButton8->Size = System::Drawing::Size(23, 20);
      this->toolStripButton8->Text = L"Add new";
      // 
      // toolStripLabel2
      // 
      this->toolStripLabel2->Name = L"toolStripLabel2";
      this->toolStripLabel2->Size = System::Drawing::Size(42, 22);
      this->toolStripLabel2->Text = L"of {0}";
      this->toolStripLabel2->ToolTipText = L"Total number of items";
      // 
      // toolStripButton9
      // 
      this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton9.Image")));
      this->toolStripButton9->Name = L"toolStripButton9";
      this->toolStripButton9->RightToLeftAutoMirrorImage = true;
      this->toolStripButton9->Size = System::Drawing::Size(23, 20);
      this->toolStripButton9->Text = L"Delete";
      // 
      // toolStripButton10
      // 
      this->toolStripButton10->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton10.Image")));
      this->toolStripButton10->Name = L"toolStripButton10";
      this->toolStripButton10->RightToLeftAutoMirrorImage = true;
      this->toolStripButton10->Size = System::Drawing::Size(23, 22);
      this->toolStripButton10->Text = L"Move first";
      // 
      // toolStripButton11
      // 
      this->toolStripButton11->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton11->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton11.Image")));
      this->toolStripButton11->Name = L"toolStripButton11";
      this->toolStripButton11->RightToLeftAutoMirrorImage = true;
      this->toolStripButton11->Size = System::Drawing::Size(23, 22);
      this->toolStripButton11->Text = L"Move previous";
      // 
      // toolStripSeparator4
      // 
      this->toolStripSeparator4->Name = L"toolStripSeparator4";
      this->toolStripSeparator4->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripTextBox2
      // 
      this->toolStripTextBox2->AccessibleName = L"Position";
      this->toolStripTextBox2->AutoSize = false;
      this->toolStripTextBox2->Name = L"toolStripTextBox2";
      this->toolStripTextBox2->Size = System::Drawing::Size(50, 23);
      this->toolStripTextBox2->Text = L"0";
      this->toolStripTextBox2->ToolTipText = L"Current position";
      // 
      // toolStripSeparator5
      // 
      this->toolStripSeparator5->Name = L"toolStripSeparator5";
      this->toolStripSeparator5->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripButton12
      // 
      this->toolStripButton12->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton12->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton12.Image")));
      this->toolStripButton12->Name = L"toolStripButton12";
      this->toolStripButton12->RightToLeftAutoMirrorImage = true;
      this->toolStripButton12->Size = System::Drawing::Size(23, 20);
      this->toolStripButton12->Text = L"Move next";
      // 
      // toolStripButton13
      // 
      this->toolStripButton13->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton13->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton13.Image")));
      this->toolStripButton13->Name = L"toolStripButton13";
      this->toolStripButton13->RightToLeftAutoMirrorImage = true;
      this->toolStripButton13->Size = System::Drawing::Size(23, 20);
      this->toolStripButton13->Text = L"Move last";
      // 
      // toolStripSeparator6
      // 
      this->toolStripSeparator6->Name = L"toolStripSeparator6";
      this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripButton14
      // 
      this->toolStripButton14->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripButton14->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton14.Image")));
      this->toolStripButton14->Name = L"toolStripButton14";
      this->toolStripButton14->Size = System::Drawing::Size(23, 20);
      this->toolStripButton14->Text = L"Save Data";
      // 
      // ProductsBindingSource
      // 
      this->ProductsBindingSource->DataMember = L"Products";
      this->ProductsBindingSource->DataSource = this->DataSet1;
      // 
      // ProductsTableAdapter
      // 
      this->ProductsTableAdapter->ClearBeforeFill = true;
      // 
      // ProductsDataGridView
      // 
      this->ProductsDataGridView->AutoGenerateColumns = false;
      this->ProductsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {this->dataGridViewTextBoxColumn29, 
        this->dataGridViewTextBoxColumn30, this->dataGridViewTextBoxColumn31, this->dataGridViewTextBoxColumn32, this->dataGridViewTextBoxColumn33, 
        this->dataGridViewTextBoxColumn34, this->dataGridViewTextBoxColumn35, this->dataGridViewTextBoxColumn36, this->dataGridViewTextBoxColumn37, 
        this->dataGridViewCheckBoxColumn1});
      this->ProductsDataGridView->DataSource = this->ProductsBindingSource;
      this->ProductsDataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
      this->ProductsDataGridView->Location = System::Drawing::Point(0, 25);
      this->ProductsDataGridView->Name = L"ProductsDataGridView";
      this->ProductsDataGridView->Size = System::Drawing::Size(375, 205);
      this->ProductsDataGridView->TabIndex = 2;
      // 
      // dataGridViewTextBoxColumn29
      // 
      this->dataGridViewTextBoxColumn29->DataPropertyName = L"ProductID";
      this->dataGridViewTextBoxColumn29->HeaderText = L"ProductID";
      this->dataGridViewTextBoxColumn29->Name = L"dataGridViewTextBoxColumn29";
      this->dataGridViewTextBoxColumn29->ReadOnly = true;
      // 
      // dataGridViewTextBoxColumn30
      // 
      this->dataGridViewTextBoxColumn30->DataPropertyName = L"ProductName";
      this->dataGridViewTextBoxColumn30->HeaderText = L"ProductName";
      this->dataGridViewTextBoxColumn30->Name = L"dataGridViewTextBoxColumn30";
      // 
      // dataGridViewTextBoxColumn31
      // 
      this->dataGridViewTextBoxColumn31->DataPropertyName = L"SupplierID";
      this->dataGridViewTextBoxColumn31->HeaderText = L"SupplierID";
      this->dataGridViewTextBoxColumn31->Name = L"dataGridViewTextBoxColumn31";
      // 
      // dataGridViewTextBoxColumn32
      // 
      this->dataGridViewTextBoxColumn32->DataPropertyName = L"CategoryID";
      this->dataGridViewTextBoxColumn32->HeaderText = L"CategoryID";
      this->dataGridViewTextBoxColumn32->Name = L"dataGridViewTextBoxColumn32";
      // 
      // dataGridViewTextBoxColumn33
      // 
      this->dataGridViewTextBoxColumn33->DataPropertyName = L"QuantityPerUnit";
      this->dataGridViewTextBoxColumn33->HeaderText = L"QuantityPerUnit";
      this->dataGridViewTextBoxColumn33->Name = L"dataGridViewTextBoxColumn33";
      // 
      // dataGridViewTextBoxColumn34
      // 
      this->dataGridViewTextBoxColumn34->DataPropertyName = L"UnitPrice";
      this->dataGridViewTextBoxColumn34->HeaderText = L"UnitPrice";
      this->dataGridViewTextBoxColumn34->Name = L"dataGridViewTextBoxColumn34";
      // 
      // dataGridViewTextBoxColumn35
      // 
      this->dataGridViewTextBoxColumn35->DataPropertyName = L"UnitsInStock";
      this->dataGridViewTextBoxColumn35->HeaderText = L"UnitsInStock";
      this->dataGridViewTextBoxColumn35->Name = L"dataGridViewTextBoxColumn35";
      // 
      // dataGridViewTextBoxColumn36
      // 
      this->dataGridViewTextBoxColumn36->DataPropertyName = L"UnitsOnOrder";
      this->dataGridViewTextBoxColumn36->HeaderText = L"UnitsOnOrder";
      this->dataGridViewTextBoxColumn36->Name = L"dataGridViewTextBoxColumn36";
      // 
      // dataGridViewTextBoxColumn37
      // 
      this->dataGridViewTextBoxColumn37->DataPropertyName = L"ReorderLevel";
      this->dataGridViewTextBoxColumn37->HeaderText = L"ReorderLevel";
      this->dataGridViewTextBoxColumn37->Name = L"dataGridViewTextBoxColumn37";
      // 
      // dataGridViewCheckBoxColumn1
      // 
      this->dataGridViewCheckBoxColumn1->DataPropertyName = L"Discontinued";
      this->dataGridViewCheckBoxColumn1->HeaderText = L"Discontinued";
      this->dataGridViewCheckBoxColumn1->Name = L"dataGridViewCheckBoxColumn1";
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(389, 262);
      this->Controls->Add(this->tabControl1);
      this->Name = L"Form1";
      this->Text = L"Accessing Multiple Tables";
      this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
      this->tabControl1->ResumeLayout(false);
      this->tabPage1->ResumeLayout(false);
      this->tabPage2->ResumeLayout(false);
      this->tabPage3->ResumeLayout(false);
      this->panel1->ResumeLayout(false);
      this->panel1->PerformLayout();
      this->panel2->ResumeLayout(false);
      this->panel2->PerformLayout();
      this->panel3->ResumeLayout(false);
      this->panel3->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DataSet1))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EmployeesBindingSource))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EmployeesBindingNavigator))->EndInit();
      this->EmployeesBindingNavigator->ResumeLayout(false);
      this->EmployeesBindingNavigator->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EmployeesDataGridView))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CustomersBindingSource))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CustomersDataGridView))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingNavigator1))->EndInit();
      this->bindingNavigator1->ResumeLayout(false);
      this->bindingNavigator1->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingNavigator2))->EndInit();
      this->bindingNavigator2->ResumeLayout(false);
      this->bindingNavigator2->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ProductsBindingSource))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ProductsDataGridView))->EndInit();
      this->ResumeLayout(false);

    }
#pragma endregion
  private: System::Void EmployeesBindingNavigatorSaveItem_Click(System::Object^  sender, System::EventArgs^  e) {
             this->Validate();
             this->EmployeesBindingSource->EndEdit();
             this->EmployeesTableAdapter->Update(this->DataSet1->Employees);
           }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
           // TODO: This line of code loads data into the 'DataSet1.Products' table. You can move, or remove it, as needed.
           this->ProductsTableAdapter->Fill(this->DataSet1->Products);
           // TODO: This line of code loads data into the 'DataSet1.Customers' table. You can move, or remove it, as needed.
           this->CustomersTableAdapter->Fill(this->DataSet1->Customers);
           // TODO: This line of code loads data into the 'DataSet1.Employees' table. You can move, or remove it, as needed.
           this->EmployeesTableAdapter->Fill(this->DataSet1->Employees);
         }
};
}

