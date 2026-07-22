#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//screen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//pins
#define BTN_UP   D0
#define BTN_LEFT D1
#define BTN_RIGHT  D2
#define BTN_DOWN   D3
#define BTN_SIDEDOWN   D9
#define BTN_SIDEUP   D8
#define BTN_UPLEFT   4
#define BTN_UPRIGHT   6
#define BUZZER D10

//adjust
#define CELL 4
#define MAX_LENGTH 80

//vars
bool isStarted = false;
bool isGameOver = false;

bool hasFood = false;
bool needNewFood = false;

int snakeX[MAX_LENGTH];
int snakeY[MAX_LENGTH];
int snakeLength;

int dirX, dirY;
int foodX, foodY;

int gridW = SCREEN_WIDTH / CELL;
int gridH = SCREEN_HEIGHT / CELL;

int score;

//press any side button (for start screen)
bool pressedSideButton() {
  return !digitalRead(BTN_SIDEDOWN) || !digitalRead(BTN_SIDEUP);
}

//movement buttons
void movementButtons() {
  if (!digitalRead(BTN_UP) && dirY != 1) {
    dirX = 0; dirY = -1;
  }
  if (!digitalRead(BTN_LEFT) && dirX != 1) {
    dirX = -1; dirY = 0;
  }
  if (!digitalRead(BTN_RIGHT) && dirX != -1) {
    dirX = 1; dirY = 0;
  }
  if (!digitalRead(BTN_DOWN) && dirY != -1) {
    dirX = 0; dirY = 1;
  }
}

//food spawning
void spawnFood() {
  bool allowed = false;

  while (!allowed) {
    allowed = true;

    foodX = random(0, gridW);
    foodY = random(0, gridH);

    for (int i = 0; i < snakeLength; i++) {
      if (foodX == snakeX[i] && foodY == snakeY[i]) {
        allowed = false;
        break;
      }
    }
  }

  hasFood = true;
}

//reset game from the beginning
void resetGame() {
  snakeLength = 4;
  dirX = 1;
  dirY = 0;
  score = 0;

  isGameOver = false;

  for (int i = 0; i < snakeLength; i++) {
    snakeX[i] = 4 - i;
    snakeY[i] = 4;
  }

  spawnFood();
}

//game progress updates
void updateGame() {
  //snake general movement
  for (int i = snakeLength - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  //head movement
  snakeX[0] += dirX;
  snakeY[0] += dirY;

  //if snake hits the walls
  if (snakeX[0] < 0 || snakeX[0] >= gridW || snakeY[0] < 0 || snakeY[0] >= gridH) {
    isGameOver = true;
    return;
  }

  //if snake hits itself
  for (int i = 1; i< snakeLength; i++) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      isGameOver = true;
      return;
    }
  }

  //eating food
  if (hasFood && snakeX[0] == foodX && snakeY[0] == foodY) {
    score++;

    int tailX = snakeX[snakeLength - 1];
    int tailY = snakeY[snakeLength - 1];

    if (snakeLength < MAX_LENGTH) {
      snakeLength++;
      snakeX[snakeLength - 1] = tailX;
      snakeY[snakeLength - 1] = tailY;
    }

    hasFood = false;
    needNewFood = true;

    return;
  }
}

//draw start screen
void drawStartScreen() {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("SNAKE");

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Press a button to start");

  display.display();
}

//draw game over screen
void drawGameOverScreen() {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("GAME OVER");

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Score: ");
  display.println(score);

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Press a button to start again");

  display.display();
}

//draw main gameplay
void drawGame() {
  display.clearDisplay();

  for (int i = 0; i < snakeLength; i++) {
    display.fillRect(
      snakeX[i] * CELL,
      snakeY[i] * CELL,
      CELL,
      CELL,
      WHITE
    );
  }

  if (hasFood) {
    display.fillRect(
      foodX * CELL, 
      foodY * CELL, 
      CELL,
      CELL, 
      WHITE
    );
  }

  display.display();
}

//setup
void setup() {
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SIDEDOWN, INPUT_PULLUP);
  pinMode(BTN_SIDEUP, INPUT_PULLUP);
  pinMode(BTN_UPLEFT, INPUT_PULLUP);
  pinMode(BTN_UPRIGHT, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

//loop
void loop() {
  
  if (!isStarted) {
    drawStartScreen();

    if (pressedSideButton()) {
      delay(300);
      drawGame();
      isStarted = true;
    }
    return;
  }

  if (!isGameOver) {
    movementButtons();
    updateGame();

    if (needNewFood) {
      spawnFood();
      needNewFood = false;
    }

    drawGame();
    delay(100);
  }
  else {
    drawGameOverScreen();

    if (pressedSideButton()) {
      delay(300);
      resetGame();
      isGameOver = false;
    }
  }
}
