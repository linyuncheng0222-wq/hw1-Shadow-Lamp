
const int R = 9;
const int G = 10;
const int B = 11;
const int button = 2;

int colorIndex = 0;
bool lastButton = HIGH;

int colors[6][3] = {
  {255, 255, 255}, // 白
  {255, 0, 0},     // 紅
  {0, 0, 255},     // 藍
  {0, 255, 0},     // 綠
  {180, 0, 255},   // 紫
  {0, 180, 255}    // 淺藍
};

void setColor(int i) {
  analogWrite(R, 255 - colors[i][0]);
  analogWrite(G, 255 - colors[i][1]);
  analogWrite(B, 255 - colors[i][2]);
}

void setup() {
  pinMode(button, INPUT_PULLUP);
  setColor(colorIndex);
}

void loop() {
  bool current = digitalRead(button);

  if (lastButton == HIGH && current == LOW) {
    colorIndex = (colorIndex + 1) % 6;
    setColor(colorIndex);
    delay(200);
  }

  lastButton = current;
}
