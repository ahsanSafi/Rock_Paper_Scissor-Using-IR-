int ifread_01, ifread_02;
int flag_01 = 0, flag_02 = 0, result = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  Serial.println("Press 'x' to start the game or 'o' to stop the game.");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();  // Read a single character

    if (input == 'x' || input == 'X') {
      Serial.println("\nGame started! Press 'o' to stop the game.");
      playGame();
    } 
    else if (input == 'o' || input == 'O') {
      Serial.println("\nGame over! Program stopped.");
      while (true);  // Halt the program (Arduino does not support exit(0))
    }
  }
}

void playGame() {
  ifread_01 = analogRead(A0);
  ifread_02 = analogRead(A2);

  flag_01 = (ifread_01 >= 150) ? 1 : 0;
  flag_02 = (ifread_02 >= 150) ? 1 : 0;

  result = flag_01 + flag_02;
  int player_choice = (result == 2) ? 2 : (result == 1) ? 1 : 0;
  int bot_choice = random(0, 3);
  int winner = get_winner(player_choice, bot_choice);

  Serial.println("\n--- Rock-Paper-Scissors ---");
  Serial.print("Your choice: ");
  Serial.println(getChoiceName(player_choice));
  Serial.print("Computer's choice: ");
  Serial.println(getChoiceName(bot_choice));
  Serial.print("Result: ");
  result_show(winner);
}

int get_winner(int player, int computer) {
  if (player == computer) return 0;  // Draw
  if ((player == 0 && computer == 1) || 
      (player == 1 && computer == 2) || 
      (player == 2 && computer == 0)) {
    return 1;  // Player wins
  }
  return -1;  // Computer wins
}

void result_show(int x) {
  switch (x) {
    case 0: Serial.println("It's a Draw!"); break;
    case 1: Serial.println("You Win!"); break;
    case -1: Serial.println("You Lose!"); break;
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
