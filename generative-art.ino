#include <TFT_eSPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   5
#define TFT_DC   4
#define TFT_RST  22
#define TFT_SCLK 18
#define TFT_MISO 19

TFT_eSPI tft = TFT_eSPI();


// Global variables
const char* lovePoems[] = {
    "Roses are red,\nViolets are blue,\nSugar is sweet,\nAnd so are you.",
    "Love is a canvas\nFurnished by nature\nAnd embroidered by \nimagination.",
    "You are the\nsunshine of my life,\nThe love that\nlights up my way.",
    "Love is like a\nbutterfly,\nIt settles upon you\nwhen you least \nexpect it.",
    "Your smile, my joy, \na sunny day, \nIn your embrace, \nI wish to stay.",
    "Stars align, \nhearts entwine, \nYour love, forever, \nwill be mine.",
    "Whispers soft, \nlove's gentle art, \nYou're the rhythm \nof my heart.",
    "Moonlit skies, \nour love entwined, \nForever yours, \neternally bind.",
    "In your eyes, \na world revealed, \nLove's language, \nsilently sealed."
};

const int numPoems = sizeof(lovePoems) / sizeof(lovePoems[0]); 

unsigned long lastPoemTime = 0;
unsigned long lastHeartTime = 0;

int poemIndex = 0;

uint16_t colorList[] = {
    tft.color565(255, 0, 127),      // Vivid Pink
    tft.color565(255, 182, 193),    // Light Pink
    tft.color565(255, 20, 147),      // Deep Pink
    tft.color565(255, 105, 180),     // Hot Pink
    tft.color565(220, 20, 60),        // Crimson
    tft.color565(255, 99, 71),         // Tomato
    tft.color565(205, 92, 92),        // Indian Red
    tft.color565(250, 128, 114),      // Salmon
    tft.color565(233, 150, 122),    // Dark Salmon
    tft.color565(240, 128, 128)     // Light Coral
};



void setup() {
    tft.begin();
    tft.setRotation(1); // Landscaoe mode
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE); 
    tft.setTextSize(2);

    // Set screen backlight brightness
    pinMode(TFT_BL, OUTPUT);
    ledcSetup(0, 5000, 8); // 0-15, 5000, 8
    ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
    ledcWrite(0, 40); // Increase the brightness value (0-255)
}



void loop() {
    // Clear the screen
    tft.fillScreen(TFT_BLACK);

    // Draw 3 hearts
    for (int i = 0; i < 3; i++) {
        drawHeart();
    }

    // Display the selected poem
    tft.setCursor(0, 40);
    tft.println(lovePoems[poemIndex]);

    // Delay for 1 second
    delay(1000);

    // Check if 10 seconds have passed since the last poem
    if (millis() - lastPoemTime >= 10000) {
        // Generate a new random index to select a poem
        poemIndex = random(numPoems);
        lastPoemTime = millis();
    }
}



void drawHeart() {

    // Random size and location for heart
    int heartSize = random(10, 50); 
    int heartX = random(tft.width() - heartSize); 
    int heartY = random(tft.height() - heartSize); 

    // Random color for heart
    uint16_t randomColor = colorList[random(sizeof(colorList) / sizeof(colorList[0]))]; 

    int heartWidth = heartSize / 2;
    int heartHeight = heartSize * 3 / 4;

    // Draw the heart
    tft.fillTriangle(heartX, heartY + heartHeight / 4, heartX + heartSize, heartY + heartHeight / 4, heartX + heartWidth, heartY + heartHeight, randomColor);
    tft.fillCircle(heartX + heartWidth / 2, heartY + heartHeight / 4, heartWidth / 2, randomColor);
    tft.fillCircle(heartX + heartWidth * 3 / 2, heartY + heartHeight / 4, heartWidth / 2, randomColor);
}