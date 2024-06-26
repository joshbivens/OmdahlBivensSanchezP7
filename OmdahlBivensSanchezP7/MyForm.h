/*Section done by:
Name: Alexsia Omdahl
Email: aomdahl1@cnm.edu
Program: C++ Craps Game Group Project
File Name: OmdahlBivensSanchezP7*/

/*Art done by: LimeRi Arts (Catriona Omdahl)
Instagram: @limeriart
Inspiration for the art: Nier Replicant*/

#pragma once

#include "CrapsGame.h"
#include "UtilityFunctions.h"

namespace OmdahlBivensSanchezP7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	//class
	CrapsGame game;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//check if log was opened or not
			if (!game.IsTheLogOpen())
			{
				//message to user that log did not open
				GameStatus->Text = "Sorry! The log file has not opened properly!";
				
			}

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ GameRules;
	private: System::Windows::Forms::MenuStrip^ GameRulesMenu;
	private: System::Windows::Forms::PictureBox^ GameTablePic;
	private: System::Windows::Forms::Button^ RollD6Button;
	private: System::Windows::Forms::Button^ ReadyButton;
	private: System::Windows::Forms::Button^ DonePlayingBtn;
	private: System::Windows::Forms::Button^ PlayAgainBtn;
	private: System::Windows::Forms::Label^ GameStatusLable;
	private: System::Windows::Forms::Label^ PlayerNameLable;
	private: System::Windows::Forms::Label^ PlayerReadyLable;
	private: System::Windows::Forms::Label^ PlayerBetLable;
	private: System::Windows::Forms::TextBox^ PlayerBetTxtBox;
	private: System::Windows::Forms::TextBox^ PlayerNameTxtBox;
	private: System::Windows::Forms::PictureBox^ d6Left;
	private: System::Windows::Forms::PictureBox^ d6Right;
	private: System::Windows::Forms::PictureBox^ IdleDice;
	private: System::Windows::Forms::RichTextBox^ GameStatus;
	private: System::Windows::Forms::RichTextBox^ PlayerBalance;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->GameRules = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GameRulesMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->GameTablePic = (gcnew System::Windows::Forms::PictureBox());
			this->RollD6Button = (gcnew System::Windows::Forms::Button());
			this->ReadyButton = (gcnew System::Windows::Forms::Button());
			this->DonePlayingBtn = (gcnew System::Windows::Forms::Button());
			this->PlayAgainBtn = (gcnew System::Windows::Forms::Button());
			this->GameStatusLable = (gcnew System::Windows::Forms::Label());
			this->PlayerNameLable = (gcnew System::Windows::Forms::Label());
			this->PlayerReadyLable = (gcnew System::Windows::Forms::Label());
			this->PlayerBetLable = (gcnew System::Windows::Forms::Label());
			this->PlayerBetTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->PlayerNameTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->d6Left = (gcnew System::Windows::Forms::PictureBox());
			this->d6Right = (gcnew System::Windows::Forms::PictureBox());
			this->IdleDice = (gcnew System::Windows::Forms::PictureBox());
			this->GameStatus = (gcnew System::Windows::Forms::RichTextBox());
			this->PlayerBalance = (gcnew System::Windows::Forms::RichTextBox());
			this->GameRulesMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameTablePic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d6Left))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d6Right))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IdleDice))->BeginInit();
			this->SuspendLayout();
			// 
			// GameRules
			// 
			this->GameRules->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameRules->Name = L"GameRules";
			this->GameRules->Size = System::Drawing::Size(113, 22);
			this->GameRules->Text = L"Game Rules";
			this->GameRules->Click += gcnew System::EventHandler(this, &MyForm::GameRules_Click);
			// 
			// GameRulesMenu
			// 
			this->GameRulesMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->GameRulesMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->GameRules });
			this->GameRulesMenu->Location = System::Drawing::Point(0, 0);
			this->GameRulesMenu->Name = L"GameRulesMenu";
			this->GameRulesMenu->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->GameRulesMenu->Size = System::Drawing::Size(954, 26);
			this->GameRulesMenu->TabIndex = 0;
			this->GameRulesMenu->Text = L"menuStrip1";
			// 
			// GameTablePic
			// 
			this->GameTablePic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GameTablePic.Image")));
			this->GameTablePic->Location = System::Drawing::Point(0, 25);
			this->GameTablePic->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GameTablePic->Name = L"GameTablePic";
			this->GameTablePic->Size = System::Drawing::Size(754, 534);
			this->GameTablePic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->GameTablePic->TabIndex = 1;
			this->GameTablePic->TabStop = false;
			// 
			// RollD6Button
			// 
			this->RollD6Button->BackColor = System::Drawing::Color::Black;
			this->RollD6Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RollD6Button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->RollD6Button->Location = System::Drawing::Point(759, 522);
			this->RollD6Button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RollD6Button->Name = L"RollD6Button";
			this->RollD6Button->Size = System::Drawing::Size(186, 150);
			this->RollD6Button->TabIndex = 2;
			this->RollD6Button->Text = L"Roll the Dice";
			this->RollD6Button->UseVisualStyleBackColor = false;
			this->RollD6Button->Click += gcnew System::EventHandler(this, &MyForm::RollD6Button_Click);
			// 
			// ReadyButton
			// 
			this->ReadyButton->BackColor = System::Drawing::Color::Black;
			this->ReadyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ReadyButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ReadyButton->Location = System::Drawing::Point(161, 629);
			this->ReadyButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ReadyButton->Name = L"ReadyButton";
			this->ReadyButton->Size = System::Drawing::Size(254, 42);
			this->ReadyButton->TabIndex = 3;
			this->ReadyButton->Text = L"Ready To Play";
			this->ReadyButton->UseVisualStyleBackColor = false;
			this->ReadyButton->Click += gcnew System::EventHandler(this, &MyForm::ReadyButton_Click);
			// 
			// DonePlayingBtn
			// 
			this->DonePlayingBtn->BackColor = System::Drawing::Color::Black;
			this->DonePlayingBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DonePlayingBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->DonePlayingBtn->Location = System::Drawing::Point(419, 575);
			this->DonePlayingBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DonePlayingBtn->Name = L"DonePlayingBtn";
			this->DonePlayingBtn->Size = System::Drawing::Size(159, 96);
			this->DonePlayingBtn->TabIndex = 4;
			this->DonePlayingBtn->Text = L"I\'m Done!";
			this->DonePlayingBtn->UseVisualStyleBackColor = false;
			this->DonePlayingBtn->Click += gcnew System::EventHandler(this, &MyForm::DonePlayingBtn_Click);
			// 
			// PlayAgainBtn
			// 
			this->PlayAgainBtn->BackColor = System::Drawing::Color::Black;
			this->PlayAgainBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayAgainBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->PlayAgainBtn->Location = System::Drawing::Point(583, 575);
			this->PlayAgainBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PlayAgainBtn->Name = L"PlayAgainBtn";
			this->PlayAgainBtn->Size = System::Drawing::Size(159, 96);
			this->PlayAgainBtn->TabIndex = 5;
			this->PlayAgainBtn->Text = L"Play Again\?";
			this->PlayAgainBtn->UseVisualStyleBackColor = false;
			this->PlayAgainBtn->Click += gcnew System::EventHandler(this, &MyForm::PlayAgainBtn_Click);
			// 
			// GameStatusLable
			// 
			this->GameStatusLable->AutoSize = true;
			this->GameStatusLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameStatusLable->Location = System::Drawing::Point(792, 26);
			this->GameStatusLable->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GameStatusLable->Name = L"GameStatusLable";
			this->GameStatusLable->Size = System::Drawing::Size(127, 24);
			this->GameStatusLable->TabIndex = 6;
			this->GameStatusLable->Text = L"Game Status";
			// 
			// PlayerNameLable
			// 
			this->PlayerNameLable->AutoSize = true;
			this->PlayerNameLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerNameLable->Location = System::Drawing::Point(38, 579);
			this->PlayerNameLable->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PlayerNameLable->Name = L"PlayerNameLable";
			this->PlayerNameLable->Size = System::Drawing::Size(109, 15);
			this->PlayerNameLable->TabIndex = 8;
			this->PlayerNameLable->Text = L"1st, Your Name:";
			// 
			// PlayerReadyLable
			// 
			this->PlayerReadyLable->AutoSize = true;
			this->PlayerReadyLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerReadyLable->Location = System::Drawing::Point(12, 638);
			this->PlayerReadyLable->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PlayerReadyLable->Name = L"PlayerReadyLable";
			this->PlayerReadyLable->Size = System::Drawing::Size(136, 15);
			this->PlayerReadyLable->TabIndex = 11;
			this->PlayerReadyLable->Text = L"Lastly, Press Ready:";
			// 
			// PlayerBetLable
			// 
			this->PlayerBetLable->AutoSize = true;
			this->PlayerBetLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerBetLable->Location = System::Drawing::Point(9, 606);
			this->PlayerBetLable->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PlayerBetLable->Name = L"PlayerBetLable";
			this->PlayerBetLable->Size = System::Drawing::Size(135, 15);
			this->PlayerBetLable->TabIndex = 12;
			this->PlayerBetLable->Text = L"2nd, Enter Your Bet:";
			// 
			// PlayerBetTxtBox
			// 
			this->PlayerBetTxtBox->BackColor = System::Drawing::Color::Black;
			this->PlayerBetTxtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerBetTxtBox->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->PlayerBetTxtBox->Location = System::Drawing::Point(161, 602);
			this->PlayerBetTxtBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PlayerBetTxtBox->Name = L"PlayerBetTxtBox";
			this->PlayerBetTxtBox->Size = System::Drawing::Size(107, 21);
			this->PlayerBetTxtBox->TabIndex = 13;
			// 
			// PlayerNameTxtBox
			// 
			this->PlayerNameTxtBox->BackColor = System::Drawing::Color::Black;
			this->PlayerNameTxtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerNameTxtBox->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->PlayerNameTxtBox->Location = System::Drawing::Point(161, 575);
			this->PlayerNameTxtBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PlayerNameTxtBox->Name = L"PlayerNameTxtBox";
			this->PlayerNameTxtBox->Size = System::Drawing::Size(107, 21);
			this->PlayerNameTxtBox->TabIndex = 14;
			// 
			// d6Left
			// 
			this->d6Left->Location = System::Drawing::Point(575, 43);
			this->d6Left->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->d6Left->Name = L"d6Left";
			this->d6Left->Size = System::Drawing::Size(86, 88);
			this->d6Left->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->d6Left->TabIndex = 15;
			this->d6Left->TabStop = false;
			// 
			// d6Right
			// 
			this->d6Right->Location = System::Drawing::Point(665, 43);
			this->d6Right->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->d6Right->Name = L"d6Right";
			this->d6Right->Size = System::Drawing::Size(86, 88);
			this->d6Right->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->d6Right->TabIndex = 16;
			this->d6Right->TabStop = false;
			// 
			// IdleDice
			// 
			this->IdleDice->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IdleDice.Image")));
			this->IdleDice->Location = System::Drawing::Point(575, 136);
			this->IdleDice->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->IdleDice->Name = L"IdleDice";
			this->IdleDice->Size = System::Drawing::Size(166, 93);
			this->IdleDice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->IdleDice->TabIndex = 17;
			this->IdleDice->TabStop = false;
			// 
			// GameStatus
			// 
			this->GameStatus->BackColor = System::Drawing::Color::DarkGray;
			this->GameStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameStatus->ForeColor = System::Drawing::Color::White;
			this->GameStatus->Location = System::Drawing::Point(776, 50);
			this->GameStatus->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GameStatus->Name = L"GameStatus";
			this->GameStatus->Size = System::Drawing::Size(158, 453);
			this->GameStatus->TabIndex = 18;
			this->GameStatus->Text = L"";
			// 
			// PlayerBalance
			// 
			this->PlayerBalance->BackColor = System::Drawing::Color::DarkGray;
			this->PlayerBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerBalance->ForeColor = System::Drawing::Color::White;
			this->PlayerBalance->Location = System::Drawing::Point(272, 567);
			this->PlayerBalance->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PlayerBalance->Name = L"PlayerBalance";
			this->PlayerBalance->Size = System::Drawing::Size(144, 58);
			this->PlayerBalance->TabIndex = 19;
			this->PlayerBalance->Text = L"Your balance is:\n$200.00";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(954, 681);
			this->Controls->Add(this->PlayerBalance);
			this->Controls->Add(this->GameStatus);
			this->Controls->Add(this->IdleDice);
			this->Controls->Add(this->d6Right);
			this->Controls->Add(this->d6Left);
			this->Controls->Add(this->PlayerNameTxtBox);
			this->Controls->Add(this->PlayerBetTxtBox);
			this->Controls->Add(this->PlayerBetLable);
			this->Controls->Add(this->PlayerReadyLable);
			this->Controls->Add(this->PlayerNameLable);
			this->Controls->Add(this->GameStatusLable);
			this->Controls->Add(this->PlayAgainBtn);
			this->Controls->Add(this->DonePlayingBtn);
			this->Controls->Add(this->ReadyButton);
			this->Controls->Add(this->RollD6Button);
			this->Controls->Add(this->GameTablePic);
			this->Controls->Add(this->GameRulesMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->GameRulesMenu;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"Omdahl Bivens and Sanchez P7 Craps Game";
			this->GameRulesMenu->ResumeLayout(false);
			this->GameRulesMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameTablePic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d6Left))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d6Right))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IdleDice))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GameRules_Click(System::Object^ sender, System::EventArgs^ e) {
		//get managed String for the games rules and show in a messageBox using game.GameRules();
		//MessageBox::Show("Temp");
		MessageBox::Show(gcnew String(game.GetRules().c_str()));

	}

	private: System::Void RollD6Button_Click(System::Object^ sender, System::EventArgs^ e) {
		bool pointRound{ false };
		int i{0}, j{0};
		
		//roll the dice using ThrowTheDice()
		game.ThrowTheDice();

		//checks if the player is in the game or in the Point Round
		//uses game.GetPoint() to get the info. true for point round, false if not
		pointRound = game.GetPoint();

		//use tuple to get the dice number and unpack it
		auto tupeN = game.GetTheDice();
		tie(i, j) = tupeN;

		int total = i + j;

		//shows the dice for when the player roll the dice
		showDice();

		//crate a string to show the results to the player depending if it is a point round or not
		//include the balance as well
		if (pointRound)
		{
			GameStatus->Text = gcnew String(game.PlayPointRound().c_str());
		}
		else
		{
			GameStatus->Text = gcnew String(game.MakeYourPlay().c_str());
		}

		PlayerBalance->Text = "Your balance is: \n$" + gcnew String(game.GetBalance().ToString()) + ".00";
	}
	private: System::Void showDice() {
		int d6A{ 0 }, d6B{ 0 };
	
		//use tuple to get the dice images.
		auto tupeI = game.GetTheDice();

		//unpack the tuple into two components, d6A and d6B into the two dice
		d6A = get<0>(tupeI);
		d6B = get<1>(tupeI);

		//set the image info
		d6Left->Image = Image::FromFile(".\\die" + Convert::ToString(d6A) + "weiss.png");
		d6Right->Image = Image::FromFile(".\\die" + Convert::ToString(d6B) + "weiss.png");

	}

	private: System::Void PlayAgainBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//resets the game to its default values
		game.ResetGame();
		GameStatus->Text = "";
		PlayerBalance->Text = "Your balance is: \n$200.00";

	}

	private: System::Void DonePlayingBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//displays a summary using game.GetSummary() and calls GameOver()
		GameStatus->Text = gcnew String(game.GetSummary().c_str());
		game.GameOver();
		

	}

	private: System::Void ReadyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		bool isBet{ false };
		string name;

		//if successful, use SetName() and SetBet() methods from CrapsGame class to the there values

		//get the name of the user
		To_string(PlayerNameTxtBox->Text, name);
		game.SetName(name);

		//convert bet text from user to an number
		//SetBet() is a bool check if the bet is valid
		isBet = game.SetBet(Convert::ToInt32(PlayerBetTxtBox->Text));

		//if it is valid send a message to the GameSatus
		if (isBet)
		{
			//it will greet the player using there name and shows their bet and asks the player to
			//start playing by pressing Roll the Dice
			GameStatus->Text = "Hello " + gcnew String(game.GetName().c_str()) + ",\n you have placed a bet of $" + PlayerBetTxtBox->Text +
							".\n Please press 'Roll the Dice' to start playing.";
		};
	}
};
}
