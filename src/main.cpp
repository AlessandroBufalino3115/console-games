#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>



//completed assignment --- grade 100%




int target_number = 0;    //general randomization variable bin

int player_guess = 0;        // guessing vars
bool guess_right;

char player_response_gametype, player_response_RPS_gametype;    // vars for what type of game mode is chosen from the main menu

char player_guess_rps;
std::string comp_guess_rps;      // rps vars
bool game_on;

int games_Won_In_Rps, games_played_in_RPS, games_Draw_in_RPS,games_False_in_RPS;     //all of the different stats in the RPs gamemode

bool Game_loop = true; // until this is true the game runs


void Guess_number()
{
  guess_right = false;

    srand(time(0));
    target_number = rand() % 10 + 1;
    std::cout << target_number << std::endl;
    std::cout << "The computer has guesses a number from 1 to 10, try and guess it! \n " << std::endl;

    for (int i = 1; i <= 5; ++i)
    {
      //std::cout << i << std::endl;      debugging purpose
      std:: cin >> player_guess;

      if (player_guess == target_number)
      {
        std::cout << "Nice, you guessed it right!\n\n" << std::endl;
        guess_right = true;
        break;
      }
      else if (player_guess > target_number)
      {
        std::cout << "Too high!" << std::endl;
      }
      else if (player_guess < target_number)
      {
        std::cout << "Too low!" << std::endl;
      }
    }

    if (!guess_right)
    {
      std::cout << "unlucky, the right number was " << target_number << ", maybe next time\n\n" << std::endl;
    }
}

void RPS(char player_Guess_rpsf, std::string comp_Guess_rpsf)    // takes in the two arguments and work out the outcome of the game
{
    // all of the conditions of the game

    switch (player_Guess_rpsf)
    {
      case 'r':
        if (comp_Guess_rpsf == "P")
        {
          std::cout << "computer chose paper, therefore you lose" << std::endl;
        }
        else if (comp_Guess_rpsf == "R")
        {
          std::cout << "computer chose rock, therefore you draw" << std::endl;
          games_Draw_in_RPS++;
        }
        else if (comp_Guess_rpsf == "S")
        {
          std::cout << "computer chose scissors, therefore you win" << std::endl;
          games_Won_In_Rps++;
        }
        break;

      case 'p':

        if (comp_Guess_rpsf == "P")
        {
          std::cout << "computer chose paper, therefore you draw" << std::endl;
          games_Draw_in_RPS++;
        }
        else if (comp_Guess_rpsf == "R")
        {
          std::cout << "computer chose rock, therefore you win" << std::endl;
          games_Won_In_Rps++;
        }
        else if (comp_Guess_rpsf == "S")
        {
          std::cout << "computer chose scissors, therefore you lose" << std::endl;
        }

        break;

      case 's':


        if (comp_Guess_rpsf == "P")
        {
          std::cout << "computer chose paper, therefore you win" << std::endl;
          games_Won_In_Rps++;
        }
        else if (comp_Guess_rpsf == "R")
        {
          std::cout << "computer chose rock, therefore you lose" << std::endl;
        }
        else if (comp_Guess_rpsf == "S")
        {
          std::cout << "computer chose scissors, therefore you draw"<< std::endl;
          games_Draw_in_RPS++;
        }


        break;

      default:
        std::cout << "looks like you miss typed something there"<< std::endl;
        games_False_in_RPS++;
            // to add to
        break;

    }
}

