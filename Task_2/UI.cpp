

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
    string  main_menu= "1.Pyramic_Tic\n2.Four_in_a_row\n3.Tic Tac Toc size 5\n4.Word Tic\n5.Math Tic Tac Toe\n6.Misere Tic Tac Teo\n7.Tic Tac Toc size 4\n8.Tic Tac Teo 9x9\n9.Exit";
    string choice =check_menu(main_menu,choices);

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
    }else if(find(chars.begin(),chars.end(),choice)!=chars.end()){
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

    }else if(choice=="5"){
        // game 5
        Board<int> *Game;
        Player<int> *player1;
        Player<int> *player2;

        if(type!=0){
            MathTic(player1,player2,Game,type);
        }

    }else{
        return 0 ;
    }

   return 1;

}

int UI:: display_menu_players(string choice)
{
    string menu_1="Do you want to play with :\n\n1.AI_Player\n2.Human_Player\n3.Random Computer player\n4.Go Back\n\n";
    string menu_2="Do you want to play with :\n\n1.Human_Player\n2.Random Computer player\n3.Go Back\n\n";
    vector<string>choices_1={"1","2","3","4"};
    vector<string>choices_2={"1","2","3"};
    string menu;vector<string>choices;
    if(choice=="2"||choice=="5"){
        menu=menu_1;
        choices=choices_1;
    }else{
        menu=menu_2;
        choices=choices_2;
    }
    string Choice=check_menu(menu,choices);

    if(Choice=="4")
        return 0;
    else if(Choice=="1"){
        return 1;
    }else if(Choice=="2"){
        return 2;
    }else if(Choice=="3"){
        return 3;
    }
};

void UI:: Connect_4(Player<char>*player1,Player<char>*player2,Board<char>*board,int type)
{

   board=new Connect_Board();
   string name;cout<<"Enter your name ya first player : ";
   cin>>name;
   player1=new Connect_Player(name,'X');
   if(type==1){
       cout<<"Enter your name ya second player : ";
       cin>>name;
       player2=new Connect_Player(name,'O');
   }else if(type==2){
     player2=new AI_Player_Connect_Four('O');
     // SET BOARD
     player2->setBoard(board);
   }else if(type==3){
       player2=new Connect_Random_Player('O');
   }


    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();


}

void UI:: Pyramic(Player<char>*player1,Player<char>*player2,Board<char>*board,int type)
{

    board= new Pyramic_Board<char>();
    string name;cout<<"Enter your name ya first player : ";
    cin>>name;
    player1=new Pyramic_Player (name,'X');

    if(type==1){

        cout<<"Enter your name ya second player : ";
        cin>>name;
        player2=new Pyramic_Player<char> (name,'O');

    }/*else if(type==2){
        //AI PLAYER

        player2->setBoard(board);
    }*/else if(type==2){
        player2=new Pyramic_Random_Player<char>('O');
    }

    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();

}

void UI::wordTic(Player<char> *player1, Player<char> *player2, Board<char> *board, int type)
{
    board=new Word_Board<char> ();
    string name;cout<<"Enter your name ya first player : ";
    cin>>name;
    player1=new Word_Player<char>(name);
    if(type==1){
        cout<<"Enter your name ya second player : ";
        cin>>name;
        player2=new Word_Player<char>(name);
    }/*else if(type==2){
        //AI PLAYER
        // SET BOARD
        player2->setBoard(board);
    }*/else if(type==2){
        player2=new Word_Random_Player<char>();
    }

    Player<char>* playerPtr[2]={player1,player2};
    GameManager<char>manager(board, playerPtr);
    manager.run();


}

void UI:: Misere(Player<string>*player1,Player<string>*player2,Board<string>*board,int type)
{
    board=new MisereTicTacToc();
    string name;cout<<"Enter your name ya first player : ";
    cin>>name;
    player1=new MisereTicTacTocPlayer(name,"X");
    if(type==1){
        cout<<"Enter your name ya second player : ";
        cin>>name;
        player2=new MisereTicTacTocPlayer(name,"O");
    }else if(type==2){
        // SET BOARD
        player2->setBoard(board);
    }else if(type==3){
        player2=new MisereTicTacTocRandomPlayer("O");
    }

    //change of names
    //???



    Player<string>* playerPtr[2]={player1,player2};
    GameManager<string>manager(board, playerPtr);
    manager.run();

}

void UI:: TicSize5(Player<string>*player1,Player<string>*player2,Board<string>*board,int type){

    board=new TicTacToc_Size5();
    string name;cout<<"Enter your name ya first player : ";
    cin>>name;
    player1=new TicTacTocPlayer(name,"X");
    if(type==1){
        cout<<"Enter your name ya second player : ";
        cin>>name;
        player2=new TicTacTocPlayer(name,"O");
    }else if(type==2){
        //AI player

        // SET BOARD
        player2->setBoard(board);
    }else if(type==3){
        player2=new TicTacTocRandomPlayer("O");
    }

    Player<string>* playerPtr[2]={player1,player2};
    GameManager<string>manager(board, playerPtr);
    manager.run();

}

void UI:: MathTic(Player<int>*player1,Player<int>*player2,Board<int>*board,int type)
{
    board=new Math_Tic_Tac_Teo_board();
    string name;cout<<"Enter your name ya first player : ";
    cin>>name;
    player1=new Math_Tic_Tac_Teo_player(name,1);
    if(type==1){
        cout<<"Enter your name ya second player : ";
        cin>>name;
        player2=new Math_Tic_Tac_Teo_player(name,2);
    }else if(type==2){
        player2=new Math_Tic_Tac_Teo_AI_player(2);
        // SET BOARD
        player2->setBoard(board);
    }else if(type==3){
        player2=new Math_Tic_Tac_Teo_random_player(2);
    }


    Player<int>* playerPtr[2]={player1,player2};
    GameManager<int>manager(board, playerPtr);
    manager.run();



}




// needs to be implemented //NO AI
void UI:: TicSize4(Player<string>*player1,Player<string>*player2,Board<string>*board,int type)
{

}

// needs to be implemented //NO AI
void UI:: Tic9x9(Player<char>*player1,Player<char>*player2,Board<char>*board,int type)
{

}
