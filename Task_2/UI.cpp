//
// Created by Fatma on 12/13/2024.
//

#include "UI.h"
string UI::check_menu(const string& menuText , vector<string>choices){
    string currentAnswer;

    while(true){
        cout << menuText ;
        getline(cin, currentAnswer);
        if(currentAnswer.size() != 1 || find(choices.begin(),choices.end(), currentAnswer) == choices.end())
            cout << "Please Enter a valid option\n" ;
        else
            break;
    }
    cin.ignore(0, '\n');

    return currentAnswer;
}

int UI::display_main_menu()
{


    // we will separate according to that criteria then according the single issues
    vector<string>choices{"1","2","3","4","5","6","7","8","9"};
    string  main_menu= "1.Pyramic_Tic\n2.Four_in_a_row\n3.Tic Tac Toc size 5\n4.Word Tic\n5.Math Tic Tac Toe\n6.Misere Tic Tac Teo\n7.Tic Tac Toc size 4\n8.Tic Tac Teo 9x9\n9.Exit\nYour Choice:";
    string choice =check_menu(main_menu,choices);

    if(choice=="9")
        return 0;

    vector<string>chars={"1","2","4","8"};
    vector<string>strings={"3","6","7"};

    int type=display_menu_players(choice);

    if(find(strings.begin(),strings.end(),choice)!=strings.end()){
        Board<string> *Game;
        Player<string> *player1;
        Player<string> *player2;

        if(type!=0){
            if (choice == "6") {
                Misere(player1,player2,Game,type);
            } else if (choice == "3") {
                TicSize5(player1,player2,Game,type);
            } else {
                TicSize4(player1,player2,Game,type);
            }
        }
    }
    else if(find(chars.begin(),chars.end(),choice)!=chars.end()){
        Board<char> *Game;
        Player<char> *player1;
        Player<char> *player2;

        if(type!=0){

           if(choice=="1"){
               Pyramic(player1,player2,Game,type);
           }else if(choice=="2"){
               Connect_4(player1,player2,Game,type);
           }else if(choice=="4"){
               wordTic(player1,player2,Game,type);
           }else{
               Tic9x9(player1,player2,Game,type);
           }

        }

    }
    else if(choice=="5"){
        // game 5
        Board<int> *Game;
        Player<int> *player1;
        Player<int> *player2;

        if(type!=0){
            MathTic(player1,player2,Game,type);
        }
    }

    return 1;

}

int UI:: display_menu_players(string choice)
{
    string menu_1="Type of player :\n\n1.AI_Player\n2.Human_Player\n3.Random Computer player\n4.Go Back\n\n";
    string menu_2="Type of player :\n\n1.Human_Player\n2.Random Computer player\n3.Go Back\n\n";
    vector<string>choices_1={"1","2","3","4"};
    vector<string>choices_2={"1","2","3"};
    string menu;vector<string>choices;
    bool flag;
    if( choice=="6"){
        menu=menu_1;
        choices=choices_1;
        flag=true;
    }else{
        menu=menu_2;
        choices=choices_2;
        flag= false;
    }
    string Choice=check_menu(menu,choices);

    if(flag){
        if (Choice == "4")
            return 0;
        else if (Choice == "1") {
            return 1;
        } else if (Choice == "2") {
            return 2;
        } else if (Choice == "3") {
            return 3;
        }
    }else{
        if (Choice == "3")
            return 0;
        else if (Choice == "1") {
            return 1;
        } else if (Choice == "2") {
            return 2;
        }
    }
};

void UI:: Connect_4(Player<char>*player1,Player<char>*player2,Board<char>*board,int type)
{

   board=new Connect_Board();
    string name;
   // for player_1
   if(type==1){
       cout<<"Enter your name ya first player : ";
       getline(cin,name,'\n');
       player1=new Connect_Player(name,'X');
   }else if(type==2){
       player1=new Connect_Random_Player('X');
   }


   int type_2= display_menu_players("2");

    if(type_2==1){
        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new Connect_Player(name,'O');
    }else if(type_2==2){
        player2=new Connect_Random_Player('O');
    }


    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();


}

void UI:: Pyramic(Player<char>*player1,Player<char>*player2,Board<char>*board,int type)
{

    board= new Pyramic_Board<char>();
    string name;


    if(type==1){

        cout<<"Enter your name ya first player : ";
        getline(cin,name,'\n');
        player1=new Pyramic_Player (name,'X');

    }else if(type==2){
        player1=new Pyramic_Random_Player<char>('X');
    }

    int type_2= display_menu_players("1");

    if(type_2==1){

        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new Pyramic_Player<char> (name,'O');

    }else if(type_2==2){
        player2=new Pyramic_Random_Player<char>('O');
    }

    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();

}

