#pragma once


namespace Ex23_04 {

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
  private: Ex23_04::DataSet1^  DataSet1;
  protected: 
  private: System::Windows::Forms::BindingSource^  Order_DetailsBindingSource;
  private: Ex23_04::DataSet1TableAdapters::Order_DetailsTableAdapter^  Order_DetailsTableAdapter;
  private: System::Windows::Forms::BindingNavigator^  Order_DetailsBindingNavigator;
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
  private: System::Windows::Forms::ToolStripButton^  Order_DetailsBindingNavigatorSaveItem;
  private: System::Windows::Forms::TextBox^  OrderIDTextBox;
  private: System::Windows::Forms::TextBox^  ProductIDTextBox;
  private: System::Windows::Forms::TextBox^  UnitPriceTextBox;
  private: System::Windows::Forms::NumericUpDown^  QuantityNumericUpDown;
  private: System::Windows::Forms::TextBox^  DiscountTextBox;
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
      System::Windows::Forms::Label^  OrderIDLabel;
      System::Windows::Forms::Label^  ProductIDLabel;
      System::Windows::Forms::Label^  UnitPriceLabel;
      System::Windows::Forms::Label^  QuantityLabel;
      System::Windows::Forms::Label^  DiscountLabel;
      this->DataSet1 = (gcnew Ex23_04::DataSet1());
      this->Order_DetailsBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
      this->Order_DetailsTableAdapter = (gcnew Ex23_04::DataSet1TableAdapters::Order_DetailsTableAdapter());
      this->Order_DetailsBindingNavigator = (gcnew System::Windows::Forms::BindingNavigator(this->components));
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
      this->Order_DetailsBindingNavigatorSaveItem = (gcnew System::Windows::Forms::ToolStripButton());
      this->OrderIDTextBox = (gcnew System::Windows::Forms::TextBox());
      this->ProductIDTextBox = (gcnew System::Windows::Forms::TextBox());
      this->UnitPriceTextBox = (gcnew System::Windows::Forms::TextBox());
      this->QuantityNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
      this->DiscountTextBox = (gcnew System::Windows::Forms::TextBox());
      OrderIDLabel = (gcnew System::Windows::Forms::Label());
      ProductIDLabel = (gcnew System::Windows::Forms::Label());
      UnitPriceLabel = (gcnew System::Windows::Forms::Label());
      QuantityLabel = (gcnew System::Windows::Forms::Label());
      DiscountLabel = (gcnew System::Windows::Forms::Label());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DataSet1))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Order_DetailsBindingSource))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Order_DetailsBindingNavigator))->BeginInit();
      this->Order_DetailsBindingNavigator->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->QuantityNumericUpDown))->BeginInit();
      this->SuspendLayout();
      // 
      // DataSet1
      // 
      this->DataSet1->DataSetName = L"DataSet1";
      this->DataSet1->SchemaSerializationMode = System::Data::SchemaSerializationMode::IncludeSchema;
      // 
      // Order_DetailsBindingSource
      // 
      this->Order_DetailsBindingSource->DataMember = L"Order Details";
      this->Order_DetailsBindingSource->DataSource = this->DataSet1;
      // 
      // Order_DetailsTableAdapter
      // 
      this->Order_DetailsTableAdapter->ClearBeforeFill = true;
      // 
      // Order_DetailsBindingNavigator
      // 
      this->Order_DetailsBindingNavigator->AddNewItem = this->bindingNavigatorAddNewItem;
      this->Order_DetailsBindingNavigator->BindingSource = this->Order_DetailsBindingSource;
      this->Order_DetailsBindingNavigator->CountItem = this->bindingNavigatorCountItem;
      this->Order_DetailsBindingNavigator->DeleteItem = this->bindingNavigatorDeleteItem;
      this->Order_DetailsBindingNavigator->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->bindingNavigatorMoveFirstItem, 
        this->bindingNavigatorMovePreviousItem, this->bindingNavigatorSeparator, this->bindingNavigatorPositionItem, this->bindingNavigatorCountItem, 
        this->bindingNavigatorSeparator1, this->bindingNavigatorMoveNextItem, this->bindingNavigatorMoveLastItem, this->bindingNavigatorSeparator2, 
        this->bindingNavigatorAddNewItem, this->bindingNavigatorDeleteItem, this->Order_DetailsBindingNavigatorSaveItem});
      this->Order_DetailsBindingNavigator->Location = System::Drawing::Point(0, 0);
      this->Order_DetailsBindingNavigator->MoveFirstItem = this->bindingNavigatorMoveFirstItem;
      this->Order_DetailsBindingNavigator->MoveLastItem = this->bindingNavigatorMoveLastItem;
      this->Order_DetailsBindingNavigator->MoveNextItem = this->bindingNavigatorMoveNextItem;
      this->Order_DetailsBindingNavigator->MovePreviousItem = this->bindingNavigatorMovePreviousItem;
      this->Order_DetailsBindingNavigator->Name = L"Order_DetailsBindingNavigator";
      this->Order_DetailsBindingNavigator->PositionItem = this->bindingNavigatorPositionItem;
      this->Order_DetailsBindingNavigator->Size = System::Drawing::Size(349, 25);
      this->Order_DetailsBindingNavigator->TabIndex = 0;
      this->Order_DetailsBindingNavigator->Text = L"bindingNavigator1";
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
      this->bindingNavigatorCountItem->Size = System::Drawing::Size(42, 16);
      this->bindingNavigatorCountItem->Text = L"of {0}";
      this->bindingNavigatorCountItem->ToolTipText = L"Total number of items";
      // 
      // bindingNavigatorSeparator1
      // 
      this->bindingNavigatorSeparator1->Name = L"bindingNavigatorSeparator";
      this->bindingNavigatorSeparator1->Size = System::Drawing::Size(6, 6);
      // 
      // bindingNavigatorMoveNextItem
      // 
      this->bindingNavigatorMoveNextItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorMoveNextItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorMoveNextItem.Image")));
      this->bindingNavigatorMoveNextItem->Name = L"bindingNavigatorMoveNextItem";
      this->bindingNavigatorMoveNextItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorMoveNextItem->Size = System::Drawing::Size(23, 20);
      this->bindingNavigatorMoveNextItem->Text = L"Move next";
      // 
      // bindingNavigatorMoveLastItem
      // 
      this->bindingNavigatorMoveLastItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->bindingNavigatorMoveLastItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bindingNavigatorMoveLastItem.Image")));
      this->bindingNavigatorMoveLastItem->Name = L"bindingNavigatorMoveLastItem";
      this->bindingNavigatorMoveLastItem->RightToLeftAutoMirrorImage = true;
      this->bindingNavigatorMoveLastItem->Size = System::Drawing::Size(23, 20);
      this->bindingNavigatorMoveLastItem->Text = L"Move last";
      // 
      // bindingNavigatorSeparator2
      // 
      this->bindingNavigatorSeparator2->Name = L"bindingNavigatorSeparator";
      this->bindingNavigatorSeparator2->Size = System::Drawing::Size(6, 6);
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
      this->bindingNavigatorDeleteItem->Size = System::Drawing::Size(23, 20);
      this->bindingNavigatorDeleteItem->Text = L"Delete";
      // 
      // Order_DetailsBindingNavigatorSaveItem
      // 
      this->Order_DetailsBindingNavigatorSaveItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->Order_DetailsBindingNavigatorSaveItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Order_DetailsBindingNavigatorSaveItem.Image")));
      this->Order_DetailsBindingNavigatorSaveItem->Name = L"Order_DetailsBindingNavigatorSaveItem";
      this->Order_DetailsBindingNavigatorSaveItem->Size = System::Drawing::Size(23, 23);
      this->Order_DetailsBindingNavigatorSaveItem->Text = L"Save Data";
      this->Order_DetailsBindingNavigatorSaveItem->Click += gcnew System::EventHandler(this, &Form1::Order_DetailsBindingNavigatorSaveItem_Click);
      // 
      // OrderIDLabel
      // 
      OrderIDLabel->AutoSize = true;
      OrderIDLabel->Location = System::Drawing::Point(81, 72);
      OrderIDLabel->Name = L"OrderIDLabel";
      OrderIDLabel->Size = System::Drawing::Size(50, 13);
      OrderIDLabel->TabIndex = 1;
      OrderIDLabel->Text = L"Order ID:";
      // 
      // OrderIDTextBox
      // 
      this->OrderIDTextBox->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->Order_DetailsBindingSource, L"OrderID", 
        true)));
      this->OrderIDTextBox->Location = System::Drawing::Point(148, 69);
      this->OrderIDTextBox->Name = L"OrderIDTextBox";
      this->OrderIDTextBox->Size = System::Drawing::Size(120, 20);
      this->OrderIDTextBox->TabIndex = 2;
      // 
      // ProductIDLabel
      // 
      ProductIDLabel->AutoSize = true;
      ProductIDLabel->Location = System::Drawing::Point(81, 98);
      ProductIDLabel->Name = L"ProductIDLabel";
      ProductIDLabel->Size = System::Drawing::Size(61, 13);
      ProductIDLabel->TabIndex = 3;
      ProductIDLabel->Text = L"Product ID:";
      // 
      // ProductIDTextBox
      // 
      this->ProductIDTextBox->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->Order_DetailsBindingSource, L"ProductID", 
        true)));
      this->ProductIDTextBox->Location = System::Drawing::Point(148, 95);
      this->ProductIDTextBox->Name = L"ProductIDTextBox";
      this->ProductIDTextBox->Size = System::Drawing::Size(120, 20);
      this->ProductIDTextBox->TabIndex = 4;
      // 
      // UnitPriceLabel
      // 
      UnitPriceLabel->AutoSize = true;
      UnitPriceLabel->Location = System::Drawing::Point(81, 124);
      UnitPriceLabel->Name = L"UnitPriceLabel";
      UnitPriceLabel->Size = System::Drawing::Size(56, 13);
      UnitPriceLabel->TabIndex = 5;
      UnitPriceLabel->Text = L"Unit Price:";
      // 
      // UnitPriceTextBox
      // 
      this->UnitPriceTextBox->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->Order_DetailsBindingSource, L"UnitPrice", 
        true)));
      this->UnitPriceTextBox->Location = System::Drawing::Point(148, 121);
      this->UnitPriceTextBox->Name = L"UnitPriceTextBox";
      this->UnitPriceTextBox->Size = System::Drawing::Size(120, 20);
      this->UnitPriceTextBox->TabIndex = 6;
      // 
      // QuantityLabel
      // 
      QuantityLabel->AutoSize = true;
      QuantityLabel->Location = System::Drawing::Point(81, 147);
      QuantityLabel->Name = L"QuantityLabel";
      QuantityLabel->Size = System::Drawing::Size(49, 13);
      QuantityLabel->TabIndex = 7;
      QuantityLabel->Text = L"Quantity:";
      // 
      // QuantityNumericUpDown
      // 
      this->QuantityNumericUpDown->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Value", this->Order_DetailsBindingSource, 
        L"Quantity", true)));
      this->QuantityNumericUpDown->Location = System::Drawing::Point(148, 147);
      this->QuantityNumericUpDown->Name = L"QuantityNumericUpDown";
      this->QuantityNumericUpDown->Size = System::Drawing::Size(120, 20);
      this->QuantityNumericUpDown->TabIndex = 8;
      // 
      // DiscountLabel
      // 
      DiscountLabel->AutoSize = true;
      DiscountLabel->Location = System::Drawing::Point(81, 176);
      DiscountLabel->Name = L"DiscountLabel";
      DiscountLabel->Size = System::Drawing::Size(52, 13);
      DiscountLabel->TabIndex = 9;
      DiscountLabel->Text = L"Discount:";
      // 
      // DiscountTextBox
      // 
      this->DiscountTextBox->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->Order_DetailsBindingSource, L"Discount", 
        true)));
      this->DiscountTextBox->Location = System::Drawing::Point(148, 173);
      this->DiscountTextBox->Name = L"DiscountTextBox";
      this->DiscountTextBox->Size = System::Drawing::Size(120, 20);
      this->DiscountTextBox->TabIndex = 10;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(349, 262);
      this->Controls->Add(OrderIDLabel);
      this->Controls->Add(this->OrderIDTextBox);
      this->Controls->Add(ProductIDLabel);
      this->Controls->Add(this->ProductIDTextBox);
      this->Controls->Add(UnitPriceLabel);
      this->Controls->Add(this->UnitPriceTextBox);
      this->Controls->Add(QuantityLabel);
      this->Controls->Add(this->QuantityNumericUpDown);
      this->Controls->Add(DiscountLabel);
      this->Controls->Add(this->DiscountTextBox);
      this->Controls->Add(this->Order_DetailsBindingNavigator);
      this->Name = L"Form1";
      this->Text = L"Binding Multiple Controls";
      this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DataSet1))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Order_DetailsBindingSource))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Order_DetailsBindingNavigator))->EndInit();
      this->Order_DetailsBindingNavigator->ResumeLayout(false);
      this->Order_DetailsBindingNavigator->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->QuantityNumericUpDown))->EndInit();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void Order_DetailsBindingNavigatorSaveItem_Click(System::Object^  sender, System::EventArgs^  e) {
             this->Validate();
             this->Order_DetailsBindingSource->EndEdit();
             this->Order_DetailsTableAdapter->Update(this->DataSet1->Order_Details);
           }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
           // TODO: This line of code loads data into the 'DataSet1.Order_Details' table. You can move, or remove it, as needed.
           this->Order_DetailsTableAdapter->Fill(this->DataSet1->Order_Details);
         }
};
}

