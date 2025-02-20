int ifread_01;
int ifread_02;
int flag_01=0;
int flag_02=0;
int result=0;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT); 
  Serial.println("Press 'x' to start the game or 'o' to stop the game.");


}

void loop() {

   if (Serial.available() > 0) {
    char input = Serial.read(); // Read a single character

    if (input == 'x' || input == 'X') {
      Serial.println("\nGame started! Press 'o' to stop the game.");
      playGame();
    } else if (input == 'o' || input == 'O') {
      Serial.println("\nGame over! Program stopped.");
      exit(0); // Terminate the program
    }
  }
}

void playGame(){
  ifread_01=analogRead(A0);
  ifread_02=analogRead(A2);

  if (ifread_01 >= 150) {
    flag_01 = 1;
  } else {
    flag_01 = 0;  
  }
   if (ifread_02 >= 150) {
    flag_02 = 1;
  } else {
    flag_02 = 0;  
  }
  int player_choice;
  result=flag_01 + flag_02;
  if(result==2){
    player_choice=2;
  }
  else if(result==1){
  player_choice=1;
  }
  else if(result==0){
player_choice=0;
  }
int bot_choice=random(0,3);
int winner=get_winner(player_choice, bot_choice);
Serial.println(winner);
 Serial.println("\n--- Rock-Paper-Scissors ---");
    Serial.print("Your choice: ");
    Serial.println(getChoiceName(player_choice));
    Serial.print("Computer's choice: ");
    Serial.println(getChoiceName(bot_choice));
    Serial.print("Result: ");
    result_show(winner);x
   }

int get_winner(int player, int computer){
  if (player == computer) {
    return 0; // Draw
  } else if ((player == 0 && computer == 1) || 
             (player == 1 && computer == 2) || 
             (player == 2 && computer == 0)) {
    return 1; // Player wins
  } else {
    return -1; // Computer wins
  }
}
void result_show(int x){
  switch (x) {
    case 0: 
      Serial.println("It's a Draw!");
      break;
    case 1: 
      Serial.println("You Win!");
      break;
    case -1:
     Serial.println("You Loose!");
     break;
  }
}
String getChoiceName(int choice) {
  switch (choice) {
    case 0: return "Rock";
    case 1: return "Scissors";
    case 2: return "Paper";
    default: return "Unknown";
  }
}



