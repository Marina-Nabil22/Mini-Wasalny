#pragma once
#include "Graph.h"
#include "IGetShortestPath.h"
#include "Dijkstra.h"
#include "SaveData.h"
#include "Display.h"
#include "Bellmanford.h"
#include <msclr\marshal_cppstd.h>
namespace DS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CreateNewGraph
	/// </summary>
	public ref class CreateNewGraph : public System::Windows::Forms::Form
	{
	public:
		CreateNewGraph(void)
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
		~CreateNewGraph()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ AddTown;
	private: System::Windows::Forms::Button^ DeleteTown;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ Undirected;

	private: System::Windows::Forms::RadioButton^ Directed;
	private: System::Windows::Forms::TextBox^ FirstTownName;
	private: System::Windows::Forms::TextBox^ SecondTownName;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Cost;
	private: System::Windows::Forms::Button^ UpdateEdge;










	private: System::Windows::Forms::Button^ RemoveEdge;

	private: System::Windows::Forms::Button^ AddEdge;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ TownName;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ saveData;
	private: System::Windows::Forms::TextBox^ GraphID;

	private: System::Windows::Forms::Label^ ID;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ BellmanFord;


	private: System::Windows::Forms::RadioButton^ dijkstra;











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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateNewGraph::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AddTown = (gcnew System::Windows::Forms::Button());
			this->DeleteTown = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Undirected = (gcnew System::Windows::Forms::RadioButton());
			this->Directed = (gcnew System::Windows::Forms::RadioButton());
			this->FirstTownName = (gcnew System::Windows::Forms::TextBox());
			this->SecondTownName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Cost = (gcnew System::Windows::Forms::TextBox());
			this->UpdateEdge = (gcnew System::Windows::Forms::Button());
			this->RemoveEdge = (gcnew System::Windows::Forms::Button());
			this->AddEdge = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TownName = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->saveData = (gcnew System::Windows::Forms::Button());
			this->GraphID = (gcnew System::Windows::Forms::TextBox());
			this->ID = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->BellmanFord = (gcnew System::Windows::Forms::RadioButton());
			this->dijkstra = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(720, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Town Name";
			this->label1->Click += gcnew System::EventHandler(this, &CreateNewGraph::label1_Click);
			// 
			// AddTown
			// 
			this->AddTown->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddTown->Location = System::Drawing::Point(898, 93);
			this->AddTown->Name = L"AddTown";
			this->AddTown->Size = System::Drawing::Size(103, 38);
			this->AddTown->TabIndex = 2;
			this->AddTown->Text = L"AddTown";
			this->AddTown->UseVisualStyleBackColor = true;
			this->AddTown->Click += gcnew System::EventHandler(this, &CreateNewGraph::button1_Click);
			// 
			// DeleteTown
			// 
			this->DeleteTown->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DeleteTown->Location = System::Drawing::Point(1029, 93);
			this->DeleteTown->Name = L"DeleteTown";
			this->DeleteTown->Size = System::Drawing::Size(103, 38);
			this->DeleteTown->TabIndex = 3;
			this->DeleteTown->Text = L"DeleteTown";
			this->DeleteTown->UseVisualStyleBackColor = true;
			this->DeleteTown->Click += gcnew System::EventHandler(this, &CreateNewGraph::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Undirected);
			this->groupBox1->Controls->Add(this->Directed);
			this->groupBox1->Location = System::Drawing::Point(1009, 182);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(157, 85);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &CreateNewGraph::groupBox1_Enter);
			// 
			// Undirected
			// 
			this->Undirected->AutoSize = true;
			this->Undirected->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Undirected->Location = System::Drawing::Point(32, 58);
			this->Undirected->Name = L"Undirected";
			this->Undirected->Size = System::Drawing::Size(77, 17);
			this->Undirected->TabIndex = 1;
			this->Undirected->Text = L"Undirected";
			this->Undirected->UseVisualStyleBackColor = true;
			this->Undirected->CheckedChanged += gcnew System::EventHandler(this, &CreateNewGraph::radioButton2_CheckedChanged);
			// 
			// Directed
			// 
			this->Directed->AutoSize = true;
			this->Directed->Checked = true;
			this->Directed->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Directed->Location = System::Drawing::Point(32, 19);
			this->Directed->Name = L"Directed";
			this->Directed->Size = System::Drawing::Size(65, 17);
			this->Directed->TabIndex = 0;
			this->Directed->TabStop = true;
			this->Directed->Text = L"Directed";
			this->Directed->UseVisualStyleBackColor = true;
			this->Directed->CheckedChanged += gcnew System::EventHandler(this, &CreateNewGraph::Directed_CheckedChanged);
			// 
			// FirstTownName
			// 
			this->FirstTownName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FirstTownName->Location = System::Drawing::Point(629, 347);
			this->FirstTownName->Name = L"FirstTownName";
			this->FirstTownName->Size = System::Drawing::Size(148, 29);
			this->FirstTownName->TabIndex = 5;
			this->FirstTownName->TextChanged += gcnew System::EventHandler(this, &CreateNewGraph::textBox2_TextChanged);
			// 
			// SecondTownName
			// 
			this->SecondTownName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SecondTownName->Location = System::Drawing::Point(824, 347);
			this->SecondTownName->Name = L"SecondTownName";
			this->SecondTownName->Size = System::Drawing::Size(148, 29);
			this->SecondTownName->TabIndex = 6;
			this->SecondTownName->TextChanged += gcnew System::EventHandler(this, &CreateNewGraph::textBox3_TextChanged);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label2->Location = System::Drawing::Point(832, 321);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 23);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Second Town";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label3->Location = System::Drawing::Point(650, 321);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 23);
			this->label3->TabIndex = 8;
			this->label3->Text = L"First Town";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label4->Location = System::Drawing::Point(1042, 321);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 23);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Cost";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &CreateNewGraph::label4_Click);
			// 
			// Cost
			// 
			this->Cost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cost->Location = System::Drawing::Point(1009, 347);
			this->Cost->Name = L"Cost";
			this->Cost->Size = System::Drawing::Size(148, 29);
			this->Cost->TabIndex = 10;
			// 
			// UpdateEdge
			// 
			this->UpdateEdge->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UpdateEdge->Location = System::Drawing::Point(848, 413);
			this->UpdateEdge->Name = L"UpdateEdge";
			this->UpdateEdge->Size = System::Drawing::Size(103, 38);
			this->UpdateEdge->TabIndex = 11;
			this->UpdateEdge->Text = L"Update Edge";
			this->UpdateEdge->UseVisualStyleBackColor = true;
			this->UpdateEdge->Click += gcnew System::EventHandler(this, &CreateNewGraph::button3_Click);
			// 
			// RemoveEdge
			// 
			this->RemoveEdge->Cursor = System::Windows::Forms::Cursors::Hand;
			this->RemoveEdge->Location = System::Drawing::Point(994, 413);
			this->RemoveEdge->Name = L"RemoveEdge";
			this->RemoveEdge->Size = System::Drawing::Size(103, 38);
			this->RemoveEdge->TabIndex = 16;
			this->RemoveEdge->Text = L"Remove Edge";
			this->RemoveEdge->UseVisualStyleBackColor = true;
			this->RemoveEdge->Click += gcnew System::EventHandler(this, &CreateNewGraph::button4_Click);
			// 
			// AddEdge
			// 
			this->AddEdge->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddEdge->Location = System::Drawing::Point(703, 413);
			this->AddEdge->Name = L"AddEdge";
			this->AddEdge->Size = System::Drawing::Size(103, 38);
			this->AddEdge->TabIndex = 17;
			this->AddEdge->Text = L"Add Edge";
			this->AddEdge->UseVisualStyleBackColor = true;
			this->AddEdge->Click += gcnew System::EventHandler(this, &CreateNewGraph::button5_Click);
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Location = System::Drawing::Point(148, 27);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(150, 38);
			this->button6->TabIndex = 18;
			this->button6->Text = L"Display Graph Data";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &CreateNewGraph::button6_Click);
			// 
			// button7
			// 
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->Location = System::Drawing::Point(164, 550);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(150, 38);
			this->button7->TabIndex = 19;
			this->button7->Text = L"Shortest Path";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &CreateNewGraph::button7_Click);
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(58, 495);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(148, 29);
			this->textBox7->TabIndex = 20;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &CreateNewGraph::textBox7_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(282, 495);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(148, 29);
			this->textBox8->TabIndex = 21;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &CreateNewGraph::textBox8_TextChanged);
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label7->Location = System::Drawing::Point(99, 469);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 23);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Source";
			this->label7->Click += gcnew System::EventHandler(this, &CreateNewGraph::label7_Click);
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label8->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label8->Location = System::Drawing::Point(301, 469);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(115, 23);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Destination";
			// 
			// TownName
			// 
			this->TownName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TownName->Location = System::Drawing::Point(703, 95);
			this->TownName->Name = L"TownName";
			this->TownName->Size = System::Drawing::Size(148, 29);
			this->TownName->TabIndex = 0;
			this->TownName->TextChanged += gcnew System::EventHandler(this, &CreateNewGraph::textBox1_TextChanged);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 25;
			this->listBox1->Location = System::Drawing::Point(23, 93);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(392, 329);
			this->listBox1->TabIndex = 24;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &CreateNewGraph::listBox1_SelectedIndexChanged_1);
			// 
			// saveData
			// 
			this->saveData->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveData->Location = System::Drawing::Point(1029, 550);
			this->saveData->Name = L"saveData";
			this->saveData->Size = System::Drawing::Size(103, 38);
			this->saveData->TabIndex = 25;
			this->saveData->Text = L"Save and Exit";
			this->saveData->UseVisualStyleBackColor = true;
			this->saveData->Click += gcnew System::EventHandler(this, &CreateNewGraph::saveData_Click);
			// 
			// GraphID
			// 
			this->GraphID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GraphID->Location = System::Drawing::Point(836, 559);
			this->GraphID->Name = L"GraphID";
			this->GraphID->Size = System::Drawing::Size(148, 29);
			this->GraphID->TabIndex = 26;
			this->GraphID->TextChanged += gcnew System::EventHandler(this, &CreateNewGraph::textBox1_TextChanged_1);
			// 
			// ID
			// 
			this->ID->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->ID->AutoSize = true;
			this->ID->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ID->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID->ForeColor = System::Drawing::SystemColors::Highlight;
			this->ID->Location = System::Drawing::Point(894, 533);
			this->ID->Name = L"ID";
			this->ID->Size = System::Drawing::Size(33, 23);
			this->ID->TabIndex = 27;
			this->ID->Text = L"ID";
			this->ID->Click += gcnew System::EventHandler(this, &CreateNewGraph::ID_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->BellmanFord);
			this->groupBox2->Controls->Add(this->dijkstra);
			this->groupBox2->Location = System::Drawing::Point(450, 495);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(157, 85);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			// 
			// BellmanFord
			// 
			this->BellmanFord->AutoSize = true;
			this->BellmanFord->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BellmanFord->Location = System::Drawing::Point(32, 58);
			this->BellmanFord->Name = L"BellmanFord";
			this->BellmanFord->Size = System::Drawing::Size(83, 17);
			this->BellmanFord->TabIndex = 1;
			this->BellmanFord->Text = L"BellmanFord";
			this->BellmanFord->UseVisualStyleBackColor = true;
			// 
			// dijkstra
			// 
			this->dijkstra->AutoSize = true;
			this->dijkstra->Checked = true;
			this->dijkstra->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dijkstra->Location = System::Drawing::Point(32, 19);
			this->dijkstra->Name = L"dijkstra";
			this->dijkstra->Size = System::Drawing::Size(60, 17);
			this->dijkstra->TabIndex = 0;
			this->dijkstra->TabStop = true;
			this->dijkstra->Text = L"Dijkstra";
			this->dijkstra->UseVisualStyleBackColor = true;
			this->dijkstra->CheckedChanged += gcnew System::EventHandler(this, &CreateNewGraph::radioButton2_CheckedChanged_1);
			// 
			// CreateNewGraph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1216, 645);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->ID);
			this->Controls->Add(this->GraphID);
			this->Controls->Add(this->saveData);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->AddEdge);
			this->Controls->Add(this->RemoveEdge);
			this->Controls->Add(this->UpdateEdge);
			this->Controls->Add(this->Cost);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->SecondTownName);
			this->Controls->Add(this->FirstTownName);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->DeleteTown);
			this->Controls->Add(this->AddTown);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TownName);
			this->Name = L"CreateNewGraph";
			this->Text = L"CreateNewGraph";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &CreateNewGraph::CreateNewGraph_FormClosed);
			this->Load += gcnew System::EventHandler(this, &CreateNewGraph::CreateNewGraph_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void CreateNewGraph_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			Application::OpenForms[0]->Close();
		}
		private: System::Void CreateNewGraph_Load(System::Object^ sender, System::EventArgs^ e) {
			
		}
		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			if (TownName->Text == "")
				return;
			msclr::interop::marshal_context context;
			std::string Name = context.marshal_as<std::string>(TownName->Text);
			Graph::Instance()->AddTown(Name);
			TownName->Clear();
		}
		private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			msclr::interop::marshal_context context;
			std::string Name = context.marshal_as<std::string>(TownName->Text);
			Graph::Instance()->RemoveTown(Name);
			TownName->Clear();
		}
		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			msclr::interop::marshal_context context;
			std::string firstTown = context.marshal_as<std::string>(FirstTownName->Text);
			std::string secondTown = context.marshal_as<std::string>(SecondTownName->Text);
			int cost;
			try {
				cost = System::Convert::ToInt32(Cost->Text);
			}
			catch (...) {
				MessageBox::Show("Please Enter A valid Cost");
				return;
			}
			Graph::Instance()->AddEdge(firstTown, secondTown, cost);
			if (Undirected->Checked) {
				Graph::Instance()->AddEdge(secondTown, firstTown, cost);
			}
			FirstTownName->Clear();
			SecondTownName->Clear();
			Cost->Clear();
		}
		private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			msclr::interop::marshal_context context;
			std::string firstTown = context.marshal_as<std::string>(FirstTownName->Text);
			std::string secondTown = context.marshal_as<std::string>(SecondTownName->Text);
			int cost;
			try {
				cost = System::Convert::ToInt32(Cost->Text);
			}
			catch (...) {
				MessageBox::Show("Please Enter A valid Cost");
				return;
			}
			Graph::Instance()->UpdateEdge(firstTown, secondTown, cost);
			if (Undirected->Checked) {
				Graph::Instance()->UpdateEdge(secondTown, firstTown, cost);
			}
			FirstTownName->Clear();
			SecondTownName->Clear();
			Cost->Clear();
		}
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			msclr::interop::marshal_context context;
			std::string firstTown = context.marshal_as<std::string>(FirstTownName->Text);
			std::string secondTown = context.marshal_as<std::string>(SecondTownName->Text);
			int cost;
			try {
				cost = System::Convert::ToInt32(Cost->Text);
			}
			catch (...) {
				MessageBox::Show("Please Enter A valid Cost");
				return;
			}
			Graph::Instance()->DeleteEdge(firstTown, secondTown, cost);
			if (Undirected->Checked) {
				Graph::Instance()->DeleteEdge(secondTown, firstTown, cost);
			}
			FirstTownName->Clear();
			SecondTownName->Clear();
			Cost->Clear();
		}
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			msclr::interop::marshal_context context;
			Display d;
			std::list<std::string> Data = d.DisplayGraphData(Graph::Instance()->getTowns());
			listBox1->Items->Clear();
			for (auto &it : Data) {
				String^ newItem = gcnew String(it.c_str());
				listBox1->Items->Add(newItem);
				delete newItem;
			}
		}
		private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
			listBox1->Items->Clear();
			msclr::interop::marshal_context context;
			std::string source = context.marshal_as<std::string>(textBox7->Text);
			std::string destination = context.marshal_as<std::string>(textBox8->Text);
			IGetShortestPath *p = nullptr;
			if (dijkstra->Checked)
				p = new Dijkstra;
			else
				p = new Bellmanford;
			std::pair<std::list<std::string>,int> path = p->GetShortestPath(source, destination, Graph::Instance()->getTowns());
			if (path.first.empty()) {
				listBox1->Items->Add("Can't find path to the destination");
				return;
			}
			listBox1->Items->Add("Total Cost = " + path.second);
			for (auto& it : path.first) {
				String^ Item = gcnew String(it.c_str());
				listBox1->Items->Add(Item);
				delete Item;
			}
			delete p;
		}
		private: System::Void GraphData_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label9_Click_1(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void listBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void saveData_Click(System::Object^ sender, System::EventArgs^ e) {
			SaveData s;
			msclr::interop::marshal_context context;
			std::string ID = context.marshal_as<std::string>(GraphID->Text);
			s.Save(ID, Graph::Instance()->getTowns());
			this->Close();
		}
		private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void ID_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		}
private: System::Void Directed_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton2_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