int main()
{
  std:: cout <<"Hello, welcome to console games.\n";

 while (Game_loop)
 {
   std:: cout <<"Input g to play Guess the number,\ninput r to "
                "play Rock Paper Scissors or\nto exit the game input e. " << std:: endl;    // main menu screen

   std:: cin >> player_response_gametype;     // player choosing the gamemode

   switch(player_response_gametype)
   {
     case 'r':       //rock paper scissors has been selected
       games_Won_In_Rps    = 0;
       games_played_in_RPS = 0;      // resetting stats
       games_Draw_in_RPS   = 0;

       std:: cout << "rock, paper, scissors has been chosen. What would you like to play against, "
                    "the file (f) [10 rounds] or a Random (r) number generator [infinite rounds]? \n" << std::endl;  // input for RPS game type
       std:: cin >> player_response_RPS_gametype;

       if (player_response_RPS_gametype == 'f')            // file type RPS game mode
       {
         std::cout << "Welcome to RPS, playing against file" << std::endl;

         std::ifstream inFile;

         inFile.open("C:\\Users\\alexh\\OneDrive\\Desktop\\Uni work\\Repositories for Git\\console-games-2020-AlessandroBufalino3115\\cmake-build-debug\\CMakeFiles\\RPS.txt");     // path of the file

         if (!inFile) {
           std::cout << "Unable to open file datafile.txt";     // error checking
         }
         else
         {
           while (std::getline(inFile, comp_guess_rps))         // getting each line from the .txt file
           {
             std::cout << "Chose: rock(r), paper(p), scissors(s): " << std::endl;
             std::cin >> player_guess_rps;

             RPS(player_guess_rps, comp_guess_rps);
           }

           inFile.close();  // closing the file when not in use anymore
           std:: cout << "Nice game, in total you have won " << games_Won_In_Rps
                     << "\nThe computer won " << 10 - games_Won_In_Rps - games_Draw_in_RPS - games_False_in_RPS
                     << "\nGames Draws " << games_Draw_in_RPS
                     << "\nGames with false inputs " << games_False_in_RPS
                     << "\n\n\n "<< std::endl;
         }
       }
       else if (player_response_RPS_gametype == 'r')
       {
         game_on = true;        // reset of the state of the bool if the player comes back to this game mode
         std::cout << "in this mode you are free to have as many goes as you want and the outcomes are all randomized, when you want to leave just input q"<< std::endl;

         while (game_on)             //true until the player wants to quit
         {
           std::cout << "chose: rock(r), paper(p), scissors(s)?" << std::endl;
           std :: cin >> player_guess_rps;

           if (player_guess_rps == 'q')        // finishing game, displaying values and outcomes
           {
             std::cout << "your total wins were " << games_Won_In_Rps
                       << " out of " << games_played_in_RPS
                       << ", therefore the winner is " <<std::endl;
             if (
               games_Won_In_Rps > games_played_in_RPS - games_Draw_in_RPS -
                                    games_Won_In_Rps - games_False_in_RPS)
             {
               std::cout << "The player!" <<std::endl;
             }
             else if(
               games_Won_In_Rps < games_played_in_RPS - games_Draw_in_RPS -
                                    games_Won_In_Rps -
                                    games_False_in_RPS)               // working out who won
             {
               std::cout << "The Comp!" <<std::endl;
             }
             else if(
               games_Won_In_Rps = games_played_in_RPS - games_Draw_in_RPS -
                                  games_Won_In_Rps - games_False_in_RPS)
             {
               std::cout << "no-one, its a draw!" <<std::endl;
             }

             std::cout << "The amount of game draws were " << games_Draw_in_RPS
                       << " and the amount of misstypes were " << games_False_in_RPS << "\n" <<std::endl;

             game_on = false;         // ending while loop
           }
           else
           {
             games_played_in_RPS++;

             srand(time(0));       // to ensure that its actually random
             target_number = rand() % 3 + 1;              // 1 rock    ,,   2 paper   ,,   3 scissors

             switch (target_number)                     // converting number into string type var used in the function
             {
               case 1:
                 comp_guess_rps = "R";
                 break;
               case 2:
                 comp_guess_rps = "P";
                 break;
               case 3:
                 comp_guess_rps = "S";
                 break;
             }
             RPS(player_guess_rps, comp_guess_rps);         // sending the values
           }
         }
       }
       break;

     case 'g':
       std:: cout << "Guess the number has been chosen\n" << std::endl;
       Guess_number();
       break;

     case 'e':
       std:: cout << "exiting game....";
       return 1;

     default:
       std :: cout << "sorry didnt get that \n" << std :: endl;      // in case of any typos
       continue;
   }
 }
  return 0;
}