void UI::wordTic(Player<char> *player1, Player<char> *player2, Board<char> *board, int type)
{
    board=new Word_Board<char> ();
    string name;

    if(type==1){
        cout<<"Enter your name ya first player : ";
        getline(cin,name,'\n');
        player1=new Word_Player<char>(name);
    }else if(type==2){
        player1=new Word_Random_Player<char>();
    }


    int type_2= display_menu_players("4");
    if(type_2==1){
        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new Word_Player<char>(name);
    }else if(type_2==2){
        player2=new Word_Random_Player<char>();
    }

    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();


}

void UI:: Misere(Player<string>*player1,Player<string>*player2,Board<string>*board,int type){
    board=new MisereTicTacToc();
    string name1, name2;

    if(type == 1)
        name1 =  "AI Player 1";
    if(type==2){
        cout<<"Enter your name ya first player : ";
        getline(cin,name1,'\n');
    }
    else if(type==3)
        name1 =  "Random Computer Player 1";

    int type_2 = display_menu_players("6");

    if(type_2 == 1)
        name2 =  "AI Player 2";
    if(type_2==2){
        cout<<"Enter your name ya second player : ";
        getline(cin,name2,'\n');
    }
    else if(type_2==3)
        name2 =  "Random Computer Player 2";


    if(type==1){
        player1 = new MisereTicTacTacAIPlayer("X", name2);
        player1->setBoard(board);
    }
    else if(type==2)
        player1=new MisereTicTacTocPlayer(name2,"X");
    else if(type==3)
        player1=new MisereTicTacTocRandomPlayer("X" , name2);

    if(type_2==1){
        player2 = new MisereTicTacTacAIPlayer("O", name1);
        player2->setBoard(board);
    }
    else if(type_2==2)
        player2=new MisereTicTacTocPlayer(name1,"O");
    else if(type_2==3)
        player2=new MisereTicTacTocRandomPlayer("O",name1);

    Player<string>* playerPtr[2]={player1,player2};

    GameManager<string>manager(board, playerPtr);
    manager.run();

}

void UI:: TicSize5(Player<string>*player1,Player<string>*player2,Board<string>*board,int type){

    board=new TicTacToc_Size5();
    string name;

    if(type==1){
        cout<<"Enter your name ya first player : ";
        getline(cin,name,'\n');
        player1=new TicTacTocPlayer(name,"X");
    }
    else if(type==2)
        player1=new TicTacTocRandomPlayer("X");


    int type_2= display_menu_players("3");

    if(type_2==1){
        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new TicTacTocPlayer(name,"O");
    }
    else if(type_2==2)
        player2=new TicTacTocRandomPlayer("O");


    Player<string>* playerPtr[2]={player1,player2};
    GameManager<string>manager(board, playerPtr);
    manager.run();

}

void UI:: MathTic(Player<int>*player1,Player<int>*player2,Board<int>*board,int type)
{
    board=new Math_Tic_Tac_Teo_board();
    string name;
    if(type==1){
        cout<<"Enter your name ya first player : ";
        getline(cin,name,'\n');
        player1=new Math_Tic_Tac_Teo_player(name,1);

    }else if(type==2){
        player1=new Math_Tic_Tac_Teo_random_player(1);
    }

    int type_2= display_menu_players("5");
    if(type_2==1){
        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new Math_Tic_Tac_Teo_player(name,2);

    }else if(type_2==2){
        player2=new Math_Tic_Tac_Teo_random_player(2);
    }


    Player<int>* playerPtr[2]={player1,player2};
    GameManager<int>manager(board, playerPtr);
    manager.run();



}




// needs to be implemented //NO AI
void UI:: TicSize4(Player<string>*player1,Player<string>*player2,Board<string>*board,int type){
    board = new TicTacTocSize4Board();
    string name;
    if(type==1){
        cout<<"Enter your name ya first player : ";
        getline(cin,name,'\n');
        player1=new TicTacTocSize4Player(name,"X");
    }
    else if(type==2)
        player1=new TicTacTocSize4RandomPlayer("X");


    int type_2= display_menu_players("7");
    if(type_2==1){
        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new TicTacTocSize4Player(name,"O");
    }
    else if(type_2==2)
        player2=new TicTacTocSize4RandomPlayer("O");


    Player<string>* playerPtr[2]={player1,player2};

    for(auto player : playerPtr)
        player->setBoard(board);

    GameManager<string>manager(board, playerPtr);
    manager.run();

}

// needs to be implemented //NO AI
void UI:: Tic9x9(Player<char>*player1,Player<char>*player2,Board<char>*board,int type){

    board=new Tic_Tac_Toe_9x9_board();
    string name;
    if(type==1){
        cout<<"Enter your name ya first player : ";
        getline(cin,name,'\n');
        player1=new Tic_Tac_Toe_9x9_player(name,'X');
    }else if(type==2){
        player1=new Tic_Tac_Toe_9x9_random_player('X');
    }

    int type_2= display_menu_players("8");

    if(type_2==1){
        cout<<"Enter your name ya second player : ";
        getline(cin,name,'\n');
        player2=new Tic_Tac_Toe_9x9_player(name,'O');
    }else if(type_2==2){
        player2=new Tic_Tac_Toe_9x9_random_player('O');
    }


    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();
}
